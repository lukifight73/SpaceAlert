#include "space_alerte.hpp"
#include "space_alerte_values.hpp"
#include "space_alerte_struct.hpp"
#include "space_alerte_class.hpp"


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
/*
carte_action
#define INACTIF 0
#define ACT_A 1
#define ACT_B 2
#define ACT_C 3
#define ACT_R 4

carte_action_hero
#define ACT_AH 5
#define ACT_BH 6
#define ACT_RH 7

carte_deplacement
#define DIR_R 8
#define DIR_B 9
#define DIR_A 10*/

void init_carte_joueur_test(t_data& data)
{
	int i(0);
	carte carte_ACT_A(ACT_A);
	carte carte_ACT_B(ACT_B);
	carte carte_ACT_C(ACT_C);
	carte carte_DIR_A(DIR_A);
	carte carte_DIR_B(DIR_B);
	carte carte_DIR_R(DIR_R);
	carte carte_ACT_R(ACT_R);
	carte carte_ACT_AH(ACT_AH);
	carte carte_ACT_BH(ACT_BH);
	carte carte_INACTIF(INACTIF);
	data.joueurs[i]->addcartes(1, carte_ACT_C);
	data.joueurs[i]->addcartes(2, carte_ACT_C);
	data.joueurs[i]->addcartes(3, carte_INACTIF);
	data.joueurs[i]->addcartes(4, carte_ACT_C);
	data.joueurs[i]->addcartes(9, carte_DIR_B);
	data.joueurs[i]->addcartes(6, carte_ACT_R);
	data.joueurs[i]->addcartes(7, carte_ACT_A);
	data.joueurs[i]->addcartes(8, carte_DIR_A);
	data.joueurs[i]->addcartes(9, carte_DIR_A);
	data.joueurs[i]->addcartes(10, carte_ACT_B);
	data.joueurs[i]->addcartes(11, carte_ACT_A);
	data.joueurs[i]->addcartes(12, carte_INACTIF);
	i++;
	data.joueurs[i]->addcartes(1, carte_DIR_R);
	data.joueurs[i]->addcartes(2, carte_ACT_B);
	data.joueurs[i]->addcartes(3, carte_DIR_A);
	data.joueurs[i]->addcartes(4, carte_ACT_B);
	data.joueurs[i]->addcartes(5, carte_ACT_AH);
	data.joueurs[i]->addcartes(6, carte_ACT_R);
	data.joueurs[i]->addcartes(7, carte_DIR_A);
	data.joueurs[i]->addcartes(8, carte_DIR_B);
	data.joueurs[i]->addcartes(9, carte_ACT_C);
	data.joueurs[i]->addcartes(10, carte_ACT_B);
	data.joueurs[i]->addcartes(11, carte_ACT_A);
	data.joueurs[i]->addcartes(12, carte_ACT_A);
	i++;
	data.joueurs[i]->addcartes(1, carte_DIR_A);
	data.joueurs[i]->addcartes(2, carte_ACT_A);
	data.joueurs[i]->addcartes(3, carte_ACT_B);
	data.joueurs[i]->addcartes(4, carte_ACT_C);
	data.joueurs[i]->addcartes(5, carte_ACT_B);
	data.joueurs[i]->addcartes(6, carte_DIR_B);
	data.joueurs[i]->addcartes(7, carte_ACT_B);
	data.joueurs[i]->addcartes(8, carte_DIR_R);
	data.joueurs[i]->addcartes(9, carte_ACT_B);
	data.joueurs[i]->addcartes(10, carte_ACT_A);
	data.joueurs[i]->addcartes(11, carte_ACT_A);
	data.joueurs[i]->addcartes(12, carte_ACT_A);
	i++;
	data.joueurs[1]->setj_capitaine(true);
	data.joueurs[i]->addcartes(1, carte_DIR_B);
	data.joueurs[i]->addcartes(2, carte_DIR_A);
	data.joueurs[i]->addcartes(3, carte_ACT_B);
	data.joueurs[i]->addcartes(4, carte_ACT_A);
	data.joueurs[i]->addcartes(5, carte_DIR_A);
	data.joueurs[i]->addcartes(6, carte_DIR_A);
	data.joueurs[i]->addcartes(7, carte_DIR_A);
	data.joueurs[i]->addcartes(8, carte_ACT_B);
	data.joueurs[i]->addcartes(9, carte_DIR_A);
	data.joueurs[i]->addcartes(10, carte_DIR_A);
	data.joueurs[i]->addcartes(11, carte_ACT_B);
	data.joueurs[i]->addcartes(12, carte_DIR_A);
}

void move_joueurs_end_round(t_data& data)
{
	int i = 1;
	while (i < 7)
	{
		std::vector<joueur *> joueurs = data.zones[i]->getz_joueurs();
		size_t j(0);
		while (j < joueurs.size())
		{
			if (joueurs[j]->getj_zone() != i)
			{
				data.zones[i]->removez_joueurs(joueurs[j]->getj_nom());
				data.zones[j]->addz_joueurs(joueurs[j]);
			}
			j++;
		}
		i++;
	}
}

void place_joueur_start(t_data& data)
{
	int i = 1;
	while (i < 7)
	{
		std::vector<joueur *> joueurs = data.zones[i]->getz_joueurs();
		size_t j(0);
		while (j < data.joueurs.size())
		{
			std::cout << "zone :" << i << std::endl;
			std::cout << "Joueur n : " << j << "    | zone joueur " << data.joueurs[j]->getj_nom() << " : " << data.joueurs[j]->getj_zone() << std::endl;
			if (data.joueurs[j]->getj_zone() == i)
			{
				data.zones[i]->addz_joueurs(data.joueurs[j]);
				std::cout << "le joueur " << data.joueurs[j]->getj_nom() << " est place en zone " << i << std::endl;
			}
			j++;
		}
		i++;
	}
}

void init_data(t_data& data)
{
	data.nb_joueur = 4;
	int i(0);
	data.tour = 1;
	while (i < data.nb_joueur)
	{
		data.joueurs[i] = new joueur;
		i++;
	}
	data.zones[ZONE_BAS_BLUE] = new zone_bas_blue;
	data.zones[ZONE_HAUT_BLUE] = new zone_haut_blue;
	data.zones[ZONE_HAUT_WHITE] = new zone_haut_white;
	data.zones[ZONE_HAUT_RED] = new zone_haut_blue;
	data.zones[ZONE_BAS_WHITE] = new zone_bas_blue;
	data.zones[ZONE_BAS_RED] = new zone_bas_blue;
	data.zones[ZONE_HAUT_RED]->setzone_bas(data.zones[ZONE_BAS_RED]);
	data.zones[ZONE_HAUT_BLUE]->setzone_bas(data.zones[ZONE_BAS_BLUE]);
	data.zones[ZONE_HAUT_WHITE]->setzone_bas(data.zones[ZONE_BAS_WHITE]);
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
}

void	action_joueur(t_data &data, carte& carte, int joueur)
{
	int zone = data.joueurs[joueur]->getj_zone();
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
	while (i < 7)
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
		move_joueurs_end_round(data);
		print_data(data);
		data.tour++;
	}
}

int main(void)
{
    t_data data;

	init_data(data);
	init_carte_joueur_test(data);
	place_joueur_start(data);
	print_data(data);
	play_game(data);
	erase_data(data);
}
