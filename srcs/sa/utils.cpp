#include "space_alerte.hpp"
#include "GameNarrator.hpp"

void wr(std::string str)
{
    //printSlowly(str);
	std::cout << str << std::endl;
}

std::string generateRandomString(int length) {
    std::string result = "";
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int charsetSize = sizeof(charset) - 1; // -1 pour ne pas inclure le '\0'

    for (int i = 0; i < length; ++i) {
        int index = rand() % charsetSize;
        result += charset[index];
    }
    return result;
}

void printSlowly(const std::string& text, t_data &data) {
    std::cout << text << std::endl;  // afficher sans attendre le buffer
    data.text_html += text;
}

void start_color(zone *zone, t_data &data)
{
    if (zone->getz_zone() == 1)
    {
        data.text_html += "|31|";
        std::cout << "\033[1;31m";
    }
    else if (zone->getz_zone() == 2)
    {
        data.text_html += "|37|";
        std::cout << "\033[1;37m";
    }
    else if (zone->getz_zone() == 3)
    {
        data.text_html += "|36|";
        std::cout << "\033[1;36m";
    }
}

void start_color_interne(t_data &data)
{
    data.text_html += "|32|";
    std::cout << "\033[32m";
}

void print_title(std::string msg, t_data &data)
{
    std::string msg_tour_joueur = "\n----------------------------------------------------------------------------------------------------\n";
    msg_tour_joueur += "                  ****            ****            ****          [" + msg + "]          ****            ****            **** \n";
    msg_tour_joueur += "----------------------------------------------------------------------------------------------------\n\n";

	start_color_titre(data);
    data.text_html += msg_tour_joueur;
	std::cout << msg_tour_joueur;
    end_color(data);
}

void start_color_menaces(t_data &data)
{
    data.text_html += "|35|";
    std::cout << "\033[1;35m";
}

void print_title_menaces(std::string msg, t_data &data)
{
    std::string msg_tour_joueur = "\n----------------------------------------------------------------------------------------------------\n";
    msg_tour_joueur += "                  ****            ****            ****          [" + msg + "]          ****            ****            **** \n";
    msg_tour_joueur += "----------------------------------------------------------------------------------------------------\n\n";

	start_color_menaces(data);
    data.text_html += msg_tour_joueur;
	std::cout << msg_tour_joueur;
    end_color(data);
}

void start_color_tour(t_data &data)
{
    data.text_html += "|34|";
    std::cout << "\033[1;35m";
}

void mission_failed(std::string msg, t_data &data)
{
    start_color_tour(data);
    std::string msg_tour_joueur = "\n----------------------------------------------------------------------------------------------------\n";
    msg_tour_joueur += "/!\\/!\\/!\\/!\\/!\\/!\\/!\\/!\\" + msg;
    msg_tour_joueur += "----------------------------------------------------------------------------------------------------\n\n";
    data.text_html += msg_tour_joueur;
	std::cout << msg_tour_joueur;
    printSlowly("[Souhaitez-vous continuez a voir votre catastrophe ou preferez vous en finir rapidement ? (continuer : Y/y)]\n", data);
    std::string input;
    std::getline(std::cin, input);  // attend que l'utilisateur appuie sur Entrée
    end_color(data);
    if (input == "Y" || input == "y" || input == "oui" || input == "yes" || input == "OUI" || input == "YES")
        return;
    exit(1);
}

void print_tour(std::string msg, t_data &data)
{
    std::string msg_tour_joueur = "-\n---\n------\n------------\n--------------------\n";
    msg_tour_joueur += "----------------------------------------\n";
    msg_tour_joueur += "------------------------------------------------------------\n";
    msg_tour_joueur += "--------------------------------------------------------------------------------\n";
    msg_tour_joueur += "----------------------------------------------------------------------------------------------------\n";
    msg_tour_joueur += "                  ****            ****            ****              [" + msg + "]             ****            ****            ****  \n";
    msg_tour_joueur += "----------------------------------------------------------------------------------------------------\n\n";

	start_color_tour(data);
    data.text_html += msg_tour_joueur;
	std::cout << msg_tour_joueur;
    end_color(data);
}

void start_color_titre(t_data &data)
{
    data.text_html += "|33|";
    std::cout << "\033[1;33m";
}

void start_color_joueur(t_data &data)
{
    data.text_html += "|39|";
    std::cout << "\033[1;33m";
}

void print_title_joueur(std::string msg, t_data &data)
{
    std::string msg_tour_joueur = "\n----------------------------------------------------------------------------------------------------\n";
    msg_tour_joueur += "                  ****            ****            ****          [" + msg + "]          ****            ****            **** \n";
    msg_tour_joueur += "----------------------------------------------------------------------------------------------------\n\n";

	start_color_joueur(data);
    data.text_html += msg_tour_joueur;
    end_color(data);
}

void end_color(t_data &data)
{
    data.text_html += "|0|";
    std::cout << "\033[0m";
}

void free_data(t_data &data)
{
    int i(1);
    while (i <= data.nb_joueur)
    {
        delete data.joueurs[i];
        i++;
    }
    delete data.zones[ZONE_BLUE];
    delete data.zones[ZONE_WHITE];
    delete data.zones[ZONE_RED];
    delete data.VoixAlert;
    delete data.VoixRobot1;
    delete data.VoixRobot2;
    delete data.chemin_menace_interne;
}
