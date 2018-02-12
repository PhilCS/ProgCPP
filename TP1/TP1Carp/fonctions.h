/******************************************************************************
	Fichier:	fonctions.h
	
	Utilit�:	Biblioth�que contenant deux fonctions, servant respectivement �
				assigner des valeurs al�atoires pour tester l'ex�cution, et �
				calculer les statistiques globales.

	Auteur:		Philippe Carpentier-Savard
******************************************************************************/
#ifndef __FONCTIONS_H
#define __FONCTIONS_H

#include "employe.h"


// Constante servant � d�terminer la taille du vecteur
const unsigned int NB_EMPLOYES = 5;

// M�thodes
void GenererPaies (CEmploye lesEmployes[NB_EMPLOYES]);
void CalculerResultatsGlobaux (const CEmploye lesEmployes[NB_EMPLOYES], 
							   unsigned int & uiTotalSalaires, 
							   unsigned int & uiTotalHeures, 
							   float & fTauxMoyen);


#endif