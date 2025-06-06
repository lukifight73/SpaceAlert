#include "space_alerte.hpp"
#include "space_alerte_values.hpp"


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
	int i(0);
	while (i < data.nb_joueur)
	{
		data.joueurs[i]->print();
		i++;
	}
	std::cout << "-----------------------------------------DATA-------------------------------------------" << std::endl << std::endl;
}

void	action_joueur(t_data &data, carte& carte, int joueur)
{
	int zone = data.joueurs[joueur]->getj_zone() % 3;
	std::cout << "carte : " << carte.getc_action() << std::endl;
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

void put_joueur_playing(t_data &data, std::string nom_joueur)
{
	int i = 1;
	while (i < 4)
	{
		data.zones[i]->setz_joueur_playing(nom_joueur);
		i++;
	}
}

void	play_game(t_data &data)
{
	while (data.tour < 13)
	{
		int i(0);
		while (i < data.nb_joueur)
		{
			std::cout << "joueur playing : " << data.joueurs[i]->getj_nom() << std::endl;
			put_joueur_playing(data, data.joueurs[i]->getj_nom());
			carte action = data.joueurs[i]->getcartes()[data.tour];
			action_joueur(data, action, i);
			i++;
		}
		print_data(data);
		data.tour++;
	}
}

int main(void)
{
    t_data data;

	init_data(data);
	init_carte_joueur_test(data);
	print_data(data);
	play_game(data);
	erase_data(data);
}
