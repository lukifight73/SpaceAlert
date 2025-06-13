#pragma once

#include "menace.hpp"

class menace_interne :public menace
{
    protected:
    bool    m_position_haut;
    int     m_killAction;

    public:
        menace_interne();
        menace_interne(std::string input, int tourDarrivee);
        void setPositionhaut(bool position) 
        { m_position_haut = position;};
        bool getPositionhaut() 
        { return m_position_haut;};
        virtual void print_menace() const;
        virtual bool AttractAction(int joueurAction, int Zone, bool haut) const;
        virtual void getDamage(joueur *joueur);
        virtual ~menace_interne();
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
        virtual void getDamage(joueur *joueur);
        virtual void actionMenace(char input);
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
        virtual void getDamage(joueur *joueur);
        virtual void actionMenace(char input);
        ~menace_interne_i1_02() {};
};
