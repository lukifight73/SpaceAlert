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

void zone::etatdesdegats()
{
	z_degats_recu++;
	int degat = z_ordre_degats[z_degats_recu];
	if (degat == 1)
	{
		wr("[Le vaisseau a recu des degats mais ils sont negligeables!]");
	}
	else if (degat == 2)
	{
		std::cout << "[Le vaisseau a recu des degats et l'ascenseur de la " << z_nom_zone << " est endommage !]\n";
		this->removez_actions_bas(DIR_A);
		this->removez_actions_haut(DIR_A);
	}
	else if (degat == 3)
	{
		std::cout << "[Le vaisseau a recu des degats et le canon lazer lourd de la " << z_nom_zone << " est endommage !]\n";
		z_cannon_haut->setpuissance_cannon(z_cannon_haut->getpuissance_cannon() - 1);
		std::cout << "[Ce canon lourd a desormais une puissance de " << z_cannon_haut->getpuissance_cannon() << " !]\n";
	}
	else if (degat == 4)
	{
		std::cout << "[Le vaisseau a recu des degats et le reacteur de la " << z_nom_zone << " est endommage !]\n";
		z_max_reacteur--;
		if (z_reacteur > z_max_reacteur)
		{
			z_reacteur = z_max_reacteur;
		}
		std::cout << "[Ce reacteur a desormais une capacite de " << z_max_reacteur << " !]\n";
	}
	else if (degat == 5)
	{
		std::cout << "[Le vaisseau a recu des degats et le bouclier de la " << z_nom_zone << " est endommage !]\n";
		z_max_energie_bouclier--;
		if (z_bouclier > z_max_energie_bouclier)
		{
			z_bouclier = z_max_energie_bouclier;
		}
		std::cout << "[Ce bouclier a desormais une capacite de " << z_max_reacteur << " !]\n";
	}
	else
	{
		if (z_zone == ZONE_WHITE)
		{
			std::cout << "[Le vaisseau a recu des degats et le canon a impulsion de la " << z_nom_zone << " est endommage !]\n";
			z_cannon_bas->setportee_cannon(z_cannon_bas->getportee_cannon() - 5);
			std::cout << "[Ce canon leger a desormais une portee de " << z_cannon_bas->getportee_cannon() << " !]\n";
		}
		else
		{
			std::cout << "[Le vaisseau a recu des degats et le canon laser leger de la " << z_nom_zone << " est endommage !]\n";
			z_cannon_bas->setpuissance_cannon(z_cannon_bas->getpuissance_cannon() - 1);
			std::cout << "[Ce canon leger a desormais une puissance de " << z_cannon_bas->getpuissance_cannon() << " !]\n";
		}
	}
}

void zone::getdegats(int input)
{
	while (z_bouclier > 0 && input > 0)
	{
		z_bouclier --;
		input--;
	}
	while (input > 0)
		etatdesdegats();
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

std::vector<int> zone::getz_maintenance_ordinateur() const
{
	return z_maintenance_ordinateur;
}

std::vector<int> zone::getz_observations() const
{
	return z_observations;
}

void zone::addz_maintenance_ordinateur(int input)
{
	z_maintenance_ordinateur.push_back(input);
}

void zone::addz_observations(int input)
{
	z_observations.push_back(input);
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