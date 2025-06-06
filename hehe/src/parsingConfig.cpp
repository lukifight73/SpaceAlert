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
    }
	file.close();
    data.zones[ZONE_RED]->printZone();
    data.zones[ZONE_WHITE]->printZone();
    data.zones[ZONE_BLUE]->printZone();
    std::cout << "Configuration parsing complete." << std::endl;
}