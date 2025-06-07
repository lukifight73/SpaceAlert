#include "zone.hpp"

void zone::addtemps()
{
	z_temps++;
}

void zone::addz_joueurs_bas(joueur* input)
{
	z_joueurs_bas.push_back(input);
}

void zone::addz_joueurs_haut(joueur* input)
{
	z_joueurs_haut.push_back(input);
}

void zone::removez_joueurs_haut(std::string input)
{
	for (std::vector<joueur*>::iterator it = z_joueurs_haut.begin(); it != z_joueurs_haut.end();)
	{
		if (!*it)
		{
			it = z_joueurs_haut.erase(it);
			continue;
		}
		if (z_joueurs_haut.size() == 0)
		{
			return;
		}
        if ((*it)->getj_nom() == input)
		{
            it = z_joueurs_haut.erase(it);
		}
        else
            ++it;
    }
}

void zone::removez_joueurs_bas(std::string input)
{
	for (std::vector<joueur*>::iterator it = z_joueurs_bas.begin(); it != z_joueurs_bas.end();)
	{
		if (!*it)
		{
			it = z_joueurs_bas.erase(it);
			continue;
		}
		if (z_joueurs_bas.size() == 0)
		{
			return;
		}
        if ((*it)->getj_nom() == input)
            it = z_joueurs_bas.erase(it);
        else
            ++it;
    }
}

joueur* zone::getz_joueur_bas(std::string nom)
{
	std::vector<joueur*>::iterator it;

	for (it = z_joueurs_bas.begin(); it != z_joueurs_bas.end();)
	{
        if ((*it)->getj_nom() == nom)
            return *it;
        else
            ++it;
    }
	return (NULL);
}

joueur* zone::getz_joueur_haut(std::string nom)
{
	std::vector<joueur*>::iterator it;

	for (it = z_joueurs_haut.begin(); it != z_joueurs_haut.end();)
	{
        if ((*it)->getj_nom() == nom)
		{
			return *it;
		}
        else
            ++it;
    }
	return (NULL);
}

void zone::addz_actions_haut(int input)
{
	z_actions_haut.push_back(input);
}

void zone::removez_actions_haut(int input)
{
	z_actions_haut.erase(std::remove(z_actions_haut.begin(), z_actions_haut.end(), input), z_actions_haut.end());
}

void zone::removez_actions_bas(int input)
{
	z_actions_bas.erase(std::remove(z_actions_bas.begin(), z_actions_bas.end(), input), z_actions_bas.end());
}

void zone::addz_actions_used_ce_tour_haut(int input)
{
	z_actions_used_ce_tour_haut.push_back(input);
}

void zone::clearz_actions_used_ce_tour_haut()
{
	z_actions_used_ce_tour_haut.clear();
}

void zone::clearz_cannon_used() 
{
	z_cannon_used.clear();
}

void zone::addz_cannon_used(cannon* input)
{
	z_cannon_used.push_back(input);
}

void zone::addz_actions_bas(int input)
{
	z_actions_bas.push_back(input);
}

void zone::addz_actions_used_ce_tour_bas(int input)
{
	z_actions_used_ce_tour_bas.push_back(input);
}

void zone::clearz_actions_used_ce_tour_bas()
{
	z_actions_used_ce_tour_bas.clear();
}

void zone::printZone() 
{
	wr("--------- ZONE START---------");
	wr("Zone : " + z_nom_zone);
	std::cout << "Temps : " << z_temps << std::endl;
	std::cout << "Capsule d'energie : " << z_capsule_energie << std::endl;
	std::cout << "Reacteur : " << z_reacteur << "/ " << z_max_reacteur << std::endl;
	std::cout << "Capsule d'energie : " << z_capsule_energie << std::endl;
	wr("Joueur en jeu : " + z_joueur_playing);
	wr("chemin_menace : " + z_chemin_menace->get_ch_nom());
	wr("Menaces : " + z_chemin_menace->get_menaces()[0]->get_m_name());
	wr("--------- ZONE END---------");
}