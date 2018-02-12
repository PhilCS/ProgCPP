/******************************************************************************
    Fichier:    fichiers.h

    Utilité:    Bibliothèque qui effectue diverses interactions en lecture
                et en écriture sur des fichiers des données séquentielles et
                relatives, qui contiennent diverses informations et
                statistiques sur des joueurs de hockey de la LNH.

    Auteur:     Philippe Carpentier-Savard
******************************************************************************/
#ifndef __FICHIERS_H
#define __FICHIERS_H

#include "joueur.h"


const unsigned int TAILLE_ENREGISTREMENT = 70;

int GetNbLignes (const char * szFichierSrc);
bool RemplirVecteur (CJoueur ** ppLesJoueurs, const char * szFichierSrc);
bool CreerFichierDirect (const char * szFichierDest, CJoueur ** ppLesJoueurs,
                         int iNbJoueurs);
CJoueur ChercherJoueurDirect (const char * szFichierSrc, int iNbJoueurs,
                              const char * szNom, const char * szEquipe);

#endif