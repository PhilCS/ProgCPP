/******************************************************************************
    Fichier:    principal.cpp

    Utilité:    Programme permettant de tester l'implémentation des
                bibliothèques CVecteurEntiers et CListeEntiers à l'aide d'une
                interface console

    Auteur:     Philippe Carpentier-Savard
******************************************************************************/
#include "aleatoire.h"
#include "listeentiers.h"
#include "vecteurentiers.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

#ifdef _WIN32
const char EFFACER_ECRAN [] = "cls";
#else
const char EFFACER_ECRAN [] = "clear";
#endif

int main()
{
    const char szChoixInvalide[] = "Choix invalide. Appuyez sur <Entree> pour "
                                   "continuer...";
    const char szRetourMenu[] = "Appuyez sur <Entree> pour retourner au menu "
                                "principal...";
    char cChoix;

    CVecteurEntiers * pVecEntiers = new CVecteurEntiers;
    CListeEntiers * pListeEntiers = new CListeEntiers;
    unsigned int uiNbEntiers = 0;
    bool bMemoireAllouee = false;

    do
    {
        system(EFFACER_ECRAN);

        cout << "Menu principal" << '\n'
             << '\n'
             << "[1] Allocation de la memoire" << '\n'
             << "[2] Affichage des donnees" << '\n'
             << "[3] Liberation de la memoire" << '\n'
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

                char cSousChoix;

                do
                {
                    system(EFFACER_ECRAN);

                    cout << "Allocation de la memoire" << '\n' << '\n';

                    if (bMemoireAllouee)
                    {
                        cout << "Vous devez liberer la memoire avant de faire "
                                "une nouvelle allocation." << '\n' << '\n'
                                << szRetourMenu << flush;

                        while (cin.get() != '\n');
                        break;
                    }

                    cout << "[1] Creer 20000 elements" << '\n'
                            << "[2] Creer 60000 elements" << '\n'
                            << "[3] Creer 100000 elements" << '\n'
                            << "[4] Annuler" << '\n'
                            << '\n'
                            << "Votre choix: " << flush;

                    cSousChoix = cin.get();
                    while (cin.get() != '\n');

                    switch (cSousChoix)
                    {
                        case '1':
                            uiNbEntiers = 20000;
                            break;

                        case '2':
                            uiNbEntiers = 60000;
                            break;

                        case '3':
                            uiNbEntiers = 100000;
                            break;

                        case '4':
                            break;

                        default:
                            cout << '\n' << szChoixInvalide;
                            while (cin.get() != '\n');
                            break;
                    }

                    if (uiNbEntiers != 0)
                    {
                        clock_t clkDebut;
                        clock_t clkFin;
                        double dDuree;
                        unsigned int uiIndice;

                        /* Vecteur *******************************************/

                        cout << '\n' << "Ajout des " << uiNbEntiers << " "
                                        "elements au vecteur...";

                        pVecEntiers = new CVecteurEntiers;

                        clkDebut = clock();

                        for (uiIndice = 0; uiIndice < uiNbEntiers; uiIndice++)
                            pVecEntiers->Ajouter(GenererNbAleatoire(0, 32767));

                        clkFin = clock();
                        dDuree = (double) (clkFin - clkDebut) / CLOCKS_PER_SEC;

                        cout << '\n' << "Temps pris pour l'allocation du "
                                        "vecteur: " << dDuree << " secondes";

                        /* Liste *********************************************/

                        cout << '\n' << '\n' << "Ajout des " << uiNbEntiers
                             << " elements a la liste...";

                        pListeEntiers = new CListeEntiers;

                        clkDebut = clock();

                        for (uiIndice = 0; uiIndice < uiNbEntiers; uiIndice++)
                            pListeEntiers->Ajouter(GenererNbAleatoire(0,
                                                                       32767));

                        clkFin = clock();
                        dDuree = (double) (clkFin - clkDebut) / CLOCKS_PER_SEC;

                        cout << '\n' << "Temps pris pour l'allocation de la "
                                        "liste: " << dDuree << " secondes";

                        /*****************************************************/

                        bMemoireAllouee = true;

                        cout << '\n' << '\n' << szRetourMenu << flush;

                        while (cin.get() != '\n');
                        cSousChoix = '4';
                        break;
                    }

                } while (cSousChoix != '4');
                break;
            /*****************************************************************/
            case '2':
                system(EFFACER_ECRAN);

                cout << "Affichage des donnees" << '\n' << '\n';

                if (!bMemoireAllouee)
                    cout << "Le vecteur et la liste sont vides." << '\n'
                         << '\n';
                else
                {
                    unsigned int uiIndice;
                    unsigned int uiNbElements;

                    /* Vecteur ***********************************************/

                    cout << "Appuyez sur <Entree> pour demarrer l'affichage "
                            "des elements du vecteur..." << flush;
                    while (cin.get() != '\n');

                    cout << '\n';

                    for (uiIndice = 0,
                         uiNbElements = pVecEntiers->NbElements();
                         uiIndice < uiNbElements; uiIndice++)
                    {
                        cout.setf(ios :: left);
                        cout.width(8);
                        cout << (*pVecEntiers)[uiIndice];
                    }


                    cout << '\n' << "Fin de l'affichage des elements du "
                                    "vecteur." << '\n' << '\n';

                    /* Liste *************************************************/

                    cout << "Appuyez sur <Entree> pour demarrer l'affichage "
                            " des elements de la liste..." << flush;
                    while (cin.get() != '\n');

                    cout << '\n';

                    for (uiIndice = 0,
                         uiNbElements = pListeEntiers->NbElements();
                         uiIndice < uiNbElements; uiIndice++)
                    {
                        cout.setf(ios :: left);
                        cout.width(8);
                        cout << (*pListeEntiers)[uiIndice];
                    }

                    cout << '\n' << "Fin de l'affichage des elements de la "
                                    "liste." << '\n' << '\n';

                    /*********************************************************/
                }

                cout << szRetourMenu << flush;
                while (cin.get() != '\n');
                break;
            /*****************************************************************/
            case '3':
                system(EFFACER_ECRAN);

                cout << "Liberation de la memoire" << '\n' << '\n';

                if (!bMemoireAllouee)
                {
                    cout << "Vous devez allouer la memoire avant de la "
                            "liberer." << '\n' << '\n';
                }
                else
                {
                    clock_t clkDebut;
                    clock_t clkFin;
                    double dDuree;
                    unsigned int uiIndice;

                    /* Vecteur ***********************************************/

                    cout << "Retrait des " << uiNbEntiers << " elements du "
                            "vecteur...";

                    clkDebut = clock();

                    for (uiIndice = 0; uiIndice < uiNbEntiers; uiIndice++)
                        pVecEntiers->Retirer(0);

                    clkFin = clock();
                    dDuree = (double) (clkFin - clkDebut) / CLOCKS_PER_SEC;

                    cout << '\n' << "Temps pris pour la liberation du vecteur:"
                                    " " << dDuree << " secondes";

                    /* Liste *************************************************/

                    cout << '\n' << '\n' << "Retrait des " << uiNbEntiers <<
                            " elements de la liste...";

                    clkDebut = clock();

                    pListeEntiers->Vider();

                    clkFin = clock();
                    dDuree = (double) (clkFin - clkDebut) / CLOCKS_PER_SEC;

                    cout << '\n' << "Temps pris pour la liberation de la "
                                    "liste: " << dDuree << " secondes" << '\n'
                         << '\n';

                    /*********************************************************/

                    bMemoireAllouee = false;
                }

                cout << szRetourMenu << flush;
                while (cin.get() != '\n');
                break;
            /*****************************************************************/
            case '4':
                clock_t clkDebut;
                clock_t clkFin;
                double dDuree;

                system(EFFACER_ECRAN);

                cout << "Destruction du vecteur et de la liste" << '\n'
                     << '\n';

                /* Vecteur ***************************************************/

                cout << "Liberation du vecteur...";

                clkDebut = clock();

                delete pVecEntiers;

                clkFin = clock();
                dDuree = (double) (clkFin - clkDebut) / CLOCKS_PER_SEC;

                cout << '\n' << "Temps pris pour la destruction du vecteur: "
                             << dDuree << " secondes" << '\n' << '\n';

                /* Liste *****************************************************/

                cout << "Liberation de la liste...";

                clkDebut = clock();

                delete pListeEntiers;

                clkFin = clock();
                dDuree = (double) (clkFin - clkDebut) / CLOCKS_PER_SEC;

                cout << '\n' << "Temps pris pour la destruction de la liste: "
                     << dDuree << " secondes";

                /*************************************************************/

                cout << '\n' << '\n' << '\n' << "Appuyez sur <Entree> pour "
                                                "quitter..." << flush;

                while (cin.get() != '\n');
                break;
            /*****************************************************************/
            default:
                cout << '\n' << szChoixInvalide;

                while (cin.get() != '\n');
                break;
            /*****************************************************************/
        }

    } while (cChoix != '4');

    return 0;
}