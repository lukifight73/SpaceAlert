#include "menace.hpp"

menace::menace()
{
}

// Surcharge de l'opérateur d'affectation
menace &menace::operator=(const menace &other) {
            if (this != &other) {
                m_name = other.m_name;
                m_tourDarrivee = other.m_tourDarrivee;
                m_presence = other.m_presence;
                m_vitesse = other.m_vitesse;
                m_vie = other.m_vie;
                m_position = other.m_position;
                m_bouclier = other.m_bouclier;
                m_difficulte = other.m_difficulte;
                m_canon_used = other.m_canon_used;
                m_canon_immunity = other.m_canon_immunity;
            }
            return *this;
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


/// Action des menaces

// draine l'energie du bouclier de toutes les zones
void menace::draineEnergieBouclier(int input) 
{
    m_zone->setz_bouclier(m_zone->getz_bouclier() - input);
    if (m_zone->getz_bouclier() < 0) {
        m_zone->setz_bouclier(0);
    }
    m_zone->getzone_left()->setz_bouclier(m_zone->getzone_left()->getz_bouclier() - input);
    if (m_zone->getzone_left()->getz_bouclier() < 0) {
        m_zone->getzone_left()->setz_bouclier(0);
    }
    m_zone->getzone_right()->setz_bouclier(m_zone->getzone_right()->getz_bouclier() - input);
    if (m_zone->getzone_right()->getz_bouclier() < 0) {
        m_zone->getzone_right()->setz_bouclier(0);
    }
    if( m_zone->getz_bouclier() == 0 && m_zone->getzone_left()->getz_bouclier() == 0 && m_zone->getzone_right()->getz_bouclier() == 0) {
        std::cout << "[Toutes les zones ont perdu leur bouclier !]\n";
    } else {
        std::cout << "[Le bouclier de la zone " << m_zone->getz_nom_zone() << " est maintenant de " << m_zone->getz_bouclier() << ".]\n";
        std::cout << "[Le bouclier de la zone " << m_zone->getzone_left()->getz_nom_zone() << " est maintenant de " << m_zone->getzone_left()->getz_bouclier() << ".]\n";
        std::cout << "[Le bouclier de la zone " << m_zone->getzone_right()->getz_nom_zone() << " est maintenant de " << m_zone->getzone_right()->getz_bouclier() << ".]\n";
    }
};
