#include "space_alerte.hpp"
#include "SA_Values.hpp"
#include "menace.hpp"
#include "menace_externe.hpp"
#include "menace_interne.hpp"
#include "GameNarrator.hpp"

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
	std::vector<menace_interne*> tmp = data.chemin_menace_interne->get_menacesInte();
	for (std::vector<menace_interne*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		(*it)->effetDebutTour();
	}
}

void effetMenaceApresMvt(t_data &data)
{
	for (int i = 1; i < 4; i++)
	{
		std::vector<menace_externe*> tmp = data.zones[i]->getz_chemin_menace()->get_menacesExte();
		for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
		{
			(*it)->effetApresMvt();
		}
	}
	std::vector<menace_interne*> tmp = data.chemin_menace_interne->get_menacesInte();
	for (std::vector<menace_interne*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		(*it)->effetApresMvt();
	}
}


void infligeDegats(menace_externe *menace)
{
	if (menace->get_m_degats() > 0)
	{
		wait();
	}
	else
	{
		menace->add_m_degats_totaux_str(menace->get_m_degats_str());
	}
	if(menace->get_m_vie() <= 0)
	{
		menace->add_m_degats_str("[La " + menace->get_m_name() + " est deja morte.]\n");
		menace->add_m_degats_totaux_str(menace->get_m_degats_str());
	}
	// check imunity
	else if (menace->get_m_degats() > menace->get_m_etat_bouclier() && menace->get_m_degats() > 0)
	{
		int degatsInfliges = menace->get_m_degats() - menace->get_m_etat_bouclier();
		start_color(menace->get_m_zone());
		menace->add_m_degats_str("[La menace " + menace->get_m_name() + " absorbe " + std::to_string(menace->get_m_etat_bouclier()) + " degats et recois " + std::to_string(degatsInfliges) + " degats.]\n");
		menace->add_m_degats_totaux_str(menace->get_m_degats_str());
		printSlowly(menace->get_m_degats_str());
		menace->set_m_etat_bouclier(0); // Bouclier épuisé
		menace->recoitDegats(degatsInfliges); // Inflige les dégâts restants à la menace
		end_color();
	}
	else if(menace->get_m_degats() != 0 && menace->get_m_degats() <= menace->get_m_etat_bouclier()) // Si la puissance du canon est supérieure à l'état du bouclier de la menace
	{
		start_color(menace->get_m_zone());
		menace->add_m_degats_str("[La menace " + menace->get_m_name() + " absorbe " + std::to_string(menace->get_m_etat_bouclier()) + " degats.]\n");
		menace->add_m_degats_totaux_str(menace->get_m_degats_str());
		printSlowly(menace->get_m_degats_str());
		end_color();
	}
	menace->set_m_degats(0);
	menace->set_m_degats_str("");
}

void putDegatsIntoAction(t_data &data)
{
	for (int i = 1; i < 4; i++)
	{
		std::vector<menace_externe*> tmp = data.zones[i]->getz_chemin_menace()->get_menacesExte();
		for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
		{
			infligeDegats(*it);
		}
	}
	std::vector<menace_interne*> tmp = data.zones[1]->getz_chemin_menace_Int()->get_menacesInte();
	for (std::vector<menace_interne*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		if ((*it)->get_m_degats() > 0 || (*it)->get_m_degats_str() != "")
		{
			wait();
			(*it)->getDamaged();
		}
	}
}

void getPlayerCard(t_data &data, int num_joueur)
{
	data.joueurs[num_joueur]->getcarteTour(data.tour);
}

std::string get_zone_joueur_str(t_data &data, joueur *j)
{
	int i(1);
	while (i < 4)
	{
		if (data.zones[i]->getz_joueur_haut(j->getj_nom()))
		{
			return ("la station haute " + data.zones[i]->getz_nom_zone());
		}
		else if (data.zones[i]->getz_joueur_bas(j->getj_nom()))
		{
			return ("la station basse " + data.zones[i]->getz_nom_zone());
		}
		else if (data.zones[i]->getz_joueur_intercepteurs())
		{
			return ("les vaisseaux intercepteurs");
		}
		i++;
	}
	return ("");
}

void wait()
{
	std::string input;
    std::getline(std::cin, input);
}

void create_card(t_data &data)
{
	int i(1);
	while(i <= data.nb_joueur)
    {
		carte carte(TODO);
		data.joueurs[i]->addcartes(data.tour, carte);
		i++;
	}
}

void	play_game(t_data &data)
{
	while (data.tour < 13)//commence a 1 et finit a 12
	{
		create_card(data);
		int num_joueur(1);
		print_tour("TOUR " + std::to_string(data.tour));
		apparitionMenaces(data);
		clear_actionUsage(data);
		actionMenaceDebutTour(data);
		print_title("ACTION DES JOUEURS");
		while (num_joueur <= data.nb_joueur)
		{
			std::cout << "									------									\n";
			start_color(data.zones[data.joueurs[num_joueur]->getj_zone()]);
			std::string zone_joueur = get_zone_joueur_str(data, data.joueurs[num_joueur]);
			std::cout << "C'est a " << data.joueurs[num_joueur]->getj_nom() << " de jouer. Vous vous trouvez dans " << zone_joueur << std::endl;
			setPlayerEngaged(data, data.joueurs[num_joueur]->getj_nom());
			getPlayerCard(data, num_joueur);
			action_joueur(data, num_joueur);
			end_color();
			num_joueur++;
		}
		effetMenaceApresMvt(data); // effet des menaces apres que les joueurs ai bouge (eg. si ils croisent une menace interne)
		print_title("CALCUL DES DEGATS");
		attaqueDesCanons(data); // remplace les deux d apres
		rocketActions(data);
		putDegatsIntoAction(data);
		remove_dead_or_outdated_menaces(data); // doit etre fait avant le mouvement des menaces pour voir si elles sont mortes ou non
		//std::cout << "\n\n----------------------------- INFORMATIONS MENACE AVANT MVMT-----------------------------" << std::endl;
		//printInfoMenace(data);
		//std::cout << "----------------------------- FIN INFORMATIONS MENACE AVANT MVMT-----------------------------" << std::endl;
		mouvement_menaces(data);
		effetMenaceApresMvt(data); // effet des menaces apres qu'elles aint bouge (eg. si ils croisent un joueur par ex.)
	    remove_dead_or_outdated_menaces(data); // doit etre fait apres le mouvement des menaces pour voir si elles sont parties ou non
		//std::cout << "\n\n----------------------------- INFORMATIONS MENACE APRES MVMT-----------------------------" << std::endl;
		//printInfoMenace(data);
		//std::cout << "----------------------------- FIN INFORMATIONS MENACE APRES MVMT-----------------------------" << std::endl;
		//check_maintenance(data);
		//print_data(data);
		retarder_joueurs(data);
		setTemps(data);
		data.tour++;
	}
}

void chose_ton_blase(t_data &data)
{
	int i(1);
	std::string nom;
    while(i <= data.nb_joueur)
    {
		std::cout << "Joueur " << i << " choisi ton blaaazze:\n";
        std::cin >> nom;
		std::cout << "All right  " << nom << " bienvenu dans le vaisseau!!\n";
		data.joueurs[i]->setj_nom(nom); // Créer un nouveau joueur
        i++;
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
	chose_ton_blase(data);
	//init_carte_joueur_test(data);
	print_data(data);
	data.VoixAlert->announce("===IL SE PASSE UN TRUC DE OUF!!!!");
	data.VoixRobot1->announce("Je suis le test pour la voix des Joueurs");
	//data.VoixRobot2->announce("et moi je suis le test pour la voix des Menace");
	// data.VoixRobot1->announceUrgent("Je suis le test pour la voix des Joueurs");
	// data.VoixRobot2->announceUrgent("et moi je suis le test pour la voix des Menace");
	play_game(data);
	erase_data(data);
}
