/******************************************************************************
	Fichier:	fonctions.cpp
	
	Utilit�:	Impl�mentation de la biblioth�que des deux fonctions servant �
				tester le programme et � calculer les statistiques.

	Auteur:		Philippe Carpentier-Savard
******************************************************************************/
#include "fonctions.h"
#include "aleatoire.h"


/******************************************************************************
	Fonction servant � assigner des valeurs al�atoires au nombres d'heures de 
	chaque semaine et au taux horaire de chacun des objets CEmploye dans le 
	vecteur pass� en entr�e.
******************************************************************************/
void GenererPaies (CEmploye lesEmployes[NB_EMPLOYES])
{
	unsigned int uiEmploye;
	int iSemaine;

	for (uiEmploye = 0; uiEmploye < NB_EMPLOYES; uiEmploye++)
	{
		lesEmployes[uiEmploye].SetTauxHoraire(GenererNbAleatoire(0,3) * 5 +10);

		for (iSemaine = 0; iSemaine < NB_SEMAINES; ++iSemaine)
			lesEmployes[uiEmploye].SetHeures(GenererNbAleatoire(35,44),
																	 iSemaine);
	}
}


/******************************************************************************
	Fonction servant � calculer le montant total des salaires, le nombre total 
	d'heures, et le taux horaire moyen pour tous les objets CEmploye du vecteur
	pass� en entr�e, et d'assigner les r�sultats correspondants aux r�f�rences 
	pass�es en entr�e.
******************************************************************************/
void CalculerResultatsGlobaux (const CEmploye lesEmployes[NB_EMPLOYES], 
							   unsigned int & uiTotalSalaires, 
							   unsigned int & uiTotalHeures, 
							   float & fTauxMoyen)
{
	unsigned int uiEmploye;
	unsigned int uiSemaine;
	unsigned int uiHeures;
	unsigned int uiTauxHoraire;
	unsigned int uiTotalSalairesTemp;
	unsigned int uiTotalHeuresTemp;
	float fTauxMoyenTemp;

	for (uiEmploye = 0,
		 uiTotalSalairesTemp = 0,
		 uiTotalHeuresTemp = 0,
		 fTauxMoyenTemp = 0; uiEmploye < NB_EMPLOYES; ++uiEmploye)
	{
		uiHeures = 0;
		uiTauxHoraire = lesEmployes[uiEmploye].GetTauxHoraire();

		for (uiSemaine = 0; uiSemaine < NB_SEMAINES; ++uiSemaine)
			uiHeures += lesEmployes[uiEmploye].GetHeures(uiSemaine);

		uiTotalSalairesTemp += uiTauxHoraire * uiHeures;
		uiTotalHeuresTemp += uiHeures;
		fTauxMoyenTemp += uiTauxHoraire;
	}

	fTauxMoyenTemp /= NB_EMPLOYES;

	uiTotalSalaires = uiTotalSalairesTemp;
	uiTotalHeures = uiTotalHeuresTemp;
	fTauxMoyen = fTauxMoyenTemp;
}