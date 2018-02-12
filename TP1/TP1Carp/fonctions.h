/******************************************************************************
	Fichier:	fonctions.h
	
	Utilité:	Bibliothèque contenant deux fonctions, servant respectivement à
				assigner des valeurs aléatoires pour tester l'exécution, et à
				calculer les statistiques globales.

	Auteur:		Philippe Carpentier-Savard
******************************************************************************/
#ifndef __FONCTIONS_H
#define __FONCTIONS_H

#include "employe.h"


// Constante servant à déterminer la taille du vecteur
const unsigned int NB_EMPLOYES = 5;

// Méthodes
void GenererPaies (CEmploye lesEmployes[NB_EMPLOYES]);
void CalculerResultatsGlobaux (const CEmploye lesEmployes[NB_EMPLOYES], 
							   unsigned int & uiTotalSalaires, 
							   unsigned int & uiTotalHeures, 
							   float & fTauxMoyen);


#endif