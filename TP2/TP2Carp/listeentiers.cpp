/******************************************************************************
    Fichier:    listeentiers.cpp

    Utilité:    Implémentation de la bibliothèque CVecteurEntiers pour la
                gestion de listes dynamiques chainées à l'aide d'objets

    Auteur:     Philippe Carpentier-Savard
******************************************************************************/
#include "listeentiers.h"


/******************************************************************************
    Constructeur permettant d'initialiser les attributs.
******************************************************************************/
CNoeudEntier :: CNoeudEntier (int iEntier)
: m_iElement(iEntier), m_pLeSuivant(0) {}


/******************************************************************************
    Constructeur permettant d'initialiser les attributs à l'aide de l'objet
    passé en entrée
******************************************************************************/
CNoeudEntier :: CNoeudEntier (const CNoeudEntier & unNoeud)
: m_iElement(unNoeud.m_iElement), m_pLeSuivant(0) {}


/******************************************************************************
    Constructeur permettant d'initialiser l'attribut
******************************************************************************/
CListeEntiers :: CListeEntiers ()
: m_pLePremier(0) {}


/******************************************************************************
    Constructeur permettant d'initialiser les attributs à l'aide de l'objet
    passé en entrée
******************************************************************************/
CListeEntiers :: CListeEntiers (const CListeEntiers & desEntiers)
{
    * this = desEntiers;
}


/******************************************************************************
    Destructeur libérant la mémoire occupée par tous les noeuds de la liste
******************************************************************************/
CListeEntiers :: ~CListeEntiers()
{
    Vider();
}


/******************************************************************************
    Méthode permettant d'insérer un entier dans un noeud à la fin de chaîne
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
    Méthode permettant de retirer le noeud de la chaîne situé à l'indice passé
    en entrée
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
    Fonction retournant le nombre de noeuds contenu dans la chaîne
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
    Fonction retournant un booléen indiquant si la chaîne est vide
******************************************************************************/
bool CListeEntiers :: EstVide () const
{
    if (m_pLePremier == 0) return true;
    return false;
}


/******************************************************************************
    Méthode permettant de retirer de la mémoire tout les noeuds de la chaîne
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
    Opérateur permettant de copier la chaîne de noeuds de l'objet passé en
    entrée vers l'objet courant
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
    Opérateur permettant de retourner l'entier contenu dans le noeud de la
    chaîne situé à l'indice passé en entrée
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