#include "zone.hpp"


chemin_menace* zone::getz_chemin_menace() const {
	return (z_chemin_menace);
}

chemin_menace *zone::getz_chemin_menace_interne() const {
	return (z_chemin_menace_interne);
}

void zone::setzone_white(zone* zone)
{
	zone_white = zone;
}
void zone::setzone_red(zone* zone)
{
	zone_red = zone;
}

void zone::setzone_blue(zone* zone)
{
	zone_blue = zone;
}

void zone::setzone_right(zone* zone)
{
	zone_right = zone;
}

void zone::setzone_left(zone* zone)
{
	zone_left = zone;
}

void zone::setcannon_haut(cannon *input)
{
	cannon_haut = input;
}

void zone::setcannon_bas(cannon *input)
{
	cannon_bas = input;
}

void zone::setz_nom_zone(std::string input)
{
	z_nom_zone = input;
}

void zone::setz_chemin(chemin_menace *input)
{
	z_chemin_menace = input;
}

void zone::setz_bots(bool input)
{
	z_bots = input;
}

void zone::setz_zone(int input)
{
	z_zone = input;
}

void zone::setz_temps(int input)
{
	z_temps = input;
}

void zone::setz_capsule_energie(int input)
{
	z_capsule_energie = input;
}

void zone::setz_reacteur(int input)
{
	z_reacteur = input;
}

void zone::setz_max_energie_reservoir(int input)
{
	z_max_reacteur = input;
}

void zone::setz_bouclier(int input)
{
	z_bouclier = input;
}

void zone::setz_max_energie_bouclier(int input)
{
	z_max_energie_bouclier = input;
}

void zone::setz_ascenseur(bool input)
{
	z_ascenseur = input;
}

void zone::setz_joueur_playing(std::string input)
{
	z_joueur_playing = input;
}

int zone::gettemps() const
{
	return (z_temps);
}

int zone::getz_reacteur() const
{
	return (z_reacteur);
}

int zone::getz_max_energie_reservoir() const
{
	return (z_max_reacteur);
}

int zone::getz_capsule_energie() const
{
	return (z_capsule_energie);
}

bool zone::getz_bots() const
{
	return (z_bots);
}

int zone::getz_bouclier() const
{
	return (z_bouclier);
}

int zone::getz_max_energie_bouclier() const
{
	return (z_max_energie_bouclier);
}

std::vector<cannon*> zone::getz_cannon_used() const
{
	return (z_cannon_used);
}

std::string zone::getz_joueur_playing() const
{
	return (z_joueur_playing);
}

std::vector<joueur*> zone::getz_joueurs_bas() const
{
	return (z_joueurs_bas);
}

std::vector<int>    zone::getz_actions_bas() const
{
	return (z_actions_bas);
}

std::vector<int>    zone::getz_actions_used_ce_tour_bas() const
{
	return (z_actions_used_ce_tour_bas);
}

std::vector<joueur*> zone::getz_joueurs_haut() const
{
	return (z_joueurs_haut);
}

std::vector<int>    zone::getz_actions_haut() const
{
	return (z_actions_haut);
}

std::vector<int>    zone::getz_actions_used_ce_tour_haut() const
{
	return (z_actions_used_ce_tour_haut);
}