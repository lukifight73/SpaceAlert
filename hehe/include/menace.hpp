#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "space_alerte.hpp"

class menace
{
    protected:
    std::string m_name;
    int m_vitesse;
    int m_vie;
    int difficulte;

    public:
        menace();
        ~menace();
};
