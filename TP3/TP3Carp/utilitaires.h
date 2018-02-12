/******************************************************************************
	Fichier:		utilitaires.h

	Bibliothèque:	Utilitaires

	Auteur:			José Consola

	Utilité:		Bibliothèque qui fournit des fonctions de base dans le but
					d'éviter d'intégrer des bibliothèques plus volumineuses
					et/ou qui contiennent des fonctions hors standard.
******************************************************************************/
#ifndef __UTILITAIRES_H
#define __UTILITAIRES_H


bool EstPremier (unsigned int uiNombre);
void CopierChaine (char * szDest, const char * szSource,
				   unsigned int uiNbCars);
int ComparerChaines (const char * szChaine1, const char * szChaine2);
unsigned int GetLongueurChaine (const char * szSource);


#endif