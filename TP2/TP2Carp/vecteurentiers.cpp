/******************************************************************************
	Fichier:	vecteurentiers.cpp
	
	Utilité:	Implémentation de la bibliothèque CVecteurEntiers pour la 
				gestion de vecteurs dynamiques virtuels à l'aide d'objets

	Auteur:		Philippe Carpentier-Savard
******************************************************************************/
#include "vecteurentiers.h"


/******************************************************************************
	Constructeur permettant d'initialiser les attributs.
******************************************************************************/
CVecteurEntiers :: CVecteurEntiers ()
: m_uiNbElements(0), m_piLesElements(0) {}


/******************************************************************************
	Constructeur permettant de copier les valeurs du vecteur de l'objet passé 
	en entrée dans le vecteur de l'objet courant
******************************************************************************/
CVecteurEntiers :: CVecteurEntiers (const CVecteurEntiers & desEntiers)
: m_piLesElements(0)
{
	* this = desEntiers;
}


/******************************************************************************
	Destructeur libérant la mémoire allouée pour le vecteur, et assignant à 
	celui-ci la valeur 0
******************************************************************************/
CVecteurEntiers :: ~CVecteurEntiers ()
{
	if (m_piLesElements != 0)
	{
		delete[] m_piLesElements;
		m_piLesElements = 0;
		m_uiNbElements = 0;
	}
}


/******************************************************************************
	Méthode permettant d'insérer un entier à la fin du vecteur
******************************************************************************/
void CVecteurEntiers :: Ajouter (int iEntier)
{
	if (m_piLesElements == 0)
	{
		m_piLesElements = new int[1];
		m_piLesElements[0] = iEntier;
	}
	else
	{
		unsigned int uiIndice;

		int * piNouveauVecteur = new int[m_uiNbElements + 1];

		for (uiIndice = 0; uiIndice < m_uiNbElements; ++uiIndice)
			piNouveauVecteur[uiIndice] = m_piLesElements[uiIndice];

		piNouveauVecteur[uiIndice] = iEntier;

		delete[] m_piLesElements;
		m_piLesElements = piNouveauVecteur;
	}

	m_uiNbElements++;
}


/******************************************************************************
	Méthode permettant de retirer du vecteur l'entier à l'indice passé en 
	entrée
******************************************************************************/
bool CVecteurEntiers :: Retirer (unsigned int uiIndiceSuppr)
{
	unsigned int uiIndice;
	int * piNouveauVecteur;

	if (uiIndiceSuppr >= m_uiNbElements)
		return false;

	if (m_uiNbElements == 1)
	{
		delete[] m_piLesElements;
		m_piLesElements = 0;
		m_uiNbElements = 0;
		return true;
	}

	piNouveauVecteur = new int[m_uiNbElements - 1];

	for (uiIndice = 0; uiIndice < m_uiNbElements - 1; uiIndice++)
		piNouveauVecteur[uiIndice] = m_piLesElements[uiIndice +
													 (uiIndice < uiIndiceSuppr
													  ? 0 : 1)];

	delete[] m_piLesElements;
	m_piLesElements = piNouveauVecteur;

	m_uiNbElements--;
	return true;
}


/******************************************************************************
	Fonction retournant le nombre d'entiers contenu dans le vecteur
******************************************************************************/
unsigned int CVecteurEntiers :: NbElements () const
{
	return m_uiNbElements;
}


/******************************************************************************
	Opérateur permettant de retourner l'entier situé à l'indice passé en entrée
******************************************************************************/
int CVecteurEntiers :: operator [] (unsigned int uiIndice)
{
	if (uiIndice >= m_uiNbElements)
		throw "Indice en dehors de la plage.";

	return m_piLesElements[uiIndice];
}


/******************************************************************************
	Opérateur permettant de copier tous les entiers du vecteur de l'objet passé
	en entrée vers le vecteur de l'objet courant
******************************************************************************/
const CVecteurEntiers & CVecteurEntiers :: operator = (const CVecteurEntiers & 
													   desEntiers)
{
	unsigned int uiIndice;

	if (m_piLesElements != 0)
		delete[] m_piLesElements;

	m_uiNbElements = desEntiers.m_uiNbElements;

	if (m_uiNbElements > 0)
	{
		m_piLesElements = new int[m_uiNbElements];

		for (uiIndice = 0; uiIndice < m_uiNbElements; uiIndice++)
			m_piLesElements[uiIndice] = desEntiers.m_piLesElements[uiIndice];
	}
	else
		m_piLesElements = 0;

	return * this;
}