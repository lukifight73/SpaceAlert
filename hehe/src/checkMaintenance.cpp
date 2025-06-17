#include "space_alerte.hpp"

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
			data.joueurs[i]->setj_jump_tour(true);
		}
	}
}

void retarder_joueurs(t_data &data)
{
	for (int i = 1; i <= data.nb_joueur; i++)
	{
		if (data.joueurs[i]->getj_jump_tour())
		{
			data.joueurs[i]->passerTour(data.tour);
			data.joueurs[i]->setj_jump_tour(false);
		}
	}
}
