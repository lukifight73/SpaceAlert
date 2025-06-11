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
    m_attraction_roquette = false;
    m_vulnerable_roquette = true;
    m_buff_attack = 0;
    // m_degatsRecus = 0;
    m_revele = true;
    m_presence = false;
    m_immunity = false;
    m_tourDarrivee = tourDarrivee;
    if(input == "se1-01")
    {
        m_bouclier = 2;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Fregate";
        m_vie = 7;
        m_vitesse = 2;
    }
    if(input == "se1-02")
    {
        m_bouclier = 2;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Man of War";
        m_vie = 9;
        m_vitesse = 1;
    }
    if(input == "se1-03")
    {
        m_bouclier = 3;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Ravitailleur Leviathan";
        m_vie = 8;
        m_vitesse = 2;
    }
    if(input == "se1-04")
    {
        m_revele = false;
        m_bouclier = 2;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Satellite a impulsion";
        m_vie = 4;
        m_vitesse = 3;
    }
    if(input == "se1-05")
    {
        m_immunity = true;
        m_bouclier = 1;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Fregate a Cryoprotection";
        m_vie = 7;
        m_vitesse = 2;
    }
    if(input == "se1-06")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 1;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Pieuvre Interstellaire";
        m_vie = 8;
        m_vitesse = 2;
    }
    if(input == "se1-07")
    {
        m_bouclier = 3;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Maelstrom";
        m_vie = 8;
        m_vitesse = 2;
    }
    if(input == "se1-08")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 0;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Asteroide";
        m_vie = 9;
        m_vitesse = 3;
    }
    if(input == "se2-01")
    {
        m_bouclier = 4;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Behemoth";
        m_vie = 7;
        m_vitesse = 2;
    }
    if(input == "se2-02")
    {
        m_attraction_roquette = true;
        m_bouclier = 3;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Juggernaut";
        m_vie = 10;
        m_vitesse = 1;
    }
    if(input == "se2-03")
    {
        m_revele = false;
        m_bouclier = 2;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Satellite Psionique";
        m_vie = 5;
        m_vitesse = 2;
    }
    if(input == "se2-04")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 2;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Crabe nebula";
        m_vie = 7;
        m_vitesse = 2;
    }
    if(input == "se2-05")
    {
        m_bouclier = 1;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Nemesis";
        m_vie = 9;
        m_vitesse = 3;
    }
    if(input == "se2-06")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 0;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Asteroide Majeur";
        m_vie = 11;
        m_vitesse = 2;
    }
    if(input == "e1-01")
    {
        m_bouclier = 1;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Pulsar";
        m_vie = 5;
        m_vitesse = 2;
    }
    if(input == "e1-02")
    {
        m_bouclier = 2;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Destroyer";
        m_vie = 5;
        m_vitesse = 2;
    }
    if(input == "e1-03")
    {
        m_revele = false;
        m_bouclier = 2;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Chasseur furtif";
        m_vie = 4;
        m_vitesse = 3;
    }
    if(input == "e1-04")
    {
        m_bouclier = 3;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Nuage d'energie";
        m_vie = 5;
        m_vitesse = 2;
    }
    if(input == "e1-05")
    {
        m_bouclier = 2;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Vaisseau de combat";
        m_vie = 5;
        m_vitesse = 2;
    }
    if(input == "e1-06")
    {
        m_immunity = true;
        m_bouclier = 1;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Chasseur a cryoprotection";
        m_vie = 4;
        m_vitesse = 3;
    }
    if(input == "e1-07")
    {
        m_bouclier = 2;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Chasseur";
        m_vie = 4;
        m_vitesse = 3;
    }
    if(input == "e1-08")
    {
        m_bouclier = 3;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Constricteur Blinde";
        m_vie = 4;
        m_vitesse = 2;
    }
    if(input == "e1-09")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 0;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Amibe";
        m_vie = 8;
        m_vitesse = 2;
    }
    if(input == "e1-10")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 0;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Meteorite";
        m_vie = 5;
        m_vitesse = 5;
    }
    if(input == "e2-01")
    {
        m_bouclier = 2;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Kamikaze";
        m_vie = 5;
        m_vitesse = 4;
    }
    if(input == "e2-02")
    {
        m_bouclier = 1;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Eclaireur";
        m_vie = 3;
        m_vitesse = 2;
    }
    if(input == "e2-03")
    {
        m_revele = false;
        m_vulnerable_roquette = false;
        m_attraction_roquette = true;
        m_bouclier = 3;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Chasseur fantome";
        m_vie = 3;
        m_vitesse = 3;
    }
    if(input == "e2-04")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 0;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Nuee Insectoide";
        m_vie = 3;
        m_vitesse = 2;
    }
    if(input == "e2-05")
    {
        m_vulnerable_roquette = false;
        m_bouclier = -2;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Meduse";
        m_vie = 13;
        m_vitesse = 2;
    }
    if(input == "e2-06")
    {
        m_bouclier = 1;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Maraudeur";
        m_vie = 6;
        m_vitesse = 3;
    }
    if(input == "e2-07")
    {
        m_vulnerable_roquette = false;
        m_bouclier = 0;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Asteroide mineur";
        m_vie = 7;
        m_vitesse = 4;
    }
    m_max_vie = m_vie; // Initialiser la vie maximale à la vie actuelle
    m_etat_bouclier = m_bouclier; // L'état du bouclier est initialisé à la valeur de m_bouclier
}

void menace::send_announcement_message() const
{
    start_color(m_zone);
    std::cout << "[Attention, la menace " << m_name << " vient d'arriver !]\n";
    std::cout << "[Difficulté : " << m_difficulte << ", Vitesse : " << m_vitesse << ", Vie : " << m_vie << ", Bouclier : " << m_bouclier << "]" << std::endl;
    end_color(m_zone);
}

void menace::print_menace() const
{
    start_color(m_zone);
    std::cout << "Menace : " << m_name << std::endl;
    std::cout << "Tour d'arrivée : " << m_tourDarrivee << std::endl;
    std::cout << "Position : " << m_position << std::endl;
    std::cout << "Vitesse : " << m_vitesse << std::endl;
    std::cout << "Vie : " << m_vie << std::endl;
    std::cout << "Bouclier : " << m_bouclier << std::endl;
    std::cout << "Etat Bouclier : " << m_etat_bouclier << std::endl;
    std::cout << "Difficulté : " << m_difficulte << std::endl;
    // std::cout << "DegatsRecus : " << m_degatsRecus << std::endl;
    std::cout << "Zone : " << m_zone->getz_nom_zone() << std::endl;
    std::cout << "Chemin : " << m_chemin->get_ch_nom() << std::endl;
    for (std::vector<cannon *>::const_iterator it = m_canon_used.begin(); it != m_canon_used.end(); ++it)
    {
        std::cout << "Canon utilisé contre elle : " << (*it)->getnom_cannon() << std::endl;
    }
    end_color(m_zone);
}

void menace::actionMenace(char input)
{
    input += 0;
}

void menace::actionQuandDetruit() {
    std::cout << "\033[1;32m[ELIMINATION DE LA MENACE !\033[0m\n";
    if (m_zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (m_zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (m_zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
    std::cout << "[La menace " << m_name << " en " << m_zone << " a été détruite.]\033[0m\n";
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

void menace::makedegatsInZone(int input)
{
    m_zone->getdegats(input + m_buff_attack);
}

void menace::makedegatsInZoneIgnoreBouclier(int input)
{
    m_zone->getdegatsIgnoreBouclier(input + m_buff_attack);
}

void menace::makedegatsLeft(int input)
{
    m_zone->getzone_left()->getdegats(input + m_buff_attack);
}

void menace::makedegatsRight(int input)
{
    m_zone->getzone_right()->getdegats(input + m_buff_attack);
}

void menace::regeneration(int input)
{
    m_vie += input;
    if (m_vie > m_max_vie) {
        m_vie = m_max_vie; // Ne pas dépasser la vie maximale
    }
    std::string msg = "[La menace " + m_name + " se régénère de " + std::to_string(input) + " points de vie. Vie actuelle : " + std::to_string(m_vie) + "!]";
    messageBufferMenace(msg, -1);
}

// combien de X, Y, Z ont été jusqu'à présent traversés par la menace
int menace::checkNombreInputCrossed(char input) const
{
    int count = 0;
    for (int i = m_chemin->get_ch_chemin_size(); i >= m_position; i--) {
        if (m_chemin->get_ch_chemin()[i] == input) {
            count++;
        }
    }
    return count;
}

// enleve les PV correspondant au degats (apres bouclier)
void menace::recoitDegats(int input)
{
    m_vie -= input;
    if (m_vie < 0) {
        m_vie = 0;
    }
    if (m_zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (m_zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (m_zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
    std::cout << "[La menace " << m_name << " a reçu " << input << " points de dégâts. Vie restante : " << m_vie << "]\033[0m" << std::endl;
    if (m_vie == 0) {
        actionQuandDetruit();
        m_presence = false; // La menace n'est plus présente
    }
}
