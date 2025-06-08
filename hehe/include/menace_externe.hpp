#pragma once

#include "space_alerte.hpp"

#include "menace.hpp"

class menace_se1_01: public menace
{
    private:

    public:
        menace_se1_01() : menace() {};
        menace_se1_01(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual ~menace_se1_01() {};
};

class menace_se1_02: public menace
{
    private:

    public:
        menace_se1_02() : menace() {};
        menace_se1_02(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual ~menace_se1_02() {};
};

class menace_se1_03: public menace
{
    private:

    public:
        menace_se1_03() : menace() {};
        menace_se1_03(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionQuandDetruit();
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual ~menace_se1_03() {};
};

class menace_se1_04: public menace
{
    private:

    public:
        menace_se1_04() : menace() {};
        menace_se1_04(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se1_04() {};
};

class menace_se1_05: public menace
{
    private:

    public:
        menace_se1_05() : menace() {};
        menace_se1_05(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se1_05() {};
};

class menace_se1_06: public menace
{
    private:

    public:
        menace_se1_06() : menace() {};
        menace_se1_06(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se1_06() {};
};

class menace_se1_07: public menace
{
    private:

    public:
        menace_se1_07() : menace() {};
        menace_se1_07(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se1_07() {};
};

class menace_se1_08: public menace
{
    private:

    public:
        menace_se1_08() : menace() {};
        menace_se1_08(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se1_08() {};
};

class menace_se2_01: public menace
{
    private:

    public:
        menace_se2_01() : menace() {};
        menace_se2_01(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se2_01() {};
};

class menace_se2_02: public menace
{
    private:

    public:
        menace_se2_02() : menace() {};
        menace_se2_02(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se2_02() {};
};

class menace_se2_03: public menace
{
    private:

    public:
        menace_se2_03() : menace() {};
        menace_se2_03(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se2_03() {};
};

class menace_se2_04: public menace
{
    private:

    public:
        menace_se2_04() : menace() {};
        menace_se2_04(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se2_04() {};
};

class menace_se2_05: public menace
{
    private:

    public:
        menace_se2_05() : menace() {};
        menace_se2_05(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se2_05() {};
};

class menace_se2_06: public menace
{
    private:

    public:
        menace_se2_06() : menace() {};
        menace_se2_06(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_se2_06() {};
};