#include "space_alerte.hpp"
#include "SA_Values.hpp"
#include "menace.hpp"
#include "menace_externe.hpp"
#include "menace_interne.hpp"

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
		data.zones[i]->getz_cannon_bas()->setcanon_used(false);
		data.zones[i]->getz_cannon_haut()->setcanon_used(false);
		std::vector<menace_externe*> vecteur_menace = data.zones[i]->getz_chemin_menace()->get_menacesExte();
		for (std::vector<menace_externe*>::iterator it = vecteur_menace.begin(); it != vecteur_menace.end(); ++it)
		{
			(*it)->clear_m_canon_used();
			(*it)->set_m_etat_bouclier((*it)->get_m_bouclier() + (*it)->getm_buff_blindage());
			(*it)->setm_buff_blindage(0);
			(*it)->setm_buff_attack(0);
		}
		i++;
	}
	std::vector<menace_interne*> tmp = data.chemin_menace_interne->get_menacesInte();
	for (std::vector<menace_interne*>::iterator it = tmp.begin(); it != tmp.end(); ++it) 
	{
		(*it)->setm_buff_attack(0);
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

void setTemps(t_data &data)
{
	int i(1);
	while (i < 4)
	{
		data.zones[i]->addtemps();
		i++;
	}
} 

void printInfoMenace(t_data &data)
{
	for (int i = 1; i < 4; i++) 
	{
		std::vector<menace_externe*> tmp = data.zones[i]->getz_chemin_menace()->get_menacesExte();
		std::cout << "--------------------INFORMATION MENACE ZONE " << data.zones[i]->getz_nom_zone() << "----------------------" << std::endl;
		for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it) 
		{
			if((*it)->get_m_presence() == true)
				(*it)->print_menace();
		}
	}
	std::vector<menace_interne*> tmp = data.chemin_menace_interne->get_menacesInte();
	std::cout << "--------------------INFORMATION MENACE INTERNE ----------------------" << std::endl;
	for (std::vector<menace_interne*>::iterator it = tmp.begin(); it != tmp.end(); ++it) 
	{
		if((*it)->get_m_presence() == true)
			(*it)->print_menace();
	}
}

void actionMenaceDebutTour(t_data &data)
{
	for (int i = 1; i < 4; i++) 
	{
		std::vector<menace_externe*> tmp = data.zones[i]->getz_chemin_menace()->get_menacesExte();
		for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it) 
		{
			(*it)->effetDebutTour();
		}
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
		actionMenaceDebutTour(data);
		while (num_joueur <= data.nb_joueur)
		{
			start_color(data.zones[data.joueurs[num_joueur]->getj_zone()]);
			std::cout << "----------------------------------- JOUEUR n " << num_joueur << " playing : " << data.joueurs[num_joueur]->getj_nom() << "----------------------------" << std::endl;
			setPlayerEngaged(data, data.joueurs[num_joueur]->getj_nom());
			action_joueur(data, num_joueur);
			std::cout << "----------------------------------- fin tour joueur n " << num_joueur << " : " << data.joueurs[num_joueur]->getj_nom() << "----------------------------" << std::endl;
			end_color(data.zones[data.joueurs[num_joueur]->getj_zone()]);
			num_joueur++;
		}
		attaqueDesCanons(data); // remplace les deux d apres
		rocketActions(data);
		remove_dead_or_outdated_menaces(data); // doit etre fait avant le mouvement des menaces pour voir si elles sont mortes ou non
		std::cout << "\n\n----------------------------- INFORMATIONS MENACE AVANT MVMT-----------------------------" << std::endl;
		printInfoMenace(data);
		std::cout << "----------------------------- FIN INFORMATIONS MENACE AVANT MVMT-----------------------------" << std::endl;
		mouvement_menaces(data);
	    remove_dead_or_outdated_menaces(data); // doit etre fait apres le mouvement des menaces pour voir si elles sont parties ou non
		std::cout << "\n\n----------------------------- INFORMATIONS MENACE APRES MVMT-----------------------------" << std::endl;
		printInfoMenace(data);
		std::cout << "----------------------------- FIN INFORMATIONS MENACE APRES MVMT-----------------------------" << std::endl;
		//check_maintenance(data);
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
