#include "zone.hpp"

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
				wr("[ATTACK avec le " + this->getz_cannon_haut()->getnom_cannon() + " !]");
				z_reacteur -= 1;
				std::cout << "[Carburant disponible : " << z_reacteur << "]\n";
				this->addz_actions_used_ce_tour_haut(ACT_A);
				addz_cannon_used(this->getz_cannon_haut());
			}
			else
			{
				wr("[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " ... Echec par manque d'energie! Dommage...]");
				this->addz_actions_used_ce_tour_haut(ACT_A);
			}
		}
		else if (action_ce_tour != this->getz_actions_used_ce_tour_haut().end() && action_possible != this->getz_actions_haut().end()) //action deja utilisee ce tour
		{
			wr("[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " Echec, coordonnez vous bordel]");
		}
		else
			wr("[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " Echec, impossible d'utiliser cet arme ce tour]");
	}
	else
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_bas().begin(), this->getz_actions_bas().end(), ACT_A);
		const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour_bas().begin(), this->getz_actions_used_ce_tour_bas().end(), ACT_A);
		if (action_possible != this->getz_actions_bas().end() && action_ce_tour == this->getz_actions_used_ce_tour_bas().end())
		{
			if (z_reacteur)
			{
				wr("[ATTACK avec le " + this->getz_cannon_bas()->getnom_cannon() + " !]");
				if (this->getz_cannon_bas()->gettype_cannon() == CANON_IMPULSION)
				{
					z_reacteur -= 1;
					std::cout << "[Carburant disponible : " << z_reacteur << "]\n";
				}
				this->addz_actions_used_ce_tour_bas(ACT_A);
				addz_cannon_used(this->getz_cannon_bas());
			}
			else
			{
				wr("[Tentative d'attack avec " + this->getz_cannon_bas()->getnom_cannon() + " ... Echec par manque d'energie! Dommage...]");
				this->addz_actions_used_ce_tour_bas(ACT_A);
			}
		}
		else if (action_ce_tour != this->getz_actions_used_ce_tour_bas().end() && action_possible != this->getz_actions_bas().end()) //action deja utilisee ce tour
		{
			wr("[Tentative d'attack avec " + this->getz_cannon_bas()->getnom_cannon() + " Echec, coordonnez vous bordel]");
		}
		else
			wr("[Tentative d'attack avec " + this->getz_cannon_bas()->getnom_cannon() + " Echec, impossible d'utiliser cet arme ce tour]");
	}
}

void calculateDegatsCanons() 
{
	// dans quelle zone on est?
	// quel est le type de canon?
	// qui est le monstre le plus proche?
	// combien de canons peuvent l'atteindre? combien de degats il prend 
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
				wr("[ATTACK avec le " + this->getz_cannon_haut()->getnom_cannon() + " !]");
				z_reacteur -= 1;
				std::cout << "[Carburant disponible : " << z_reacteur << "]\n";
				this->addz_actions_used_ce_tour_haut(ACT_AH);
			}
			else
			{
				wr("[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " ... Echec par manque d'energie! Dommage...]");
				this->addz_actions_used_ce_tour_haut(ACT_AH);
			}
		}
		else if (action_ce_tour != this->getz_actions_used_ce_tour_haut().end() && action_possible != this->getz_actions_haut().end()) //action deja utilisee ce tour
		{
			wr("[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " Echec, coordonnez vous bordel]");
		}
		else
			wr("[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " Echec, impossible d'utiliser cet arme ce tour]");
	}
	else
	{
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_bas().begin(), this->getz_actions_bas().end(), ACT_AH);
		const std::vector<int>::const_iterator action_ce_tour = std::find(this->getz_actions_used_ce_tour_bas().begin(), this->getz_actions_used_ce_tour_bas().end(), ACT_AH);
		if (action_possible != this->getz_actions_bas().end() && action_ce_tour == this->getz_actions_used_ce_tour_bas().end())
		{
			if (z_reacteur)
			{
				wr("[ATTACK avec le " + this->getz_cannon_bas()->getnom_cannon() + " !]");
				if (this->getz_cannon_bas()->gettype_cannon() == CANON_IMPULSION)
				{
					z_reacteur -= 1;
					std::cout << "[Carburant disponible : " << z_reacteur << "]\n";
				}
				this->addz_actions_used_ce_tour_bas(ACT_AH);
			}
			else
			{
				wr("[Tentative d'attack avec " + this->getz_cannon_bas()->getnom_cannon() + " ... Echec par manque d'energie! Dommage...]");
				this->addz_actions_used_ce_tour_bas(ACT_AH);
			}
		}
		else if (action_ce_tour != this->getz_actions_used_ce_tour_bas().end() && action_possible != this->getz_actions_bas().end()) //action deja utilisee ce tour
		{
			wr("[Tentative d'attack avec " + this->getz_cannon_bas()->getnom_cannon() + " Echec, coordonnez vous bordel]");
		}
		else
			wr("[Tentative d'attack avec " + this->getz_cannon_bas()->getnom_cannon() + " Echec, impossible d'utiliser cet arme ce tour]");
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
				z_maintenance_ordinateur.push_back(this->getz_temps());
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

