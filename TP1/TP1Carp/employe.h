/******************************************************************************
	Fichier:	employe.h
	
	Utilit�:	D�claration de la classe CEmploye servant � faire � contenir
				les informations de temps de travail relatives � un employ�

	Auteur:		Philippe Carpentier-Savard
******************************************************************************/
#ifndef __EMPLOYE_H
#define __EMPLOYE_H


// Constante servant � d�terminer la taille du vecteur
const unsigned int NB_SEMAINES = 52;

class CEmploye
{
	public:
		//	Constructeurs
		CEmploye ();
		CEmploye (const CEmploye & unEmploye);

		//	M�thodes
		void SetTauxHoraire (unsigned int uiTauxHoraire);
		void SetHeures (unsigned int uiHeures, int iSemaine);
		unsigned int GetTauxHoraire () const;
		unsigned int GetHeures (unsigned int uiSemaine) const;

	private:
		//	Donn�es-membres
		unsigned int m_uiTauxHoraire;
		unsigned int m_uiLesHeures[NB_SEMAINES];
};


#endif