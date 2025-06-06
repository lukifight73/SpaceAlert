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
