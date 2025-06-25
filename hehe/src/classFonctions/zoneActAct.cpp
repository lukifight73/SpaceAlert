#include "zone.hpp"
#include "menace_interne.hpp"

void zone::actionA()
{
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
					wr("[ATTACK avec le " + this->getz_cannon_haut()->getnom_cannon() + " !]");
					z_reacteur -= 1;
					std::cout << "[Carburant disponible : " << z_reacteur << "]\n";
					this->addz_actions_used_ce_tour_haut(ACT_A);
					addz_cannon_used(this->getz_cannon_haut());
					this->getz_cannon_haut()->setcanon_used(true);
					this->getz_cannon_haut()->settireur(z_joueur_playing);
				}
				else
				{
					wr("[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " ... Echec par manque d'energie! Dommage...]");
					this->addz_actions_used_ce_tour_haut(ACT_A);
				}
			}
			else if (this->action_used_ce_tour_haut(ACT_A) && this->action_possible_haut(ACT_A)) //action deja utilisee ce tour
			{
				wr("[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " Echec, coordonnez vous bordel]");
			}
			else
				wr("[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " Echec, impossible d'utiliser cet arme ce tour]");
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
						wr("[ATTACK avec le " + this->getz_cannon_bas()->getnom_cannon() + " !]\n");
						z_reacteur -= 1;
						std::cout << "[Carburant disponible : " << z_reacteur << "]\n";
					}
					else
					{
						std::cout << "[Echec de l'attack avec le " + this->getz_cannon_bas()->getnom_cannon() + " par manque d'energie...]\n";
						return ;
					}
				}
				else
				{
					wr("[ATTACK avec le " + this->getz_cannon_bas()->getnom_cannon() + " !]\n");
				}
				this->addz_actions_used_ce_tour_bas(ACT_A);
				addz_cannon_used(this->getz_cannon_bas());
				this->getz_cannon_bas()->setcanon_used(true);
				this->getz_cannon_bas()->settireur(z_joueur_playing);
			}
			else if (this->action_used_ce_tour_bas(ACT_A))
			{
				wr("[Les frerots la coordination c'est pas votre fort...]\n");
			}
			else
				wr("[Tentative d'attack avec " + this->getz_cannon_bas()->getnom_cannon() + " Echec, impossible d'utiliser cet arme ce tour]");
		}
	}
	else if(z_joueur_intercepteurs)
		wrongActionInSpace();
}

void zone::actionAHeros()
{
	wr("[ACTION HEROIQUE !!!]");
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
					wr("[ATTACK avec le " + this->getz_cannon_haut()->getnom_cannon() + " !]");
					z_reacteur -= 1;
					std::cout << "[Carburant disponible : " << z_reacteur << "]\n";
					this->addz_actions_used_ce_tour_haut(ACT_A);
					addz_cannon_used(this->getz_cannon_haut());
					this->getz_cannon_haut()->setcanon_used(true);
					this->getz_cannon_haut()->setactionHeroique(true);
					this->getz_cannon_haut()->settireur("ACTION HEROHIQUE! " + z_joueur_playing);
				}
				else
				{
					wr("[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " ... Echec par manque d'energie! Dommage...]");
					this->addz_actions_used_ce_tour_haut(ACT_A);
				}
			}
			else if (this->action_used_ce_tour_haut(ACT_A) && this->action_possible_haut(ACT_A)) //action deja utilisee ce tour
			{
				wr("[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " Echec, coordonnez vous bordel]");
			}
			else
				wr("[Tentative d'attack avec " + this->getz_cannon_haut()->getnom_cannon() + " Echec, impossible d'utiliser cet arme ce tour]");
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
							wr("[ATTACK avec le " + this->getz_cannon_bas()->getnom_cannon() + " !]\n");
							z_reacteur -= 1;
							std::cout << "[Carburant disponible : " << z_reacteur << "]\n";
						}
						else
						{
							std::cout << "[Echec de l'attack avec le " + this->getz_cannon_bas()->getnom_cannon() + " par manque d'energie...]\n";
							return ;
						}
					}
					else
					{
						wr("[ATTACK avec le " + this->getz_cannon_bas()->getnom_cannon() + " !]\n");
					}
					this->getz_cannon_bas()->setactionHeroique(true);
					this->addz_actions_used_ce_tour_bas(ACT_A);
					addz_cannon_used(this->getz_cannon_bas());
					this->getz_cannon_bas()->setcanon_used(true);
					this->getz_cannon_bas()->settireur("ACTION HEROHIQUE! " + z_joueur_playing);
			}
			else if (this->action_used_ce_tour_bas(ACT_A))
			{
				wr("[Les frerots la coordination c'est pas votre fort...]\n");
			}
			else
				wr("[Tentative d'attack avec " + this->getz_cannon_bas()->getnom_cannon() + " Echec, impossible d'utiliser cet arme ce tour]");
		}
	}
	else if(z_joueur_intercepteurs)
		wrongActionInSpace();
}

void zone::actionB()
{
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
	else if(z_joueur_intercepteurs)
		wrongActionInSpace();
}

void zone::actionBHeros()
{
	wr("[ACTION HEROIQUE !!!]");
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
	else if(z_joueur_intercepteurs)
		wrongActionInSpace();
}

menace_interne* zone::checkIfMenaceInternAttrackAction(int joueurAction, int Zone, bool haut)
{
	std::vector<menace_interne*> tmp = this->getz_chemin_menace_Int()->get_menacesInte();
	for (std::vector<menace_interne*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		if((*it)->AttractAction(joueurAction, Zone, haut))
			return (*it); // si on veut optimiser il faut checker s il y en a plusieur!!
	}
	return NULL;
}

void zone::actionC()//attention la maintenance on ne peut la faire qu'une fois du tour 1 a 3, puis une fois du tour 4 a 6  et une fois du tour 7 a 9 -> a actualiser dans getz_actions_haut donc fin tour 3, 6 et 9 il faudra la reset des actions possibles.
{
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
					wr("[Vous faites la maintenance!]");
					this->addz_actions_used_ce_tour_haut(ACT_C);
					//this->removez_actions_haut(ACT_C);
				}
				else if (!this->action_possible_haut(ACT_C))
					wr("[Impossible de faire la maintenance maintenant!]");
				else
					wr("[Cette action a deja ete faite ce tour... staffez vous!]");
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
						wr("[Vous prenez les robots avec vous! C'est parti pour la baston!]");
						z_bots = false;
						this->getz_joueur_haut(z_joueur_playing)->setj_bots(1);
					}
					else if (this->getz_joueur_haut(z_joueur_playing)->getj_bots() == 2)
					{
						wr("[Vous reactivez les robots qui vous accompagnent!]");
						this->getz_joueur_haut(z_joueur_playing)->setj_bots(1);
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
						wr("[Impossible de prendre les vaisseaux, ils sont deja en vol!]\n");
					}
					else if (this->getz_joueur_haut(z_joueur_playing)->getj_bots() == BOTS_EVEILLE)
					{
						this->getz_joueur_haut(z_joueur_playing)->attaqueIntercepteur(*z_data);
						this->setz_joueur_intercepteurs(this->getz_joueur_haut(z_joueur_playing));
						this->removez_joueurs_haut(z_joueur_playing);
						wr("[Vous vous envolez avec les robots dans l'espace!!]");
					}
					else if (this->getz_joueur_haut(z_joueur_playing)->getj_bots() != BOTS_EVEILLE)
						wr("[Impossible de prendre les vaisseaux, tu n'as pas de robots operationel avec toi!]\n");
				}
				else
				{
					wr("[Impossible de prendre les vaisseaux a ce tour, dommage!]\n");
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
						wr("[Lancement de la premiere rocket !]");
						z_roquete_position[1] = 1;
						this->addz_actions_used_ce_tour_bas(ACT_C);
					}
					else if (z_roquete_position[2] == 0)
					{
						wr("[Lancement de la seconde rocket !]");
						z_roquete_position[2] = 1;
						this->addz_actions_used_ce_tour_bas(ACT_C);
					}
					else if (z_roquete_position[3] == 0)
					{
						wr("[Lancement de la troisieme rocket !]");
						z_roquete_position[3] = 1;
						this->addz_actions_used_ce_tour_bas(ACT_C);
					}
					else
					{
						wr("[Toutes les roquetes ont deja ete lancees... pas la peine de s'exciter frere]");
					}
					std::cout << z_roquete_position[1] << "\n";
					std::cout << z_roquete_position[2] << "\n";
					std::cout << z_roquete_position[3] << "\n";
				}
				else if (this->action_used_ce_tour_bas(ACT_C))
				{
					wr("[Mais coordonnez vous bordel]");
				}
				else if (!this->action_possible_bas(ACT_C))
				{
					wr("[Impossible de lancer les roquettes]");
				}
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
							wr("[Vous prenez les robots avec vous! Ils sont englues, il faut donc les activer une seconde fois!]");
						}
						else
						{
							this->getz_joueur_bas(z_joueur_playing)->setj_bots(1);
							wr("[Vous prenez les robots avec vous! C'est parti pour la baston!]");
						}
						z_bots = false;
					}
					else if (this->getz_joueur_bas(z_joueur_playing)->getj_bots() == 2)
					{
						wr("[Vous reactivez les robots qui vous accompagnent!]");
						this->getz_joueur_bas(z_joueur_playing)->setj_bots(1);
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
				wr("[Vous effectuez une observation de vos alentours, en toute detente.]\n");
			}
		}
	}
	else if(z_joueur_intercepteurs)
		wrongActionInSpace();
}

zone::~zone() {}

void zone::actionR()//attention la maintenance on ne peut la faire qu'une fois du tour 1 a 3, puis une fois du tour 4 a 6  et une fois du tour 7 a 9 -> a actualiser dans getz_actions_haut donc fin tour 3, 6 et 9 il faudra la reset des actions possibles.
{
	menace_interne* menaceInt = NULL;
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		if (this->getz_joueur_haut(z_joueur_playing)->getj_bots() == BOTS_EVEILLE)
		{
			wr("[Vous effectuez l'action Robot !]");
			menaceInt = checkIfMenaceInternAttrackAction(ACT_R, z_zone, 1);
			if(menaceInt)
			{
				menaceInt->getDamage(this->getz_joueur_haut(z_joueur_playing));
				if(menaceInt->get_m_Ripost())
					this->getz_joueur_haut(z_joueur_playing)->setj_bots(BOTS_INACTIF);
			}
			else
				wr("[Il n'y a aucun ennemi a proximite... flute.]");
		}
		else if (this->getz_joueur_haut(z_joueur_playing)->getj_bots() == BOTS_INACTIF)
			wr("[Vous effectuez l'action Robot ! Malheureusement, vos robots sont inactifs...]");
		else
			wr("[Vous effectuez l'action Robot ! Malheureusement, vous n'avez pas de robots avec vous, dommage!]");
	}
	else if (this->getz_joueur_bas(z_joueur_playing))
	{
		if (this->getz_joueur_bas(z_joueur_playing)->getj_bots() == BOTS_EVEILLE)
		{
			wr("[Vous effectuez l'action Robot !]");
			menaceInt = checkIfMenaceInternAttrackAction(ACT_R, z_zone, 0);
			if(menaceInt)
			{
				menaceInt->getDamage(this->getz_joueur_bas(z_joueur_playing));
				if(menaceInt->get_m_Ripost())
					this->getz_joueur_bas(z_joueur_playing)->setj_bots(BOTS_INACTIF);
			}
			else
				wr("[Il n'y a aucun ennemi a proximite... flute.]");
		}
		else if (this->getz_joueur_bas(z_joueur_playing)->getj_bots() == BOTS_INACTIF)
			wr("[Vous effectuez l'action Robot ! Malheureusement, vos robots sont inactifs...]");
		else
			wr("[Vous effectuez l'action Robot ! Malheureusement, vous n'avez pas de robots avec vous, dommage!]");
	}
	else if(z_joueur_intercepteurs)
	{
		wr("[Vous restez avec les robots dans l'espace!!]");
		z_joueur_intercepteurs->attaqueIntercepteur(*z_data);
	}
}

void zone::actionRHeros()//attention la maintenance on ne peut la faire qu'une fois du tour 1 a 3, puis une fois du tour 4 a 6  et une fois du tour 7 a 9 -> a actualiser dans getz_actions_haut donc fin tour 3, 6 et 9 il faudra la reset des actions possibles.
{
	wr("[ACTION HEROIQUE !!!]");
	menace_interne* menaceInt = NULL;
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		if (this->getz_joueur_haut(z_joueur_playing)->getj_bots() == BOTS_EVEILLE)
		{
			wr("[Vous effectuez l'action Robot !]");
			menaceInt = checkIfMenaceInternAttrackAction(ACT_R, z_zone, 1);
			if(menaceInt)
			{
				menaceInt->getDamageHero(this->getz_joueur_haut(z_joueur_playing));
				if(menaceInt->get_m_Ripost())
					wr("[La menace riposte mais vous etes un Hero et cette riposte ne vous attend pas!!]");
			}
			else
				wr("[Il n'y a aucun ennemi a proximite... flute.]");
		}
		else if (this->getz_joueur_haut(z_joueur_playing)->getj_bots() == BOTS_INACTIF)
			wr("[Vous effectuez l'action Robot ! Malheureusement, vos robots sont inactifs...]");
		else
			wr("[Vous effectuez l'action Robot ! Malheureusement, vous n'avez pas de robots avec vous, dommage!]");
	}
	else if (this->getz_joueur_bas(z_joueur_playing))
	{
		if (this->getz_joueur_bas(z_joueur_playing)->getj_bots() == BOTS_EVEILLE)
		{
			wr("[Vous effectuez l'action Robot !]");
			menaceInt = checkIfMenaceInternAttrackAction(ACT_R, z_zone, 0);
			if(menaceInt)
			{
				menaceInt->getDamageHero(this->getz_joueur_bas(z_joueur_playing));
				if(menaceInt->get_m_Ripost())
					wr("[La menace riposte mais vous etes un Hero et cette riposte ne vous attend pas!!]");
			}
			else
				wr("[Il n'y a aucun ennemi a proximite... flute.]");
		}
		else if (this->getz_joueur_bas(z_joueur_playing)->getj_bots() == BOTS_INACTIF)
			wr("[Vous effectuez l'action Robot ! Malheureusement, vos robots sont inactifs...]");
		else
			wr("[Vous effectuez l'action Robot ! Malheureusement, vous n'avez pas de robots avec vous, dommage!]");
	}
	else if(z_joueur_intercepteurs)
	{
		wr("[Vous restez avec les robots dans l'espace!!]");
		z_joueur_intercepteurs->attaqueIntercepteurHero(*z_data);
	}
}

