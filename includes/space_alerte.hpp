
#pragma once

#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib> // Pour rand() et srand()
#include <ctime>   // Pour time()
#include <chrono>
#include <thread>

#include "SA_Struct.hpp"
#include "SA_Class.hpp"
class menace;
class menace_externe;


void wr(std::string str);
std::string generateRandomString(int length);
void init_carte_joueur_test(t_data& data);
void init_data(t_data& data);
void apparitionMenaces(t_data &data);
void parsing_config(t_data &data, std::map<std::string, std::string> &infos);
void	action_joueur(t_data &data, int joueur);
void assignationCannons(t_data &data);
void mouvement_menaces(t_data &data);
void remove_dead_or_outdated_menaces(t_data &data);
void analyseDesDegatsCanons(t_data &data);
void rocketActions(t_data &data);
void impactDegatsTotaux(t_data &data);
void check_maintenance(t_data &data);
void attaqueDesCanons(t_data &data);
menace* get_closest_menace_in_vector(std::vector<menace*> menaces);
void revelerMenace(menace* menace);
void end_color(t_data &data);
void start_color(zone *zone, t_data &data);
menace_externe* get_closest_menace_in_vector(std::vector<menace_externe*> menaces);
void revelerMenace(menace_externe* menace);
void retarder_joueurs(t_data &data);
int get_nb_actions(std::string nomAction);
void printSlowly(const std::string& text, t_data &data);
void start_color_interne(t_data &data);
void start_color_titre(t_data &data);
void print_title(std::string msg, t_data &data);
void print_tour(std::string msg, t_data &data);
void wait();
void mission_failed(std::string msg, t_data &data);
void	play_tour(t_data &data);
void free_data(t_data &data);
void print_title_joueur(std::string msg, t_data &data);
void start_color_joueur(t_data &data);
void print_title_menaces(std::string msg, t_data &data);
