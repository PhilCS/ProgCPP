/******************************************************************************
	Fichier:	employe.cpp
	
	Utilit�:	Impl�mentation des m�thodes de la classe Cemploye.

	Auteur:		Philippe Carpentier-Savard
******************************************************************************/
#include "employe.h"


/******************************************************************************
	Constructeur permettant d'initialiser toutes les donn�es-membres � 0.
******************************************************************************/
CEmploye :: CEmploye ()
: m_uiTauxHoraire (0)
{
	unsigned int uiSemaine;
	
	for (uiSemaine = 0; uiSemaine < NB_SEMAINES; ++uiSemaine)
		m_uiLesHeures[uiSemaine] = 0;
}


/******************************************************************************
	Constructeur permettant d'initialiser toutes les donn�es membres avec les
	valeurs des donn�es-membres de l'objet CEmploye pass� en entr�e.
******************************************************************************/
CEmploye :: CEmploye (const CEmploye & unVendeur)
: m_uiTauxHoraire (unVendeur.m_uiTauxHoraire)
{
	unsigned int uiSemaine;

	for (uiSemaine = 0; uiSemaine < NB_SEMAINES; ++uiSemaine)
		m_uiLesHeures[uiSemaine] = unVendeur.m_uiLesHeures[uiSemaine];
}


/******************************************************************************
	M�thode permettant d'affecter la valeur pass�e en param�tre � la donn�e-
	membre correspondante.
******************************************************************************/
void CEmploye :: SetTauxHoraire (unsigned int uiTauxHoraire)
{
	m_uiTauxHoraire = uiTauxHoraire;
}


/******************************************************************************
	M�thode permettant d'affecter la valeur pass�e en param�tre � l'index 
	choisi du vecteur-membre correspondant.
******************************************************************************/
void CEmploye :: SetHeures (unsigned int uiHeures, int iSemaine)
{
	if (iSemaine < 0 || iSemaine >= NB_SEMAINES)
		throw "Indice en dehors de la plage.";

	m_uiLesHeures[iSemaine] = uiHeures;
}


/******************************************************************************
	M�thode permettant d'obtenir la valeur de la donn�e-membre repr�sentant le 
	taux de commission du employe.
******************************************************************************/
unsigned int CEmploye :: GetTauxHoraire () const
{
	return m_uiTauxHoraire;
}


/******************************************************************************
	M�thode permettant d'obtenir la valeur du vecteur-membre repr�sentant le 
	montant des ventes du employe pour le mois choisi.
******************************************************************************/
unsigned int CEmploye :: GetHeures (unsigned int uiSemaine) const
{
	if (uiSemaine >= NB_SEMAINES)
		throw "Indice en dehors de la plage.";

	return m_uiLesHeures[uiSemaine];
}