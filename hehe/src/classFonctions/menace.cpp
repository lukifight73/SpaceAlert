#include "menace.hpp"

menace::menace()
{
}

menace::menace(std::string input, int tourDarrivee)
{
    m_presence = false;
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

void menace::send_announcement_message() const
{
    std::cout << "[Attention, la menace " << m_name << " vient d'arriver !]\n";
    std::cout << "[Difficulté : " << m_difficulte << ", Vitesse : " << m_vitesse << ", Vie : " << m_vie << ", Bouclier : " << m_bouclier << "]" << std::endl;
}

menace::~menace() {}
