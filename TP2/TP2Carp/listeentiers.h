/******************************************************************************
	Fichier:	listeentiers.h
	
	Utilit�:	Biblioth�que permettant la gestion de listes dynamiques 
				chain�es � l'aide d'objets

	Auteur:		Philippe Carpentier-Savard
******************************************************************************/
#ifndef __LISTEENTIERS_H
#define __LISTEENTIERS_H

class CNoeudEntier
{
	friend class CListeEntiers;

	private:
		//	Donn�es-membres
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

		//	M�thodes
		const CListeEntiers & operator = (const CListeEntiers & desEntiers);
		int operator [] (unsigned int uiIndiceVoulu);

		void Ajouter (int iEntier);
		bool Retirer (unsigned int uiIndiceSuppr);
		unsigned int NbElements () const;
		bool EstVide () const;
		void Vider ();

	private:
		//	Donn�es-membres
		CNoeudEntier * m_pLePremier;
};

#endif