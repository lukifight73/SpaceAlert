#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "SA_Values.hpp"

/*
//cannon_action
#define INACTIF 0
#define ACT_A 1
#define ACT_B 2
#define ACT_C 3
#define ACT_R 4

//cannon_action_hero
#define ACT_AH 5
#define ACT_BH 6
#define ACT_RH 7

//cannon_deplacement
#define DIR_R 8
#define DIR_B 9
#define DIR_A 10//ascenseur
*/

class cannon;

class cannon
{
    std::string nom_cannon;
    int puissance_cannon;
    int portee_cannon;
    int type_cannon;

    public:
        cannon();
        void setpuissance_cannon(int input);
        void setportee_cannon(int input);
        int getpuissance_cannon() const;
        int getportee_cannon() const;
        int gettype_cannon() const;
        std::string getnom_cannon () const;
        cannon(std::string nom_cannon, int puissance_cannon, int portee_cannon, int type);
        void debuf_puissance_cannon(int debuf);
        void debuf_portee_cannon(int debuf);
        ~cannon();
};
