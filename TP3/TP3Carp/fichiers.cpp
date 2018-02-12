/******************************************************************************
    Fichier:    fichiers.cpp

    Utilité:    Implémentation des fonctions de la bibliothèque Fichiers.

    Auteur:     Philippe Carpentier-Savard
******************************************************************************/
#include "fichiers.h"
#include "utilitaires.h"
#include <fstream>
#include <stdlib.h>
#include <string>

#ifdef _MSC_VER
#pragma warning (disable : 4996)
#endif

using namespace std;


/******************************************************************************
    Fonction retournant le nombre de lignes contenues dans le fichier situé au
    chemin passé en entrée.
******************************************************************************/
int GetNbLignes (const char * szFichierSrc)
{
    fstream leFichier;

    leFichier.open(szFichierSrc, ios :: in | ios :: binary);

    if (!leFichier.fail())
    {
        int iNbLignes = 0;

        while (!leFichier.eof())
            if (leFichier.get() == '\n')
                iNbLignes++;

        leFichier.close();
        return iNbLignes;
    }

    return -1;
}


/******************************************************************************
    Fonction permettant de générer des objets CJoueur à partir des données
    contenues dans le fichier situé au chemin passé en entrée.
******************************************************************************/
bool RemplirVecteur (CJoueur ** ppLesJoueurs, const char * szFichierSrc)
{
    int iNbJoueurs = GetNbLignes(szFichierSrc);

    if (iNbJoueurs != -1)
    {
        fstream ficJoueurs;

        ficJoueurs.open(szFichierSrc, ios :: in | ios :: binary);

        if (!ficJoueurs.fail())
        {
            int iIndice;
            int iIndiceJoueur;
            unsigned int uiPosDebut;
            unsigned int uiPosFin;
            string strTampon;
            string strValeurs[9];

            for (iIndiceJoueur = 0;
                 iIndiceJoueur < iNbJoueurs && !ficJoueurs.eof();
                 iIndiceJoueur++)
            {
                getline(ficJoueurs, strTampon);

                for (iIndice = 0, uiPosDebut = 0; iIndice < 9; iIndice++)
                {
                    uiPosFin = strTampon.find(';', uiPosDebut);
                    strValeurs[iIndice] = strTampon.substr(uiPosDebut,
                                                           uiPosFin -
                                                           uiPosDebut);
                    uiPosDebut = uiPosFin + 1;
                }

                ppLesJoueurs[iIndiceJoueur] =
                                    new CJoueur(strValeurs[0].c_str(),
                                                strValeurs[1].c_str(),
                                                strValeurs[2].c_str(),
                                                strValeurs[3][0],
                                                atoi(strValeurs[4].c_str()),
                                                atoi(strValeurs[5].c_str()),
                                                atoi(strValeurs[6].c_str()),
                                                atoi(strValeurs[7].c_str()),
                                                atoi(strValeurs[8].c_str()));
            }

            ficJoueurs.close();
            return true;
        }
    }

    return false;
}


/******************************************************************************
    Fonction permettant de créer un fichier de données relatives, situé au
    chemin passé en entrée, à partir du vecteur de pointeurs d'objets CJoueur
    passé en entrée.
******************************************************************************/
bool CreerFichierDirect (const char * szFichierDest, CJoueur ** ppLesJoueurs,
                         int iNbJoueurs)
{
    fstream ficDest;

    ficDest.open(szFichierDest, ios :: in | ios :: out | ios :: trunc |
                                ios :: binary);

    if (!ficDest.fail())
    {
        int iIndice;
        CJoueur * pUnJoueur;
        unsigned int uiPosition;
        unsigned int uiDiviseur = (unsigned int)(iNbJoueurs * 1.25f);
        unsigned int uiDebordement = uiDiviseur * TAILLE_ENREGISTREMENT;
        char szEnregistrement[TAILLE_ENREGISTREMENT + 1] = "";

        while (!EstPremier(uiDiviseur))
            uiDiviseur++;

        for (iIndice = 0; iIndice < iNbJoueurs; iIndice++)
        {
            pUnJoueur = ppLesJoueurs[iIndice];

            uiPosition = pUnJoueur->GetNom()[0] *
                         pUnJoueur->GetNom()[
                             GetLongueurChaine(pUnJoueur->GetNom()) - 1] *
                         pUnJoueur->GetEquipe()[0] % uiDiviseur *
                         TAILLE_ENREGISTREMENT;

            ficDest.seekg(uiPosition, ios :: beg);

            if (ficDest.peek() != 0 && !ficDest.eof())
            {
                unsigned int uiCourant;
                unsigned int uiSuivant = uiPosition;
                char szSuivant[9] = "";

                do
                {
                    ficDest.seekg(TAILLE_ENREGISTREMENT - 8, ios :: cur);
                    ficDest.read(szSuivant, 8);

                    uiCourant = uiSuivant;
                    uiSuivant = atoi(szSuivant);

                    if (uiSuivant != 0)
                        ficDest.seekg(uiSuivant, ios :: beg);

                } while (uiSuivant != 0);


                ficDest.seekp(uiCourant + TAILLE_ENREGISTREMENT - 8,
                              ios :: beg);
                sprintf(szSuivant, "%8d", uiDebordement);

                ficDest.write(szSuivant, 8);

                ficDest.seekp(uiDebordement, ios :: beg);

                uiDebordement += TAILLE_ENREGISTREMENT;
            }
            else
            {
                ficDest.clear();
                ficDest.seekp(uiPosition, ios :: beg);
            }

            sprintf(szEnregistrement, "%3s%-30s%3s%c%5d%5d%5d%5d%5d%8d",
                    pUnJoueur->GetRang(), pUnJoueur->GetNom(),
                    pUnJoueur->GetEquipe(), pUnJoueur->GetPosition(),
                    pUnJoueur->GetNbParties(), pUnJoueur->GetNbButs(),
                    pUnJoueur->GetNbPasses(),
                    pUnJoueur->GetDifferentiel(),
                    pUnJoueur->GetNbMinutesPunition(), 0);

            ficDest.write(szEnregistrement, TAILLE_ENREGISTREMENT);
        }

        ficDest.close();
        return true;
    }

    return false;
}

/******************************************************************************
    Fonction permettant de chercher un joueur dans un fichier de données
    relatives, dont le chemin est passé en entrée, et de retourner un objet
    CJoueur contenant ses informations si la recherche est fructueuse.
******************************************************************************/
CJoueur ChercherJoueurDirect (const char * szFichierSrc, int iNbJoueurs,
                                const char * szNom, const char * szEquipe)
{
    CJoueur leJoueur;
    fstream ficJoueurs;

    ficJoueurs.open(szFichierSrc, ios :: in | ios :: binary);

    if (!ficJoueurs.fail())
    {
        bool bJoueurTrouve = false;
        unsigned int uiPosition = szNom[0] *
                                  szNom[GetLongueurChaine(szNom) - 1] *
                                  szEquipe[0] %
                                  (unsigned int)(iNbJoueurs * 1.25f) *
                                  TAILLE_ENREGISTREMENT;

        ficJoueurs.seekg(uiPosition, ios :: beg);

        if (ficJoueurs.peek() != 0)
        {
            char szSuivant[9] = "";
            char szNomEquipe[34] = "";
            char szTampon[TAILLE_ENREGISTREMENT + 1] = "";
            string strTampon;

            sprintf(szNomEquipe, "%-30s%3s", szNom, szEquipe);

            do
            {
                ficJoueurs.read(szTampon, TAILLE_ENREGISTREMENT);
                strTampon = szTampon;

                if (ComparerChaines(szNomEquipe,
                                    strTampon.substr(3, 33).c_str()))
                {

                    leJoueur = CJoueur(strTampon.substr(0, 3).c_str(),
                                       szNom,
                                       szEquipe,
                                       strTampon[36],
                                       atoi(strTampon.substr(37, 5).c_str()),
                                       atoi(strTampon.substr(42, 5).c_str()),
                                       atoi(strTampon.substr(47, 5).c_str()),
                                       atoi(strTampon.substr(52, 5).c_str()),
                                       atoi(strTampon.substr(57, 5).c_str()));

                    bJoueurTrouve = true;
                }
                else
                {
                    uiPosition = atoi(strTampon.substr
                                       (TAILLE_ENREGISTREMENT - 8, 8).c_str());

                    if (uiPosition != 0)
                        ficJoueurs.seekg(uiPosition, ios :: beg);
                }

            } while (uiPosition != 0 && !bJoueurTrouve);
        }

        ficJoueurs.close();

        if (!bJoueurTrouve)
            throw "Enregistrement inexistant.";
    }
    else
        throw "Fichier invalide.";

    return leJoueur;
}