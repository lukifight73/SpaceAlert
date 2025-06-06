#include "menace.hpp"

menace::menace()
{
}

menace::menace(std::string input, int tourDarrivee)
{
    m_tourDarrivee = tourDarrivee;
    if(input == "se1-06")
    {
        m_bouclier = 1;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Pieuvre Interstellaire";
        m_vie = 8;
        m_vitesse = 2;
    }
    if(input == "se2-03")
    {
        m_bouclier = 2;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Satellite Psionique";
        m_vie = 5;
        m_vitesse = 2;
    }
}

menace::~menace() {}
