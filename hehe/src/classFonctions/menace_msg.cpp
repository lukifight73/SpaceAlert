#include "menace.hpp"
#include "menace_externe.hpp"

void messageAttaque(std::string nom)
{
    std::cout << "\033[1;35m[ACTION MENACE " << nom << "!]\033[0m" << std::endl;
}

void menace::messageMenaceZone(int degats, zone *zone)
{
    messageAttaque(m_name);
    if (m_zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (m_zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (m_zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
    std::cout << "[La menace " << m_name << " lance une attaque de puissance " << degats << "\033[0m";
    if (zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
    std::cout << " sur la " << zone->getz_nom_zone() << "!]\033[0m]" << std::endl;
}

void menace::messageAttaqueMenace(int degats)
{
    messageAttaque(m_name);
    if (m_zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (m_zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (m_zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
    std::cout << "[La menace " << m_name << " lance une attaque de puissance " << degats << "!]\033[0m" << std::endl;
}

void menace::messageBufferMenace(std::string &string, int degats)
{
    messageAttaque(m_name);
    if (m_zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (m_zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (m_zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
    if (degats < 0)
        std::cout << "[" << string << "!]\033[0m" << std::endl;
    else
        std::cout << string << degats << "\033[0m" << std::endl;
}
