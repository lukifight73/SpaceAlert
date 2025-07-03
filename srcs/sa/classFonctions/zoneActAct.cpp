#include "zone.hpp"
#include "menace_interne.hpp"

void zone::actionA()
{
	std::string msg = "[ACTION A de " + z_joueur_playing + "!!!]\n";
	z_data->text_robot += msg;
	menace_interne* menaceInt = NULL;
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		menaceInt = checkIfMenaceInternAttrackAction(ACT_A, z_zone, 1);
		if(menaceInt)
		{
			menaceInt->getDamage(this->getz_joueur_haut(z_joueur_playing));
		}
		else
		{
			if (this->action_possible_haut(ACT_A) && !this->action_used_ce_tour_haut(ACT_A))
			{
				if (z_reacteur)
				{
					msg = "[ATTACK avec le " + this->getz_cannon_haut()->getnom_cannon() + " !]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
					z_reacteur -= 1;
					msg = "[Carburant disponible : " + std::to_string(z_reacteur) + "]\n";
					printSlowly(msg, *z_data);
					this->addz_actions_used_ce_tour_haut(ACT_A);
					addz_cannon_used(this->getz_cannon_haut());
					this->getz_cannon_haut()->setcanon_used(true);
					this->getz_cannon_haut()->settireur(z_joueur_playing);
				}
				else
				{
					msg = "[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " ... Échec par manque d'énergie! Dommage...]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
					this->addz_actions_used_ce_tour_haut(ACT_A);
				}
			}
			else if (this->action_used_ce_tour_haut(ACT_A) && this->action_possible_haut(ACT_A)) //action deja utilisee ce tour
			{
				msg = "[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " Échec, coordonnez vous bordel]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
			else
			{
				msg = "[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " Échec, impossible d'utiliser cet arme ce tour]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
		}
	}
	else if (this->getz_joueur_bas(z_joueur_playing))
	{
		menaceInt = checkIfMenaceInternAttrackAction(ACT_A, z_zone, 0);
		if(menaceInt)
		{
			menaceInt->getDamage(this->getz_joueur_bas(z_joueur_playing));
		}
		else
		{
			if (this->action_possible_bas(ACT_A) && !this->action_used_ce_tour_bas(ACT_A))
			{
				if (this->getz_cannon_bas()->gettype_cannon() == CANON_IMPULSION)
				{
					if (z_reacteur)
					{
						msg = "[ATTACK avec le " + this->getz_cannon_bas()->getnom_cannon() + " !]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
						z_reacteur -= 1;
						msg = "[Carburant disponible : " + std::to_string(z_reacteur) + "]\n";
						printSlowly(msg, *z_data);
					}
					else
					{
						msg = "[Échec de l'attack avec le " + this->getz_cannon_bas()->getnom_cannon() + " par manque d'énergie...]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
						return ;
					}
				}
				else
				{
					msg = "[ATTACK avec le " + this->getz_cannon_bas()->getnom_cannon() + " !]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
				}
				this->addz_actions_used_ce_tour_bas(ACT_A);
				addz_cannon_used(this->getz_cannon_bas());
				this->getz_cannon_bas()->setcanon_used(true);
				this->getz_cannon_bas()->settireur(z_joueur_playing);
			}
			else if (this->action_used_ce_tour_bas(ACT_A))
			{
				msg = "[Les frérots la coordination c'est pas votre fort...]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
			else
			{
				msg = "[Tentative d'attack avec " + this->getz_cannon_bas()->getnom_cannon() + " Échec, impossible d'utiliser cet arme ce tour]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
		}
	}
	else if(z_joueur_intercepteurs)
		wrongActionInSpace();
}

void zone::actionAHeros()
{
	std::string msg = "[ACTION A HÉROIQUE DE " + z_joueur_playing + "!!!]\n";
	z_data->text_robot += msg;
	printSlowly(msg, *z_data);
	menace_interne* menaceInt = NULL;
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		menaceInt = checkIfMenaceInternAttrackAction(ACT_AH, z_zone, 1);
		if(menaceInt)
		{
			menaceInt->getDamageHero(this->getz_joueur_haut(z_joueur_playing));
		}
		else
		{
			if (this->action_possible_haut(ACT_A) && !this->action_used_ce_tour_haut(ACT_A))
			{
				if (z_reacteur)
				{
					msg = "[ATTACK avec le " + this->getz_cannon_haut()->getnom_cannon() + " !]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
					z_reacteur -= 1;
					msg = "[Carburant disponible : " + std::to_string(z_reacteur) + "]\n";
					printSlowly(msg, *z_data);
					this->addz_actions_used_ce_tour_haut(ACT_A);
					addz_cannon_used(this->getz_cannon_haut());
					this->getz_cannon_haut()->setcanon_used(true);
					this->getz_cannon_haut()->setactionHeroique(true);
					this->getz_cannon_haut()->settireur("ACTION HÉROIQUE! " + z_joueur_playing);
				}
				else
				{
					msg = "[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " ... Échec par manque d'énergie! Dommage...]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
					this->addz_actions_used_ce_tour_haut(ACT_A);
				}
			}
			else if (this->action_used_ce_tour_haut(ACT_A) && this->action_possible_haut(ACT_A)) //action deja utilisee ce tour
			{
				msg = "[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " Échec, coordonnez vous bordel]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
			else
			{
				msg = "[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " Échec, impossible d'utiliser cet arme ce tour]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);;
			}
		}
	}
	else if (this->getz_joueur_bas(z_joueur_playing))
	{
		menaceInt = checkIfMenaceInternAttrackAction(ACT_AH, z_zone, 0);
		if(menaceInt)
		{
			menaceInt->getDamageHero(this->getz_joueur_bas(z_joueur_playing));
		}
		else
		{
			if (this->action_possible_bas(ACT_A) && !this->action_used_ce_tour_bas(ACT_A))
			{

					if (this->getz_cannon_bas()->gettype_cannon() == CANON_IMPULSION)
					{
						if (z_reacteur)
						{
							msg = "[ATTACK avec le " + this->getz_cannon_bas()->getnom_cannon() + " !]\n";
							z_data->text_robot += msg;
							printSlowly(msg, *z_data);
							z_reacteur -= 1;
							msg = "[Carburant disponible : " + std::to_string(z_reacteur) + "]\n";
							printSlowly(msg, *z_data);
						}
						else
						{
							msg = "[Échec de l'attack avec le " + this->getz_cannon_bas()->getnom_cannon() + " par manque d'énergie...]\n";
							z_data->text_robot += msg;
							printSlowly(msg, *z_data);
							return ;
						}
					}
					else
					{
						msg = "[ATTACK avec le " + this->getz_cannon_bas()->getnom_cannon() + " !]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
					}
					this->getz_cannon_bas()->setactionHeroique(true);
					this->addz_actions_used_ce_tour_bas(ACT_A);
					addz_cannon_used(this->getz_cannon_bas());
					this->getz_cannon_bas()->setcanon_used(true);
					this->getz_cannon_bas()->settireur("ACTION HÉROIQUE! " + z_joueur_playing);
			}
			else if (this->action_used_ce_tour_bas(ACT_A))
			{
				msg = "[Les frérots la coordination c'est pas votre fort...]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
			else
			{
				msg = "[Tentative d'attack avec " + this->getz_cannon_bas()->getnom_cannon() + " Échec, impossible d'utiliser cet arme ce tour]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
		}
	}
	else if(z_joueur_intercepteurs)
		wrongActionInSpace();
}

void zone::actionB()
{
	std::string msg = "[ACTION B de " + z_joueur_playing + "!!!]\n";
	z_data->text_robot += msg;
	printSlowly(msg, *z_data);
	menace_interne* menaceInt = NULL;
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		menaceInt = checkIfMenaceInternAttrackAction(ACT_B, z_zone, 1);
		if(menaceInt)
		{
			menaceInt->getDamage(this->getz_joueur_haut(z_joueur_playing));
		}
		else
		{
			if (this->action_possible_haut(ACT_B))
			{
				if (z_reacteur)
				{
					msg = "[Récuperation de l'énergie du réacteur de la " + z_nom_zone + " pour alimenter le bouclier de la " + z_nom_zone + "]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
					while (z_reacteur && z_bouclier < z_max_energie_bouclier)
					{
						z_reacteur--;
						z_bouclier++;
					}
					msg = "[Énergie disponible dans le bouclier de la " + z_nom_zone + " : " + std::to_string(z_bouclier) + "]\n";
					printSlowly(msg, *z_data);
					msg = "[Énergie disponible dans le réacteur de la " + z_nom_zone + " : " + std::to_string(z_reacteur) + "]\n";
					printSlowly(msg, *z_data);
				}
				else
				{
					msg = "[Tentative de récuperation de l'énergie du réacteur de la " + z_nom_zone + " pour alimenter le bouclier.. Échec... c'est la merde, et en plus ton tour sert a rien...]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
				}
			}
			else
			{
				msg = "[Tentative de récuperation de l'énergie du réacteur de la " + z_nom_zone + " pour alimenter le bouclier.. Échec... Impossible ce tour...]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
		}
	}
	else if (this->getz_joueur_bas(z_joueur_playing))
	{
		menaceInt = checkIfMenaceInternAttrackAction(ACT_B, z_zone, 0);
		if(menaceInt)
		{
			menaceInt->getDamage(this->getz_joueur_bas(z_joueur_playing));
		}
		else
		{
			if (this->action_possible_bas(ACT_B))
			{
				if (z_zone == ZONE_WHITE)
				{
					if (z_capsule_energie)
					{
						msg = "[Activation d'une capsule de carburant - Carburant disponible : 5]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
						z_reacteur = 5;
						z_capsule_energie -= 1;
						msg = "[Capsule de carburant restante : " + std::to_string(z_capsule_energie) + "]\n";
						printSlowly(msg, *z_data);
					}
					else
					{
						msg = "[Tentative d'activation d'une capsule de carburant... échouée... plus de carburant disponible]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
					}

				}
				else
				{
					if (zone_white->getz_reacteur())
					{
						msg = "[Récuperation de l'énergie du réacteur central pour alimenter le réacteur de la " + z_nom_zone + "]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
						while (zone_white->getz_reacteur() && z_reacteur < z_max_reacteur)
						{
							z_reacteur++;
							zone_white->setz_reacteur(zone_white->getz_reacteur() - 1);
						}
						msg = "[Énergie disponible dans le réacteur de la " + z_nom_zone + " : " + std::to_string(z_reacteur) + "]\n";
						printSlowly(msg, *z_data);
						msg = "[Énergie disponible dans le réacteur central : " + std::to_string(zone_white->getz_reacteur()) + "]\n";
						printSlowly(msg, *z_data);
					}
					else
					{
						msg = "[Tentative de récuperation de l'énergie du réacteur central pour alimenter le réacteur de la " + z_nom_zone + "... Échec... il n'y a pas d'énergie...]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
					}
				}
			}
			else
			{
				msg = "[Tentative de récuperation de l'énergie du réacteur central pour alimenter le réacteur de la " + z_nom_zone + " mais ce n'est pas possible ce tour.]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
		}
	}
	else if(z_joueur_intercepteurs)
		wrongActionInSpace();
}

void zone::actionBHeros()
{
	std::string msg = "[ACTION B HÉROIQUE DE " + z_joueur_playing + "!!!]\n";
	z_data->text_robot += msg;
	printSlowly(msg, *z_data);
	menace_interne* menaceInt = NULL;
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		menaceInt = checkIfMenaceInternAttrackAction(ACT_B, z_zone, 1);
		if(menaceInt)
		{
			menaceInt->getDamageHero(this->getz_joueur_haut(z_joueur_playing));
		}
		else
		{
			if (this->action_possible_haut(ACT_B))
			{
				if (z_reacteur)
				{
					msg = "[Récuperation de l'énergie du réacteur de la " + z_nom_zone + " pour alimenter le bouclier de la " + z_nom_zone + "]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
					while (z_reacteur && z_bouclier < z_max_energie_bouclier)
					{
						z_reacteur--;
						z_bouclier++;
					}
					z_bouclier++;
					msg = "[Énergie disponible dans le bouclier de la " + z_nom_zone + " : " + std::to_string(z_bouclier) + "]\n";
					printSlowly(msg, *z_data);
					msg = "[Énergie disponible dans le réacteur de la " + z_nom_zone + " : " + std::to_string(z_reacteur) + "]\n";
					printSlowly(msg, *z_data);
				}
				else
				{
					msg = "[Tentative de récuperation de l'énergie du réacteur de la " + z_nom_zone + " pour alimenter le bouclier.. Échec... c'est la merde, et en plus ton tour sert a rien...]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
				}
			}
			else
			{
				msg = "[Tentative de récuperation de l'énergie du réacteur de la " + z_nom_zone + " pour alimenter le bouclier.. Échec... Impossible ce tour...]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
		}
	}
	else if (this->getz_joueur_bas(z_joueur_playing))
	{
		menaceInt = checkIfMenaceInternAttrackAction(ACT_B, z_zone, 0);
		if(menaceInt)
		{
			menaceInt->getDamage(this->getz_joueur_bas(z_joueur_playing));
		}
		else
		{
			if (this->action_possible_bas(ACT_B))
			{
				if (z_zone == ZONE_WHITE)
				{
					if (z_capsule_energie)
					{
						msg = "[Activation d'une capsule de carburant - Carburant disponible : 6]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
						z_reacteur = 6;
						z_capsule_energie -= 1;
						msg = "[Capsule de carburant restante : " + std::to_string(z_capsule_energie) + "]\n";
						printSlowly(msg, *z_data);
					}
					else
					{
						msg = "[Tentative d'activation d'une capsule de carburant... échouée... plus de carburant disponible]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
					}

				}
				else
				{
					if (zone_white->getz_reacteur())
					{
						msg = "[Récuperation de l'énergie du réacteur central pour alimenter le réacteur de la " + z_nom_zone + "]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
						while (zone_white->getz_reacteur() && z_reacteur < z_max_reacteur)
						{
							z_reacteur++;
							zone_white->setz_reacteur(zone_white->getz_reacteur() - 1);
						}
						z_reacteur++;
						msg = "[Énergie disponible dans le réacteur de la " + z_nom_zone + " : " + std::to_string(z_reacteur) + "]\n";
						printSlowly(msg, *z_data);
						msg = "[Énergie disponible dans le réacteur central : " + std::to_string(zone_white->getz_reacteur()) + "]\n";
						printSlowly(msg, *z_data);
					}
					else
					{
						msg = "[Tentative de récuperation de l'énergie du réacteur central pour alimenter le réacteur de la " + z_nom_zone + "... Échec... il n'y a pas d'énergie...]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
					}
				}
			}
			else
			{
				msg = "[Tentative de récuperation de l'énergie du réacteur central pour alimenter le réacteur de la " + z_nom_zone + " mais ce n'est pas possible ce tour.]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
		}
	}
	else if(z_joueur_intercepteurs)
		wrongActionInSpace();
}

menace_interne* zone::checkIfMenaceInternAttrackAction(int joueurAction, int Zone, bool haut)
{
	std::vector<menace_interne*> tmp = this->getz_chemin_menace_Int()->get_menacesInte();
	if (tmp.size() == 0)
		return (NULL);
	for (std::vector<menace_interne*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		if((*it)->AttractAction(joueurAction, Zone, haut))
			return (*it); // si on veut optimiser il faut checker s il y en a plusieur!!
	}
	return NULL;
}

void zone::actionC()//attention la maintenance on ne peut la faire qu'une fois du tour 1 a 3, puis une fois du tour 4 a 6  et une fois du tour 7 a 9 -> a actualiser dans getz_actions_haut donc fin tour 3, 6 et 9 il faudra la reset des actions possibles.
{
	std::string msg;
	menace_interne* menaceInt = NULL;
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		if (z_zone == ZONE_WHITE)
		{
			menaceInt = checkIfMenaceInternAttrackAction(ACT_C, ZONE_WHITE, 1);
			if(menaceInt)
			{
				menaceInt->getDamage(this->getz_joueur_haut(z_joueur_playing));
			}
			else
			{
				if (this->action_possible_haut(ACT_C) && !this->action_used_ce_tour_haut(ACT_C))
				{
					z_maintenance_ordinateur.push_back(this->getz_temps());
					msg = "[" + z_joueur_playing + " fais la maintenance!]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
					this->addz_actions_used_ce_tour_haut(ACT_C);
					//this->removez_actions_haut(ACT_C);
				}
				else if (!this->action_possible_haut(ACT_C))
				{
					msg = "[" + z_joueur_playing + ", impossible de faire la maintenance maintenant!]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
				}
				else
				{
					msg = "[Cette action a deja ete faite ce tour... staffe toi " + z_joueur_playing + "!]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
				}
			}
		}
		if (z_zone == ZONE_BLUE)//a finaliser il faut ajouter les robots au joueur
		{
			menaceInt = checkIfMenaceInternAttrackAction(ACT_C, ZONE_BLUE, 1);
			if(menaceInt)
			{
				menaceInt->getDamage(this->getz_joueur_haut(z_joueur_playing));
			}
			else
			{
				if (this->action_possible_haut(ACT_C))
				{
					if (z_bots && this->getz_joueur_haut(z_joueur_playing)->getj_bots() == 0)
					{
						msg = "[" + z_joueur_playing + " prenez les robots! C'est parti pour la baston!]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
						z_bots = false;
						this->getz_joueur_haut(z_joueur_playing)->setj_bots(1);
					}
					else if (this->getz_joueur_haut(z_joueur_playing)->getj_bots() == 2)
					{
						msg = "[" + z_joueur_playing + " reactive les robots qui l'accompagnent!]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
						this->getz_joueur_haut(z_joueur_playing)->setj_bots(1);
					}
					else
					{
						msg = "[" + z_joueur_playing + ", fais un effort, la vous allez tous mourir... Les robots accompagnent deja un autre joueur.]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
					}
				}
				else
				{
					msg = "[" + z_joueur_playing + ", impossible de prendre les robots a ce tour, dommage!]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
				}
			}
		}
		if (z_zone == ZONE_RED)//a finaliser
		{
			menaceInt = checkIfMenaceInternAttrackAction(ACT_C, ZONE_RED, 1);
			if(menaceInt)
			{
				menaceInt->getDamage(this->getz_joueur_haut(z_joueur_playing));
			}
			else
			{
				if (this->action_possible_haut(ACT_C))
				{
					if(this->z_joueur_intercepteurs)
					{
						msg = "[" + z_joueur_playing + ", impossible de prendre les vaisseaux, ils sont deja en vol!]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
					}
					else if (this->getz_joueur_haut(z_joueur_playing)->getj_bots() == BOTS_EVEILLE)
					{
						msg = "[" + z_joueur_playing + " s'envole avec les robots dans l'espace!!]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
						this->getz_joueur_haut(z_joueur_playing)->attaqueIntercepteur(*z_data);
						this->setz_joueur_intercepteurs(this->getz_joueur_haut(z_joueur_playing));
						this->removez_joueurs_haut(z_joueur_playing);
					}
					else if (this->getz_joueur_haut(z_joueur_playing)->getj_bots() != BOTS_EVEILLE)
					{
						msg = "[Impossible de prendre les vaisseaux, " + z_joueur_playing + " n'as pas de robots operationel!]\n";
						z_data->text_robot += msg;
						printSlowly(msg, *z_data);
					}
				}
				else
				{
					msg = "[" + z_joueur_playing + ", impossible de prendre les vaisseaux a ce tour, dommage!]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
				}
			}
		}
	}
	else if (this->getz_joueur_bas(z_joueur_playing))
	{
		if (z_zone == ZONE_BLUE)
		{
			menaceInt = checkIfMenaceInternAttrackAction(ACT_C, ZONE_BLUE, 0);
			if(menaceInt)
			{
				menaceInt->getDamage(this->getz_joueur_bas(z_joueur_playing));
			}
			else
			{
				if (this->action_possible_bas(ACT_C) && !this->action_used_ce_tour_bas(ACT_C))
				{
					if (z_roquete_position[1] == 0)
					{
						msg = "[" + z_joueur_playing + " lance la premiere rocket !]\n";
						z_roquete_position[1] = 1;
						this->addz_actions_used_ce_tour_bas(ACT_C);
					}
					else if (z_roquete_position[2] == 0)
					{
						msg = "[" + z_joueur_playing + " lance la seconde rocket !]\n";
						z_roquete_position[2] = 1;
						this->addz_actions_used_ce_tour_bas(ACT_C);
					}
					else if (z_roquete_position[3] == 0)
					{
						msg = "[" + z_joueur_playing + " lance la troisieme rocket !]\n";
						z_roquete_position[3] = 1;
						this->addz_actions_used_ce_tour_bas(ACT_C);
					}
					else
					{
						msg = "[Toutes les roquetes ont deja ete lancees... pas la peine de s'exciter " + z_joueur_playing + "]\n";
					}
				}
				else if (this->action_used_ce_tour_bas(ACT_C))
				{
					msg = "[Mais coordonnez vous bordel, " + z_joueur_playing + ", une rocket a deja ete lancee ce tour]\n";
				}
				else if (!this->action_possible_bas(ACT_C))
				{
					msg = "[Impossible de lancer les roquettes]\n";
				}
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
		}
		if (z_zone == ZONE_RED)//a finaliser il faut ajouter les robots au joueur
		{
			menaceInt = checkIfMenaceInternAttrackAction(ACT_C, ZONE_RED, 0);
			if(menaceInt)
			{
				menaceInt->getDamage(this->getz_joueur_bas(z_joueur_playing));
			}
			else
			{
				if (this->action_possible_bas(ACT_C))
				{
					if (z_bots && this->getz_joueur_bas(z_joueur_playing)->getj_bots() == 0)
					{
						if (this->getz_bots_englues())
						{
							this->getz_joueur_bas(z_joueur_playing)->setj_bots(2);
							msg = "[" + z_joueur_playing + " prend les robots! Ils sont englues, il faut donc les activer une seconde fois!]\n";
						}
						else
						{
							this->getz_joueur_bas(z_joueur_playing)->setj_bots(1);
							msg = "[" + z_joueur_playing + " prend les robots! C'est parti pour la baston!]\n";
						}
						z_bots = false;
					}
					else if (this->getz_joueur_bas(z_joueur_playing)->getj_bots() == 2)
					{
						msg = "[" + z_joueur_playing + " reactive les robots qui l'accompagnent!]\n";
						this->getz_joueur_bas(z_joueur_playing)->setj_bots(1);
					}
					else
					{
						msg = "[Fais un effort " + z_joueur_playing + ", la vous allez tous mourir... Les robots accompagnent deja un autre joueur.]\n";
					}
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
				}
				else
				{
					msg = "[Impossible de prendre les robots a ce tour, dommage " + z_joueur_playing + "!]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
				}
			}
		}
		if (z_zone == ZONE_WHITE)
		{
			menaceInt = checkIfMenaceInternAttrackAction(ACT_C, ZONE_WHITE, 0);
			if(menaceInt)
			{
				menaceInt->getDamage(this->getz_joueur_bas(z_joueur_playing));
			}
			else
			{
				msg = "[" + z_joueur_playing + " effectue une observation de ses alentours, en toute détente.]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
		}
	}
	else if(z_joueur_intercepteurs)
		wrongActionInSpace();
}

zone::~zone() {}

void zone::actionR()//attention la maintenance on ne peut la faire qu'une fois du tour 1 a 3, puis une fois du tour 4 a 6  et une fois du tour 7 a 9 -> a actualiser dans getz_actions_haut donc fin tour 3, 6 et 9 il faudra la reset des actions possibles.
{
	std::string msg;
	menace_interne* menaceInt = NULL;
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		if (this->getz_joueur_haut(z_joueur_playing)->getj_bots() == BOTS_EVEILLE)
		{
			msg = "[" + z_joueur_playing + " effectue l'action Robot !]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
			menaceInt = checkIfMenaceInternAttrackAction(ACT_R, z_zone, 1);
			if(menaceInt)
			{
				menaceInt->getDamage(this->getz_joueur_haut(z_joueur_playing));
				if(menaceInt->get_m_Ripost())
					this->getz_joueur_haut(z_joueur_playing)->setj_bots(BOTS_INACTIF);
			}
			else
			{
				msg = "[Il n'y a aucun ennemi a proximité... flute.]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
		}
		else if (this->getz_joueur_haut(z_joueur_playing)->getj_bots() == BOTS_INACTIF)
		{
			msg = "[" + z_joueur_playing + " effectue l'action Robot ! Malheureusement, ses robots sont inactifs...]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
		else
		{
			msg = "[" + z_joueur_playing + " effectue l'action Robot ! Malheureusement, il n'a pas de robots avec lui, dommage!]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
	}
	else if (this->getz_joueur_bas(z_joueur_playing))
	{
		if (this->getz_joueur_bas(z_joueur_playing)->getj_bots() == BOTS_EVEILLE)
		{
			msg = "[" + z_joueur_playing + " effectue l'action Robot !]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);

			menaceInt = checkIfMenaceInternAttrackAction(ACT_R, z_zone, 0);
			if(menaceInt)
			{
				menaceInt->getDamage(this->getz_joueur_bas(z_joueur_playing));
				if(menaceInt->get_m_Ripost())
					this->getz_joueur_bas(z_joueur_playing)->setj_bots(BOTS_INACTIF);
			}
			else
			{
				msg = "[Il n'y a aucun ennemi a proximité... flute.]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
		}
		else if (this->getz_joueur_bas(z_joueur_playing)->getj_bots() == BOTS_INACTIF)
		{
			msg = "[" + z_joueur_playing + " effectue l'action Robot ! Malheureusement, ses robots sont inactifs...]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
		else
		{
			msg = "[" + z_joueur_playing + " effectue l'action Robot ! Malheureusement, il n'a pas de robots avec lui, dommage!]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
	}
	else if(z_joueur_intercepteurs)
	{
		msg = "[" + z_joueur_playing + " reste avec les robots dans l'espace!!]\n";
		z_data->text_robot += msg;
		printSlowly(msg, *z_data);
		z_joueur_intercepteurs->attaqueIntercepteur(*z_data);
	}
}

void zone::actionRHeros()//attention la maintenance on ne peut la faire qu'une fois du tour 1 a 3, puis une fois du tour 4 a 6  et une fois du tour 7 a 9 -> a actualiser dans getz_actions_haut donc fin tour 3, 6 et 9 il faudra la reset des actions possibles.
{
	std::string msg = "[ACTION HÉROIQUE DE " + z_joueur_playing + "!!!]\n";
	z_data->text_robot += msg;
	printSlowly(msg, *z_data);
	menace_interne* menaceInt = NULL;
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		if (this->getz_joueur_haut(z_joueur_playing)->getj_bots() == BOTS_EVEILLE)
		{
			msg = "[" + z_joueur_playing + " effectue l'action Robot !]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
			menaceInt = checkIfMenaceInternAttrackAction(ACT_R, z_zone, 1);
			if(menaceInt)
			{
				menaceInt->getDamage(this->getz_joueur_haut(z_joueur_playing));
				if(menaceInt->get_m_Ripost())
				{
					msg = "[La menace riposte mais " + z_joueur_playing + " est un Héro et cette riposte ne l'atteind pas!!]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
				}
			}
			else
			{
				msg = "[Il n'y a aucun ennemi a proximité... flute.]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
		}
		else if (this->getz_joueur_haut(z_joueur_playing)->getj_bots() == BOTS_INACTIF)
		{
			msg = "[" + z_joueur_playing + " effectue l'action Robot ! Malheureusement, ses robots sont inactifs...]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
		else
		{
			msg = "[" + z_joueur_playing + " effectue l'action Robot ! Malheureusement, il n'a pas de robots avec lui, dommage!]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
	}
	else if (this->getz_joueur_bas(z_joueur_playing))
	{
		if (this->getz_joueur_bas(z_joueur_playing)->getj_bots() == BOTS_EVEILLE)
		{
			msg = "[" + z_joueur_playing + " effectue l'action Robot !]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
			menaceInt = checkIfMenaceInternAttrackAction(ACT_R, z_zone, 0);
			if(menaceInt)
			{
				menaceInt->getDamage(this->getz_joueur_bas(z_joueur_playing));
				if(menaceInt->get_m_Ripost())
				{
					msg = "[La menace riposte mais " + z_joueur_playing + " est un Hero et cette riposte ne l'atteind pas!!]\n";
					z_data->text_robot += msg;
					printSlowly(msg, *z_data);
				}
			}
			else
			{
				msg = "[Il n'y a aucun ennemi a proximité... flute.]\n";
				z_data->text_robot += msg;
				printSlowly(msg, *z_data);
			}
		}
		else if (this->getz_joueur_bas(z_joueur_playing)->getj_bots() == BOTS_INACTIF)
		{
			msg = "[" + z_joueur_playing + " effectue l'action Robot ! Malheureusement, ses robots sont inactifs...]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
		else
		{
			msg = "[" + z_joueur_playing + " effectue l'action Robot ! Malheureusement, il n'a pas de robots avec lui, dommage!]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
	}
	else if(z_joueur_intercepteurs)
	{
		msg = "[" + z_joueur_playing + " reste avec les robots dans l'espace!!]\n";
		z_data->text_robot += msg;
		printSlowly(msg, *z_data);
		z_joueur_intercepteurs->attaqueIntercepteurHero(*z_data);
	}
}

