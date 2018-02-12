/******************************************************************************
	Fichier:	listeentiers.cpp
	
	Utilit�:	Impl�mentation de la biblioth�que CVecteurEntiers pour la 
				gestion de listes dynamiques chain�es � l'aide d'objets

	Auteur:		Philippe Carpentier-Savard
******************************************************************************/
#include "listeentiers.h"


/******************************************************************************
	Constructeur permettant d'initialiser les attributs.
******************************************************************************/
CNoeudEntier :: CNoeudEntier (int iEntier)
: m_iElement(iEntier), m_pLeSuivant(0) {}


/******************************************************************************
	Constructeur permettant d'initialiser les attributs � l'aide de l'objet 
	pass� en entr�e
******************************************************************************/
CNoeudEntier :: CNoeudEntier (const CNoeudEntier & unNoeud)
: m_iElement(unNoeud.m_iElement), m_pLeSuivant(0) {}


/******************************************************************************
	Constructeur permettant d'initialiser l'attribut
******************************************************************************/
CListeEntiers :: CListeEntiers ()
: m_pLePremier(0) {}


/******************************************************************************
	Constructeur permettant d'initialiser les attributs � l'aide de l'objet 
	pass� en entr�e
******************************************************************************/
CListeEntiers :: CListeEntiers (const CListeEntiers & desEntiers)
{
	* this = desEntiers;
}


/******************************************************************************
	Destructeur lib�rant la m�moire occup�e par tous les noeuds de la liste
******************************************************************************/
CListeEntiers :: ~CListeEntiers()
{
	Vider();
}


/******************************************************************************
	M�thode permettant d'ins�rer un entier dans un noeud � la fin de cha�ne
******************************************************************************/
void CListeEntiers :: Ajouter (int iEntier)
{
	CNoeudEntier * pNouveauNoeud = new CNoeudEntier(iEntier);
	
	if (m_pLePremier == 0)
	{
		m_pLePremier = pNouveauNoeud;
	}
	else
	{
		CNoeudEntier * m_pLeCourant = m_pLePremier;

		while (m_pLeCourant->m_pLeSuivant != 0)
			m_pLeCourant = m_pLeCourant->m_pLeSuivant;

		m_pLeCourant->m_pLeSuivant = pNouveauNoeud;
	}
}


/******************************************************************************
	M�thode permettant de retirer le noeud de la cha�ne situ� � l'indice pass� 
	en entr�e
******************************************************************************/
bool CListeEntiers :: Retirer (unsigned int uiIndiceSuppr)
{
	if (uiIndiceSuppr == 0)
	{
		if (m_pLePremier != 0)
		{
			CNoeudEntier * pLeNoeudARetirer = m_pLePremier;

			m_pLePremier = m_pLePremier->m_pLeSuivant;
			delete pLeNoeudARetirer;
			return true;
		}

		return false;
	}
	else
	{
		unsigned int uiIndice = 0;
		CNoeudEntier * pLePrecedent = m_pLePremier;

		while (uiIndice != uiIndiceSuppr - 1 && pLePrecedent != 0)
		{
			pLePrecedent = pLePrecedent->m_pLeSuivant;
			uiIndice++;
		}

		if (pLePrecedent != 0 && pLePrecedent->m_pLeSuivant != 0)
		{
			CNoeudEntier * pLeNoeudARetirer = pLePrecedent->m_pLeSuivant;

			pLePrecedent->m_pLeSuivant = pLeNoeudARetirer->m_pLeSuivant;
			delete pLeNoeudARetirer;
			return true;
		}

		return false;
	}
}


/******************************************************************************
	Fonction retournant le nombre de noeuds contenu dans la cha�ne
******************************************************************************/
unsigned int CListeEntiers :: NbElements () const
{
	unsigned int uiNbElements = 0;
	CNoeudEntier * pLeCourant = m_pLePremier;

	while (pLeCourant != 0)
	{
		pLeCourant = pLeCourant->m_pLeSuivant;
		uiNbElements++;
	}

	return uiNbElements;
}


/******************************************************************************
	Fonction retournant un bool�en indiquant si la cha�ne est vide
******************************************************************************/
bool CListeEntiers :: EstVide () const
{
	if (m_pLePremier == 0) return true;
	return false;
}


/******************************************************************************
	M�thode permettant de retirer de la m�moire tout les noeuds de la cha�ne
******************************************************************************/
void CListeEntiers :: Vider ()
{
	CNoeudEntier * pLeNoeudARetirer;

	while (m_pLePremier != 0)
	{
		pLeNoeudARetirer = m_pLePremier;
		m_pLePremier = m_pLePremier->m_pLeSuivant;
		delete pLeNoeudARetirer;
	}
}


/******************************************************************************
	Op�rateur permettant de copier la cha�ne de noeuds de l'objet pass� en 
	entr�e vers l'objet courant
******************************************************************************/
const CListeEntiers & CListeEntiers :: operator = (const CListeEntiers & 
												   desEntiers)
{
	CNoeudEntier * pLeCourant = desEntiers.m_pLePremier;

	Vider();

	while (pLeCourant != 0)
	{
		Ajouter(pLeCourant->m_iElement);
		pLeCourant = pLeCourant->m_pLeSuivant;
	}

	return * this;
}


/******************************************************************************
	Op�rateur permettant de retourner l'entier contenu dans le noeud de la 
	cha�ne situ� � l'indice pass� en entr�e
******************************************************************************/
int CListeEntiers :: operator [] (unsigned int uiIndiceVoulu)
{
	unsigned int uiIndice = 0;
	CNoeudEntier * pLeCourant = m_pLePremier;

	while (pLeCourant != 0 && uiIndice != uiIndiceVoulu)
	{
		pLeCourant = pLeCourant->m_pLeSuivant;
		uiIndice++;
	}

	if (pLeCourant == 0)
		throw "Indice en dehors de la plage.";

	return pLeCourant->m_iElement;
}