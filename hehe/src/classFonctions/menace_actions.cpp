#include "menace.hpp"
#include "menace_externe.hpp"

void menace_se1_01::actionMenace(char input) 
{
    if (input == 'X') {
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
    } else if (input == 'Y') {
        makedegatsInZone(3);
        std::cout << "[ " << m_name << " lance une attaque de puissance 3!]" << std::endl;
    } else if (input == 'Z') {
        makedegatsInZone(4);
        std::cout << "[ " << m_name << " lance une attaque de puissance 4!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se1_03::actionMenace(char input) 
{
    if (input == 'X') {
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
    } else if (input == 'Y') {
        makedegatsInZone(2);
        augmenteVie(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2 et regagne 2 points de vie!]" << std::endl;
    } else if (input == 'Z') {
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se1_03::actionQuandDetruit() 
{
    std::vector<menace *> menaces = m_zone->getzone_left()->getz_chemin_menace()->get_menaces();
    
    std::vector<menace *>::iterator it;
    for (it = menaces.begin(); it != menaces.end(); ++it) 
    {
        if ((*it)->get_m_presence() && (*it)->get_m_etat_bouclier() <= 0) 
        {
            (*it)->set_m_degatsRecus(1); // fait un degats si pas de bouclier
            if ((*it)->get_m_vie() <= 0) 
            {
                (*it)->set_m_presence(false);
                (*it)->actionQuandDetruit();
            }
        }
    }

    menaces = m_zone->getzone_right()->getz_chemin_menace()->get_menaces();
    for (it = menaces.begin(); it != menaces.end(); ++it) 
    {
        if ((*it)->get_m_presence() && (*it)->get_m_etat_bouclier() <= 0) 
        {
            (*it)->set_m_degatsRecus(1); // fait un degats si pas de bouclier
            if ((*it)->get_m_vie() <= 0) 
            {
                (*it)->set_m_presence(false);
                (*it)->actionQuandDetruit();
            }
        }
    }
    menaces = m_zone->getz_chemin_menace()->get_menaces();
    for (it = menaces.begin(); it != menaces.end(); ++it) 
    {
        if ((*it)->get_m_presence() && (*it)->get_m_etat_bouclier() <= 0) 
        {
            (*it)->set_m_degatsRecus(1); // fait un degats si pas de bouclier
            if ((*it)->get_m_vie() <= 0) 
            {
                (*it)->set_m_presence(false);
                (*it)->actionQuandDetruit();
            }
        }
    }
    std::cout << "[La menace " << m_name << " a été détruite. Elle inflige 1 point de dégâts aux menaces presentes.]\n";
}
        