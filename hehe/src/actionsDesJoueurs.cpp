#include "space_alerte.hpp"

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


void	action_joueur(t_data &data, int num_joueur)
{
    carte carte = data.joueurs[num_joueur]->getcartes()[data.tour];
	int zone = data.joueurs[num_joueur]->getj_zone();
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