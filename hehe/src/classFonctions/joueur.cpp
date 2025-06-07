#include "joueur.hpp"
#include "SA_Values.hpp"

joueur::joueur()
{
    j_nom = generateRandomString(5);
	j_state = ACTIF;
    j_bots = NO_BOTS;
    j_zone = ZONE_WHITE;
    j_capitaine = false;
}

joueur::joueur(std::string nom)
{
    j_nom = nom;
	j_state = ACTIF;
    j_bots = NO_BOTS;
    j_zone = ZONE_WHITE;
}
void joueur::print()
{
    std::cout  << "                     ----- JOUEUR ------" << std::endl;
    std::cout << "Je suis " << j_nom << " et je me trouve en ";
    if (j_zone == ZONE_BLUE)
        std::cout << "zone bleue.\n";
    else if (j_zone == ZONE_WHITE)
        std::cout << "zone blanche.\n";
    else if (j_zone == ZONE_RED)
        std::cout << "zone rouge.\n";
    if (j_state == INACTIF)
        std::cout << "Je suis inactif" << std::endl;
    if (j_bots == NO_BOTS)
        std::cout << "Je n'ai pas de robots" << std::endl;
    else if (j_bots == BOTS_EVEILLE)
        std::cout << "J'ai des robots actifs avec moi" << std::endl;
    else if (j_bots == BOTS_INACTIF)
        std::cout << "J'ai des robots inactif avec moi" << std::endl;
}

void joueur::setj_number(int input)
{
    j_number = input;
}

int joueur::getj_number() const
{
    return (j_number);
}

void joueur::setj_state(bool input)
{
    j_state = input;
}

void joueur::setj_capitaine(bool input)
{
    j_capitaine = input;
}
void joueur::setj_bots(int input)
{
    j_bots = input;
}

void joueur::setj_zone(int input)
{
    j_zone = input;
}

//autre
void joueur::addcartes(int input, carte carte)
{
    cartes[input] = carte;
}
void joueur::passerTour(int input)
{
    int i = 12;
    while (i > input + 1)
    {
        cartes[i] = cartes[i - 1];
        i--;
    }
    cartes[i].setc_action(INACTIF);
}

//getters
bool joueur::getj_state()const
{
    return (j_state);
}

int joueur::getj_bots() const
{
    return (j_bots);
}

bool joueur::getj_capitaine() const
{
    return (j_bots);
}

int joueur::getj_zone() const
{
    return (j_zone);
}

std::string joueur::getj_nom() const
{
    return (j_nom);
}

std::map<int, carte> joueur::getcartes() const
{
    return (cartes);
}

joueur::~joueur() {}
