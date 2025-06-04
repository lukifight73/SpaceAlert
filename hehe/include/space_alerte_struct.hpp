
#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour time()

#include "joueur.hpp"
#include "zone.hpp"

typedef struct s_data
{
	int nb_joueur;
	std::map<int, joueur*> joueurs;
	std::map<int, zone*> zones;
	int tour;
} t_data;

void wr(std::string str);
std::string generateRandomString(int length);


