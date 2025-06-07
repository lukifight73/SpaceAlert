#include "chemin_menace.hpp"

chemin_menace::chemin_menace()
{
}

// arrive a la fin du chemin
void chemin_menace::add_menace(menace *input) {
    input->setm_position(get_ch_chemin_size()); // On place la menace a la fin du chemin
    ch_menaces.push_back(input);
}

menace* chemin_menace::get_closest_menace() 
{
    if (ch_menaces.empty()) {
        throw std::runtime_error("No menaces available.");
    }
    int positionPlusProche = 0;
    menace *menaceProche = nullptr;
    for (auto it = ch_menaces.begin(); it != ch_menaces.end(); it++)
    {
        if ((*it)->get_m_presence() == false) // Si la menace n'est pas presente, on passe a la suivante
        {
            continue;
        }
        if (positionPlusProche == 0)
        {
            positionPlusProche = (*it)->get_m_position(); // La position la plus prochde de la ou les menaces
            menaceProche = (*it); // La menace la plus proche
        }
        else if ((*it)->get_m_position() < positionPlusProche || ((*it)->get_m_position() == positionPlusProche && (*it)->get_m_tourDarrivee() < menaceProche->get_m_tourDarrivee())) // Si la menace est plus proche que la menace la plus proche
        {
            positionPlusProche = (*it)->get_m_position(); // On change la position de la menace la plus proche
            menaceProche = (*it); // On change la menace la plus proche
        }
    }
    return menaceProche; // On retourne la menace la plus proche
}

chemin_menace::chemin_menace(std::string input)
{
    if(input == "t1")
    {
        ch_nom = "t1";
        ch_chemin_size = 10;
        ch_chemin[10] = 'R';
        ch_chemin[9] = 'R';
        ch_chemin[8] = 'R';
        ch_chemin[7] = 'R';
        ch_chemin[6] = 'R';
        ch_chemin[5] = 'X';
        ch_chemin[4] = 'R';
        ch_chemin[3] = 'R';
        ch_chemin[2] = 'R';
        ch_chemin[1] = 'Z';
    }
    if(input == "t2")
    {
        ch_nom = "t2";
        ch_chemin_size = 11;
        ch_chemin[11] = 'R';
        ch_chemin[10] = 'R';
        ch_chemin[9] = 'R';
        ch_chemin[8] = 'X';
        ch_chemin[7] = 'R';
        ch_chemin[6] = 'R';
        ch_chemin[5] = 'R';
        ch_chemin[4] = 'R';
        ch_chemin[3] = 'R';
        ch_chemin[2] = 'R';
        ch_chemin[1] = 'Z';
    }
    if(input == "t3")
    {
        ch_nom = "t3";
        ch_chemin_size = 12;
        ch_chemin[12] = 'R';
        ch_chemin[11] = 'R';
        ch_chemin[10] = 'R';
        ch_chemin[9] = 'R';
        ch_chemin[8] = 'X';
        ch_chemin[7] = 'R';
        ch_chemin[6] = 'R';
        ch_chemin[5] = 'R';
        ch_chemin[4] = 'R';
        ch_chemin[3] = 'Y';
        ch_chemin[2] = 'R';
        ch_chemin[1] = 'Z';
    }
        if(input == "t4")
    {
        ch_nom = "t4";
        ch_chemin_size = 13;
        ch_chemin[13] = 'R';
        ch_chemin[12] = 'R';
        ch_chemin[11] = 'R';
        ch_chemin[10] = 'R';
        ch_chemin[9] = 'X';
        ch_chemin[8] = 'R';
        ch_chemin[7] = 'R';
        ch_chemin[6] = 'R';
        ch_chemin[5] = 'Y';
        ch_chemin[4] = 'R';
        ch_chemin[3] = 'R';
        ch_chemin[2] = 'R';
        ch_chemin[1] = 'Z';
    }
        if(input == "t5")
    {
        ch_nom = "t5";
        ch_chemin_size = 14;
        ch_chemin[14] = 'R';
        ch_chemin[13] = 'R';
        ch_chemin[12] = 'R';
        ch_chemin[11] = 'X';
        ch_chemin[10] = 'R';
        ch_chemin[9] = 'R';
        ch_chemin[8] = 'R';
        ch_chemin[7] = 'Y';
        ch_chemin[6] = 'R';
        ch_chemin[5] = 'R';
        ch_chemin[4] = 'R';
        ch_chemin[3] = 'R';
        ch_chemin[2] = 'R';
        ch_chemin[1] = 'Z';
    }
        if(input == "t6")
    {
        ch_nom = "t6";
        ch_chemin_size = 15;
        ch_chemin[15] = 'R';
        ch_chemin[14] = 'R';
        ch_chemin[13] = 'R';
        ch_chemin[12] = 'R';
        ch_chemin[11] = 'R';
        ch_chemin[10] = 'X';
        ch_chemin[9] = 'R';
        ch_chemin[8] = 'R';
        ch_chemin[7] = 'Y';
        ch_chemin[6] = 'R';
        ch_chemin[5] = 'R';
        ch_chemin[4] = 'R';
        ch_chemin[3] = 'Y';
        ch_chemin[2] = 'R';
        ch_chemin[1] = 'Z';
    }
        if(input == "t7")
    {
        ch_nom = "t7";
        ch_chemin_size = 16;
        ch_chemin[16] = 'R';
        ch_chemin[15] = 'R';
        ch_chemin[14] = 'R';
        ch_chemin[13] = 'R';
        ch_chemin[12] = 'X';
        ch_chemin[11] = 'R';
        ch_chemin[10] = 'R';
        ch_chemin[9] = 'R';
        ch_chemin[8] = 'Y';
        ch_chemin[7] = 'R';
        ch_chemin[6] = 'R';
        ch_chemin[5] = 'Y';
        ch_chemin[4] = 'R';
        ch_chemin[3] = 'R';
        ch_chemin[2] = 'R';
        ch_chemin[1] = 'Z';
    }
}

chemin_menace::~chemin_menace() {}
