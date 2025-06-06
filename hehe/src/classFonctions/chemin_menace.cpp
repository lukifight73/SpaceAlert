#include "chemin_menace.hpp"

chemin_menace::chemin_menace()
{
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
        ch_chemin[6] = 'X';
        ch_chemin[5] = 'R';
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
}

chemin_menace::~chemin_menace() {}
