#pragma once

#include "menace.hpp"

class menace_interne :public menace
{
    protected:
    bool    m_position_haut;

    public:
        menace_interne();
        menace_interne(std::string input, int tourDarrivee): menace(input, tourDarrivee) {};
        ~menace_interne();
};

class menace_interne_i1_01 :public menace_interne
{
    protected:
    bool    m_position_haut;

    public:
        menace_interne_i1_01() {};
        menace_interne_i1_01(bool position_haut, std::string input, int tourDarrivee) : menace_interne(input, tourDarrivee) 
        {
            m_position_haut = position_haut;
        };
        ~menace_interne_i1_01() {};
};

class menace_interne_i1_02 :public menace_interne
{
    protected:
    bool    m_position_haut;

    public:
        menace_interne_i1_02() {};
        menace_interne_i1_02(bool position_haut, std::string input, int tourDarrivee) : menace_interne(input, tourDarrivee) 
        {
            m_position_haut = position_haut;
        };
        ~menace_interne_i1_02() {};
};
