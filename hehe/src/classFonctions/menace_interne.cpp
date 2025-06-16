#include "menace.hpp"
#include "menace_interne.hpp"

menace_interne::menace_interne()
{
}

void menace_interne::print_menace() const {
    menace::print_menace();  // Appeler la version de base
    std::cout << "La menace interne est en haut? : " << m_position_haut << std::endl;
}

bool menace_interne::AttractAction(int joueurAction, int Zone, bool haut) const
{
    if(m_position_haut == haut && joueurAction == m_killAction && m_zoneInt == Zone)
        return true;
    else
        return false;
};

void menace_interne::getDamage(joueur *joueur)
{
    joueur->setj_bots(joueur->getj_bots()); // pour eviter probleme de compilation
    m_vie--;
    if(m_vie <= 0)
    {
        m_vie = 0;
        actionQuandDetruit();
    }
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
        m_killAction = ACT_R;
    }
    else if(input == "i1-02")
    {
        m_position_haut = true;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Eclaireurs";
        m_vie = 1;
        m_vitesse = 3;
        m_killAction = ACT_R;
    }
    else if(input == "i1-03")
    {
        m_position_haut = false;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Saboteur";
        m_vie = 1;
        m_vitesse = 4;
        m_killAction = ACT_R;
    }
    else if(input == "i1-04")
    {
        m_position_haut = false;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Saboteur";
        m_vie = 1;
        m_vitesse = 4;
        m_killAction = ACT_R;
    }
    else if(input == "i1-05")
    {
        m_position_haut = true;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Piratage des boucliers";
        m_vie = 3;
        m_vitesse = 2;
        m_killAction = ACT_B;
    }
    else if(input == "i1-06")
    {
        m_position_haut = true;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Piratage des boucliers";
        m_vie = 3;
        m_vitesse = 2;
        m_killAction = ACT_B;
    }
    else if(input == "i1-07")
    {
        m_position_haut = false;
        m_difficulte = MENACE_COMMUNE;
        m_name ="Tetes nucleaires instables";
        m_vie = 100; // va etre set plus tard
        m_vitesse = 2;
        m_killAction = ACT_C;
    }
};


void menace_interne_i1_01::getDamage(joueur *joueur)
{
    m_vie--;
    if(m_vie <= 0)
    {
        m_vie = 0;
        joueur->setj_bots(BOTS_INACTIF);
        actionQuandDetruit();
    }
}

void menace_interne_i1_01::actionMenace(char input) 
{
    if (input == 'X') 
    {
        this->set_m_zone(this->get_m_zone()->getzone_right());
        this->set_m_zoneInt(ZONE_WHITE);
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } 
    else if (input == 'Y') 
    {
        this->setPositionhaut(0);
        std::string msg = "[La menace " + m_name + " descend en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } 
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(3);
        std::string msg = "[La menace " + m_name + " inflige 3 degats a la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i1_02::getDamage(joueur *joueur)
{
    m_vie--;
    if(m_vie <= 0)
    {
        m_vie = 0;
        joueur->setj_bots(BOTS_INACTIF);
        actionQuandDetruit();
    }
}

void menace_interne_i1_02::actionMenace(char input) 
{
    if (input == 'X') 
    {
        this->set_m_zone(this->get_m_zone()->getzone_left());
        this->set_m_zoneInt(ZONE_WHITE);
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } 
    else if (input == 'Y') 
    {
        this->setPositionhaut(0);
        std::string msg = "[La menace " + m_name + " descend en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } 
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(3);
        std::string msg = "[La menace " + m_name + " inflige 3 degats a la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i1_03::actionMenace(char input) 
{
    if (input == 'X') 
    {
        this->set_m_zone(this->get_m_zone()->getzone_right());
        this->set_m_zoneInt(ZONE_BLUE);
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } 
    else if (input == 'Y') 
    {
        std::string msg = ""; 
        if(m_zone->getz_reacteur() > 0)
        {
            m_zone->setz_reacteur(m_zone->getz_reacteur() -1);
            msg = "[La menace " + m_name + " consume 1 d'energie au reacteur de la " + m_zone->getz_nom_zone() + " .]\n";
        }
        else
        {
            m_zone->getdegatsIgnoreBouclier(1);
            msg = "[La menace " + m_name + " inflige 1 degats a la " + m_zone->getz_nom_zone() + " .]\n";
        }
        std::cout << msg;
    } 
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(2);
        std::string msg = "[La menace " + m_name + " inflige 2 degats a la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i1_04::actionMenace(char input) 
{
    if (input == 'X') 
    {
        this->set_m_zone(this->get_m_zone()->getzone_left());
        this->set_m_zoneInt(ZONE_RED);
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } 
    else if (input == 'Y') 
    {
        std::string msg = ""; 
        if(m_zone->getz_reacteur() > 0)
        {
            m_zone->setz_reacteur(m_zone->getz_reacteur() -1);
            msg = "[La menace " + m_name + " consume 1 d'energie au reacteur de la " + m_zone->getz_nom_zone() + " .]\n";
        }
        else
        {
            m_zone->getdegatsIgnoreBouclier(1);
            msg = "[La menace " + m_name + " inflige 1 degats a la " + m_zone->getz_nom_zone() + " .]\n";
        }
        std::cout << msg;
    } 
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(2);
        std::string msg = "[La menace " + m_name + " inflige 2 degats a la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i1_05::actionMenace(char input) 
{
    if (input == 'X') 
    {
        this->m_zone->setz_bouclier(0);
        std::string msg = "[La menace " + m_name + " draine toute l'energie du bouclier de la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } 
    else if (input == 'Y') 
    {
        this->m_zone->setz_reacteur(0);
        std::string msg = "[La menace " + m_name + " draine toute l'energie du reacteur de la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } 
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(2);
        std::string msg = "[La menace " + m_name + " inflige 2 degats a la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i1_06::actionMenace(char input) 
{
    if (input == 'X') 
    {
        this->m_zone->setz_bouclier(0);
        std::string msg = "[La menace " + m_name + " draine toute l'energie du bouclier de la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } 
    else if (input == 'Y') 
    {
        this->m_zone->setz_reacteur(0);
        std::string msg = "[La menace " + m_name + " draine toute l'energie du reacteur de la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } 
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(2);
        std::string msg = "[La menace " + m_name + " inflige 2 degats a la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i1_07::actionMenace(char input) 
{
    if (input == 'Z') {
        int degats = this->get_m_vie()*3;
        m_zone->getdegatsIgnoreBouclier(degats);
        std::cout <<  "[La menace " + m_name + " inflige " << degats << " degats a la " + m_zone->getz_nom_zone() + " .]\n";
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i1_07::effetDebutTour()
{
    if(!m_life_set)
    {
        std::map<int, int> mapRocket = get_m_zone()->getzone_left()->getz_roquete_position();
        int rocketNum(1);
        int life(0);
        while (rocketNum < 4)
        {
            if (mapRocket[rocketNum] == 0) // rocket non lancee
                life++;
            rocketNum++;
        }
        this->set_m_vie(life);
        m_life_set = true;
    }
}

menace_interne::~menace_interne() {}
