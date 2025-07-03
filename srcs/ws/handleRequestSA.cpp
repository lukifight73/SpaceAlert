#include "space_alerte.hpp"
#include "webserv.hpp"

int check_post_SA(t_client &client, const t_location &current_location, t_globalData &dataStruct)
{
	std::map<std::string, std::string>			headers = client.request.getHeader();
	if (headers["Content-Type"] == "application/x-www-form-urlencoded") {
        std::map<std::string, std::string> bodyMap = parse_urlencoded(client.request.getbodyVec());
        if (current_location.path == "/Parse_mission")
        {
            parsing_config(*dataStruct.data, bodyMap);
            update_card_choice(dataStruct);
            GetGoodResponse(client, "./www/webservSite/card_choice.html");
            return (1);
        }
	}
	return (0);
}

void setcartesjoueurtour(t_globalData &dataStruct)
{
	int i(1);
    while (i <= dataStruct.data->nb_joueur)
	{
		if (dataStruct.data->joueurs[i]->getcartes()[dataStruct.data->tour].getc_action() != ASSOME)
		{
			dataStruct.data->joueurs[i]->getcartes()[dataStruct.data->tour].setc_action(TODO);
		}
        i++;
	}
}

int check_get_SA(t_client &client, t_globalData &dataStruct)
{
	std::map<std::string, std::string>			headers = client.request.getHeader();
	if (client.request.getUri() == "/Hub?" || client.request.getUri() == "/Hub")
	{
		GetGoodResponse(client, "./www/webservSite/Hub.html");
		return (1);
	}
	else if (client.request.getUri() == "/Next_round?" || client.request.getUri() == "/Next_round")
	{
		if (!dataStruct.data->vaisseau_en_vie)
		{
			GetGoodResponse(client, "./www/webservSite/vaisseau_KO.html");
			dataStruct.data->vaisseau_en_vie = true;
			return (1);
		}
		else if (dataStruct.data->tour >= 13)
		{
			client.request.setUri("/Round_process");
		}
		else if (!update_card_choice(dataStruct))
		{
			GetGoodResponse(client, "./www/webservSite/inactif.html");
			return (1);
		}
		else
		{
			GetGoodResponse(client, "./www/webservSite/card_choice.html");
			return (1);
		}
	}
	else if (get_nb_actions(client.request.getUri().substr(1)) >= 0)
	{
		int tour = dataStruct.data->tour;
    	int i(1);
		while (i <= dataStruct.data->nb_joueur && (dataStruct.data->joueurs[i]->getcartes()[tour].getc_action() != TODO || dataStruct.data->joueurs[i]->getcartes()[tour].getc_action() == ASSOME || dataStruct.data->joueurs[i]->getcartes()[tour].getc_action() == INACTIF))
			i++;
		dataStruct.data->joueurs[i]->setcarteTour(tour, get_nb_actions(client.request.getUri().substr(1)));
		i++;
		if (i > dataStruct.data->nb_joueur)
		{
			modifier_fichier_bilan_tour_joueur("./www/webservSite/action_joueur_bilan.html", dataStruct);
			GetGoodResponse(client, "./www/webservSite/action_joueur_bilan.html");
			return (1);
		}
		else
		{
			update_card_choice(dataStruct);
			GetGoodResponse(client, "./www/webservSite/card_choice.html");
			return (1);
		}
	}
	else if (client.request.getUri() == "/Retry?" || client.request.getUri() == "/Retry")
	{
		int i(1);
		while (i <= dataStruct.data->nb_joueur)
		{
			dataStruct.data->joueurs[i]->setcarteTour(dataStruct.data->tour, TODO);
			i++;
		}
		update_card_choice(dataStruct);
		GetGoodResponse(client, "./www/webservSite/card_choice.html");
		return (1);
	}
	if (client.request.getUri() == "/Round_process?" || client.request.getUri() == "/Round_process")
	{
		play_tour(*dataStruct.data);
		if (dataStruct.data->tour > 13)
		{
			mettreAJourDegatsHTML(dataStruct.data->zones[ZONE_RED]->getz_degats_recu(), dataStruct.data->zones[ZONE_BLUE]->getz_degats_recu(), dataStruct.data->zones[ZONE_WHITE]->getz_degats_recu(), "./www/webservSite/Victoire.html");
			insertThreatRecap("./www/webservSite/Victoire.html", dataStruct.data->text_recap);
			GetGoodResponse(client, "./www/webservSite/Victoire.html");
			return (1);
		}
		else
		{
			nettoyerFichierHtml("./www/webservSite/mission_in_process.html");
			insererTexteAvecCouleurs("./www/webservSite/mission_in_process.html", dataStruct.data->text_html);
			GetGoodResponse(client, "./www/webservSite/mission_in_process.html");
		}
		return (1);
	}
	return (0);
}
