#include "menace.hpp"

menace::menace()
{
}

menace::menace(std::string input, int tourDarrivee)
{
    m_degatsRecus = 0;
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

void menace::print_menace() const
{
    std::cout << "Menace : " << m_name << std::endl;
    std::cout << "Tour d'arrivée : " << m_tourDarrivee << std::endl;
    std::cout << "Position : " << m_position << std::endl;
    std::cout << "Vitesse : " << m_vitesse << std::endl;
    std::cout << "Vie : " << m_vie << std::endl;
    std::cout << "Bouclier : " << m_bouclier << std::endl;
    std::cout << "Difficulté : " << m_difficulte << std::endl;
    std::cout << "DegatsRecus : " << m_degatsRecus << std::endl;
    std::cout << "Zone : " << m_zone->getz_nom_zone() << std::endl;
    std::cout << "Chemin : " << m_chemin->get_ch_nom() << std::endl;
    for (std::vector<cannon *>::const_iterator it = m_canon_used.begin(); it != m_canon_used.end(); ++it)
    {
        std::cout << "Canon utilisé : " << (*it)->getnom_cannon() << std::endl;
    }
}
void menace::actionMenace(char input)
{
    input += 0;
    // Implement the action logic based on the input character
    // This is a placeholder for the actual implementation
}
void menace::checkIfCrossActionZone(int positionBefore, int positionAfter)
{
    while(positionBefore != positionAfter) 
    {
        positionBefore--;
        if(m_chemin->get_ch_chemin()[positionBefore] == 'X') 
        {
            actionMenace('X');
        }
        else if (m_chemin->get_ch_chemin()[positionBefore] == 'Y') 
        {
            actionMenace('Y');
        }
        else if (m_chemin->get_ch_chemin()[positionBefore] == 'Z')
        {
            actionMenace('Z');
        }
    }
}


menace::~menace() {}
