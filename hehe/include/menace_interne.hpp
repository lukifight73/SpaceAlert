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

//MENACES COMMUNES

class menace_interne_i1_01 :public menace_interne
{
    protected:

    public:
        menace_interne_i1_01() {};
        menace_interne_i1_01(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
        virtual void getDamage(joueur *joueur);
        virtual void actionMenace(char input);
        virtual ~menace_interne_i1_01() {};
};

class menace_interne_i1_02 :public menace_interne
{
    protected:

    public:
        menace_interne_i1_02() {};
        menace_interne_i1_02(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
        virtual void getDamage(joueur *joueur);
        virtual void actionMenace(char input);
        virtual ~menace_interne_i1_02() {};
};

class menace_interne_i1_03 :public menace_interne
{
    protected:

    public:
        menace_interne_i1_03() {};
        menace_interne_i1_03(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_i1_03() {};
};

class menace_interne_i1_04 :public menace_interne
{
    protected:

    public:
        menace_interne_i1_04() {};
        menace_interne_i1_04(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_i1_04() {};
};

class menace_interne_i1_05 :public menace_interne
{
    protected:

    public:
        menace_interne_i1_05() {};
        menace_interne_i1_05(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_i1_05() {};
};

class menace_interne_i1_06 :public menace_interne
{
    protected:

    public:
        menace_interne_i1_06() {};
        menace_interne_i1_06(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_i1_06() {};
};

class menace_interne_i1_07 :public menace_interne
{
    protected:
    bool m_life_set;

    public:
        menace_interne_i1_07() {};
        menace_interne_i1_07(bool life_set, std::string input, int tourDarrivee): menace_interne(input, tourDarrivee)
        {m_life_set = life_set;};
        virtual void actionMenace(char input);
        virtual void effetDebutTour();
        virtual ~menace_interne_i1_07() {};
};

//MENACES COMMUNES AVANCEES

class menace_interne_i2_01 :public menace_interne
{
    protected:
    bool m_zone_delay_set;

    public:
        menace_interne_i2_01() {};
        menace_interne_i2_01(bool zone_delay_set, std::string input, int tourDarrivee): menace_interne(input, tourDarrivee)
        {m_zone_delay_set = zone_delay_set;};
        //virtual void getDamage(joueur *joueur);
        virtual void effetDebutTour();
        virtual void actionQuandDetruit();
        virtual void actionMenace(char input);
        virtual ~menace_interne_i2_01() {};
};

class menace_interne_i2_015 :public menace_interne
{
    protected:
    bool m_zone_delay_set;

    public:
        menace_interne_i2_015() {};
        menace_interne_i2_015(bool zone_delay_set, std::string input, int tourDarrivee): menace_interne(input, tourDarrivee)
        {m_zone_delay_set = zone_delay_set;};
        //virtual void getDamage(joueur *joueur);
        virtual void effetDebutTour();
        virtual void actionQuandDetruit();
        virtual void actionMenace(char input);
        virtual ~menace_interne_i2_015() {};
};

class menace_interne_i2_02 :public menace_interne
{
    protected:
    bool m_zone_delay_set;

    public:
        menace_interne_i2_02() {};
        menace_interne_i2_02(bool zone_delay_set, std::string input, int tourDarrivee): menace_interne(input, tourDarrivee)
        {m_zone_delay_set = zone_delay_set;};
        //virtual void getDamage(joueur *joueur);
        virtual void effetDebutTour();
        virtual void actionQuandDetruit();
        virtual void actionMenace(char input);
        virtual ~menace_interne_i2_02() {};
};

class menace_interne_i2_03 :public menace_interne
{
    protected:

    public:
        menace_interne_i2_03() {};
        menace_interne_i2_03(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_i2_03() {};
};

class menace_interne_i2_04 :public menace_interne
{
    protected:

    public:
        menace_interne_i2_04() {};
        menace_interne_i2_04(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_i2_04() {};
};

class menace_interne_i2_05 :public menace_interne
{
    protected:

    public:
        menace_interne_i2_05() {};
        menace_interne_i2_05(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_i2_05() {};
};

class menace_interne_i2_06 :public menace_interne
{
    protected:

    public:
        menace_interne_i2_06() {};
        menace_interne_i2_06(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual void actionQuandDetruit();
        virtual ~menace_interne_i2_06() {};
};


//MENACES SERIEUSE

class menace_interne_si1_01 :public menace_interne
{
    protected:

    public:
        menace_interne_si1_01() {};
        menace_interne_si1_01(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_si1_01() {};
};

class menace_interne_si1_02 :public menace_interne
{
    protected:

    public:
        menace_interne_si1_02() {};
        menace_interne_si1_02(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
        virtual void actionMenace(char input);
        virtual ~menace_interne_si1_02() {};
};

class menace_interne_si1_03 :public menace_interne
{
    protected:
    bool m_grandit;

    public:
        menace_interne_si1_03() {};
        menace_interne_si1_03(bool grandit, std::string input, int tourDarrivee): menace_interne(input, tourDarrivee)
        {m_grandit = grandit;};
        virtual void actionMenace(char input);
        virtual ~menace_interne_si1_03() {};
};

// class menace_interne_si1_04 :public menace_interne
// {
//     protected:

//     public:
//         menace_interne_si1_04() {};
//         menace_interne_si1_04(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
//         virtual void getDamage(joueur *joueur);
//         virtual void actionMenace(char input);
//         virtual ~menace_interne_si1_04() {};
// };


// class menace_interne_si1_05 :public menace_interne
// {
//     protected:

//     public:
//         menace_interne_si1_05() {};
//         menace_interne_si1_05(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
//         virtual void getDamage(joueur *joueur);
//         virtual void actionMenace(char input);
//         virtual ~menace_interne_si1_05() {};
// };


// class menace_interne_si1_06 :public menace_interne
// {
//     protected:

//     public:
//         menace_interne_si1_06() {};
//         menace_interne_si1_06(std::string input, int tourDarrivee): menace_interne(input, tourDarrivee) {};
//         virtual void getDamage(joueur *joueur);
//         virtual void actionMenace(char input);
//         virtual ~menace_interne_si1_06() {};
// };



