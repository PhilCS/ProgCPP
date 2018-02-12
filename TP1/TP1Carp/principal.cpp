/******************************************************************************
    Fichier:    principal.cpp

    Utilité:    Programme permettant de tester la classe CEmploye, ainsi que sa
                bibliothèque de fonctions, à l'aide d'une interface console.

    Auteur:     Philippe Carpentier-Savard
******************************************************************************/
#include "fonctions.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


#ifdef _WIN32
const char EFFACER_ECRAN [] = "cls";
#else
const char EFFACER_ECRAN [] = "clear";
#endif


/******************************************************************************
    Définition de la fonction main ()
******************************************************************************/
int main()
{
    char cChoix;
    CEmploye lesEmployes[NB_EMPLOYES];
    bool bPaiesGeneres = false;
    char szRetourMenu[] = "Appuyez sur <Entree> pour retourner au menu "
                          "principal...";

    do
    {
        system(EFFACER_ECRAN);

        cout << "Menu principal" << '\n'
             << '\n'
             << "[1] Generation des paies" << '\n'
             << "[2] Salaires detailles" << '\n'
             << "[3] Sommaire global" << '\n'
             << "[4] Quitter" << '\n'
             << '\n'
             << "Votre choix: " << flush;

        cChoix = cin.get();
        while (cin.get() != '\n');

        switch (cChoix)
        {
            /*****************************************************************/
            case '1':
                system(EFFACER_ECRAN);

                cout << "Generation des paies" << '\n' << '\n'
                     << "Traitement en cours..." << '\n';

                GenererPaies(lesEmployes);
                bPaiesGeneres = true;

                cout << "Generation des paies pour les " << NB_EMPLOYES
                     << " employes terminee!" << '\n' << '\n'
                     << szRetourMenu << flush;

                while (cin.get() != '\n');
                break;
            /*****************************************************************/
            case '2':
                system(EFFACER_ECRAN);

                cout << "Salaires detailles" << '\n' << '\n';

                if (bPaiesGeneres)
                {
                    unsigned int uiEmploye;
                    unsigned int uiHeures;
                    unsigned int uiSemaine;

                    streamsize iPrecision;
                    cout.setf(ios_base :: fixed, ios_base :: floatfield);
                    iPrecision = cout.precision(2);

                    for (uiEmploye = 0; uiEmploye < NB_EMPLOYES; ++uiEmploye)
                    {
                        cout << "Employe no. " << uiEmploye+1 << '\n'
                             << "Taux horaire:";
                        cout.width(16);
                        cout << (float)lesEmployes[uiEmploye].GetTauxHoraire()
                             << "$" << '\n';

                        for (uiSemaine = 0, uiHeures = 0;
                                          uiSemaine < NB_SEMAINES; ++uiSemaine)
                            uiHeures += lesEmployes[uiEmploye].GetHeures
                                                                   (uiSemaine);

                        cout << "Total des heures:";
                        cout.width(11);
                        cout << uiHeures << '\n' << '\n';
                    }

                    cout.precision(iPrecision);
                    cout.unsetf(ios_base :: floatfield);
                }
                else
                {
                    cout << "Vous devez avoir effectue au moins une generation"
                            " des paies " << '\n' << "pour afficher les "
                            "salaires detailles." << '\n' << '\n';
                }

                cout << szRetourMenu << flush;
                while (cin.get() != '\n');
                break;
            /*****************************************************************/
            case '3':
                system(EFFACER_ECRAN);

                cout << "Sommaire global" << '\n' << '\n';

                if (bPaiesGeneres)
                {
                    unsigned int uiTotalSalaires;
                    unsigned int uiTotalHeures;
                    float fTauxMoyen;

                    CalculerResultatsGlobaux(lesEmployes, uiTotalSalaires,
                                             uiTotalHeures, fTauxMoyen);

                    streamsize iPrecision;
                    cout.setf(ios_base :: fixed, ios_base :: floatfield);
                    iPrecision = cout.precision(2);

                    cout << "Nombre d'employes: ";
                    cout.width(14);
                    cout << NB_EMPLOYES << '\n';

                    cout << "Total des salaires verses: ";
                    cout.width(14);
                    cout << (float)uiTotalSalaires << "$" << '\n';

                    cout << "Total des heures: ";
                    cout.width(19);
                    cout << uiTotalHeures << '\n';

                    cout << "Taux horaire moyen: ";
                    cout.width(17);
                    cout << fTauxMoyen << "$" << '\n' << '\n';

                    cout.precision(iPrecision);
                    cout.unsetf(ios_base :: floatfield);
                }
                else
                {
                    cout << "Vous devez avoir effectue au moins une generation"
                            " des ventes "  << '\n' << "pour afficher le "
                            "sommaire global." << '\n' << '\n';
                }

                cout << szRetourMenu << flush;
                while (cin.get() != '\n');
                break;
            /*****************************************************************/
            case '4':
                system(EFFACER_ECRAN);

                cout << "Au revoir!" << '\n' << '\n' << "Appuyez sur <Entree> "
                        "pour terminer..."<< flush;

                while (cin.get() != '\n');
                break;
            /*****************************************************************/
            default:
                cout << '\n' << "Choix invalide. Appuyez sur <Entree> pour "
                                "continuer...";

                while (cin.get() != '\n');
                break;
            /*****************************************************************/
        }
    }
    while (cChoix != '4');

    return 0;
}