/******************************************************************************
	Fichier:	employe.cpp
	
	Utilité:	Implémentation des méthodes de la classe Cemploye.

	Auteur:		Philippe Carpentier-Savard
******************************************************************************/
#include "employe.h"


/******************************************************************************
	Constructeur permettant d'initialiser toutes les données-membres à 0.
******************************************************************************/
CEmploye :: CEmploye ()
: m_uiTauxHoraire (0)
{
	unsigned int uiSemaine;
	
	for (uiSemaine = 0; uiSemaine < NB_SEMAINES; ++uiSemaine)
		m_uiLesHeures[uiSemaine] = 0;
}


/******************************************************************************
	Constructeur permettant d'initialiser toutes les données membres avec les
	valeurs des données-membres de l'objet CEmploye passé en entrée.
******************************************************************************/
CEmploye :: CEmploye (const CEmploye & unVendeur)
: m_uiTauxHoraire (unVendeur.m_uiTauxHoraire)
{
	unsigned int uiSemaine;

	for (uiSemaine = 0; uiSemaine < NB_SEMAINES; ++uiSemaine)
		m_uiLesHeures[uiSemaine] = unVendeur.m_uiLesHeures[uiSemaine];
}


/******************************************************************************
	Méthode permettant d'affecter la valeur passée en paramètre à la donnée-
	membre correspondante.
******************************************************************************/
void CEmploye :: SetTauxHoraire (unsigned int uiTauxHoraire)
{
	m_uiTauxHoraire = uiTauxHoraire;
}


/******************************************************************************
	Méthode permettant d'affecter la valeur passée en paramètre à l'index 
	choisi du vecteur-membre correspondant.
******************************************************************************/
void CEmploye :: SetHeures (unsigned int uiHeures, int iSemaine)
{
	if (iSemaine < 0 || iSemaine >= NB_SEMAINES)
		throw "Indice en dehors de la plage.";

	m_uiLesHeures[iSemaine] = uiHeures;
}


/******************************************************************************
	Méthode permettant d'obtenir la valeur de la donnée-membre représentant le 
	taux de commission du employe.
******************************************************************************/
unsigned int CEmploye :: GetTauxHoraire () const
{
	return m_uiTauxHoraire;
}


/******************************************************************************
	Méthode permettant d'obtenir la valeur du vecteur-membre représentant le 
	montant des ventes du employe pour le mois choisi.
******************************************************************************/
unsigned int CEmploye :: GetHeures (unsigned int uiSemaine) const
{
	if (uiSemaine >= NB_SEMAINES)
		throw "Indice en dehors de la plage.";

	return m_uiLesHeures[uiSemaine];
}