/******************************************************************************
	Fichier:	listeentiers.h
	
	Utilité:	Bibliothèque permettant la gestion de listes dynamiques 
				chainées à l'aide d'objets

	Auteur:		Philippe Carpentier-Savard
******************************************************************************/
#ifndef __LISTEENTIERS_H
#define __LISTEENTIERS_H

class CNoeudEntier
{
	friend class CListeEntiers;

	private:
		//	Données-membres
		int m_iElement;
		CNoeudEntier * m_pLeSuivant;

		//	Constructeurs
		CNoeudEntier (int iEntier = 0);
		CNoeudEntier (const CNoeudEntier & unNoeud);
};

class CListeEntiers
{
	public:
		//	Constructeurs
		CListeEntiers ();
		CListeEntiers (const CListeEntiers & desEntiers);

		//	Destructeur
		~CListeEntiers ();

		//	Méthodes
		const CListeEntiers & operator = (const CListeEntiers & desEntiers);
		int operator [] (unsigned int uiIndiceVoulu);

		void Ajouter (int iEntier);
		bool Retirer (unsigned int uiIndiceSuppr);
		unsigned int NbElements () const;
		bool EstVide () const;
		void Vider ();

	private:
		//	Données-membres
		CNoeudEntier * m_pLePremier;
};

#endif