#include "menace.hpp"
#include "menace_interne.hpp"

menace_interne *create_menaceI(std::string typeMenace, int tempsArrivee, t_data &data);

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

menace_interne::menace_interne(zone *zone, std::string input, int tourDarrivee): menace(input, tourDarrivee)
{
    m_ripost = false;
    m_zone = zone;
    m_zoneInt = zone->getz_zone();
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
    else if(input == "i2-01")
    {
        m_position_haut = false;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Slime";
        m_vie = 2;
        m_vitesse = 2;
        m_killAction = ACT_R;
    }
    else if(input == "i2-015")
    {
        m_position_haut = false;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Bebe Slime";
        m_vie = 1;
        m_vitesse = 2;
        m_killAction = ACT_R;
    }
    else if(input == "i2-02")
    {
        m_position_haut = false;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Slime";
        m_vie = 2;
        m_vitesse = 2;
        m_killAction = ACT_R;
    }
    else if(input == "i2-03")
    {
        m_ripost = true;
        m_position_haut = true;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Troupe d'assaut";
        m_vie = 2;
        m_vitesse = 2;
        m_killAction = ACT_R;
    }
    else if(input == "i2-04")
    {
        m_ripost = true;
        m_position_haut = false;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Troupe d'assaut";
        m_vie = 2;
        m_vitesse = 2;
        m_killAction = ACT_R;
    }
    else if(input == "i2-05")
    {
        m_position_haut = true;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Virus";
        m_vie = 3;
        m_vitesse = 3;
        m_killAction = ACT_C;
    }
    else if(input == "i2-06")
    {
        m_position_haut = false;
        m_difficulte = MENACE_COMMUNE_AVANCEE;
        m_name ="Reacteur en fusion";
        m_vie = 3;
        m_vitesse = 2;
        m_killAction = ACT_B;
    }
    else if(input == "si1-01")
    {
        m_ripost = true;
        m_position_haut = false;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Commandos";
        m_vie = 2;
        m_vitesse = 2;
        m_killAction = ACT_R;
    }
    else if(input == "si1-02")
    {
        m_ripost = true;
        m_position_haut = true;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Commandos";
        m_vie = 2;
        m_vitesse = 2;
        m_killAction = ACT_R;
    }
    else if(input == "si1-03")
    {
        m_position_haut = false;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Alien";
        m_vie = 2;
        m_vitesse = 2;
        m_killAction = ACT_R;
    }
    else if(input == "si1-04")
    {
        m_position_haut = true;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Fissure";
        m_vie = 2;
        m_vitesse = 2;
        m_killAction = ACT_R;
    }
    else if(input == "si1-05")
    {
        m_position_haut = true;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Courts-Circuits";
        m_vie = 4;
        m_vitesse = 3;
        m_killAction = ACT_B;
    }
    else if(input == "si1-06")
    {
        m_position_haut = false;
        m_difficulte = MENACE_SERIEUSE;
        m_name ="Revolte des robots de combat";
        m_vie = 4;
        m_vitesse = 2;
        m_killAction = ACT_C;
    }
        else if(input == "si2-01")
    {
        m_ripost = true;
        m_position_haut = true;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Executeur";
        m_vie = 2;
        m_vitesse = 2;
        m_killAction = ACT_R;
    }
    else if(input == "si2-02")
    {
        m_ripost = false;
        m_position_haut = true;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Droide Fureteur";
        m_vie = 2;
        m_vitesse = 2;
        m_killAction = ACT_R;
    }
    else if(input == "si2-03")
    {
        m_position_haut = false;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Surcharge des generateurs";
        m_vie = 3;
        m_vitesse = 7;
        m_killAction = ACT_B;
    }
    else if(input == "si2-04")
    {
        m_position_haut = false;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Contamination";
        m_vie = 2;
        m_vitesse = 3;
        m_killAction = ACT_R;
    }
    else if(input == "si2-05")
    {
        m_position_haut = false;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Engin nucleaire";
        m_vie = 1;
        m_vitesse = 4;
        m_killAction = ACT_C;
    }
};




//MENACE COMMUNES

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
        this->set_m_Positionhaut(0);
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
        this->set_m_Positionhaut(0);
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


//MENACES COMMUNES AVANCEES

void menace_interne_i2_01::actionMenace(char input)
{
    if (input == 'X')
    {
        std::string msg = "[La menace " + m_name + " tente de detruire une roquette, mais il n'y en a aucune au vaisseau.]\n";
        std::map<int, int> roquette_position = this->m_zone->getz_roquete_position();
        if (roquette_position[1] == 0)
        {
            this->m_zone->setz_roquete_position(1, 2);
            msg = "[La menace " + m_name + " detruit la roquette 1 du vaisseau.]\n";
        }
        else if (roquette_position[2] == 0)
        {
            this->m_zone->setz_roquete_position(2, 2);
            msg = "[La menace " + m_name + " detruit la roquette 2 du vaisseau.]\n";
        }
        else if (roquette_position[3] == 0)
        {
            this->m_zone->setz_roquete_position(3, 2);
            msg = "[La menace " + m_name + " detruit la roquette 3 du vaisseau.]\n";
        }
        std::cout << msg;
    }
    else if (input == 'Y')
    {
        std::vector<menace_interne *> menaceInte = this->get_m_chemin()->get_menacesInte();
        for (std::vector<menace_interne *>::iterator it = menaceInte.begin(); it != menaceInte.end(); it++)
        {
            if ((*it)->get_m_name() == "Bebe Slime")
            {
                std::string msg = "[La menace " + m_name + " ne s'etend pas car la " + m_zone->getz_nom_zone() + " contient deja un Bebe Slime.]\n";
                std::cout << msg;
                return ;
            }
        }
        menace_interne *new_menace = create_menaceI("i2-015", this->get_m_zone()->getz_temps() + 1, *this->get_m_zone()->getz_data());
        new_menace->set_m_zone(this->get_m_zone()->getzone_white());
        new_menace->set_m_zoneInt(ZONE_WHITE);
        new_menace->set_m_chemin(this->get_m_zone()->getzone_white()->getz_chemin_menace_Int());
        std::string msg = "[La menace " + m_name + " s'etend dans la " + new_menace->get_m_zone()->getz_nom_zone() + " avec un point de vie.]\n";
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

void menace_interne_i2_01::effetDebutTour()
{
    if (m_presence)
    {
        if(!m_zone_delay_set)
        {
            m_zone->setz_jump_tour_upon_entry_bas(true);
            m_zone_delay_set = true;
        }
    }
}

void menace_interne_i2_01::actionQuandDetruit()
{
    m_zone->setz_jump_tour_upon_entry_bas(false);
    menace_interne::actionQuandDetruit();
}


void menace_interne_i2_015::actionMenace(char input)
{
    if (input == 'X')
    {
    }
    else if (input == 'Y')
    {
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(2);
        std::string msg = "[La menace " + m_name + " inflige 2 degats a la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i2_015::effetDebutTour()
{
    if(!m_zone_delay_set)
    {
        m_zone->setz_jump_tour_upon_entry_bas(true);
        m_zone_delay_set = true;
    }
}

void menace_interne_i2_015::actionQuandDetruit()
{
    m_zone->setz_jump_tour_upon_entry_bas(false);
    menace_interne::actionQuandDetruit();
}

void menace_interne_i2_02::effetDebutTour()
{
    if(!m_zone_delay_set)
    {
        m_zone->setz_jump_tour_upon_entry_bas(true);
        m_zone_delay_set = true;
    }
}

void menace_interne_i2_02::actionQuandDetruit()
{
    m_zone->setz_jump_tour_upon_entry_bas(false);
    menace_interne::actionQuandDetruit();
}

void menace_interne_i2_02::actionMenace(char input)
{
    if (input == 'X')
    {
        if (this->m_zone->getz_bots())
        {
            this->m_zone->setz_bots_englues(true);
            std::string msg = "[La menace " + m_name + " englue les robots de combats. Ils doivent etre actives deux fois pour pouvoir etre utilises.]\n";
            std::cout << msg;
        }
    }
    if (input == 'Y')
    {
        std::vector<menace_interne *> menaceInte = this->get_m_chemin()->get_menacesInte();
        for (std::vector<menace_interne *>::iterator it = menaceInte.begin(); it != menaceInte.end(); it++)
        {
            if ((*it)->get_m_name() == "Bebe Slime")
            {
                std::string msg = "[La menace " + m_name + " ne s'etend pas car la " + m_zone->getz_nom_zone() + " contient deja un Bebe Slime.]\n";
                std::cout << msg;
                return ;
            }
        }
        menace_interne *new_menace = create_menaceI("i2-015", this->get_m_zone()->getz_temps() + 1, *this->get_m_zone()->getz_data());
        new_menace->set_m_zone(this->get_m_zone()->getzone_white());
        new_menace->set_m_zoneInt(ZONE_WHITE);
        new_menace->set_m_chemin(this->get_m_zone()->getzone_white()->getz_chemin_menace_Int());
        this->get_m_zone()->getzone_white()->getz_chemin_menace_Int()->add_menaceInt(new_menace);
        std::string msg = "[La menace " + m_name + " s'etend dans la " + new_menace->get_m_zone()->getz_nom_zone() + " avec un point de vie.]\n";
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

void menace_interne_i2_03::actionMenace(char input)
{
    if (input == 'X')
    {
        this->set_m_Positionhaut(0);
        std::string msg = "[La menace " + m_name + " descend en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    }
    else if (input == 'Y')
    {
        this->set_m_zone(this->get_m_zone()->getzone_right());
        this->set_m_zoneInt(ZONE_WHITE); // le Int qui correspond a la zone
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(4);
        std::string msg = "[La menace " + m_name + " inflige 4 degats a la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i2_04::actionMenace(char input)
{
    if (input == 'X')
    {
        this->set_m_Positionhaut(1);
        std::string msg = "[La menace " + m_name + " monte en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    }
    else if (input == 'Y')
    {
        this->set_m_zone(this->get_m_zone()->getzone_left());
        this->set_m_zoneInt(ZONE_WHITE); // le Int qui correspond a la zone
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(4);
        std::string msg = "[La menace " + m_name + " inflige 4 degats a la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i2_05::actionMenace(char input)
{
    if (input == 'X')
    {
        int energie = this->m_zone->getz_reacteur() - 1;
        if(energie < 0)
            energie = 0;
        this->m_zone->setz_reacteur(energie);
        // LEFT
        energie = this->m_zone->getzone_left()->getz_reacteur() - 1;
        if(energie < 0)
            energie = 0;
        this->m_zone->getzone_left()->setz_reacteur(energie);
        // RIGHT
        energie = this->m_zone->getzone_right()->getz_reacteur() - 1;
        if(energie < 0)
            energie = 0;
        this->m_zone->getzone_right()->setz_reacteur(energie);
        std::string msg = "[La menace " + m_name + " draine un d'energie a chaque reacteur.]\n";
        std::cout << msg;
    }
    else if (input == 'Y')
    {
        m_zone->retarderactionZone();
        m_zone->getzone_right()->retarderactionZone();
        m_zone->getzone_left()->retarderactionZone();
        std::string msg = "[La menace " + m_name + " retard tous les joueurs.]\n";
        std::cout << msg;
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(1);
        m_zone->getzone_right()->getdegatsIgnoreBouclier(1);
        m_zone->getzone_left()->getdegatsIgnoreBouclier(1);
        std::string msg = "[La menace " + m_name + " inflige 1 degats sur toutes les zones...]\n";
        std::cout << msg;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i2_06::actionMenace(char input)
{
    if (input == 'X')
    {
        int degats = this->m_zone->getz_reacteur();
        m_zone->getdegatsIgnoreBouclier(degats);
        std::cout << "[La menace " + m_name + "inflige " << degats << " degats sur " + m_zone->getz_nom_zone() + ".]\n";
    }
    else if (input == 'Y')
    {
        int energie = this->m_zone->getz_capsule_energie() - 1;
        if(energie < 0)
            energie = 0;
        this->m_zone->setz_capsule_energie(energie);
        std::string msg = "[La menace " + m_name + " consume 1 capsule de carburant.]\n";
        std::cout << msg;
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(3);
        std::cout << "[La menace " + m_name + "inflige 3 degats sur " + m_zone->getz_nom_zone() + ".]\n";
    }
    else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i2_06::actionQuandDetruit()
{
   m_zone->getzone_right()->assomerjoueursZoneBas();
   m_zone->getzone_left()->assomerjoueursZoneBas();
   std::cout << "[Les joueurs en bas des Zones Bleu et Rouge sont assomes par " << m_name << ".]\n";
}

void menace_interne_si1_01::actionMenace(char input)
{
    if (input == 'X')
    {
        this->set_m_Positionhaut(1);
        std::string msg = "[La menace " + m_name + " monte en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    }
    else if (input == 'Y')
    {
        if(get_m_vie() < get_m_max_vie())
        {
            this->set_m_zone(this->get_m_zone()->getzone_right());
            this->set_m_zoneInt(ZONE_WHITE); // le Int qui correspond a la zone
            std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
            std::cout << msg;
        }
        else
        {
             m_zone->getdegatsIgnoreBouclier(2);
            std::string msg = "[La menace " + m_name + " inflige 2 degats a la " + m_zone->getz_nom_zone() + " .]\n";
            std::cout << msg;
        }

    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(4);
        m_zone->assomerjoueursZoneHaut();
        std::string msg = "[La menace " + m_name + " inflige 4 degats a la " + m_zone->getz_nom_zone() + " et assome les joueurs qui y sont presents a son niveau .]\n";
        std::cout << msg;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_si1_02::actionMenace(char input)
{
    if (input == 'X')
    {
        this->set_m_Positionhaut(0);
        std::string msg = "[La menace " + m_name + " descend en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
    }
    else if (input == 'Y')
    {
        if(get_m_vie() < get_m_max_vie())
        {
            this->set_m_zone(this->get_m_zone()->getzone_left());
            this->set_m_zoneInt(ZONE_WHITE); // le Int qui correspond a la zone
            std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
            std::cout << msg;
        }
        else
        {
             m_zone->getdegatsIgnoreBouclier(2);
            std::string msg = "[La menace " + m_name + " inflige 2 degats a la " + m_zone->getz_nom_zone() + " .]\n";
            std::cout << msg;
        }

    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(4);
        m_zone->assomerjoueursZoneBas();
        std::string msg = "[La menace " + m_name + " inflige 4 degats a la " + m_zone->getz_nom_zone() + " et assome les joueurs qui y sont presents a son niveau.]\n";
        std::cout << msg;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_si1_03::actionMenace(char input)
{
    if (input == 'X')
    {
        m_grandit = true; // sert a rien!
        m_ripost = true;
        std::string msg = "[La menace " + m_name + " grandit !]\n";
        std::cout << msg;
    }
    else if (input == 'Y')
    {
        this->set_m_Positionhaut(1);
        int joueurCount(0);
        std::vector<joueur*>::iterator it;
        for (it = m_zone->getz_joueurs_haut().begin(); it != m_zone->getz_joueurs_haut().end(); it++)
        {
            joueurCount++;
        }
        m_zone->getdegatsIgnoreBouclier(joueurCount);
        std::string msg = "[La menace " + m_name + " monte en " + m_zone->getz_nom_zone();
        std::cout << msg << " et inflige " << joueurCount << " degats.]\n";
    }
    else if (input == 'Z') {
        std::string msg = "[La menace " + m_name + " s empare du vaisseau !!!! YOU LOSE !!!!!]\n";
        std::cout << msg;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}



void menace_interne_si1_05::actionMenace(char input)
{
    if (input == 'X')
    {
        int EnergieReacteur = m_zone->getz_reacteur();
        m_zone->setz_reacteur(0);
        int EnergieBouclier = m_zone->getz_bouclier() + EnergieReacteur;
        if(EnergieBouclier > m_zone->getz_max_energie_bouclier())
        {
            m_zone->setz_bouclier(m_zone->getz_max_energie_bouclier());
            m_zone->getdegatsIgnoreBouclier(EnergieBouclier - m_zone->getz_max_energie_bouclier());
            std::string msg = "[La menace " + m_name + " transfere l'energie du reacteur central au bouclier, le sruplus se volatilise et cause ";
            std::cout << msg << EnergieBouclier - m_zone->getz_max_energie_bouclier() << " degats.]\n";
        }
        else
        {
            m_zone->setz_bouclier(EnergieBouclier);
            std::string msg = "[La menace " + m_name + " transfere l'energie du reacteur central au bouclier sans causer de degats.]\n ";
            std::cout << msg;
        }

    }
    else if (input == 'Y')
    {
        int EnergieReacteur = m_zone->getz_reacteur();
        m_zone->setz_reacteur(0);
        m_zone->getdegatsIgnoreBouclier(EnergieReacteur);
        std::string msg = "[La menace " + m_name + " fait se volatiliser l'energie du reacteur, causant ";
        std::cout << msg << EnergieReacteur << " degats.]\n";
    }
    else if (input == 'Z') {
        int EnergieReacteur = m_zone->getz_reacteur();
        m_zone->setz_reacteur(0);
        m_zone->getdegatsIgnoreBouclier(EnergieReacteur);
        int EnergieReacteurR = m_zone->getzone_right()->getz_reacteur();
        m_zone->getzone_right()->setz_reacteur(0);
        m_zone->getzone_right()->getdegatsIgnoreBouclier(EnergieReacteurR);
        int EnergieReacteurL = m_zone->getzone_left()->getz_reacteur();
        m_zone->getzone_left()->setz_reacteur(0);
        m_zone->getzone_left()->getdegatsIgnoreBouclier(EnergieReacteurL);
        std::string msg = "[La menace " + m_name + " fait se volatiliser l'energie du reacteur, causant ";
        std::cout << msg << EnergieReacteur << " degats a la " << m_zone->getz_nom_zone() << ", " <<
        EnergieReacteurR << " degats a la " << m_zone->getzone_right()->getz_nom_zone() << ", " <<
        EnergieReacteurL << " degats a la " << m_zone->getzone_left()->getz_nom_zone() <<
        ".]\n";
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_si1_06::actionMenace(char input)
{
    if (input == 'X')
    {
        std::string msg = "[La menace " + m_name + " assome tous les joueurs ayant des robots actifs.\n";
        std::cout << msg;
        m_zone->getzone_right()->assomerjoueursZoneRobotsActifs();
        m_zone->getzone_left()->assomerjoueursZoneRobotsActifs();
        m_zone->assomerjoueursZoneRobotsActifs();
    }
    else if (input == 'Y')
    {
        std::string msg = "[La menace " + m_name + " assome tous les joueurs present en zone bleu haute et en zone basse rouge.]\n";
        std::cout << msg;
        m_zone->assomerjoueursZoneBas();
        m_zone_bis->assomerjoueursZoneHaut();
    }
    else if (input == 'Z') {
        std::string msg = "[La menace " + m_name + " assome tous les joueurs qui ne sont pas sur la passerelle (zone blanche haute).]\n";
        std::cout << msg;
        m_zone->assomerjoueursZone();
        m_zone_bis->assomerjoueursZone();
        m_zone->getzone_white()->assomerjoueursZoneBas();
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

bool menace_interne_si1_06::AttractAction(int joueurAction, int Zone, bool haut) const
{
    if(m_position_haut == haut && joueurAction == m_killAction && m_zoneInt == Zone)
        return true;
    else if (m_position_haut_bis == haut && joueurAction == m_killAction && m_zoneInt_bis == Zone)
        return true;
    else
        return false;
};

void menace_interne_si1_06::getDamage(joueur *joueur)
{
    joueur->setj_bots(joueur->getj_bots()); // pour eviter probleme de compilation
    m_vie--;
    if (m_degats_tour_zone != joueur->getj_zone() && m_degats_tour_zone != 0)
    {
        std::string msg = "[Vous avez infliges un degat a la menace " + m_name + " dans chaque zone ou elle se trouve lors du meme tour!.]\n";
        std::cout << msg << "[+1 degats!!!]";
        m_vie--;
    }
    m_degats_tour_zone = joueur->getj_zone();
    if(m_vie <= 0)
    {
        m_vie = 0;
        actionQuandDetruit();
    }
}

void menace_interne_si1_06::effetDebutTour()
{
    m_degats_tour_zone = 0;
}


void menace_interne_si2_01::actionMenace(char input)
{
    if (input == 'X')
    {
        m_ripost = true;
        std::string msg = "[La menace " + m_name + " grandit !]\n";
        std::cout << msg;
    }
    else if (input == 'Y')
    {
        this->set_m_Positionhaut(1);
        int joueurCount(0);
        std::vector<joueur*>::iterator it;
        for (it = m_zone->getz_joueurs_haut().begin(); it != m_zone->getz_joueurs_haut().end(); it++)
        {
            joueurCount++;
        }
        m_zone->getdegatsIgnoreBouclier(joueurCount);
        std::string msg = "[La menace " + m_name + " monte en " + m_zone->getz_nom_zone();
        std::cout << msg << " et inflige " << joueurCount << " degats.]\n";
    }
    else if (input == 'Z') {
        std::string msg = "[La menace " + m_name + " s empare du vaisseau !!!! YOU LOSE !!!!!]\n";
        std::cout << msg;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}


void menace_interne_si2_03::actionMenace(char input)
{
    int z_reacteur = 0;
    if (input == 'X')
    {
        std::string msg = "[La menace " + m_name + " consume 2 blocs d'energie du reacteur central.]\n";
        std::cout << msg;
        z_reacteur = m_zone->getzone_white()->getz_reacteur() - 2;
        if (z_reacteur < 0)
            z_reacteur = 0;
        m_zone->getzone_white()->setz_reacteur(z_reacteur);
    }
    else if (input == 'Y')
    {
        std::string msg = "[La menace " + m_name + " consume 1 blocs d'energie de chaque reacteur.]\n";
        std::cout << msg;
        z_reacteur = m_zone->getzone_white()->getz_reacteur() - 1;
        if (z_reacteur < 0)
            z_reacteur = 0;
        m_zone->getzone_white()->setz_reacteur(z_reacteur);
        z_reacteur = m_zone->getzone_red()->getz_reacteur() - 1;
        if (z_reacteur < 0)
            z_reacteur = 0;
        m_zone->getzone_red()->setz_reacteur(z_reacteur);
                z_reacteur = m_zone->getzone_blue()->getz_reacteur() - 1;
        if (z_reacteur < 0)
            z_reacteur = 0;
        m_zone->getzone_blue()->setz_reacteur(z_reacteur);
    }
    else if (input == 'Z') {
        std::string msg = "[La menace " + m_name + " inflige 3 degats a chaque zones.]\n";
        std::cout << msg;
        m_zone->getzone_blue()->getdegatsIgnoreBouclier(3);
        m_zone->getzone_white()->getdegatsIgnoreBouclier(3);
        m_zone->getzone_red()->getdegatsIgnoreBouclier(3);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

bool menace_interne_si2_03::AttractAction(int joueurAction, int Zone, bool haut) const
{
    if(m_position_haut == haut && joueurAction == m_killAction && m_zoneInt == Zone)
        return true;
    else if (m_position_haut_bis1 == haut && joueurAction == m_killAction && m_zoneInt_bis1 == Zone)
        return true;
    else if (m_position_haut_bis2 == haut && joueurAction == m_killAction && m_zoneInt_bis2 == Zone)
        return true;
    else
        return false;
};

void menace_interne_si2_03::getDamage(joueur *joueur)
{
    if (joueur->getj_zone() == ZONE_BLUE)
        m_degats_zone_blue = 1;
    else if (joueur->getj_zone() == ZONE_RED)
        m_degats_zone_red = 1;
    else if (joueur->getj_zone() == ZONE_WHITE)
        m_degats_zone_white = 1;
    if (m_degats_zone_blue + m_degats_zone_red + m_degats_zone_white == 3)
    {
        std::string msg = "[Vous avez infliges un degat a la menace " + m_name + " dans chaque zone ou elle se trouve lors du meme tour!.]\n";
        std::cout << msg << "[+2 degats!!!]";
        m_vie -= 2;
    }
    m_vie--;
    if(m_vie <= 0)
    {
        m_vie = 0;
        actionQuandDetruit();
    }
}

void menace_interne_si2_03::effetDebutTour()
{
    m_degats_zone_blue = 0;
    m_degats_zone_red = 0;
    m_degats_zone_white = 0;
}

void menace_interne_si2_04::actionMenace(char input)
{
    if (input == 'X')
    {
        std::string msg = "[La menace " + m_name + " retarde tous les joueurs dans les zones contaminees.]\n";
        std::cout << msg;
        if (m_contamination_blue_haut)
        {
            msg = "[Les joueurs en zone bleu haut sont retardes.]\n";
            std::cout << msg;
            m_zone->getzone_blue()->retarderactionZoneHaut();
        }
        if (m_contamination_blue_bas)
        {
            msg = "[Les joueurs en zone bleu bas sont retardes.]\n";
            std::cout << msg;
            m_zone->getzone_blue()->retarderactionZoneBas();
        }
        if (m_contamination_red_haut)
        {
            msg = "[Les joueurs en zone rouge haut sont retardes.]\n";
            std::cout << msg;
            m_zone->getzone_red()->retarderactionZoneHaut();
        }
        if (m_contamination_red_bas)
        {
            msg = "[Les joueurs en zone rouge bas sont retardes.]\n";
            std::cout << msg;
            m_zone->getzone_red()->retarderactionZoneBas();
        }
    }
    else if (input == 'Y')
    {
        std::string msg = "[La menace " + m_name + " inflige 1 degat dans chaque zone contaminee.]\n";
        std::cout << msg;
        if (m_contamination_blue_haut)
        {
            m_zone->getzone_blue()->getdegatsIgnoreBouclier(1);
        }
        if (m_contamination_blue_bas)
        {
            m_zone->getzone_blue()->getdegatsIgnoreBouclier(1);
        }
        if (m_contamination_red_haut)
        {
            m_zone->getzone_red()->getdegatsIgnoreBouclier(1);
        }
        if (m_contamination_red_bas)
        {
            m_zone->getzone_red()->getdegatsIgnoreBouclier(1);
        }
    }
    else if (input == 'Z')
    {
        std::string msg = "[La menace " + m_name + " assome tous les joueurs dans les zones contaminees.]\n";
        std::cout << msg;
        if (m_contamination_blue_haut)
        {
            msg = "[Les joueurs en zone bleu haut sont assomes.]\n";
            std::cout << msg;
            m_zone->getzone_blue()->assomerjoueursZoneHaut();
        }
        if (m_contamination_blue_bas)
        {
            msg = "[Les joueurs en zone bleu bas sont assomes.]\n";
            std::cout << msg;
            m_zone->getzone_blue()->assomerjoueursZoneBas();
        }
        if (m_contamination_red_haut)
        {
            msg = "[Les joueurs en zone rouge haut sont assomes.]\n";
            std::cout << msg;
            m_zone->getzone_red()->assomerjoueursZoneHaut();
        }
        if (m_contamination_red_bas)
        {
            msg = "[Les joueurs en zone rouge bas sont assomes.]\n";
            std::cout << msg;
            m_zone->getzone_red()->assomerjoueursZoneBas();
        }
    }
    else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

bool menace_interne_si2_04::AttractAction(int joueurAction, int Zone, bool haut) const
{
    if(m_position_haut == haut && joueurAction == m_killAction && m_zoneInt == Zone)
        return true;
    else if (m_position_haut_bis1 == haut && joueurAction == m_killAction && m_zoneInt_bis1 == Zone)
        return true;
    else if (m_position_haut_bis2 == haut && joueurAction == m_killAction && m_zoneInt_bis2 == Zone)
        return true;
    else if (m_position_haut_bis3 == haut && joueurAction == m_killAction && m_zoneInt_bis3 == Zone)
        return true;
    else
        return false;
};

void menace_interne_si2_04::getDamage(joueur *joueur)
{
    if (m_zone->getzone_blue()->getz_joueur_haut(joueur->getj_nom()))
    {
        if (m_contamination_blue_haut)
        {
            m_vie--;
            m_contamination_blue_haut = false;
        }
    }
    else if (m_zone->getzone_blue()->getz_joueur_bas(joueur->getj_nom()))
    {
        if (m_contamination_blue_bas)
        {
            m_vie--;
            m_contamination_blue_bas = false;
        }
    }
    else if (m_zone->getzone_red()->getz_joueur_haut(joueur->getj_nom()))
    {
        if (m_contamination_red_haut)
        {
            m_vie--;
            m_contamination_red_haut = false;
        }
    }
    else if (m_zone->getzone_red()->getz_joueur_bas(joueur->getj_nom()))
    {
        if (m_contamination_red_bas)
        {
            m_vie--;
            m_contamination_red_bas = false;
        }
    }
    if(m_vie <= 1)
    {
        m_vie = 0;
        actionQuandDetruit();
    }
}

void menace_interne_si2_05::actionMenace(char input)
{
    if (input == 'X')
    {
        std::string msg = "[La menace " + m_name + " augmente sa vitesse de 1!]\n";
        m_vitesse++;
    }
    else if (input == 'Y')
    {
        std::string msg = "[La menace " + m_name + " augmente sa vitesse de 1!]\n";
        m_vitesse++;
    }
    else if (input == 'Z') {
        std::string msg = "[La menace " + m_name + " detruit le vaisseaux.]\n";
        std::cout << msg;
        m_zone->getzone_blue()->getdegatsIgnoreBouclier(6);
        m_zone->getzone_white()->getdegatsIgnoreBouclier(6);
        m_zone->getzone_red()->getdegatsIgnoreBouclier(6);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_si2_05::getDamage(joueur *joueur)
{
    joueur->setj_bots(joueur->getj_bots()); // pour eviter probleme de compilation
    m_degats_par_tour++;
    if (m_degats_par_tour == 3)
    {
        std::string msg = "[Vous avez infliges 3 degat a la menace " + m_name + " pendant le meme tour!!.]\n";
        std::cout << msg;
        m_vie -= 1;
    }
    else
    {
        std::string msg = "[Vous avez infliges un degat a la menace " + m_name + "!.]\n";
        std::cout << msg << "[Si vous lui infligez " << 3 - m_degats_par_tour << " degat(s) de plus pendant ce tour, elle mourra!]\n";
    }
    if(m_vie <= 0)
    {
        m_vie = 0;
        actionQuandDetruit();
    }
}

void menace_interne_si2_05::effetDebutTour()
{
    m_degats_par_tour = 0;
}
