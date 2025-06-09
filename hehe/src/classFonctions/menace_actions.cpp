#include "menace.hpp"
#include "menace_externe.hpp"

//Actions des menaces externes serieuses


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

void menace_se1_02::actionMenace(char input) 
{
    if (input == 'X') {
        makedegatsInZone(1);
        std::cout << "[ " << m_name << " lance une attaque de puissance 1!]" << std::endl;
        m_vitesse++;
        std::cout << "[ " << m_name << " augmente sa vitesse de 1!]" << std::endl;
    } else if (input == 'Y') {
        makedegatsInZone(3);
        std::cout << "[ " << m_name << " lance une attaque de puissance 3!]" << std::endl;
        m_bouclier++;
        std::cout << "[ " << m_name << " augmente son blindage de 1!]" << std::endl;
    } else if (input == 'Z') {
        makedegatsInZone(5);
        std::cout << "[ " << m_name << " lance une attaque de puissance 5!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se1_03::actionMenace(char input) 
{
    if (input == 'X') {
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
        m_vitesse += 2;
        std::cout << "[ " << m_name << " augmente sa vitesse de 2!]" << std::endl;
    } else if (input == 'Y') {
        makedegatsInZone(3);
        std::cout << "[ " << m_name << " lance une attaque de puissance 3!]" << std::endl;
        m_vitesse += 2;
        std::cout << "[ " << m_name << " augmente sa vitesse de 2!]" << std::endl;
    } else if (input == 'Z') {
        makedegatsInZone(7);
        std::cout << "[ " << m_name << " lance une attaque de puissance 7!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se1_04::actionMenace(char input) 
{
    if (input == 'X') {
        makedegatsInZone(1);
        makedegatsLeft(1);
        makedegatsRight(1);
        std::cout << "[ " << m_name << " lance une attaque de puissance 1 sur chaque zone!]" << std::endl;
    } else if (input == 'Y') {
        makedegatsInZone(2);
        makedegatsLeft(2);
        makedegatsRight(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2 sur chaque zone!]" << std::endl;
    } else if (input == 'Z') {
        makedegatsInZone(3);
        makedegatsLeft(3);
        makedegatsRight(3);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2 sur chaque zone!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se1_03::actionQuandDetruit() 
{
    std::vector<menace *> menaces = m_zone->getzone_left()->getz_chemin_menace()->get_menaces();
    
    std::vector<menace *>::iterator it;
    for (it = menaces.begin(); it != menaces.end(); ++it) 
    {
        if ((*it)->get_m_presence() && (*it)->get_m_etat_bouclier() <= 0) 
        {
            (*it)->recoitDegats(1); // fait un degats si pas de bouclier
            if ((*it)->get_m_vie() <= 0) 
            {
                (*it)->set_m_presence(false);
                (*it)->actionQuandDetruit();
            }
        }
    }
    menaces = m_zone->getzone_right()->getz_chemin_menace()->get_menaces();
    for (it = menaces.begin(); it != menaces.end(); ++it) 
    {
        if ((*it)->get_m_presence() && (*it)->get_m_etat_bouclier() <= 0) 
        {
            (*it)->recoitDegats(1); // fait un degats si pas de bouclier
            if ((*it)->get_m_vie() <= 0) 
            {
                (*it)->set_m_presence(false);
                (*it)->actionQuandDetruit();
            }
        }
    }
    menaces = m_zone->getz_chemin_menace()->get_menaces();
    for (it = menaces.begin(); it != menaces.end(); ++it) 
    {
        if ((*it)->get_m_presence() && (*it)->get_m_etat_bouclier() <= 0) 
        {
            (*it)->recoitDegats(1); // fait un degats si pas de bouclier
            if ((*it)->get_m_vie() <= 0) 
            {
                (*it)->set_m_presence(false);
                (*it)->actionQuandDetruit();
            }
        }
    }
    std::cout << "[La menace " << m_name << " a été détruite. Elle inflige 1 point de dégâts aux menaces presentes.]\n";
}

void menace_se1_08::actionMenace(char input) 
{
    if (input == 'Z') {
        int degats = get_m_vie();
        makedegatsInZone(degats);
        std::cout << "[ " << m_name << " lance une attaque de puissance " << degats << "!]" << std::endl;
    } 
    else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se1_05::actionMenace(char input) 
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

void menace_se1_08::actionQuandDetruit() 
{
    int itemCrossed = (checkNombreInputCrossed('X') + checkNombreInputCrossed('Y')) * 2; // Dégâts infligés en fonction des actions croisées
    makedegatsInZone(itemCrossed);
    std::cout << "[La menace " << m_name << " a été détruite. Elle inflige " << itemCrossed << " points de dégâts!]\n";
}

//Actions des menaces externes serieuses avancees

void menace_se2_02::actionMenace(char input) 
{
    if (input == 'X') {
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
        m_vitesse += 2;
        std::cout << "[ " << m_name << " augmente sa vitesse de 2!]" << std::endl;
    } else if (input == 'Y') {
        makedegatsInZone(3);
        std::cout << "[ " << m_name << " lance une attaque de puissance 3!]" << std::endl;
        m_vitesse += 2;
        std::cout << "[ " << m_name << " augmente sa vitesse de 2!]" << std::endl;
    } else if (input == 'Z') {
        makedegatsInZone(7);
        std::cout << "[ " << m_name << " lance une attaque de puissance 7!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se2_03::actionMenace(char input) 
{
    if (input == 'X') {
        m_zone->retarderactionZone();
        std::cout << "[ " << m_name << " attaque et retarde tous les joueurs de la " << m_zone->getz_nom_zone() << std::endl;
    } else if (input == 'Y') {
        m_zone->retarderactionZone();
        m_zone->getzone_right()->retarderactionZone();
        m_zone->getzone_left()->retarderactionZone();
        std::cout << "[ " << m_name << " attaque et retarde tous les joueurs du vaisseau" << std::endl;
    } else if (input == 'Z') {
        m_zone->assomerjoueursZone();
        m_zone->getzone_right()->assomerjoueursZone();
        m_zone->getzone_left()->assomerjoueursZone();
        std::cout << "[ " << m_name << " attaque et assome tous les joueurs du vaisseau!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}


void menace_se2_04::actionMenace(char input) 
{
    if (input == 'X') {
        m_bouclier = 4;
        std::cout << "[ " << m_name << " augmente son blindage a 4!]" << std::endl;
    } else if (input == 'Y') {
        m_bouclier = 2;
        std::cout << "[ " << m_name << " augmente son blindage a 2!]" << std::endl;
        m_vitesse += 2;
        std::cout << "[ " << m_name << " augmente sa vitesse de 2!]" << std::endl;
    } else if (input == 'Z') {
        makedegatsInZone(5);
        std::cout << "[ " << m_name << " lance une attaque de puissance 5!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se2_05::actionMenace(char input)
{
    if (input == 'X') {
        makedegatsInZone(1);
        if(get_m_etat_bouclier() <= 0)
        {
            set_m_vie(get_m_vie() - 1);
            if (get_m_vie() <= 0) {
                set_m_presence(false);
                actionQuandDetruit();
            }
            std::cout << "[ " << m_name << " s'inflige 1 point de dégâts!]" << std::endl;
        }
        std::cout << "[ " << m_name << " lance une attaque de puissance 1!]" << std::endl;
    } else if (input == 'Y') {
        makedegatsInZone(2);
        if(get_m_etat_bouclier() <= 1)
        {
            set_m_vie(get_m_vie() + get_m_etat_bouclier() - 2);
            if (get_m_vie() <= 0) {
                set_m_presence(false);
                actionQuandDetruit();
            }
            std::cout << "[ " << m_name << " s'inflige " << 2 - get_m_etat_bouclier() << " point de dégâts!]" << std::endl;
        }
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
    } else if (input == 'Z') {
        std::cout << "[ GAME OVER: " << m_name << " vient de detruire le vaisseau!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se2_06::actionMenace(char input) 
{
    if (input == 'Z') {
        int degats = get_m_vie();
        makedegatsInZone(degats);
        std::cout << "[ " << m_name << " lance une attaque de puissance " << degats << "!]" << std::endl;
    } 
    else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_se2_06::actionQuandDetruit() 
{
    int itemCrossed = (checkNombreInputCrossed('X') + checkNombreInputCrossed('Y')) * 3; // Dégâts infligés en fonction des actions croisées
    makedegatsInZone(itemCrossed);
    std::cout << "[La menace " << m_name << " a été détruite. Elle inflige " << itemCrossed << " points de dégâts!]\n";
}



//Actions des menaces externes communes

void menace_e1_01::actionMenace(char input) 
{
    if (input == 'X') {
        makedegatsInZone(1);
        makedegatsLeft(1);
        makedegatsRight(1);
        std::cout << "[ " << m_name << " lance une attaque de puissance 1 sur chaque zone!]" << std::endl;
    } else if (input == 'Y') {
        makedegatsInZone(1);
        makedegatsLeft(1);
        makedegatsRight(1);
        std::cout << "[ " << m_name << " lance une attaque de puissance 1 sur chaque zone!]" << std::endl;
    } else if (input == 'Z') {
        makedegatsInZone(2);
        makedegatsLeft(2);
        makedegatsRight(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2 sur chaque zone!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_02::actionMenace(char input) 
{
    if (input == 'X') {
        if (m_zone->getz_bouclier() > 0) {
            makedegatsInZone(2);
            std::cout << "[ " << m_name << " lance une attaque de puissance 1 (pas de bouclier, attaque x2)!]" << std::endl;
        }
        else {
        makedegatsInZone(1);
        std::cout << "[ " << m_name << " lance une attaque de puissance 1!]" << std::endl;
        }
    }
    else if (input == 'Y') {
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
        if (m_zone->getz_bouclier() == 1) {
            std::cout << "[Le bouclier part un degat, l'autre degat est multiplie par deux!]" << std::endl;
            makedegatsInZone(3);
        }
        else if (m_zone->getz_bouclier() == 0) {
            std::cout << "[Il n'y a pas de bouclier, les degats sont multiplies par deux!]" << std::endl;
            makedegatsInZone(4);
        }
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
    }
    else if (input == 'Z') {
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
        if (m_zone->getz_bouclier() == 1) {
            std::cout << "[Le bouclier part un degat, l'autre degat est multiplie par deux!]" << std::endl;
            makedegatsInZone(3);
        }
        else if (m_zone->getz_bouclier() == 0) {
            std::cout << "[Il n'y a pas de bouclier, les degats sont multiplies par deux!]" << std::endl;
            makedegatsInZone(4);
        }
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_09::actionMenace(char input) 
{
    if (input == 'X') {
        regeneration(2);
        std::cout << "[ " << m_name << " regagne 2 points de vie!]" << std::endl;
    } else if (input == 'Y') {
        regeneration(2);
        std::cout << "[ " << m_name << " regagne 2 points de vie!]" << std::endl;
    } else if (input == 'Z') {
        makedegatsInZone(5);
        std::cout << "[ " << m_name << " lance une attaque de puissance 5!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_03::actionMenace(char input) 
{
    if (input == 'X') {
        set_m_revele(true);
    } else if (input == 'Y') {
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 3!]" << std::endl;
    } else if (input == 'Y') {
        makedegatsInZone(2);
        regeneration(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2 et regagne 2 points de vie!]" << std::endl;
    } else if (input == 'Z') {
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_05::actionMenace(char input) 
{
    if (input == 'X') {
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
    } else if (input == 'Y') {
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
    } else if (input == 'Z') {
        makedegatsInZone(3);
        std::cout << "[ " << m_name << " lance une attaque de puissance 3!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_06::actionMenace(char input) 
{
    if (input == 'X') {
        makedegatsInZone(1);
        std::cout << "[ " << m_name << " lance une attaque de puissance 1!]" << std::endl;
    } else if (input == 'Y') {
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
    } else if (input == 'Z') {
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_07::actionMenace(char input) 
{
    if (input == 'X') {
        makedegatsInZone(1);
        std::cout << "[ " << m_name << " lance une attaque de puissance 1!]" << std::endl;
    } else if (input == 'Y') {
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 2!]" << std::endl;
    } else if (input == 'Z') {
        makedegatsInZone(3);
        std::cout << "[ " << m_name << " lance une attaque de puissance 3!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_08::actionMenace(char input) 
{
    if (input == 'X') {
        makedegatsInZone(1);
        std::cout << "[ " << m_name << " lance une attaque de puissance 1!]" << std::endl;
    }
    else if (input == 'Y') {
        regeneration(1);
        std::cout << "[ " << m_name << " regagne 1 points de vie!]" << std::endl;
    } 
    else if (input == 'Z') {
        makedegatsInZone(4);
        std::cout << "[ " << m_name << " lance une attaque de puissance 4!]" << std::endl;
    }
    else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e1_10::actionMenace(char input) 
{
    if (input == 'X') {

    } else if (input == 'Y') {

    } else if (input == 'Z') {
        makedegatsInZone(m_vie);
        std::cout << "[ " << m_name << " lance une attaque de puissance " << m_vie << "!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

//Actions des menaces externes communes avancees

void menace_e2_03::actionMenace(char input) 
{
    if (input == 'X') {
        set_m_revele(true);
    } else if (input == 'Y') {
        makedegatsInZone(2);
        std::cout << "[ " << m_name << " lance une attaque de puissance 3!]" << std::endl;
    } else if (input == 'Z') {
        makedegatsInZone(3);
        std::cout << "[ " << m_name << " lance une attaque de puissance 3!]" << std::endl;
    } else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}


void menace_e2_07::actionMenace(char input) 
{
    if (input == 'Z') {
        int degats = get_m_vie();
        makedegatsInZone(degats);
        std::cout << "[ " << m_name << " lance une attaque de puissance " << degats << "!]" << std::endl;
    } 
    else {
        std::cerr << "Action inconnue: " << input << std::endl;
    }
}

void menace_e2_07::actionQuandDetruit() 
{
    int itemCrossed = (checkNombreInputCrossed('X') + checkNombreInputCrossed('Y')); // Dégâts infligés en fonction des actions croisées
    makedegatsInZone(itemCrossed);
    std::cout << "[La menace " << m_name << " a été détruite. Elle inflige " << itemCrossed << " points de dégâts!]\n";
}

        
