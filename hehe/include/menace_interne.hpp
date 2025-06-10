#pragma once

#include "menace.hpp"

class menace_interne: public menace
{
    protected:
    std::string m_name;
    int m_tourDarrivee;
    bool m_presence;
    int m_vitesse;
    int m_vie;
    int m_max_vie; // vie maximale de la menace
    int m_position; // position dans le chemin
    int m_bouclier;
    int m_etat_bouclier;
    chemin_menace *m_chemin; // chemin de la menace
    zone *m_zone; // zone de la menace

    public:
        menace_interne();
        ~menace_interne();
};
