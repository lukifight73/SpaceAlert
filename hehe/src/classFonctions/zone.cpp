#include "zone.hpp"

zone::zone()
{
}

zone::zone(int nb_zone)
{
	z_temps = 1;
	z_zone = nb_zone;
	z_ascenseur = true;
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
		std::cout << "ici1" << std::endl;
    }
	std::cout << "joueur pas trouve" << std::endl;
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
	std::cout << "ici2" << std::endl;
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

void zone::flechesRouge()
{
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_haut().begin(), this->getz_actions_haut().end(), DIR_R);
		if (action_possible != this->getz_actions_haut().end())
		{
			wr("[Vous vous deplacez.]");
			if (z_zone == ZONE_BLUE)
			{
				this->getz_joueur_haut(this->getz_joueur_playing())->setj_zone(ZONE_WHITE);
				zone_left->addz_joueurs_haut(this->getz_joueur_haut(z_joueur_playing));
				this->removez_joueurs_haut(z_joueur_playing);
				wr("[Vous arrivez en zone blanche, en haut.]");
			}
			if (z_zone == ZONE_WHITE)
			{
				this->getz_joueur_haut(this->getz_joueur_playing())->setj_zone(ZONE_RED);
				zone_left->addz_joueurs_haut(this->getz_joueur_haut(z_joueur_playing));
				this->removez_joueurs_haut(z_joueur_playing);
				wr("[Vous arrivez en zone rouge, en haut.]");
			}
		}
		else
		{
			wr("[Vous ne pouvez pas vous deplacer par la.]");
		}
	}
	else
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_bas().begin(), this->getz_actions_bas().end(), DIR_R);
		if (action_possible != this->getz_actions_bas().end())
		{
			wr("[Vous vous deplacez.]");
			if (z_zone == ZONE_BLUE)
			{
				wr("iceeeei\n");
				std::cout << this->getz_joueur_playing() << "feijgbfuirgfiuewhfewjfiuhwerfih" <<  std::endl;
				std::cout << this->getz_joueur_bas(this->getz_joueur_playing())->getj_nom() << this->getz_joueur_playing() << std::endl;
				this->getz_joueur_bas(this->getz_joueur_playing())->setj_zone(ZONE_WHITE);
				wr("iciefdefef1\n");
				zone_left->addz_joueurs_bas(this->getz_joueur_bas(z_joueur_playing));
				wr("icifefefdas2\n");
				this->removez_joueurs_bas(z_joueur_playing);
				wr("[Vous arrivez en zone blanche, en bas.]");
			}
			if (z_zone == ZONE_WHITE)
			{
				this->getz_joueur_bas(this->getz_joueur_playing())->setj_zone(ZONE_RED);
				zone_left->addz_joueurs_bas(this->getz_joueur_bas(z_joueur_playing));
				this->removez_joueurs_bas(z_joueur_playing);
				wr("[Vous arrivez en zone rouge, en bas.]");
			}
		}
		else
		{
			wr("[Vous ne pouvez pas vous deplacer par la.]");
		}
	}
}

void zone::flechesBleue()
{
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_haut().begin(), this->getz_actions_haut().end(), DIR_B);
		if (action_possible != this->getz_actions_haut().end())
		{
			wr("[Vous vous deplacez.]");
			if (z_zone == ZONE_RED)
			{
				this->getz_joueur_haut(this->getz_joueur_playing())->setj_zone(ZONE_WHITE);
				zone_right->addz_joueurs_haut(this->getz_joueur_haut(z_joueur_playing));
				this->removez_joueurs_haut(z_joueur_playing);
				wr("[Vous arrivez en zone blanche, en haut.]");
			}
			if (z_zone == ZONE_WHITE)
			{
				this->getz_joueur_haut(this->getz_joueur_playing())->setj_zone(ZONE_BLUE);
				zone_right->addz_joueurs_haut(this->getz_joueur_haut(z_joueur_playing));
				this->removez_joueurs_haut(z_joueur_playing);
				wr("[Vous arrivez en zone bleue, en haut.]");
			}
		}
		else
		{
			wr("[Vous ne pouvez pas vous deplacer par la.]");
		}
	}
	else
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_bas().begin(), this->getz_actions_bas().end(), DIR_B);
		if (action_possible != this->getz_actions_bas().end())
		{
			wr("[Vous vous deplacez.]");
			if (z_zone == ZONE_RED)
			{
				this->getz_joueur_bas(this->getz_joueur_playing())->setj_zone(ZONE_WHITE);
				zone_right->addz_joueurs_bas(this->getz_joueur_bas(z_joueur_playing));
				this->removez_joueurs_bas(z_joueur_playing);
				wr("[Vous arrivez en zone blanche, en bas.]");
			}
			if (z_zone == ZONE_WHITE)
			{
				this->getz_joueur_bas(this->getz_joueur_playing())->setj_zone(ZONE_BLUE);
				zone_right->addz_joueurs_bas(this->getz_joueur_bas(z_joueur_playing));
				this->removez_joueurs_bas(z_joueur_playing);
				wr("[Vous arrivez en zone bleue, en bas.]");
			}
		}
		else
		{
			wr("[Vous ne pouvez pas vous deplacer par la.]");
		}
	}
}

bool zone::getz_ascenseur() const
{
	return (z_ascenseur);
}

cannon *zone::get_cannon_haut() const
{
	return (cannon_haut);
}
cannon *zone::get_cannon_bas() const
{
	return (cannon_bas);
}

int zone::getz_zone() const
{
	return (z_zone);
}

std::string zone::getz_nom_zone() const
{
	return (z_nom_zone);
}

void zone::ascenseur()
{
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_haut().begin(), this->getz_actions_haut().end(), DIR_A);
		const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour_haut().begin(), this->getz_actions_used_ce_tour_haut().end(), DIR_A);
		if (action_possible != this->getz_actions_haut().end() && this->getz_ascenseur() && action_ce_tour == this->getz_actions_used_ce_tour_haut().end())
		{
			wr("[Vous prenez l'ascenseur pour descendre d'un etage.]");
			std::cout << "[Vous arrivez en bas, dans la " << this->getz_nom_zone() << ".]\n";
			this->addz_actions_used_ce_tour_haut(DIR_A);
			this->addz_actions_used_ce_tour_bas(DIR_A);
			this->addz_joueurs_bas(this->getz_joueur_haut(z_joueur_playing));
			this->removez_joueurs_haut(z_joueur_playing);
		}
		else
		{
			wr("[Vous ne ddpouvez pas vous deplacer par la.]");
		}
	}
	else
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_bas().begin(), this->getz_actions_bas().end(), DIR_A);
		const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour_bas().begin(), this->getz_actions_used_ce_tour_bas().end(), DIR_A);
		if (action_possible != this->getz_actions_bas().end() && this->getz_ascenseur() && action_ce_tour == this->getz_actions_used_ce_tour_bas().end())
		{
			wr("[Vous prenez l'ascenseur pour monter d'un etage.]");
			std::cout << "[Vous arrivez en haut, dans la " << this->getz_nom_zone() << ".]\n";
			this->addz_actions_used_ce_tour_haut(DIR_A);
			this->addz_actions_used_ce_tour_bas(DIR_A);
			this->addz_joueurs_haut(this->getz_joueur_bas(z_joueur_playing));
			this->removez_joueurs_bas(z_joueur_playing);
		}
		else
		{
			wr("[Vous ne pouvez pas vous deplacer par la.]");
		}
	}
}

void zone::actionA()
{
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_haut().begin(), this->getz_actions_haut().end(), ACT_A);
		const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour_haut().begin(), this->getz_actions_used_ce_tour_haut().end(), ACT_A);
		if (action_possible != this->getz_actions_haut().end() && action_ce_tour == this->getz_actions_used_ce_tour_haut().end())
		{
			if (z_reacteur)
			{
				wr("[ATTACK avec le " + this->get_cannon_haut()->getnom_cannon() + " !]");
				z_reacteur -= 1;
				std::cout << "[Carburant disponible : " << z_reacteur << "]\n";
				this->addz_actions_used_ce_tour_haut(ACT_A);
			}
			else
			{
				wr("[Tentative d'attack avec " + this->get_cannon_haut()->getnom_cannon() + " ... Echec par manque d'energie! Dommage...]");
				this->addz_actions_used_ce_tour_haut(ACT_A);
			}
		}
		else if (action_ce_tour != this->getz_actions_used_ce_tour_haut().end() && action_possible != this->getz_actions_haut().end()) //action deja utilisee ce tour
		{
			wr("[Tentative d'attack avec " + this->get_cannon_haut()->getnom_cannon() + " Echec, coordonnez vous bordel]");
		}
		else
			wr("[Tentative d'attack avec " + this->get_cannon_haut()->getnom_cannon() + " Echec, impossible d'utiliser cet arme ce tour]");
	}
	else
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_bas().begin(), this->getz_actions_bas().end(), ACT_A);
		const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour_bas().begin(), this->getz_actions_used_ce_tour_bas().end(), ACT_A);
		if (action_possible != this->getz_actions_bas().end() && action_ce_tour == this->getz_actions_used_ce_tour_bas().end())
		{
			if (z_reacteur)
			{
				wr("[ATTACK avec le " + this->get_cannon_bas()->getnom_cannon() + " !]");
				if (this->get_cannon_bas()->gettype_cannon() == CANON_IMPULSION)
				{
					z_reacteur -= 1;
					std::cout << "[Carburant disponible : " << z_reacteur << "]\n";
				}
				this->addz_actions_used_ce_tour_bas(ACT_A);
			}
			else
			{
				wr("[Tentative d'attack avec " + this->get_cannon_bas()->getnom_cannon() + " ... Echec par manque d'energie! Dommage...]");
				this->addz_actions_used_ce_tour_bas(ACT_A);
			}
		}
		else if (action_ce_tour != this->getz_actions_used_ce_tour_bas().end() && action_possible != this->getz_actions_bas().end()) //action deja utilisee ce tour
		{
			wr("[Tentative d'attack avec " + this->get_cannon_bas()->getnom_cannon() + " Echec, coordonnez vous bordel]");
		}
		else
			wr("[Tentative d'attack avec " + this->get_cannon_bas()->getnom_cannon() + " Echec, impossible d'utiliser cet arme ce tour]");
	}
}

void zone::actionAHeros()
{
	wr("[ACTION HEROIQUE !!!]");
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_haut().begin(), this->getz_actions_haut().end(), ACT_AH);
		const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour_haut().begin(), this->getz_actions_used_ce_tour_haut().end(), ACT_AH);
		if (action_possible != this->getz_actions_haut().end() && action_ce_tour == this->getz_actions_used_ce_tour_haut().end())
		{
			if (z_reacteur)
			{
				wr("[ATTACK avec le " + this->get_cannon_haut()->getnom_cannon() + " !]");
				z_reacteur -= 1;
				std::cout << "[Carburant disponible : " << z_reacteur << "]\n";
				this->addz_actions_used_ce_tour_haut(ACT_AH);
			}
			else
			{
				wr("[Tentative d'attack avec " + this->get_cannon_haut()->getnom_cannon() + " ... Echec par manque d'energie! Dommage...]");
				this->addz_actions_used_ce_tour_haut(ACT_AH);
			}
		}
		else if (action_ce_tour != this->getz_actions_used_ce_tour_haut().end() && action_possible != this->getz_actions_haut().end()) //action deja utilisee ce tour
		{
			wr("[Tentative d'attack avec " + this->get_cannon_haut()->getnom_cannon() + " Echec, coordonnez vous bordel]");
		}
		else
			wr("[Tentative d'attack avec " + this->get_cannon_haut()->getnom_cannon() + " Echec, impossible d'utiliser cet arme ce tour]");
	}
	else
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_bas().begin(), this->getz_actions_bas().end(), ACT_AH);
		const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour_bas().begin(), this->getz_actions_used_ce_tour_bas().end(), ACT_AH);
		if (action_possible != this->getz_actions_bas().end() && action_ce_tour == this->getz_actions_used_ce_tour_bas().end())
		{
			if (z_reacteur)
			{
				wr("[ATTACK avec le " + this->get_cannon_bas()->getnom_cannon() + " !]");
				if (this->get_cannon_bas()->gettype_cannon() == CANON_IMPULSION)
				{
					z_reacteur -= 1;
					std::cout << "[Carburant disponible : " << z_reacteur << "]\n";
				}
				this->addz_actions_used_ce_tour_bas(ACT_AH);
			}
			else
			{
				wr("[Tentative d'attack avec " + this->get_cannon_bas()->getnom_cannon() + " ... Echec par manque d'energie! Dommage...]");
				this->addz_actions_used_ce_tour_bas(ACT_AH);
			}
		}
		else if (action_ce_tour != this->getz_actions_used_ce_tour_bas().end() && action_possible != this->getz_actions_bas().end()) //action deja utilisee ce tour
		{
			wr("[Tentative d'attack avec " + this->get_cannon_bas()->getnom_cannon() + " Echec, coordonnez vous bordel]");
		}
		else
			wr("[Tentative d'attack avec " + this->get_cannon_bas()->getnom_cannon() + " Echec, impossible d'utiliser cet arme ce tour]");
	}
}

void zone::actionB()
{
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_haut().begin(), this->getz_actions_haut().end(), ACT_B);
		if (action_possible != this->getz_actions_haut().end())
		{
			if (z_reacteur)
			{
				wr("[Recuperation de l'energie du reacteur de la " + z_nom_zone + " pour alimenter le bouclier de la zone " + z_nom_zone + "]");
				while (z_reacteur && z_bouclier < z_max_energie_bouclier)
				{
					z_reacteur--;
					z_bouclier++;
				}
				std::cout << "[Energie disponible dans le bouclier de la zone " + z_nom_zone + " : " << z_bouclier << "]\n";
				std::cout << "[Energie disponible dans le reacteur de la zone " + z_nom_zone + " : " << z_reacteur << "]\n";
			}
			else
			{
				wr("[Tentative de recuperation de l'energie du reacteur de la zone " + z_nom_zone + " pour alimenter le bouclier.. Echec... c'est la merde, et en plus ton tour sert a rien...]");
			}
		}
		else
		{
			wr("[Tentative de recuperation de l'energie du reacteur de la zone " + z_nom_zone + " pour alimenter le bouclier.. Echec... Impossible ce tour...]");
		}
	}
	else
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_bas().begin(), this->getz_actions_bas().end(), ACT_B);
		if (action_possible != this->getz_actions_bas().end())
		{
			if (z_zone == ZONE_WHITE)
			{
				if (z_capsule_energie)
				{
					wr("[Activation d'une capsule de carburant - Carburant disponible : 5]");
					z_reacteur = 5;
					z_capsule_energie -= 1;
					std::cout << "[Capsule de carburant restante : " << z_capsule_energie << "]\n";
				}
				else
				{
					wr("[Tentative d'activation d'une capsule de carburant... echouee... plus de carburant disponible]");
				}

			}
			else
			{
				if (zone_white->getz_reacteur())
				{
					wr("[Recuperation de l'energie du reacteur central pour alimenter le reacteur de la zone " + z_nom_zone + "]");
					while (zone_white->getz_reacteur() && z_reacteur < z_max_reacteur)
					{
						z_reacteur++;
						zone_white->setz_reacteur(zone_white->getz_reacteur() - 1);
					}
					std::cout << "[Energie disponible dans le reacteur de la zone " + z_nom_zone + " : " << z_reacteur << "]\n";
					std::cout << "[Energie disponible dans le reacteur central : " << zone_white->getz_reacteur() << "]\n";
				}
				else
				{
					wr("[Tentative de recuperation de l'energie du reacteur central pour alimenter le reacteur de la zone " + z_nom_zone + "... Echec... il n'y a pas d'energie...]");
				}
			}
		}
		else
		{
			wr("[Tentative de recuperation de l'energie du reacteur central pour alimenter le reacteur de la zone " + z_nom_zone + " mais ce n'est pas possible ce tour.]");
		}
	}
}

void zone::actionBHeros()
{
	wr("[ACTION HEROIQUE !!!]");
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_haut().begin(), this->getz_actions_haut().end(), ACT_B);
		if (action_possible != this->getz_actions_haut().end())
		{
			if (z_reacteur)
			{
				wr("[Recuperation de l'energie du reacteur de la " + z_nom_zone + " pour alimenter le bouclier de la zone " + z_nom_zone + "]");
				while (z_reacteur && z_bouclier < z_max_energie_bouclier)
				{
					z_reacteur--;
					z_bouclier++;
				}
				z_bouclier++;
				std::cout << "[Energie disponible dans le bouclier de la zone " + z_nom_zone + " : " << z_bouclier << "]\n";
				std::cout << "[Energie disponible dans le reacteur de la zone " + z_nom_zone + " : " << z_reacteur << "]\n";
			}
			else
			{
				wr("[Tentative de recuperation de l'energie du reacteur de la zone " + z_nom_zone + " pour alimenter le bouclier.. Echec... c'est la merde, et en plus ton tour sert a rien...]");
			}
		}
		else
		{
			wr("[Tentative de recuperation de l'energie du reacteur de la zone " + z_nom_zone + " pour alimenter le bouclier.. Echec... Impossible ce tour...]");
		}
	}
	else
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_bas().begin(), this->getz_actions_bas().end(), ACT_B);
		if (action_possible != this->getz_actions_bas().end())
		{
			if (z_zone == ZONE_WHITE)
			{
				if (z_capsule_energie)
				{
					wr("[Activation d'une capsule de carburant - Carburant disponible : 5]");
					z_reacteur = 6;
					z_capsule_energie -= 1;
					std::cout << "[Capsule de carburant restante : " << z_capsule_energie << "]\n";
				}
				else
				{
					wr("[Tentative d'activation d'une capsule de carburant... echouee... plus de carburant disponible]");
				}

			}
			else
			{
				if (zone_white->getz_reacteur())
				{
					wr("[Recuperation de l'energie du reacteur central pour alimenter le reacteur de la zone " + z_nom_zone + "]");
					while (zone_white->getz_reacteur() && z_reacteur < z_max_reacteur)
					{
						z_reacteur++;
						zone_white->setz_reacteur(zone_white->getz_reacteur() - 1);
					}
					z_reacteur++;
					std::cout << "[Energie disponible dans le reacteur de la zone " + z_nom_zone + " : " << z_reacteur << "]\n";
					std::cout << "[Energie disponible dans le reacteur central : " << zone_white->getz_reacteur() << "]\n";
				}
				else
				{
					wr("[Tentative de recuperation de l'energie du reacteur central pour alimenter le reacteur de la zone " + z_nom_zone + "... Echec... il n'y a pas d'energie...]");
				}
			}
		}
		else
		{
			wr("[Tentative de recuperation de l'energie du reacteur central pour alimenter le reacteur de la zone " + z_nom_zone + " mais ce n'est pas possible ce tour.]");
		}
	}
}

void zone::actionC()//attention la maintenance on ne peut la faire qu'une fois du tour 1 a 3, puis une fois du tour 4 a 6  et une fois du tour 7 a 9 -> a actualiser dans getz_actions_haut donc fin tour 3, 6 et 9 il faudra la reset des actions possibles.
{
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		if (z_zone == ZONE_WHITE)
		{
			std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_haut().begin(), this->getz_actions_haut().end(), ACT_C);
			const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour_haut().begin(), this->getz_actions_used_ce_tour_haut().end(), ACT_C);
			if (action_possible != this->getz_actions_haut().end() && action_ce_tour == this->getz_actions_used_ce_tour_haut().end())
			{
				z_maintenance_ordinateur.push_back(this->gettemps());
				wr("[Bravo! Vous avez fait la maintenance! (elle genere toujours autant d'enthousiasme celle la)]");
				this->addz_actions_used_ce_tour_haut(ACT_C);
				//this->removez_actions_haut(ACT_C);
			}
			else if (action_possible == this->getz_actions_haut().end())
				wr("[Impossible de faire la maintenance maintenant!]");
			else
				wr("[Vous etes deux a faire la maintenance.......]");
		}
		if (z_zone == ZONE_BLUE)//a finaliser il faut ajouter les robots au joueur
		{
			std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_haut().begin(), this->getz_actions_haut().end(), ACT_C);
			if (action_possible != this->getz_actions_haut().end())
			{
				if (z_bots)
				{
					wr("[Vous prenez les robots avec vous! C'est parti pour la baston!]");
					z_bots = false;
				}
				else
				{
					wr("[Faites un effort, la vous allez tous mourir... Les robots accompagnent deja un autre joueur.]");
				}
			}
			else
			{
				wr("[Impossible de prendre les robots a ce tour, dommage!]");
			}
		}
		if (z_zone == ZONE_RED)//a finaliser
		{
			const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_haut().begin(), this->getz_actions_haut().end(), ACT_C);
			if (action_possible != this->getz_actions_haut().end())
			{
				wr("[Vous vous envolez avec les robots dans l'espace!!]");
			}
			else
			{
				wr("[Impossible de prendre les vaisseaux a ce tour, dommage!]");
			}
		}
	}
	else
	{
		if (z_zone == ZONE_BLUE)
		{
			const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour_bas().begin(), this->getz_actions_used_ce_tour_bas().end(), ACT_C);
			const std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_bas().begin(), this->getz_actions_bas().end(), ACT_C);
			if (action_ce_tour == this->getz_actions_used_ce_tour_bas().end() && action_possible != this->getz_actions_bas().end())
			{
				if (z_roquete_position[1] == 0)
				{
					wr("[Lancement de la premiere requete !]");
					z_roquete_position[1] = 1;
					this->addz_actions_used_ce_tour_bas(ACT_C);
				}
				else if (z_roquete_position[2] == 0)
				{
					wr("[Lancement de la seconde requete !]");
					z_roquete_position[2] = 1;
					this->addz_actions_used_ce_tour_bas(ACT_C);
				}
				else if (z_roquete_position[3] == 0)
				{
					wr("[Lancement de la troisieme requete !]");
					z_roquete_position[3] = 1;
					this->addz_actions_used_ce_tour_bas(ACT_C);
				}
				else
				{
					wr("[Toutes les roquetes ont deja ete lancees... pas la peine de s'exciter frere]");
				}
			}
			else if (action_ce_tour != this->getz_actions_used_ce_tour_bas().end())
			{
				wr("[Mais coordonnez vous bordel]");
			}
			else if (action_possible == this->getz_actions_bas().end())
			{
				wr("[Impossible de lancer les roquettes]");
			}
		}
		if (z_zone == ZONE_RED)//a finaliser il faut ajouter les robots au joueur
		{
			std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_bas().begin(), this->getz_actions_bas().end(), ACT_C);
			if (action_possible != this->getz_actions_bas().end())
			{
				if (z_bots)
				{
					wr("[Vous prenez les robots avec vous! C'est parti pour la baston!]");
					z_bots = false;
				}
				else
				{
					wr("[Faites un effort, la vous allez tous mourir... Les robots accompagnent deja un autre joueur.]");
				}
			}
			else
			{
				wr("[Impossible de prendre les robots a ce tour, dommage!]");
			}
		}
		if (z_zone == ZONE_WHITE)
		{
			//a faire
		}
	}
}

zone::~zone() {}

