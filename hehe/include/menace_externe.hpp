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
        virtual bool vulnerability_check(cannon* input);
        ~menace_se1_04() {};
};

class menace_se1_05: public menace
{
    private:

    public:
        menace_se1_05() : menace() {};
        menace_se1_05(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual void recoitDegats(int input);
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
        virtual void actionQuandDetruit();
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
        virtual bool vulnerability_check(cannon* input);
        ~menace_se2_03() {};
};

class menace_se2_04: public menace
{
    private:

    public:
        menace_se2_04() : menace() {};
        menace_se2_04(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual ~menace_se2_04() {};
};

class menace_se2_05: public menace
{
    private:

    public:
        menace_se2_05() : menace() {};
        menace_se2_05(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual void recoitDegats(int input);
        virtual ~menace_se2_05() {};
};

class menace_se2_06: public menace
{
    private:

    public:
        menace_se2_06() : menace() {};
        menace_se2_06(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionQuandDetruit();
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual ~menace_se2_06() {};
};

class menace_e1_01: public menace
{
    private:

    public:
        menace_e1_01() : menace() {};
        menace_e1_01(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_01() {};
};

class menace_e1_02: public menace
{
    private:

    public:
        menace_e1_02() : menace() {};
        menace_e1_02(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_02() {};
};

class menace_e1_03: public menace
{
    private:

    public:
        menace_e1_03() : menace() {};
        menace_e1_03(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_03() {};
};

class menace_e1_04: public menace
{
    private:

    public:
        menace_e1_04() : menace() {};
        menace_e1_04(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_04() {};
};

class menace_e1_05: public menace
{
    private:

    public:
        menace_e1_05() : menace() {};
        menace_e1_05(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_05() {};
};

class menace_e1_06: public menace
{
    private:

    public:
        menace_e1_06() : menace() {};
        menace_e1_06(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual void recoitDegats(int input);
        ~menace_e1_06() {};
};

class menace_e1_07: public menace
{
    private:

    public:
        menace_e1_07() : menace() {};
        menace_e1_07(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_07() {};
};

class menace_e1_08: public menace
{
    private:

    public:
        menace_e1_08() : menace() {};
        menace_e1_08(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_08() {};
};

class menace_e1_09: public menace
{
    private:

    public:
        menace_e1_09() : menace() {};
        menace_e1_09(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_09() {};
};

class menace_e1_10: public menace
{
    private:

    public:
        menace_e1_10() : menace() {};
        menace_e1_10(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e1_10() {};
};

class menace_e2_01: public menace
{
    private:

    public:
        menace_e2_01() : menace() {};
        menace_e2_01(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e2_01() {};
};

class menace_e2_02: public menace
{
    private:
        bool m_effetDebutTourOn;

    public:
        menace_e2_02() : menace() {};
        menace_e2_02(bool effetDebutTourOn, std::string input, int tourDarrivee) : menace(input, tourDarrivee) 
        {m_effetDebutTourOn = effetDebutTourOn;};
        virtual void effetDebutTour();
        void menaceAvanceUneCaseInZone(zone *zone);
        void augmenteAttackInZone(zone *zone);
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e2_02() {};
};

class menace_e2_03: public menace
{
    private:

    public:
        menace_e2_03() : menace() {};
        menace_e2_03(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e2_03() {};
};

class menace_e2_04: public menace
{
    private:

    public:
        menace_e2_04() : menace() {};
        menace_e2_04(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual void effetDebutTour();
        ~menace_e2_04() {};
};

class menace_e2_05: public menace
{
    private:

    public:
        menace_e2_05() : menace() {};
        menace_e2_05(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        ~menace_e2_05() {};
};

class menace_e2_06: public menace
{
    private:
        bool effetDebutTourOn;

    public:
        menace_e2_06() : menace() {};
        menace_e2_06(bool effet, std::string input, int tourDarrivee) : menace(input, tourDarrivee) {
            effetDebutTourOn = effet;
        };
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual void effetDebutTour();
        ~menace_e2_06() {};
};

class menace_e2_07: public menace
{
    private:

    public:
        menace_e2_07() : menace() {};
        menace_e2_07(std::string input, int tourDarrivee) : menace(input, tourDarrivee) {};
        virtual void actionMenace(char input); // Action de la menace, peut être redéfinie dans les classes dérivées
        virtual void actionQuandDetruit();
        ~menace_e2_07() {};
};