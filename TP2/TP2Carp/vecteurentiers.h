/******************************************************************************
    Fichier:    vecteurentiers.h

    Utilité:    Bibliothèque permettant la gestion de vecteurs dynamiques
                virtuels à l'aide d'objets

    Auteur:     Philippe Carpentier-Savard
******************************************************************************/
#ifndef __VECTEURENTIERS_H
#define __VECTEURENTIERS_H

class CVecteurEntiers
{
    public:
        //  Constructeurs
        CVecteurEntiers ();
        CVecteurEntiers (const CVecteurEntiers & desEntiers);

        //  Destructeur
        ~CVecteurEntiers ();

        //  Méthodes
        const CVecteurEntiers & operator = (const CVecteurEntiers &desEntiers);
        int operator [] (unsigned int uiIndice);

        void Ajouter (int iEntier);
        bool Retirer (unsigned int uiIndice);
        unsigned int NbElements () const;

    private:
        //  Données-membres
        int * m_piLesElements;
        unsigned int m_uiNbElements;
};

#endif