#pragma once

#include "space_alerte.hpp"

class menace_se1_01: public menace
{
    private:

    public:
        menace_se1_01();
        virtual void actionMenace(char input);
        ~menace_se1_01();
};