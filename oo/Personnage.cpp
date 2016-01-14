#include "Personnage.h"

using namespace std;

/*Personnage::Personnage(){
    m_vie = 100;
    m_mana = 100;
    m_nomArme = "Epee moisie";
    m_degatsArme = 10;
}*/
Personnage::Personnage() : m_vie(100), m_mana(100)
{}

Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100),m_arme(nomArme, degatsArme)
{}

Personnage::~Personnage()
{}

void Personnage::recevoirDegats(int nbDegats)
{
    //On enlève le nombre de dégâts reçus à la vie du personnage
    m_vie -= nbDegats;

    //On fait gaffe à pas avoir de pv négatif
    if(m_vie < 0)
    {
        m_vie = 0;
    }
}

void Personnage::attaquer(Personnage &cible)
{
    //On inflige à la cible les dégâts que cause notre arme
    cible.recevoirDegats(m_arme.getDegats());
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    //Heal
    m_vie += quantitePotion;

    //On fait gaffe à pas dépasser le max de vie
    if(m_vie > 100){
        m_vie = 100;
    }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant() const
{
    /*if(m_vie > 0){
        return true;
    }
    else{
        return false;
    }*/
    return m_vie > 0;
}

void Personnage::afficherEtat() const
{
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme.afficher();
}
