/******************************************************************************
    Fichier:    principal.cpp

    Utilité:    Programme permettant de tester les diverses fonctions de la
                bibliothèque Fichiers à l'aide d'une interface console.

    Auteur:     Philippe Carpentier-Savard
******************************************************************************/
#include "fichiers.h"
#include <iostream>

using namespace std;

#ifdef _WIN32
const char EFFACER_ECRAN [] = "cls";
#else
const char EFFACER_ECRAN [] = "clear";
#endif


int main()
{
    const char szFichierTexte[] = "./joueurs.txt";
    const char szFichierDirect[] = "./joueurs.dat";

    cout << "Obtention du nombre de lignes dans le fichier source "
            "(joueurs.txt)..." << '\n';

    int iNbLignes = GetNbLignes(szFichierTexte);

    if (iNbLignes != -1)
    {
        int iIndice;

        cout << "Nombre de lignes obtenues: " << iNbLignes
             << " [ != -1 -> OK :)]" << '\n' << '\n'
             << "Creation d'un vecteur dynamique de " << iNbLignes
             << " pointeurs d'objets CJoueur...";

        CJoueur ** ppLesJoueurs = new CJoueur * [iNbLignes];

        cout << '\n' << '\n' << "Remplissage du vecteur a partir du fichier "
                "source (joueurs.txt)...";

        if (RemplirVecteur(ppLesJoueurs, szFichierTexte))
        {
            int iSubIndice;
            iIndice = 0;

            cout << '\n' << "Objets CJoueur places en memoire (sur le tas) "
                            "avec succes!" << '\n' << '\n'
                 << "Creation du fichier a acces direct (joueurs.dat)...";

            if (CreerFichierDirect(szFichierDirect, ppLesJoueurs, iNbLignes))
            {
                CJoueur unJoueur;

                cout << '\n' << "Fichier joueurs.dat cree avec succes!" << '\n'
                     << '\n' << "Appuyez sur <Entree> pour lancer la recherche"
                                " et l'affichage " << '\n' << "des joueurs a "
                                "partir du fichier joueurs.dat...";
                while (cin.get () != '\n');

                while (iIndice < iNbLignes)
                {
                    for (iSubIndice = 0;
                         iSubIndice < 20 && iIndice < iNbLignes;
                         iIndice++, iSubIndice++)
                    {

                        unJoueur = CJoueur(ChercherJoueurDirect(szFichierDirect,
                                            iNbLignes,
                                           ppLesJoueurs[iIndice]->GetNom(),
                                          ppLesJoueurs[iIndice]->GetEquipe()));
                        cout << '\n';

                        cout.width(16);
                        cout << left << "Rang:" << unJoueur.GetRang() << '\n';

                        cout.width(16);
                        cout << left << "Nom:" << unJoueur.GetNom() << '\n';

                        cout.width(16);
                        cout << left << "Equipe:" << unJoueur.GetEquipe()
                             << '\n';

                        cout.width(16);
                        cout << left << "Position:" << unJoueur.GetPosition()
                             << '\n';

                        cout.width(16);
                        cout << left << "Parties:" << unJoueur.GetNbParties()
                             << '\n';

                        cout.width(16);
                        cout << left << "Buts:" << unJoueur.GetNbButs()
                             << '\n';

                        cout.width(16);
                        cout << left << "Passes:" << unJoueur.GetNbPasses()
                             << '\n';

                        cout.width(16);
                        cout << left << "Differentiel:"
                             << unJoueur.GetDifferentiel() << '\n';

                        cout.width(16);
                        cout << left << "Punitions:"
                             << unJoueur.GetNbMinutesPunition() << '\n';
                    }

                    if (iSubIndice == 20)
                    {
                        cout << '\n' << "Appuyez sur <Entree> pour "
                                        "continuer..." << flush;
                        while (cin.get () != '\n');
                    }
                }
            }
        }

        cout << '\n' << "Appuyez sur <Entree> pour retirer un a un tous les "
                        "objets " << '\n' << "CJoueur de la memoire..."
             << flush;
        while (cin.get () != '\n');

        for (iIndice = 0; iIndice < iNbLignes; iIndice++)
            delete ppLesJoueurs[iIndice];

        cout << '\n' << "Appuyez sur <Entree> pour retirer le vecteur de la "
                        "memoire..." << flush;
        while (cin.get () != '\n');

        delete[] ppLesJoueurs;
    }

    cout << '\n' << "Appuyez sur <Entree> pour quitter..." << flush;
    while (cin.get () != '\n');

    return 0;
}