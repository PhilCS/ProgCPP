/******************************************************************************
    Fichier:    aleatoire.cpp

    Auteur:     José Consola

    Utilité:    Implémentation de la bibliothèque contenant la fonction de
                génération de nombres pseudo-aléatoires.
******************************************************************************/
#include "aleatoire.h"
#include <time.h>
#include <stdlib.h>


/******************************************************************************
    La fonction GenererNbAleatoire (...) permet d'obtenir un nombre aléatoire
    dont la valeur est comprise inclusivement entre les bornes passées en
    paramètres. Lance une exception si l'une ou l'autre des bornes est
    négative ou si la borne inférieure a une valeur plus grande que la borne
    supérieure.
******************************************************************************/
int GenererNbAleatoire (short sMin, short sMax)
{
    // Variable statique qui permet de vérifier si le générateur des nombres
    // aléatoires a été initialisé.
    // N.B.:    Une variable déclarée statique à l'intérieur d'une fonction
    //          reste en mémoire (et conserve sa valeur) même lorsque la
    //          fonction a terminé son exécution.
    static bool bInitialise = false;

    // Initialisation unique du générateur de nombres aléatoires.
    if (! bInitialise)
    {
        srand ((unsigned) time (NULL));
        bInitialise = true;
    }
    if (sMin < 0 || sMax < 0 || sMin > sMax)
    {
        throw "Limites invalides.";
    }
    // La fonction rand () retourne un nombre pseudo-aléatoire compris
    // entre 0 et 32767 (inclusivement). La constante RAND_MAX possède la
    // valeur 32767.
    // N.B.:    Le résultat retourné par rand () et la valeur de RAND_MAX
    //          dépendent de leur implémentation.
    return sMin + (int) ((double) rand () * (sMax - sMin + 1)
        / ((unsigned) RAND_MAX + 1));
}