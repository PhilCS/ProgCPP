/******************************************************************************
    Fichier:        joueur.h

    Classe:         CJoueur

    Auteur:         José Consola

    Utilité:        Permet de stocker en mémoire les différentes
                    caractéristiques d'un joueur de la LNH.
******************************************************************************/
#ifndef __JOUEUR_H
#define __JOUEUR_H


class CJoueur
{
    public:
        CJoueur (const char szRang [4] = "", const char szNom [31] = "",
            const char szEquipe [4] = "", char cPosition = '\0',
            unsigned short usNbParties = 0, unsigned short usNbButs = 0,
            unsigned short usNbPasses = 0, short sDifferentiel = 0,
            unsigned short usNbMinutesPunition = 0);
        CJoueur (const CJoueur & unJoueur);
        const CJoueur & operator = (const CJoueur & unJoueur);
        const char * GetRang () const;
        const char * GetNom () const;
        const char * GetEquipe () const;
        char GetPosition () const;
        unsigned short GetNbParties () const;
        unsigned short GetNbButs () const;
        unsigned short GetNbPasses () const;
        short GetDifferentiel () const;
        unsigned short GetNbMinutesPunition () const;

    private:
        char m_szRang [4];
        char m_szNom [31];
        char m_szEquipe [4];
        char m_cPosition;
        unsigned short m_usNbParties;
        unsigned short m_usNbButs;
        unsigned short m_usNbPasses;
        short m_sDifferentiel;
        unsigned short m_usNbMinutesPunition;
};


#endif