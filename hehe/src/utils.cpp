#include "space_alerte.hpp"

void wr(std::string str)
{
    printSlowly(str);
	std::cout << std::endl;
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

void printSlowly(const std::string& text, int delayMs) {
    for (char c : text) {
        std::cout << c << std::flush;  // afficher sans attendre le buffer
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
}

void start_color(zone *zone)
{
    if (zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
}

void start_color_interne()
{
    std::cout << "\033[32m";
}

void print_title(std::string msg)
{
    std::string msg_tour_joueur = "-----------------------------------------------------------------------------------------------------------------------------------------------\n";
    msg_tour_joueur += "                  ****            ****            ****          [TOUR " + msg + "]          ****            ****            ****                   \n";
    msg_tour_joueur += "-----------------------------------------------------------------------------------------------------------------------------------------------\n\n";

	start_color_titre();
	std::cout << msg_tour_joueur;
    end_color();
}

void start_color_titre()
{
    std::cout << "\033[1;33m";
}

void end_color()
{
    std::cout << "\033[0m";
}
