#include "chemin_menace.hpp"
#include "space_alerte.hpp"
#include "SA_Values.hpp"
#include "menace.hpp"
#include "menace_externe.hpp"
#include "menace_interne.hpp"

menace_externe *create_menaceE(std::string typeMenace, int tempsArrivee)
{
    if (typeMenace == "se1-01") {
        return new menace_se1_01(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "se1-02") {
        return new menace_se1_02(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "se1-03") {
        return new menace_se1_03(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "se1-04") {
        return new menace_se1_04(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "se1-05") {
        return new menace_se1_05(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "se1-06") {
        return new menace_se1_06(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "se1-07") {
        return new menace_se1_07(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "se1-08") {
        return new menace_se1_08(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "se2-01") {
        return new menace_se2_01(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "se2-02") {
        return new menace_se2_02(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "se2-03") {
        return new menace_se2_03(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "se2-04") {
        return new menace_se2_04(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "se2-05") {
        return new menace_se2_05(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "se2-06") {
        return new menace_se2_06(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e1-01") {
        return new menace_e1_01(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e1-02") {
        return new menace_e1_02(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e1-03") {
        return new menace_e1_03(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e1-04") {
        return new menace_e1_04(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e1-05") {
        return new menace_e1_05(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e1-06") {
        return new menace_e1_06(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e1-07") {
        return new menace_e1_07(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e1-08") {
        return new menace_e1_08(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e1-09") {
        return new menace_e1_09(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e1-10") {
        return new menace_e1_10(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e2-01") {
        return new menace_e2_01(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e2-02") {
        return new menace_e2_02(CANON_LOURD, false, typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e2-03") {
        return new menace_e2_03(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e2-04") {
        return new menace_e2_04(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e2-05") {
        return new menace_e2_05(typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e2-06") {
        return new menace_e2_06(false, typeMenace, tempsArrivee);
    }
    else if (typeMenace == "e2-07") {
        return new menace_e2_07(typeMenace, tempsArrivee);
    }
    else {
        std::cerr << "Erreur: Type de menace inconnu " << typeMenace << std::endl;
        return new menace_externe(typeMenace, tempsArrivee);; // Retourne un pointeur nul en cas d'erreur
    }
}

menace_interne *create_menaceI(std::string typeMenace, int tempsArrivee, t_data &data)
{

    if (typeMenace == "i1-01") {
        return new menace_interne_i1_01(data.zones[ZONE_RED], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "i1-02") {
        return new menace_interne_i1_02(data.zones[ZONE_BLUE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "i1-03") {
        return new menace_interne_i1_03(data.zones[ZONE_WHITE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "i1-04") {
        return new menace_interne_i1_04(data.zones[ZONE_WHITE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "i1-05") {
        return new menace_interne_i1_05(data.zones[ZONE_BLUE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "i1-06") {
        return new menace_interne_i1_06(data.zones[ZONE_RED], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "i1-07") {
        return new menace_interne_i1_07(false, data.zones[ZONE_BLUE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "i2-01") {
        return new menace_interne_i2_01(false, data.zones[ZONE_BLUE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "i2-015") {
        return new menace_interne_i2_015(false, data.zones[ZONE_WHITE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "i2-02") {
        return new menace_interne_i2_02(false, data.zones[ZONE_RED], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "i2-03") {
        return new menace_interne_i2_03(data.zones[ZONE_RED], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "i2-04") {
        return new menace_interne_i2_04(data.zones[ZONE_BLUE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "i2-05") {
        return new menace_interne_i2_05(data.zones[ZONE_WHITE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "i2-06") {
        return new menace_interne_i2_06(data.zones[ZONE_WHITE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "si1-01") {
        return new menace_interne_si1_01(data.zones[ZONE_RED], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "si1-02") {
        return new menace_interne_si1_02(data.zones[ZONE_BLUE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "si1-03") {
        return new menace_interne_si1_03(false, data.zones[ZONE_WHITE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "si1-04") {
        return new menace_interne_si1_04(data.zones[ZONE_RED], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "si1-05") {
        return new menace_interne_si1_05(data.zones[ZONE_WHITE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "si1-06") {
        return new menace_interne_si1_06(data.zones[ZONE_RED], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "si2-01") {
        return new menace_interne_si2_01(data.zones[ZONE_BLUE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "si2-02") {
        return new menace_interne_si2_02(data.zones[ZONE_WHITE], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "si2-03") {
        return new menace_interne_si2_03(data.zones[ZONE_RED], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "si2-04") {
        return new menace_interne_si2_04(data.zones[ZONE_RED], typeMenace, tempsArrivee);
    }
    else if (typeMenace == "si2-05") {
        return new menace_interne_si2_05(data.zones[ZONE_WHITE], typeMenace, tempsArrivee);
    }
    else {
        std::cerr << "Erreur: Type de menace inconnu " << typeMenace << std::endl;
        return new menace_interne(data.zones[ZONE_RED], typeMenace, tempsArrivee); // Retourne un pointeur nul en cas d'erreur
    }
}

int get_nb_actions(std::string nomAction)
{
    if (nomAction == "ACT_A" || nomAction == "A" || nomAction == "a")
        return ACT_A;
    else if (nomAction == "ACT_B" || nomAction == "B" || nomAction == "b")
        return ACT_B;
    else if (nomAction == "ACT_C" || nomAction == "C" || nomAction == "c")
        return ACT_C;
    else if (nomAction == "ACT_R" || nomAction == "R" || nomAction == "r")
        return ACT_R;
    else if (nomAction == "ACT_RH" || nomAction == "RH" || nomAction == "rh")
        return ACT_RH;
    else if (nomAction == "ACT_AH" || nomAction == "AH" || nomAction == "a")
        return ACT_AH;
    else if (nomAction == "ACT_BH" || nomAction == "BH" || nomAction == "bh")
        return ACT_BH;
    else if (nomAction == "DIR_R" || nomAction == "DR" || nomAction == "dr")
        return DIR_R;
    else if (nomAction == "DIR_B" || nomAction == "DB" || nomAction == "db")
        return DIR_B;
    else if (nomAction == "DIR_A" || nomAction == "DA" || nomAction == "da")
        return DIR_A;
    else if (nomAction == "DIR_RB" || nomAction == "DRB" || nomAction == "drb")
        return DIR_RB;
    else if (nomAction == "DIR_RH" || nomAction == "DRH" || nomAction == "drh")
        return DIR_RH;
    else if (nomAction == "DIR_WH" || nomAction == "DWH" || nomAction == "dwh")
        return DIR_WH;
    else if (nomAction == "DIR_WB" || nomAction == "DWB" || nomAction == "dwb")
        return DIR_WB;
    else if (nomAction == "DIR_BH" || nomAction == "DBH" || nomAction == "dbh")
        return DIR_BH;
    else if (nomAction == "DIR_BB" || nomAction == "DBB" || nomAction == "dbb")
        return DIR_BB;
    else if (nomAction == "INACTIF")
        return INACTIF; // Action inactive
    else
        return (-1);
}

void create_card(t_data &data)
{
	int i(1);
	int j(1);
	while (j < 13)
	{
		while(i <= data.nb_joueur)
		{
			carte carte(TODO);
			data.joueurs[i]->addcartes(j, carte);
			i++;
		}
		j++;
        i = 1;
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

void parse_joueurs(t_data &data, std::map<std::string, std::string> &infos)
{
    int i(1);

    std::map<std::string, std::string>::const_iterator it = infos.find("nbJoueurs");
    if (it != infos.end())
    {
        data.nb_joueur = std::atoi(it->second.c_str());
    }
    it = infos.find("capitaine");
    if (it != infos.end())
    {
        i = atoi(it->second.substr(6).c_str());
    }
    int j(i);
    int joueur_param(1);
    while (i <= data.nb_joueur)
    {
        std::string finder = "joueur" + std::to_string(i);
        it = infos.find(finder);
        if (it != infos.end())
        {
            if (i == j)
                data.joueurs[joueur_param] = new joueur("Capitaine " + it->second);
            else
                data.joueurs[joueur_param] = new joueur(it->second);
            data.joueurs[joueur_param]->setj_number(data.nb_joueur); // Créer un nouveau joueur
            data.joueurs[joueur_param]->setj_data(&data);
            joueur_param++;
        }
        i++;
    }
    i = 1;
    while (i < j)
    {
        std::string finder = "joueur" + std::to_string(i);
        it = infos.find(finder);
        if (it != infos.end())
        {
            data.joueurs[joueur_param] = new joueur(it->second);
            data.joueurs[joueur_param]->setj_number(data.nb_joueur); // Créer un nouveau joueur
            data.joueurs[joueur_param]->setj_data(&data);
            joueur_param++;
        }
        i++;
    }
}

void parse_chemins(t_data &data, std::map<std::string, std::string> &infos)
{
    std::map<std::string, std::string>::const_iterator it = infos.find("cheminInterne");
    if (it != infos.end())
    {
        chemin_menace *new_chemin_menace = new chemin_menace(it->second);
        data.chemin_menace_interne = new_chemin_menace;
        data.zones[ZONE_RED]->setz_chemin_intern(new_chemin_menace);
        data.zones[ZONE_WHITE]->setz_chemin_intern(new_chemin_menace);
        data.zones[ZONE_BLUE]->setz_chemin_intern(new_chemin_menace);
    }
    it = infos.find("cheminRouge");
    if (it != infos.end())
    {
        chemin_menace *new_chemin_menace = new chemin_menace(it->second);
        data.zones[ZONE_RED]->setz_chemin(new_chemin_menace);
    }
    it = infos.find("cheminBlanche");
    if (it != infos.end())
    {
        chemin_menace *new_chemin_menace = new chemin_menace(it->second);
        data.zones[ZONE_WHITE]->setz_chemin(new_chemin_menace);
    }
    it = infos.find("cheminBleue");
    if (it != infos.end())
    {
        chemin_menace *new_chemin_menace = new chemin_menace(it->second);
        data.zones[ZONE_BLUE]->setz_chemin(new_chemin_menace);
    }
}

void parsMenace(t_data &data, std::string menace_str)
{
    std::istringstream iss(menace_str);
    std::string menace_keyword;
    iss >> menace_keyword; // Lire le mot-clé "menace"
    int tempsArrivee;
    std::string nomZone;
    std::string typeMenace;
    menace_externe *new_menace(NULL);
    menace_interne *new_menaceInt(NULL);

    if (iss >> typeMenace >> tempsArrivee) {
        if (menace_keyword == "menaceE")
        {
            iss >> nomZone;
            new_menace = create_menaceE(typeMenace, tempsArrivee);
            if(nomZone == "ZONE_RED")
            {
                data.zones[ZONE_RED]->getz_chemin_menace()->add_menaceExte(new_menace);
                new_menace->set_m_zone(data.zones[ZONE_RED]);
                new_menace->set_m_zoneInt(ZONE_RED);
                new_menace->set_m_chemin(data.zones[ZONE_RED]->getz_chemin_menace());
            }
            else if(nomZone == "ZONE_WHITE")
            {
                data.zones[ZONE_WHITE]->getz_chemin_menace()->add_menaceExte(new_menace);
                new_menace->set_m_zone(data.zones[ZONE_WHITE]);
                new_menace->set_m_zoneInt(ZONE_WHITE);
                new_menace->set_m_chemin(data.zones[ZONE_WHITE]->getz_chemin_menace());
            }
            else if(nomZone == "ZONE_BLUE")
            {
                data.zones[ZONE_BLUE]->getz_chemin_menace()->add_menaceExte(new_menace);
                new_menace->set_m_zone(data.zones[ZONE_BLUE]);
                new_menace->set_m_zoneInt(ZONE_BLUE);
                new_menace->set_m_chemin(data.zones[ZONE_BLUE]->getz_chemin_menace());
            }
            else {
            std::cerr << "Erreur: " << menace_str << std::endl;
            delete new_menace; // Nettoyage en cas d'erreur
            }
        }
        else if(menace_keyword == "menaceI")
        {
            new_menaceInt = create_menaceI(typeMenace, tempsArrivee, data);
            new_menaceInt->set_m_chemin(data.chemin_menace_interne);
            data.chemin_menace_interne->add_menaceInt(new_menaceInt);
        }
    }
}

void parse_menaces(t_data &data, std::map<std::string, std::string> &infos)
{
    std::map<std::string, std::string>::const_iterator it;
    for (it = infos.begin(); it != infos.end(); it++)
    {
        if (it->first.find("menaceE") != std::string::npos && it->second != "")
        {
            int tempsArrivee = atoi(it->first.substr(8, 1).c_str());
            menace_externe *new_menace = create_menaceE(it->second, tempsArrivee);
            char c = it->first.substr(9, 1)[0];
            if (c == 'B')
            {
                data.zones[ZONE_BLUE]->getz_chemin_menace()->add_menaceExte(new_menace);
                new_menace->set_m_zone(data.zones[ZONE_BLUE]);
                new_menace->set_m_zoneInt(ZONE_BLUE);
                new_menace->set_m_chemin(data.zones[ZONE_BLUE]->getz_chemin_menace());
            }
            else if (c == 'W')
            {
                data.zones[ZONE_WHITE]->getz_chemin_menace()->add_menaceExte(new_menace);
                new_menace->set_m_zone(data.zones[ZONE_WHITE]);
                new_menace->set_m_zoneInt(ZONE_WHITE);
                new_menace->set_m_chemin(data.zones[ZONE_WHITE]->getz_chemin_menace());
            }
            else if (c == 'R')
            {
                data.zones[ZONE_RED]->getz_chemin_menace()->add_menaceExte(new_menace);
                new_menace->set_m_zone(data.zones[ZONE_RED]);
                new_menace->set_m_zoneInt(ZONE_RED);
                new_menace->set_m_chemin(data.zones[ZONE_RED]->getz_chemin_menace());
            }
        }
        else if (it->first.find("menaceI") != std::string::npos && it->second != "")
        {
            int tempsArrivee = atoi(it->first.substr(8, 1).c_str());
            menace_interne *new_menace = create_menaceI(it->second, tempsArrivee, data);
            new_menace = create_menaceI(it->second, tempsArrivee, data);
            new_menace->set_m_chemin(data.chemin_menace_interne);
            data.chemin_menace_interne->add_menaceInt(new_menace);
        }
    }
}

void parsing_config(t_data &data, std::map<std::string, std::string> &infos)
{
    parse_joueurs(data, infos);
    place_joueurs(data);
    parse_chemins(data, infos);
    parse_menaces(data, infos);
    create_card(data);
}
