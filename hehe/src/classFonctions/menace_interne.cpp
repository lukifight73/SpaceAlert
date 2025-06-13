#include "menace.hpp"
#include "menace_interne.hpp"

menace_interne::menace_interne()
{
}

void menace_interne::print_menace() const {
    menace::print_menace();  // Appeler la version de base
    std::cout << "La menace interne est en haut? : " << m_position_haut << std::endl;
}

bool menace_interne::AttractAction(int joueurAction, int Zone, bool haut) const
{
    if(m_position_haut == haut && joueurAction == m_killAction && m_zoneInt == Zone)
        return true;
    else
        return false;
};

void menace_interne::getDamage(joueur *joueur)
{
    joueur->setj_bots(joueur->getj_bots());
    m_vie--;
    if(m_vie <= 0)
    {
        m_vie = 0;
        actionQuandDetruit();
    }
}

menace_interne::menace_interne(std::string input, int tourDarrivee): menace(input, tourDarrivee)
{

    if(input == "i1-01")
    {
        m_position_haut = true;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Eclaireurs";
        m_vie = 1;
        m_vitesse = 3;
        m_killAction = ACT_R;
    }
    else if(input == "i1-02")
    {
        m_position_haut = true;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Asteroide mineur";
        m_vie = 1;
        m_vitesse = 3;
        m_killAction = ACT_R;
    }
};


void menace_interne_i1_01::getDamage(joueur *joueur)
{
    m_vie--;
    if(m_vie <= 0)
    {
        m_vie = 0;
        joueur->setj_bots(BOTS_INACTIF);
        actionQuandDetruit();
    }
}

void menace_interne_i1_01::actionMenace(char input) 
{
    if (input == 'X') 
    {
        this->set_m_zone(this->get_m_zone()->getzone_right());
        this->set_m_zoneInt(ZONE_WHITE);
        std::string msg = "[La menace " + m_name + " va en ZONE_WHITE.]\n";
        std::cout << msg;
    } 
    else if (input == 'Y') 
    {
        this->setPositionhaut(0);
        std::string msg = "[La menace " + m_name + " descand en ZONE_WHITE.]\n";
        std::cout << msg;
    } 
    else if (input == 'Z') {
        messageAttaqueMenace(3);
        makedegatsInZone(3);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i1_02::getDamage(joueur *joueur)
{
    m_vie--;
    if(m_vie <= 0)
    {
        m_vie = 0;
        joueur->setj_bots(BOTS_INACTIF);
        actionQuandDetruit();
    }
}

menace_interne::~menace_interne() {}
