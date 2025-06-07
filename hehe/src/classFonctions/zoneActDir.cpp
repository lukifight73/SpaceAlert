#include "zone.hpp"

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

void zone::ascenseur()
{
	if (this->getz_joueur_haut(z_joueur_playing))
	{
		std::vector<int> actions_used = this->getz_actions_used_ce_tour_haut();
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_haut().begin(), this->getz_actions_haut().end(), DIR_A);
		const std::vector<int>::const_iterator action_ce_tour = std::find(actions_used.begin(), actions_used.end(), DIR_A);
		//std::cout << *action_ce_tour.base() << std::endl;
		// std::cout << "action_ce_tour" << std::endl;
		// std::vector<int> yo = this->getz_actions_used_ce_tour_haut();
		// for (std::vector<int>::const_iterator it = yo.begin(); it != yo.end(); ++it)
		// {
		// 	std::cout << *it << std::endl;
		// }
		if (action_possible != this->getz_actions_haut().end() && action_ce_tour == actions_used.end())
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
		std::vector<int> actions_used = this->getz_actions_used_ce_tour_bas();
		std::vector<int>::const_iterator action_possible = std::find(this->getz_actions_bas().begin(), this->getz_actions_bas().end(), DIR_A);
		const std::vector<int>::const_iterator action_ce_tour = std::find(actions_used.begin(), actions_used.end(), DIR_A);
		if (action_possible != this->getz_actions_bas().end() && action_ce_tour == actions_used.end())
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
