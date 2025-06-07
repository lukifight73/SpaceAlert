#include "space_alerte.hpp"
#include "SA_Values.hpp"

void erase_data(t_data& data)
{
	int i(0);
	while (i < data.nb_joueur)
	{
		delete data.joueurs[i];
		i++;
	}
	delete data.zones[ZONE_BAS_BLUE];
	delete data.zones[ZONE_HAUT_BLUE];
	delete data.zones[ZONE_HAUT_WHITE];
	delete data.zones[ZONE_HAUT_RED];
	delete data.zones[ZONE_BAS_WHITE];
	delete data.zones[ZONE_BAS_RED];
}


void print_data(t_data& data)
{
	std::cout << "-----------------------------------------DATA-------------------------------------------" << std::endl;
	std::cout << "Nombre de joueur : " << data.nb_joueur << std::endl;
	std::cout << "Tour : " << data.tour << std::endl;
	int i(1);
	while (i <= data.nb_joueur)
	{
		data.joueurs[i]->print();
		i++;
	}
	std::cout << "-----------------------------------------DATA-------------------------------------------" << std::endl << std::endl;
}

void print_joueur_zone(t_data &data)
{
	int i(1);
	while (i < 4)
	{
		std::vector <joueur*> joueurs_haut = data.zones[i]->getz_joueurs_haut();
		std::vector <joueur*> joueurs_bas = data.zones[i]->getz_joueurs_bas();
		for (std::vector<joueur*>::iterator it = joueurs_haut.begin(); it != joueurs_haut.end(); ++it)
		{
			std::cout << "Joueur " << (*it)->getj_number() << " en haut de la " << data.zones[i]->getz_nom_zone() << " : " << (*it)->getj_nom() << std::endl;
		}
		for (std::vector<joueur*>::iterator it = joueurs_bas.begin(); it != joueurs_bas.end(); ++it)
		{
			std::cout << "Joueur " << (*it)->getj_number() << " en bas de la " << data.zones[i]->getz_nom_zone() << " : " << (*it)->getj_nom() << std::endl;
		}
		i++;
	}
}

// on clear et reset tout ce qui doit l etre
void clear_actionUsage(t_data &data)
{
	int i(1);
	while (i < 4)
	{
		data.zones[i]->clearz_actions_used_ce_tour_bas();
		data.zones[i]->clearz_actions_used_ce_tour_haut();
		data.zones[i]->clearz_cannon_used();
		std::vector<menace*> vecteur_menace = data.zones[i]->getz_chemin_menace()->get_menaces();
		for (std::vector<menace*>::iterator it = vecteur_menace.begin(); it != vecteur_menace.end(); ++it)
		{
			(*it)->clear_m_canon_used();
			(*it)->set_m_degatsRecus(0);
		}
		i++;
	}
}

// clarifie quelle joueur est en action
void setPlayerEngaged(t_data &data, std::string nom_joueur)
{
	int i = 1;
	while (i < 4)
	{
		data.zones[i]->setz_joueur_playing(nom_joueur);
		i++;
	}
}

void check_maintenance(t_data &data)
{
	
	if (data.tour == 3 || data.tour == 6 || data.tour == 9)
	{
		std::vector<int> maintenance = data.zones[ZONE_WHITE]->getz_maintenance_ordinateur();
		for (std::vector<int>::iterator it = maintenance.begin(); it != maintenance.end(); it++)
		{
			if (data.tour == 3 && (*it == 1 || *it == 2 || *it == 3))
			{
				std::cout << "Maintenance de l'ordinateur effectuée pour le tour " << data.tour << std::endl;
				return;
			}
			else if (data.tour == 6 && (*it == 4 || *it == 5 || *it == 6))
			{
				std::cout << "Maintenance de l'ordinateur effectuée pour le tour " << data.tour << std::endl;
				return;
			}
			else if (data.tour == 9 && (*it == 7 || *it == 8 || *it == 9))
			{
				std::cout << "Maintenance de l'ordinateur effectuée pour le tour " << data.tour << std::endl;
				return;
			}
		}
		std::cout << "La maintenance de l'ordinateur n'a pas ete effectuée avant le tour " << data.tour << std::endl;
		std::cout << "tous les joueurs voient leurs actions decalees d'un tour." << std::endl;
		for (int i = 1; i <= data.nb_joueur; i++)
		{
			data.joueurs[i]->passerTour(data.tour);
		}
	}
}

void setTemps(t_data &data)
{
	int i(1);
	while (i < 4)
	{
		data.zones[i]->addtemps();
		i++;
	}
} 

void	play_game(t_data &data)
{
	while (data.tour < 13)//commence a 1 et finit a 12	
	{
		int num_joueur(1);
		std::cout << "\n\n\n\n\n------------------------------------------------------------------------------" << std::endl;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		std::cout << "----------------------------------- TOUR : " << data.tour << " -----------------------------------\n\n" << std::endl;
		apparitionMenaces(data);
		print_joueur_zone(data);
		clear_actionUsage(data);
		while (num_joueur <= data.nb_joueur)
		{
			std::cout << "----------------------------------- JOUEUR n " << num_joueur << " playing : " << data.joueurs[num_joueur]->getj_nom() << "----------------------------" << std::endl;
			setPlayerEngaged(data, data.joueurs[num_joueur]->getj_nom());
			action_joueur(data, num_joueur);
			std::cout << "----------------------------------- fin tour joueur n " << num_joueur << " : " << data.joueurs[num_joueur]->getj_nom() << "----------------------------" << std::endl;
			num_joueur++;
		}
		assignationCannons(data);
		analyseDesDegatsCanons(data);
		mouvement_menaces(data);
	    remove_dead_or_outdated_menaces(data);
		std::cout << "\n\n----------------------------- INFORMATIONS MENACE -----------------------------" << std::endl;
		for (int i = 1; i < 4; i++) 
		{
			std::vector<menace*> tmp = data.zones[i]->getz_chemin_menace()->get_menaces();
			std::cout << "--------------------INFORMATION MENACE ZONE " << data.zones[i]->getz_nom_zone() << "----------------------" << std::endl;
			for (std::vector<menace*>::iterator it = tmp.begin(); it != tmp.end(); ++it) 
			{
				(*it)->print_menace();
			}
		}
		std::cout << "----------------------------- FIN INFORMATIONS MENACE -----------------------------" << std::endl;
		check_maintenance(data);
		//print_data(data);
		setTemps(data);
		data.tour++;
	}
}


int main(int ac, char* *av)
{
    if(ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " <config_file>" << std::endl;
		return 1;
	}
	t_data data;

	init_data(data);
	parsing_config(data, av[1]);
	//init_carte_joueur_test(data);
	print_data(data);
	play_game(data);
	erase_data(data);
}
