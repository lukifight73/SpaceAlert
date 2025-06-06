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
			std::cout << "Joueur en haut " << data.zones[i]->getz_nom_zone() << " : " << (*it)->getj_nom() << std::endl;
		}
		for (std::vector<joueur*>::iterator it = joueurs_bas.begin(); it != joueurs_bas.end(); ++it)
		{
			std::cout << "Joueur en bas " <<  data.zones[i]->getz_nom_zone() << " : " << (*it)->getj_nom() << std::endl;
		}
		i++;
	}
}

std::string get_action(int action)
{
	if (action == ACT_A)
		return "ACT_A";
	else if (action == ACT_B)
		return "ACT_B";
	else if (action == ACT_C)
		return "ACT_C";
	else if (action == ACT_R)
		return "ACT_R";
	else if (action == ACT_AH)
		return "ACT_AH";
	else if (action == ACT_BH)
		return "ACT_BH";
	else if (action == DIR_R)
		return "DIR_R";
	else if (action == DIR_B)
		return "DIR_B";
	else if (action == DIR_A)
		return "DIR_A";
	else
		return "INACTIF";
}

void	action_joueur(t_data &data, carte& carte, int joueur)
{
	int zone = data.joueurs[joueur]->getj_zone();
	std::cout << "carte : " << get_action(carte.getc_action()) << std::endl;
	std::cout << "zone : " << zone << std::endl;
	if (carte.getc_action() == ACT_A)
	{
		data.zones[zone]->actionA();
	}
	else if (carte.getc_action() == ACT_B)
	{
		data.zones[zone]->actionB();
	}
	else if (carte.getc_action() == ACT_BH)
	{
		data.zones[zone]->actionBHeros();
	}
	else if (carte.getc_action() == ACT_AH)
	{
		data.zones[zone]->actionAHeros();
	}
	else if (carte.getc_action() == ACT_C)
	{
		data.zones[zone]->actionC();
	}
	else if (carte.getc_action() == DIR_B)
	{
		data.zones[zone]->flechesBleue();
	}
	else if (carte.getc_action() == DIR_R)
	{
		data.zones[zone]->flechesRouge();
	}
	else if (carte.getc_action() == DIR_A)
	{
		data.zones[zone]->ascenseur();
	}
}

void init_zone_for_each_round(t_data &data, std::string nom_joueur)
{
	int i = 1;
	while (i < 4)
	{
		data.zones[i]->setz_joueur_playing(nom_joueur);
		data.zones[i]->clearz_actions_used_ce_tour_bas();
		data.zones[i]->clearz_actions_used_ce_tour_haut();
		i++;
	}
}


void	play_game(t_data &data)
{
	while (data.tour < 13)
	{
		int i(1);
		std::cout << "\n\n\n\n\n----------------------------------- TOUR : " << data.tour << "----------------------------\n\n\n" << std::endl;
		print_joueur_zone(data);
		while (i <= data.nb_joueur)
		{
			std::cout << "\n----------------------------------- joueur n " << i << " playing : " << data.joueurs[i]->getj_nom() << "----------------------------" << std::endl;
			init_zone_for_each_round(data, data.joueurs[i]->getj_nom());
			carte action = data.joueurs[i]->getcartes()[data.tour];
			apparitionMenaces(data);
			action_joueur(data, action, i);
			std::cout << "\n----------------------------------- fin tour joueur n " << i << " : " << data.joueurs[i]->getj_nom() << "----------------------------" << std::endl;
			i++;
		}
		print_data(data);
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
