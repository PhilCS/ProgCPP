/******************************************************************************
	Fichier:	employe.h
	
	Utilité:	Déclaration de la classe CEmploye servant à faire à contenir
				les informations de temps de travail relatives à un employé

	Auteur:		Philippe Carpentier-Savard
******************************************************************************/
#ifndef __EMPLOYE_H
#define __EMPLOYE_H


// Constante servant à déterminer la taille du vecteur
const unsigned int NB_SEMAINES = 52;

class CEmploye
{
	public:
		//	Constructeurs
		CEmploye ();
		CEmploye (const CEmploye & unEmploye);

		//	Méthodes
		void SetTauxHoraire (unsigned int uiTauxHoraire);
		void SetHeures (unsigned int uiHeures, int iSemaine);
		unsigned int GetTauxHoraire () const;
		unsigned int GetHeures (unsigned int uiSemaine) const;

	private:
		//	Données-membres
		unsigned int m_uiTauxHoraire;
		unsigned int m_uiLesHeures[NB_SEMAINES];
};


#endif