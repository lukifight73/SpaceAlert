#include "menace.hpp"
#include "menace_interne.hpp"

menace_interne::menace_interne()
{
}

void menace_interne::print_menace() const {
    menace::print_menace();  // Appeler la version de base
    std::cout << "La menace interne est en haut? : " << m_position_haut << std::endl;
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
    }
    else if(input == "i1-02")
    {
        m_position_haut = true;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Asteroide mineur";
        m_vie = 1;
        m_vitesse = 3;
    }
};

menace_interne::~menace_interne() {}
