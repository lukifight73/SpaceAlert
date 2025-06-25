#include "menace.hpp"
#include "menace_interne.hpp"
#include "zone.hpp"
#include "GameNarrator.hpp"

menace_interne *create_menaceI(std::string typeMenace, int tempsArrivee, t_data &data);

menace_interne::menace_interne()
{
}

void menace_interne::send_announcement_message() const
{
    std::string station;
    if (m_position_haut)
        station = "station haute ";
    else
        station = "station basse ";
    std::string msg = "[Attention, la menace " + m_name + " vient d'arriver et est presente en " + station + m_zone->getz_nom_zone() + "!]\n";
    msg += "[Difficulté : " + std::to_string(m_difficulte) + ", Vitesse : " + std::to_string(m_vitesse) + ", Vie : " + std::to_string(m_vie) + "]\n\n";
    printSlowly(msg);
}

void menace_interne::print_menace() const {
    menace::print_menace();  // Appeler la version de base
    std::cout << "La menace interne est en haut? : " << m_position_haut << std::endl;
}

bool menace_interne::AttractAction(int joueurAction, int Zone, bool haut) const
{
    if(m_position_haut == haut && joueurAction == m_killAction && m_zoneInt == Zone && m_presence == true)
        return true;
    else
        return false;
};

void menace_interne::getDamage(joueur *joueur)
{
    m_degats_str += "[" + joueur->getj_nom() + " attaque la menace interne " + m_name + " et lui inflige un degat!]\n";
    m_degats++;
}

void menace_interne::getDamageHero(joueur *joueur)
{
    joueur->setj_bots(joueur->getj_bots()); // pour eviter probleme de compilation
    m_degats_str += "[ACTION HEROIQUE! " + joueur->getj_nom() + " attaque la menace interne " + m_name + " et lui inflige deux degat!]\n";
    m_degats++;
    m_degats++;
}

void menace_interne::getDamaged()
{
    start_color_interne();
    printSlowly("[La menace interne " + m_name + " a une vie de " + std::to_string(m_vie) + "].\n");
    printSlowly(m_degats_str);
    add_m_degats_totaux_str(m_degats_str);
    m_degats_str = "";
    while (m_degats)
    {
        m_vie--;
        m_degats--;
    }
    if (m_vie <= 0)
    {
        m_vie = 0;
        actionQuandDetruit();
    }
    else
        printSlowly("[La menace interne " + m_name + " a desormais une vie de " + std::to_string(m_vie) + "].\n");
    m_degats = 0;
    std::cout << std::endl;
    end_color();
}


menace_interne::menace_interne(zone *zone, std::string input, int tourDarrivee): menace(input, tourDarrivee)
{
    m_ripost = false;
    m_zone = zone;
    m_zoneInt = zone->getz_zone();
    m_degats_str = "";
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
        m_position_haut = true;
        m_difficulte = MENACE_SERIEUSE_AVANCEE;
        m_name ="Droide fureteur";
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

//TO DO
void menace_interne::printfaitdegats(int degats)
{
    // std::string msg = "[La menace " + m_name + " inflige " +  std::to_string(degats) + " degats a la " + m_zone->getz_nom_zone() + " .]\n";
    // m_zone->getz_data()->VoixRobot1->announce(msg);
    // std::cout << "La " << m_zone->getz_nom_zone() << " a " << m_zone->ge;
    degats = 0;
}

//MENACE COMMUNES

void menace_interne_i1_01::getDamage(joueur *joueur)
{
    m_degats_str += "[" + joueur->getj_nom() + " attaque la menace interne " + m_name + " et lui inflige un degat!]\n";
    m_degats++;
    if(m_vie <= m_degats)
    {
        std::cout << "[La menace internce " + m_name + " riposte et desactive les robots de " + joueur->getj_nom() + ".]\n";
        joueur->setj_bots(BOTS_INACTIF);
    }
}

void menace_interne_i1_01::getDamageHero(joueur *joueur)
{
    joueur->setj_bots(joueur->getj_bots()); // pour eviter probleme de compilation
    m_degats_str += "[ACTION HEROIQUE! " + joueur->getj_nom() + " attaque la menace interne " + m_name + " et lui inflige deux degat!]\n";
    m_degats++;
    m_degats++;
}

void menace_interne_i1_01::actionMenace(char input)
{
    if (input == 'X')
    {
        this->set_m_zone(this->get_m_zone()->getzone_right());
        this->set_m_zoneInt(ZONE_WHITE);
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " station haute.]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        this->set_m_Positionhaut(0);
        std::string msg = "[La menace " + m_name + " descend en " + m_zone->getz_nom_zone() + ".]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(3);
        this->printfaitdegats(3);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i1_02::getDamage(joueur *joueur)
{
    m_degats_str += "[" + joueur->getj_nom() + " attaque la menace interne " + m_name + " et lui inflige un degat!]\n";
    m_degats++;
    if(m_vie <= m_degats)
    {
        std::cout << "[La menace internce " + m_name + " riposte et desactive les robots de " + joueur->getj_nom() + ".]\n";
        joueur->setj_bots(BOTS_INACTIF);
    }
}

void menace_interne_i1_02::getDamageHero(joueur *joueur)
{
    m_degats_str += "[ACTION HEROIQUE! " + joueur->getj_nom() + " attaque la menace interne " + m_name + " et lui inflige deux degat!]\n";
    m_degats++;
    m_degats++;
}

void menace_interne_i1_02::actionMenace(char input)
{
    if (input == 'X')
    {
        this->set_m_zone(this->get_m_zone()->getzone_left());
        this->set_m_zoneInt(ZONE_WHITE);
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " station haute.]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        this->set_m_Positionhaut(0);
        std::string msg = "[La menace " + m_name + " descend en " + m_zone->getz_nom_zone() + ".]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(3);
        this->printfaitdegats(3);
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
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " station basse.]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        std::string msg = "";
        std::string msg2 = "";
        if(m_zone->getz_reacteur() > 0)
        {
            m_zone->setz_reacteur(m_zone->getz_reacteur() -1);
            msg = "[La menace " + m_name + " consume 1 d'energie au reacteur de la " + m_zone->getz_nom_zone() + ", il reste " + std::to_string(m_zone->getz_reacteur()) + " energie au reacteur ..]\n";
            m_zone->getz_data()->VoixRobot1->announce(msg);
        }
        else
        {
            m_zone->getdegatsIgnoreBouclier(1);
            this->printfaitdegats(1);
        }
        std::cout << msg;
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(2);
        this->printfaitdegats(2);
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
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " station basse.]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        std::string msg = "";
        if(m_zone->getz_reacteur() > 0)
        {
            m_zone->setz_reacteur(m_zone->getz_reacteur() -1);
            msg = "[La menace " + m_name + " consume 1 d'energie au reacteur de la " + m_zone->getz_nom_zone() + ", il reste " + std::to_string(m_zone->getz_reacteur()) + " energie(s) au reacteur ..]\n";
            m_zone->getz_data()->VoixRobot1->announce(msg);
        }
        else
        {
            m_zone->getdegatsIgnoreBouclier(1);
            this->printfaitdegats(1);
        }
        std::cout << msg;
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(2);
        this->printfaitdegats(2);
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
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        this->m_zone->setz_reacteur(0);
        std::string msg = "[La menace " + m_name + " draine toute l'energie du reacteur de la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(2);
        this->printfaitdegats(2);
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
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        this->m_zone->setz_reacteur(0);
        std::string msg = "[La menace " + m_name + " draine toute l'energie du reacteur de la " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(2);
        this->printfaitdegats(2);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i1_07::actionMenace(char input)
{
    if (input == 'Z') {
        int degats = this->get_m_vie()*3;
        m_zone->getdegatsIgnoreBouclier(degats);
        this->printfaitdegats(degats);
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
        std::string msg;
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
        else {
            msg = "[La menace " + m_name + " tente de detruire une roquette, mais il n'y en a aucune au vaisseau.]\n";
        }
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
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
                m_zone->getz_data()->VoixRobot1->announce(msg);
                return ;
            }
        }
        menace_interne *new_menace = create_menaceI("i2-015", this->get_m_zone()->getz_temps() + 1, *this->get_m_zone()->getz_data());
        new_menace->set_m_zone(this->get_m_zone()->getzone_white());
        new_menace->set_m_zoneInt(ZONE_WHITE);
        new_menace->set_m_chemin(this->get_m_zone()->getzone_white()->getz_chemin_menace_Int());
        std::string msg = "[La menace " + m_name + " s'etend dans la " + new_menace->get_m_zone()->getz_nom_zone() + " avec un point de vie.]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(2);
        this->printfaitdegats(2);
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
        this->printfaitdegats(2);
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
            m_zone->getz_data()->VoixRobot1->announce(msg);
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
                m_zone->getz_data()->VoixRobot1->announce(msg);
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
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(2);
        this->printfaitdegats(2);
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
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        this->set_m_zone(this->get_m_zone()->getzone_right());
        this->set_m_zoneInt(ZONE_WHITE); // le Int qui correspond a la zone
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(4);
        this->printfaitdegats(4);
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
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        this->set_m_zone(this->get_m_zone()->getzone_left());
        this->set_m_zoneInt(ZONE_WHITE); // le Int qui correspond a la zone
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(4);
        this->printfaitdegats(4);
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
        std::string msg = "[La menace " + m_name + " draine un d'energie a chaque reacteur.]\n"; //TODO
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        m_zone->retarderactionZone();
        m_zone->getzone_right()->retarderactionZone();
        m_zone->getzone_left()->retarderactionZone();
        std::string msg = "[La menace " + m_name + " retarde tous les joueurs.]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(1);
        m_zone->getzone_right()->getdegatsIgnoreBouclier(1);
        m_zone->getzone_left()->getdegatsIgnoreBouclier(1);
        std::string msg = "[La menace " + m_name + " inflige 1 degats sur toutes les zones...]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
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
        std::string msg = "[La menace " + m_name + "inflige " + std::to_string(degats) + " degats a la " + m_zone->getz_nom_zone() + ".]\n";
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        int energie = this->m_zone->getz_capsule_energie() - 1;
        if(energie < 0)
            energie = 0;
        this->m_zone->setz_capsule_energie(energie);
        std::string msg = "[La menace " + m_name + " consume 1 capsule de carburant, il en reste " + std::to_string(this->m_zone->getz_capsule_energie()) + " .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(3);
        this->printfaitdegats(3);
    }
    else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_i2_06::actionQuandDetruit()
{
   m_zone->getzone_right()->assomerjoueursZoneBas();
   m_zone->getzone_left()->assomerjoueursZoneBas();
   std::string msg = "[Les joueurs en bas des Zones Bleu et Rouge sont assomes par " + m_name + ".]\n";
   std::cout << msg;
   m_zone->getz_data()->VoixRobot1->announce(msg);
}

void menace_interne_si1_01::actionMenace(char input)
{
    if (input == 'X')
    {
        this->set_m_Positionhaut(1);
        std::string msg = "[La menace " + m_name + " monte en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        if(get_m_vie() < get_m_max_vie())
        {
            this->set_m_zone(this->get_m_zone()->getzone_right());
            this->set_m_zoneInt(ZONE_WHITE); // le Int qui correspond a la zone
            std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
            std::cout << msg;
            m_zone->getz_data()->VoixRobot1->announce(msg);
        }
        else
        {
            m_zone->getdegatsIgnoreBouclier(2);
            this->printfaitdegats(2);
        }

    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(4);
        m_zone->assomerjoueursZoneHaut();
        std::string msg = "[La menace " + m_name + " inflige 4 degats a la " + m_zone->getz_nom_zone() + " et assome les joueurs qui y sont presents a son niveau .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
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
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        if(get_m_vie() < get_m_max_vie())
        {
            this->set_m_zone(this->get_m_zone()->getzone_left());
            this->set_m_zoneInt(ZONE_WHITE); // le Int qui correspond a la zone
            std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
            std::cout << msg;
            m_zone->getz_data()->VoixRobot1->announce(msg);
        }
        else
        {
            m_zone->getdegatsIgnoreBouclier(2);
            this->printfaitdegats(2);
        }

    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(4);
        m_zone->assomerjoueursZoneBas();
        std::string msg = "[La menace " + m_name + " inflige 4 degats a la " + m_zone->getz_nom_zone() + " et assome les joueurs qui y sont presents a son niveau.]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
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
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        this->set_m_Positionhaut(1);
        int joueurCount(0);
        std::vector<joueur*>::iterator it;
        for (it = m_zone->getz_joueurs_haut_vec().begin(); it != m_zone->getz_joueurs_haut_vec().end(); it++)
        {
            joueurCount++;
        }
        m_zone->getdegatsIgnoreBouclier(joueurCount);
        std::string msg = "[La menace " + m_name + " monte en " + m_zone->getz_nom_zone() + " et inflige " + std::to_string(joueurCount) + " degats.]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Z') {
        std::string msg = "[La menace " + m_name + " s empare du vaisseau !!!! YOU LOSE !!!!!]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_si1_04::actionMenace(char input)
{
    if (input == 'X')
    {
        m_zone->setz_degats_doubles(true);
        std::string msg = "[Tant que la menace " + m_name + " est presente, les degats en zone rouge sont doubles!]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        m_zone->getzone_blue()->setz_degats_doubles(true);
        m_zone->getzone_white()->setz_degats_doubles(true);
        std::string msg = "[Tant que la menace " + m_name + " est presente, les degats sur tout le vaisseau sont doubles!]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Z') {
        std::string msg = "[La menace " + m_name + " emporte et detruit le vaisseau en piece detachees... YOU LOSE !!!!!]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_si1_04::actionQuandDetruit()
{
    m_zone->getzone_blue()->setz_degats_doubles(false);
    m_zone->getzone_white()->setz_degats_doubles(false);
    m_zone->setz_degats_doubles(false);
    std::string msg = "[La menace " + m_name + " est elimine! Les degats recu par le vaisseau ne sont plus doubles!]\n";
    std::cout << msg;
    m_zone->getz_data()->VoixRobot1->announce(msg);
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
            std::string msg = "[La menace " + m_name + " transfere l'energie du reacteur central au bouclier, le sruplus se volatilise et cause "
            + std::to_string(EnergieBouclier - m_zone->getz_max_energie_bouclier()) + " degats.]\n";
            std::cout << msg;
            m_zone->getz_data()->VoixRobot1->announce(msg);
        }
        else
        {
            m_zone->setz_bouclier(EnergieBouclier);
            std::string msg = "[La menace " + m_name + " transfere l'energie du reacteur central au bouclier sans causer de degats.]\n ";
            std::cout << msg;
            m_zone->getz_data()->VoixRobot1->announce(msg);
        }

    }
    else if (input == 'Y')
    {
        int EnergieReacteur = m_zone->getz_reacteur();
        m_zone->setz_reacteur(0);
        m_zone->getdegatsIgnoreBouclier(EnergieReacteur);
        std::string msg = "[La menace " + m_name + " fait se volatiliser l'energie du reacteur, causant " + std::to_string(EnergieReacteur) + " degats.]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
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
        std::string msg = "[La menace " + m_name + " fait se volatiliser l'energie du reacteur, causant "
        + std::to_string(EnergieReacteur) + " degats a la " + m_zone->getz_nom_zone() + ", " +
        std::to_string(EnergieReacteurR) + " degats a la " + m_zone->getzone_right()->getz_nom_zone() + ", " +
        std::to_string(EnergieReacteurL) + " degats a la " + m_zone->getzone_left()->getz_nom_zone() +
        ".]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
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
        m_zone->getz_data()->VoixRobot1->announce(msg);
        m_zone->getzone_right()->assomerjoueursZoneRobotsActifs();
        m_zone->getzone_left()->assomerjoueursZoneRobotsActifs();
        m_zone->assomerjoueursZoneRobotsActifs();
    }
    else if (input == 'Y')
    {
        std::string msg = "[La menace " + m_name + " assome tous les joueurs present en zone bleu haute et en zone basse rouge.]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
        m_zone->assomerjoueursZoneBas();
        m_zone_bis->assomerjoueursZoneHaut();
    }
    else if (input == 'Z') {
        std::string msg = "[La menace " + m_name + " assome tous les joueurs qui ne sont pas sur la passerelle (zone blanche haute).]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
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
    m_degats_str += "[" + joueur->getj_nom() + " attaque la menace interne " + m_name + " et lui inflige un degat!]\n";
    m_degats++;
    if (m_degats_tour_zone != joueur->getj_zone() && m_degats_tour_zone != 0)
    {
        m_degats_str += "[Vous avez infliges un degat a la menace " + m_name + " dans chaque zone ou elle se trouve lors du meme tour!.]\n";
        m_degats_str += "[--> +1 degats!!!]\n";
        m_degats++;
    }
    m_degats_tour_zone = joueur->getj_zone();
}

void menace_interne_si1_06::getDamageHero(joueur *joueur)
{
    m_degats_str += "[ACTION HEROIQUE! " + joueur->getj_nom() + " attaque la menace interne " + m_name + " et lui inflige deux degat!]\n";
    m_degats++;
    m_degats++;
    if (m_degats_tour_zone != joueur->getj_zone() && m_degats_tour_zone != 0)
    {
        m_degats_str += "[Vous avez infliges un degat a la menace " + m_name + " dans chaque zone ou elle se trouve lors du meme tour!.]\n";
        m_degats_str += "[--> +1 degats!!!]\n";
        m_degats++;
    }
    m_degats_tour_zone = joueur->getj_zone();
}

void menace_interne_si1_06::effetDebutTour()
{
    m_degats_tour_zone = 0;
}


void menace_interne_si2_01::actionMenace(char input)
{
   if (input == 'X')
    {
        this->set_m_zone(this->get_m_zone()->getzone_left());
        this->set_m_zoneInt(ZONE_WHITE); // le Int qui correspond a la zone
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
        this->set_m_Positionhaut(0);
        std::string msg = "[La menace " + m_name + " descend en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(3);
        this->printfaitdegats(3);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_interne_si2_01::effetApresMvt()
{
    if(m_position_haut)
         m_zone->assomerjoueursZoneHaut_IfNoActifRobot();
    else
        m_zone->assomerjoueursZoneBas_IfNoActifRobot();

}

// deplace le menace vers la bonne direction
void menace_interne::manaceMoveInZone(std::string string)
{
    if(string == "Left")
    {
        this->set_m_zone(this->get_m_zone()->getzone_left());
        if(get_m_zoneInt() == ZONE_BLUE)
            this->set_m_zoneInt(ZONE_WHITE); // le Int qui correspond a la zone
        else if(get_m_zoneInt() == ZONE_WHITE)
            this->set_m_zoneInt(ZONE_RED); // le Int qui correspond a la zone
        else
            wr("Chelou, je peux pas bouger plus a gauche\n");
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if(string == "Right")
    {
        this->set_m_zone(this->get_m_zone()->getzone_right());
        if(get_m_zoneInt() == ZONE_RED)
            this->set_m_zoneInt(ZONE_WHITE); // le Int qui correspond a la zone
        else if(get_m_zoneInt() == ZONE_WHITE)
            this->set_m_zoneInt(ZONE_BLUE); // le Int qui correspond a la zone
        else
            wr("Chelou, je peux pas bouger plus a gauche\n");
        std::string msg = "[La menace " + m_name + " va en " + m_zone->getz_nom_zone() + " .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if(string == "Up/Down")
    {
        this->set_m_Positionhaut(!m_position_haut);
        std::string msg = "[La menace " + m_name + " chagne de niveau .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }

}


void menace_interne_si2_02::actionMenace(char input)
{
    // std::cout << "Le move est :!!!!!\n";
    std::string move = m_zone->stationWithMostPlayer(m_position_haut, m_zoneInt);
    // std::cout << "Le move est :" << move << "!!!!!\n";
    if (input == 'X')
    {
        manaceMoveInZone(move);
    }
    else if (input == 'Y')
    {
        manaceMoveInZone(move);
    }
    else if (input == 'Z') {
        m_zone->getdegatsIgnoreBouclier(5);
        if(m_position_haut)
            m_zone->assomerjoueursZoneHaut();
        else
            m_zone->assomerjoueursZoneBas();
        std::string msg = "[La menace " + m_name + " inflige 5 degats a la " + m_zone->getz_nom_zone() + " et assome les joueurs de sa station .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}


void menace_interne_si2_03::actionMenace(char input)
{
    int z_reacteur = 0;
    if (input == 'X')
    {

        z_reacteur = m_zone->getzone_white()->getz_reacteur() - 2;
        if (z_reacteur < 0)
            z_reacteur = 0;
        m_zone->getzone_white()->setz_reacteur(z_reacteur);
        std::string msg = "[La menace " + m_name + " consume 2 blocs d'energie du reacteur central, il en reste " + std::to_string(m_zone->getzone_white()->getz_reacteur())
        + " .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Y')
    {
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
        std::string msg = "[La menace " + m_name + " consume 1 blocs d'energie de chaque reacteur, il en reste "
        + std::to_string(m_zone->getzone_white()->getz_reacteur()) + "dans la " + m_zone->getzone_white()->getz_nom_zone() + ", "
        + std::to_string(m_zone->getzone_red()->getz_reacteur()) + "dans la " + m_zone->getzone_red()->getz_nom_zone() + ", et "
        + std::to_string(m_zone->getzone_blue()->getz_reacteur()) + "dans la " + m_zone->getzone_blue()->getz_nom_zone()
        + " .]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
    }
    else if (input == 'Z') {
        std::string msg = "[La menace " + m_name + " inflige 3 degats a chaque zones.]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
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
    m_degats_str += "[" + joueur->getj_nom() + " attaque la menace interne " + m_name + " et lui inflige un degat!]\n";
    if (joueur->getj_zone() == ZONE_BLUE)
        m_degats_zone_blue = 1;
    else if (joueur->getj_zone() == ZONE_RED)
        m_degats_zone_red = 1;
    else if (joueur->getj_zone() == ZONE_WHITE)
        m_degats_zone_white = 1;
    if (m_degats_zone_blue + m_degats_zone_red + m_degats_zone_white == 3)
    {
        m_degats_str += "[Vous avez infliges un degat a la menace " + m_name + " dans chaque zone ou elle se trouve lors du meme tour!.]\n";
        m_degats_str += "[--> +2 degats!!!]\n";
        m_degats += 2;
    }
    m_degats++;
}

void menace_interne_si2_03::getDamageHero(joueur *joueur)
{
    m_degats_str += "[ACTION HEROIQUE! " + joueur->getj_nom() + " attaque la menace interne " + m_name + " et lui inflige deux degat!]\n";
    if (joueur->getj_zone() == ZONE_BLUE)
        m_degats_zone_blue = 1;
    else if (joueur->getj_zone() == ZONE_RED)
        m_degats_zone_red = 1;
    else if (joueur->getj_zone() == ZONE_WHITE)
        m_degats_zone_white = 1;
    if (m_degats_zone_blue + m_degats_zone_red + m_degats_zone_white == 3)
    {
        m_degats_str += "[Vous avez infliges un degat a la menace " + m_name + " dans chaque zone ou elle se trouve lors du meme tour!.]\n";
        m_degats_str += "[--> +2 degats!!!]\n";
        m_degats += 2;
    }
    m_degats++;
    m_degats++;
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
        m_zone->getz_data()->VoixRobot1->announce(msg);
        if (m_contamination_blue_haut)
        {
            msg = "[Les joueurs en zone bleu haut sont retardes.]\n";
            std::cout << msg;
            m_zone->getz_data()->VoixRobot1->announce(msg);
            m_zone->getzone_blue()->retarderactionZoneHaut();
        }
        if (m_contamination_blue_bas)
        {
            msg = "[Les joueurs en zone bleu bas sont retardes.]\n";
            std::cout << msg;
            m_zone->getz_data()->VoixRobot1->announce(msg);
            m_zone->getzone_blue()->retarderactionZoneBas();
        }
        if (m_contamination_red_haut)
        {
            msg = "[Les joueurs en zone rouge haut sont retardes.]\n";
            std::cout << msg;
            m_zone->getz_data()->VoixRobot1->announce(msg);
            m_zone->getzone_red()->retarderactionZoneHaut();
        }
        if (m_contamination_red_bas)
        {
            msg = "[Les joueurs en zone rouge bas sont retardes.]\n";
            std::cout << msg;
            m_zone->getz_data()->VoixRobot1->announce(msg);
            m_zone->getzone_red()->retarderactionZoneBas();
        }
    }
    else if (input == 'Y')
    {
        std::string msg = "[La menace " + m_name + " inflige 1 degat dans chaque zone contaminee.]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
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
            m_zone->getz_data()->VoixRobot1->announce(msg);
            m_zone->getzone_blue()->assomerjoueursZoneHaut();
        }
        if (m_contamination_blue_bas)
        {
            msg = "[Les joueurs en zone bleu bas sont assomes.]\n";
            std::cout << msg;
            m_zone->getz_data()->VoixRobot1->announce(msg);
            m_zone->getzone_blue()->assomerjoueursZoneBas();
        }
        if (m_contamination_red_haut)
        {
            msg = "[Les joueurs en zone rouge haut sont assomes.]\n";
            std::cout << msg;
            m_zone->getz_data()->VoixRobot1->announce(msg);
            m_zone->getzone_red()->assomerjoueursZoneHaut();
        }
        if (m_contamination_red_bas)
        {
            msg = "[Les joueurs en zone rouge bas sont assomes.]\n";
            std::cout << msg;
            m_zone->getz_data()->VoixRobot1->announce(msg);
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
            m_degats++;
            m_degats_str += "[" + joueur->getj_nom() + " attaque la menace interne " + m_name + " en station haute bleu et decontamine la station!]\n";
            m_contamination_blue_haut = false;
        }
    }
    else if (m_zone->getzone_blue()->getz_joueur_bas(joueur->getj_nom()))
    {
        if (m_contamination_blue_bas)
        {
            m_degats++;
            m_degats_str += "[" + joueur->getj_nom() + " attaque la menace interne " + m_name + " en station basse bleu et decontamine la station!]\n";
            m_contamination_blue_bas = false;
        }
    }
    else if (m_zone->getzone_red()->getz_joueur_haut(joueur->getj_nom()))
    {
        if (m_contamination_red_haut)
        {
            m_degats++;
            m_degats_str += "[" + joueur->getj_nom() + " attaque la menace interne " + m_name + " en station haute rouge et decontamine la station!]\n";
            m_contamination_red_haut = false;
        }
    }
    else if (m_zone->getzone_red()->getz_joueur_bas(joueur->getj_nom()))
    {
        if (m_contamination_red_bas)
        {
            m_degats++;
            m_degats_str += "[" + joueur->getj_nom() + " attaque la menace interne " + m_name + " en station basse rouge et decontamine la station!]\n";
            m_contamination_red_bas = false;
        }
    }
}

void menace_interne_si2_04::getDamageHero(joueur *joueur)
{
    if (m_zone->getzone_blue()->getz_joueur_haut(joueur->getj_nom()))
    {
        if (m_contamination_blue_haut)
        {
            m_degats++;
            m_degats++;
            m_degats_str += "[ACTION HEROIQUE! " + joueur->getj_nom() + " attaque la menace interne " + m_name + " en station haute bleu et decontamine la zone entiere!]\n";
            m_contamination_blue_haut = false;
            m_contamination_blue_bas = false;
        }
    }
    else if (m_zone->getzone_blue()->getz_joueur_bas(joueur->getj_nom()))
    {
        if (m_contamination_blue_bas)
        {
            m_degats++;
            m_degats++;
            m_degats_str += "[ACTION HEROIQUE! " + joueur->getj_nom() + " attaque la menace interne " + m_name + " en station basse bleu et decontamine la zone entiere!]\n";
            m_contamination_blue_haut = false;
            m_contamination_blue_bas = false;
        }
    }
    else if (m_zone->getzone_red()->getz_joueur_haut(joueur->getj_nom()))
    {
        if (m_contamination_red_haut)
        {
            m_degats++;
            m_degats++;
            m_degats_str += "[ACTION HEROIQUE! " + joueur->getj_nom() + " attaque la menace interne " + m_name + " en station haute rouge et decontamine la zone entiere!]\n";
            m_contamination_red_haut = false;
            m_contamination_red_bas = false;
        }
    }
    else if (m_zone->getzone_red()->getz_joueur_bas(joueur->getj_nom()))
    {
        if (m_contamination_red_bas)
        {
            m_degats++;
            m_degats++;
            m_degats_str += "[ACTION HEROIQUE! " + joueur->getj_nom() + " attaque la menace interne " + m_name + " en station basse rouge et decontamine la zone entiere!]\n";
            m_contamination_red_haut = false;
            m_contamination_red_bas = false;
        }
    }
}

void menace_interne_si2_05::actionMenace(char input)
{
    if (input == 'X')
    {
        std::string msg = "[La menace " + m_name + " augmente sa vitesse de 1!]\n";
        m_zone->getz_data()->VoixRobot1->announce(msg);
        m_vitesse++;
    }
    else if (input == 'Y')
    {
        std::string msg = "[La menace " + m_name + " augmente sa vitesse de 1!]\n";
        m_zone->getz_data()->VoixRobot1->announce(msg);
        m_vitesse++;
    }
    else if (input == 'Z') {
        std::string msg = "[La menace " + m_name + " detruit le vaisseaux. FUUUUUCCCKKK]\n";
        std::cout << msg;
        m_zone->getz_data()->VoixRobot1->announce(msg);
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
        m_degats_str += "[Vous avez infliges 3 degat a la menace " + m_name + " pendant le meme tour!! Elle prends donc 1 degats et meurt!]\n";
        m_degats++;
    }
    else
    {
        m_degats_str += "[" + joueur->getj_nom() + " attaque la menace interne " + m_name + "]\n" + "[" + std::to_string(3 - m_degats_par_tour) + " attaque(s) de plus lors de ce tour et la menace prendra un degat.]\n";
    }
}

void menace_interne_si2_05::getDamageHero(joueur *joueur)
{
    joueur->setj_bots(joueur->getj_bots()); // pour eviter probleme de compilation
    m_degats_par_tour++;
    m_degats_par_tour++;
    if (m_degats_par_tour == 3)
    {
        m_degats_str += "[Vous avez infliges 3 degat a la menace " + m_name + " pendant le meme tour!! Elle prends donc 1 degats et meurt!]\n";
        m_degats++;
    }
    else
    {
        m_degats_str += "[ACTION HEROIQUE! " + joueur->getj_nom() + " attaque la menace interne " + m_name + "]\n" + "[" + std::to_string(3 - m_degats_par_tour) + " attaque(s) de plus lors de ce tour et la menace prendra un degat.]\n";
    }
}

void menace_interne_si2_05::effetDebutTour()
{
    m_degats_par_tour = 0;
}
