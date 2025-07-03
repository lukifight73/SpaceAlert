#include "zone.hpp"

void zone::flechesRouge()
{
	std::string msg;
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		if (this->action_possible_haut(DIR_R))
		{
			msg = "[" + z_joueur_playing + " se déplace.]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
			if (z_zone == ZONE_BLUE)
			{
				this->getz_joueur_haut(this->getz_joueur_playing())->setj_zone(ZONE_WHITE);
				zone_left->addz_joueurs_haut(this->getz_joueur_haut(z_joueur_playing));
				this->removez_joueurs_haut(z_joueur_playing);
				msg = "[" + z_joueur_playing + " arrive en zone blanche, en haut.]\n";
			}
			if (z_zone == ZONE_WHITE)
			{
				this->getz_joueur_haut(this->getz_joueur_playing())->setj_zone(ZONE_RED);
				zone_left->addz_joueurs_haut(this->getz_joueur_haut(z_joueur_playing));
				this->removez_joueurs_haut(z_joueur_playing);
				msg = "[" + z_joueur_playing + " arrive en zone rouge, en haut.]\n";
			}
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
		else
		{
			msg = "[" + z_joueur_playing + " ne peux pas se déplacer par la.]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
	}
	else if (this->getz_joueur_bas(z_joueur_playing))
	{
		if (this->action_possible_bas(DIR_R))
		{
			msg = "[" + z_joueur_playing + " se déplace.]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
			if (z_zone == ZONE_BLUE)
			{
				msg = this->getz_joueur_bas(this->getz_joueur_playing())->getj_nom() + this->getz_joueur_playing() + "\n";
				printSlowly(msg, *z_data);
				this->getz_joueur_bas(this->getz_joueur_playing())->setj_zone(ZONE_WHITE);
				zone_left->addz_joueurs_bas(this->getz_joueur_bas(z_joueur_playing));
				this->removez_joueurs_bas(z_joueur_playing);
				msg = "[" + z_joueur_playing + " arrive en zone blanche, en bas.]\n";
			}
			if (z_zone == ZONE_WHITE)
			{
				this->getz_joueur_bas(this->getz_joueur_playing())->setj_zone(ZONE_RED);
				zone_left->addz_joueurs_bas(this->getz_joueur_bas(z_joueur_playing));
				this->removez_joueurs_bas(z_joueur_playing);
				msg = "[" + z_joueur_playing + " arrive en zone rouge, en bas.]\n";
			}
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
		else
		{
			msg = "[" + z_joueur_playing + " ne peux pas se déplacer par la.]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
	}
	else if(z_joueur_intercepteurs)
		wrongActionInSpace();
}

void zone::flechesBleue()
{
	std::string msg;
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		if (this->action_possible_haut(DIR_B))
		{
			msg = "[" + z_joueur_playing + " se déplace.]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
			if (z_zone == ZONE_RED)
			{
				this->getz_joueur_haut(this->getz_joueur_playing())->setj_zone(ZONE_WHITE);
				zone_right->addz_joueurs_haut(this->getz_joueur_haut(z_joueur_playing));
				this->removez_joueurs_haut(z_joueur_playing);
				msg = "[" + z_joueur_playing + " arrive en zone blanche, en haut.]\n";
			}
			if (z_zone == ZONE_WHITE)
			{
				this->getz_joueur_haut(this->getz_joueur_playing())->setj_zone(ZONE_BLUE);
				zone_right->addz_joueurs_haut(this->getz_joueur_haut(z_joueur_playing));
				this->removez_joueurs_haut(z_joueur_playing);
				msg = "[" + z_joueur_playing + " arrive en zone bleue, en haut.]\n";
			}
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
		else
		{
			msg = "[" + z_joueur_playing + " ne peux pas se déplacer par la.]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
	}
	else if (this->getz_joueur_bas(z_joueur_playing))
	{
		if (this->action_possible_bas(DIR_B))
		{
			msg = "[" + z_joueur_playing + " se déplace.]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
			if (z_zone == ZONE_RED)
			{
				this->getz_joueur_bas(this->getz_joueur_playing())->setj_zone(ZONE_WHITE);
				zone_right->addz_joueurs_bas(this->getz_joueur_bas(z_joueur_playing));
				this->removez_joueurs_bas(z_joueur_playing);
				msg = "[" + z_joueur_playing + " arrive en zone blanche, en bas.]\n";
			}
			if (z_zone == ZONE_WHITE)
			{
				this->getz_joueur_bas(this->getz_joueur_playing())->setj_zone(ZONE_BLUE);
				zone_right->addz_joueurs_bas(this->getz_joueur_bas(z_joueur_playing));
				this->removez_joueurs_bas(z_joueur_playing);
				msg = "[" + z_joueur_playing + " arrive en zone bleue, en bas.]\n";
			}
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
		else
		{
			msg = "[" + z_joueur_playing + " ne peux pas se déplacer par la.]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
	}
	else if(z_joueur_intercepteurs)
		wrongActionInSpace();
}

void zone::ascenseur()
{
	std::string msg;
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		if (this->action_possible_haut(DIR_A) && !this->action_used_ce_tour_haut(DIR_A))
		{
			msg = "[" + z_joueur_playing + " prend l'ascenseur pour descendre d'un etage.]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
			msg = "[" + z_joueur_playing + " arrive en bas, dans la " + this->getz_nom_zone() + ".]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
			this->addz_actions_used_ce_tour_haut(DIR_A);
			this->addz_actions_used_ce_tour_bas(DIR_A);
			this->addz_joueurs_bas(this->getz_joueur_haut(z_joueur_playing));
			this->removez_joueurs_haut(z_joueur_playing);
		}
		else
		{
			msg = "[" + z_joueur_playing + " ne peux pas se déplacer par la.]\n";
			printSlowly(msg, *z_data);
		}
	}
	else if (this->getz_joueur_bas(z_joueur_playing))
	{
		if (this->action_possible_bas(DIR_A) && !this->action_used_ce_tour_bas(DIR_A))
		{
			msg = "[" + z_joueur_playing + " prend l'ascenseur pour monter d'un etage.]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
			msg = "[" + z_joueur_playing + " arrive en haut, dans la " + this->getz_nom_zone() + ".]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
			this->addz_actions_used_ce_tour_haut(DIR_A);
			this->addz_actions_used_ce_tour_bas(DIR_A);
			this->addz_joueurs_haut(this->getz_joueur_bas(z_joueur_playing));
			this->removez_joueurs_bas(z_joueur_playing);
		}
		else
		{
			msg = "[" + z_joueur_playing + " ne peux pas se déplacer par la.]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
		}
	}
	else if(z_joueur_intercepteurs)
		wrongActionInSpace();
}

void zone::moveplayerzone(zone *zone_to_move, bool direction_haut)
{
	std::string msg;
	if (!direction_haut)
		msg = "[" + z_joueur_playing + " se déplace en bas, dans la " + zone_to_move->getz_nom_zone() + ".]\n";
	else
		msg = "[" + z_joueur_playing + " se déplace en haut, dans la " + zone_to_move->getz_nom_zone() + ".]\n";
	z_data->text_robot += msg;
	printSlowly(msg, *z_data);
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		this->getz_joueur_haut(z_joueur_playing)->setj_zone(zone_to_move->getz_zone());
		if (direction_haut)
			zone_to_move->addz_joueurs_haut(this->getz_joueur_haut(z_joueur_playing));
		else
			zone_to_move->addz_joueurs_bas(this->getz_joueur_haut(z_joueur_playing));
		this->removez_joueurs_haut(z_joueur_playing);
	}
	else if (this->getz_joueur_bas(z_joueur_playing))
	{
		this->getz_joueur_bas(z_joueur_playing)->setj_zone(zone_to_move->getz_zone());
		if (direction_haut)
			zone_to_move->addz_joueurs_haut(this->getz_joueur_bas(z_joueur_playing));
		else
			zone_to_move->addz_joueurs_bas(this->getz_joueur_bas(z_joueur_playing));
		this->removez_joueurs_bas(z_joueur_playing);
	}
	else if(z_joueur_intercepteurs)
	{
		z_joueur_intercepteurs->setj_zone(zone_to_move->getz_zone());
		if (direction_haut)
			zone_to_move->addz_joueurs_haut(z_joueur_intercepteurs);
		else
			zone_to_move->addz_joueurs_bas(z_joueur_intercepteurs);
		z_joueur_playing = nullptr;
	}
}

void zone::dirHeroique(int action_heroique)
{
	std::string msg;
	msg = "[ACTION TELEPORTATION HEROIQUE !!!]\n";
	z_data->text_robot += msg;
	printSlowly(msg, *z_data);
	if (action_heroique == DIR_RB)
		moveplayerzone(this->getzone_red(), false);
	else if (action_heroique == DIR_RH)
		moveplayerzone(this->getzone_red(), true);
	else if (action_heroique == DIR_WB)
		moveplayerzone(this->getzone_white(), false);
	else if (action_heroique == DIR_WH)
		moveplayerzone(this->getzone_white(), true);
	else if (action_heroique == DIR_BB)
		moveplayerzone(this->getzone_blue(), false);
	else if (action_heroique == DIR_BH)
		moveplayerzone(this->getzone_blue(), true);
}

void zone::inactif()
{
	std::string msg;
	if(!z_joueur_intercepteurs)
	{
		msg = "[" + z_joueur_playing + " est inactif!]\n";
		z_data->text_robot += msg;
		printSlowly(msg, *z_data);
	}
	else
	{
		if(z_joueur_intercepteurs->getj_nom() == z_joueur_playing)
		{
			msg = "[" + z_joueur_playing + " reviens dans le vaisseau !]\n";
			z_data->text_robot += msg;
			printSlowly(msg, *z_data);
			this->addz_joueurs_haut(z_joueur_intercepteurs);
			this->removez_joueur_intercepteurs();
		}
	}
}
