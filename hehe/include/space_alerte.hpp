
#pragma once

#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour time()

#include "SA_Struct.hpp"
#include "SA_Class.hpp"
#include "zone.hpp"
#include "joueur.hpp"

void wr(std::string str);
std::string generateRandomString(int length);
void init_carte_joueur_test(t_data& data);
void init_data(t_data& data);
void apparitionMenaces(t_data &data);
void parsing_config(t_data &data, char* av);
void	action_joueur(t_data &data, carte& carte, int joueur);



