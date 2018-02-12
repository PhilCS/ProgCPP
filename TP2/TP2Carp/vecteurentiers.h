/******************************************************************************
	Fichier:	vecteurentiers.h
	
	Utilit�:	Biblioth�que permettant la gestion de vecteurs dynamiques
				virtuels � l'aide d'objets

	Auteur:		Philippe Carpentier-Savard
******************************************************************************/
#ifndef __VECTEURENTIERS_H
#define __VECTEURENTIERS_H

class CVecteurEntiers
{
	public:
		//	Constructeurs
		CVecteurEntiers ();
		CVecteurEntiers (const CVecteurEntiers & desEntiers);

		//	Destructeur
		~CVecteurEntiers ();

		//	M�thodes
		const CVecteurEntiers & operator = (const CVecteurEntiers &desEntiers);
		int operator [] (unsigned int uiIndice);

		void Ajouter (int iEntier);
		bool Retirer (unsigned int uiIndice);
		unsigned int NbElements () const;

	private:
		//	Donn�es-membres
		int * m_piLesElements;
		unsigned int m_uiNbElements;
};

#endif