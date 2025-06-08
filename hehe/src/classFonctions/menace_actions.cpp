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
        