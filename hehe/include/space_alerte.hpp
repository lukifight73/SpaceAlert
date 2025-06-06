
#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour time()

#include "space_alerte_struct.hpp"
#include "space_alerte_class.hpp"
#include "zone.hpp"

void wr(std::string str);
std::string generateRandomString(int length);
void init_carte_joueur_test(t_data& data);
void init_data(t_data& data);



