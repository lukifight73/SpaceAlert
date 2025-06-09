#include "menace.hpp"
#include "menace_externe.hpp"

void menace::messageAttaqueMenace(int degats)
{
    if (m_zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (m_zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (m_zone->getz_zone() == 3)
        std::cout << "\033[1;34m";
    std::cout << "[La menace " << m_name << " lance une attaque de puissance " << degats << "!]\033[0m" << std::endl;
}
