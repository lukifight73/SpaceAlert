#include "space_alerte.hpp"
#include "SA_Values.hpp"

void pars_chemin_menace(t_data &data, std::string chemin_menace_str)
{
     std::istringstream iss(chemin_menace_str);
        std::string chemin_menace_keyword;
		iss >> chemin_menace_keyword; // Lire le mot-clé "chemin_menace"
        std::string nomZone;
        std::string typeChemin;
        
        if (iss >> nomZone >> typeChemin) {
            chemin_menace *new_menace = new chemin_menace(typeChemin);
            if(nomZone == "ZONE_RED")
            {
                data.zones[ZONE_RED]->setz_chemin(new_menace);
            }
            else if(nomZone == "ZONE_WHITE")
            {
                data.zones[ZONE_WHITE]->setz_chemin(new_menace);
            }
            else if(nomZone == "ZONE_BLUE")
            {
                data.zones[ZONE_BLUE]->setz_chemin(new_menace);
            }
            else {
                std::cerr << "Erreur: Zone inconnue " << nomZone << std::endl;
                delete new_menace; // Nettoyage en cas d'erreur
            }
    }
}

void pars_menace(t_data &data, std::string menace_str)
{
    std::istringstream iss(menace_str);
    std::string menace_keyword;
    iss >> menace_keyword; // Lire le mot-clé "menace"
    int tempsArrivee;
    std::string nomZone;
    std::string typeMenace;

    if (iss >> typeMenace >> tempsArrivee >> nomZone) {
        menace *new_menace = new menace(typeMenace, tempsArrivee);
        if(nomZone == "ZONE_RED")
        {
            data.zones[ZONE_RED]->getz_chemin_menace()->add_menace(new_menace);
        }
        else if(nomZone == "ZONE_WHITE")
        {
            data.zones[ZONE_WHITE]->getz_chemin_menace()->add_menace(new_menace);
        }
        else if(nomZone == "ZONE_BLUE")
        {
            data.zones[ZONE_BLUE]->getz_chemin_menace()->add_menace(new_menace);
        }
        else {
            std::cerr << "Erreur: Zone inconnue " << nomZone << std::endl;
            delete new_menace; // Nettoyage en cas d'erreur
        }
        std::cout << new_menace->get_m_tourDarrivee() << std::endl;
    }
}

int get_nb_actions(std::string nomAction)
{
    if (nomAction == "ACT_A")
        return ACT_A;
    else if (nomAction == "ACT_B")
        return ACT_B;
    else if (nomAction == "ACT_C")
        return ACT_C;
    else if (nomAction == "ACT_R")
        return ACT_R;
    else if (nomAction == "ACT_AH")
        return ACT_AH;
    else if (nomAction == "ACT_BH")
        return ACT_BH;
    else if (nomAction == "DIR_R")
        return DIR_R;
    else if (nomAction == "DIR_B")
        return DIR_B;
    else if (nomAction == "DIR_A")
        return DIR_A;
    else
        return INACTIF; // Action inactive
}

void pars_joueurs(t_data &data, std::string line_joueur)
{
    std::istringstream iss(line_joueur);
    std::string joueur_keyword;
    iss >> joueur_keyword; // Lire le mot-clé "joueur"
    int nb_tour;
    int nb_joueur;
    int action;
    std::string nomAction;
    if (iss >> nb_joueur >> nb_tour >> nomAction) {
        action = get_nb_actions(nomAction);
        if (nb_joueur > data.nb_joueur)
        {
            data.nb_joueur++;
            data.joueurs[nb_joueur] = new joueur(nomAction); // Créer un nouveau joueur
        }
        carte carte(action);
        data.joueurs[nb_joueur]->addcartes(nb_tour, carte);
    }
}

void place_joueurs(t_data& data)
{
    int i = 1;
	while (i <= data.nb_joueur)
	{
		data.zones[ZONE_WHITE]->addz_joueurs_haut(data.joueurs[i]);
		i++;
	}
}

void parsing_config(t_data &data, char* av)
{
	std::ifstream file(av);
	if (!file.is_open())
	{
		std::cerr << "Erreur lors de l'ouverture du fichier de configuration." << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string line;
	while (std::getline(file, line))
	{
		if (line.find("chemin_menace") != std::string::npos) {
            pars_chemin_menace(data, line);
		}
        if (line.find("menace") != std::string::npos) {
            pars_menace(data, line);
		}
        if (line.find("joueur") != std::string::npos) {
            pars_joueurs(data, line);
        }
    }
	file.close();
    place_joueurs(data);
    data.zones[ZONE_RED]->printZone();
    data.zones[ZONE_WHITE]->printZone();
    data.zones[ZONE_BLUE]->printZone();
    std::cout << "Configuration parsing complete." << std::endl;
}