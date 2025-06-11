#include "space_alerte.hpp"

void wr(std::string str)
{
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

void start_color(zone *zone)
{
    if (zone->getz_zone() == 1)
        std::cout << "\033[1;31m";
    else if (zone->getz_zone() == 2)
        std::cout << "\033[1;37m";
    else if (zone->getz_zone() == 3)
        std::cout << "\033[1;36m";
}

void end_color(zone *zone)
{
    if (zone->getz_zone() == 1)
        std::cout << "\033[0m";
    else if (zone->getz_zone() == 2)
        std::cout << "\033[0m";
    else if (zone->getz_zone() == 3)
        std::cout << "\033[0m";
}