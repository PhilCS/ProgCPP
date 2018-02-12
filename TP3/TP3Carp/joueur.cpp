/******************************************************************************
	Fichier:		joueur.cpp

	Classe:			CJoueur

	Auteur:			José Consola

	Utilité:		Définition des méthodes de la classe.
******************************************************************************/
#include "joueur.h"
#include "utilitaires.h"


/******************************************************************************
	Constructeur qui permet d'initialiser les attributs de l'objet à l'aide
	des valeurs reçues en paramètres.
******************************************************************************/
CJoueur :: CJoueur (const char szRang [4], const char szNom [31],
			const char szEquipe [4], char cPosition,
			unsigned short usNbParties, unsigned short usNbButs,
			unsigned short usNbPasses, short sDifferentiel,
			unsigned short usNbMinutesPunition)
: m_cPosition (cPosition), m_usNbParties (usNbParties), m_usNbButs (usNbButs),
	m_usNbPasses (usNbPasses), m_sDifferentiel (sDifferentiel),
	m_usNbMinutesPunition (usNbMinutesPunition)
{
	CopierChaine (m_szRang, szRang, 3);
	CopierChaine (m_szNom, szNom, 30);
	CopierChaine (m_szEquipe, szEquipe, 3);
}


/******************************************************************************
	Constructeur copie.
******************************************************************************/
CJoueur :: CJoueur (const CJoueur & unJoueur)
: m_cPosition (unJoueur.m_cPosition), m_usNbParties (unJoueur.m_usNbParties),
	m_usNbButs (unJoueur.m_usNbButs), m_usNbPasses (unJoueur.m_usNbPasses),
	m_sDifferentiel (unJoueur.m_sDifferentiel),
	m_usNbMinutesPunition (unJoueur.m_usNbMinutesPunition)
{
	CopierChaine (m_szRang, unJoueur.m_szRang, 3);
	CopierChaine (m_szNom, unJoueur.m_szNom, 30);
	CopierChaine (m_szEquipe, unJoueur.m_szEquipe, 3);
}


/******************************************************************************
	Opérateur d'affectation.
******************************************************************************/
const CJoueur & CJoueur :: operator = (const CJoueur & unJoueur)
{
	CopierChaine (m_szRang, unJoueur.m_szRang, 3);
	CopierChaine (m_szNom, unJoueur.m_szNom, 30);
	CopierChaine (m_szEquipe, unJoueur.m_szEquipe, 3);
	m_cPosition = unJoueur.m_cPosition;
	m_usNbParties = unJoueur.m_usNbParties;
	m_usNbButs = unJoueur.m_usNbButs;
	m_usNbPasses = unJoueur.m_usNbPasses;
	m_sDifferentiel = unJoueur.m_sDifferentiel;
	m_usNbMinutesPunition = unJoueur.m_usNbMinutesPunition;
	return * this;
}


/******************************************************************************
	Accesseurs.
******************************************************************************/
const char * CJoueur :: GetRang () const
{
	return m_szRang;
}


const char * CJoueur :: GetNom () const
{
	return m_szNom;
}


const char * CJoueur :: GetEquipe () const
{
	return m_szEquipe;
}


char CJoueur :: GetPosition () const
{
	return m_cPosition;
}


unsigned short CJoueur :: GetNbParties () const
{
	return m_usNbParties;
}


unsigned short CJoueur :: GetNbButs () const
{
	return m_usNbButs;
}


unsigned short CJoueur :: GetNbPasses () const
{
	return m_usNbPasses;
}


short CJoueur :: GetDifferentiel () const
{
	return m_sDifferentiel;
}


unsigned short CJoueur :: GetNbMinutesPunition () const
{
	return m_usNbMinutesPunition;
}
