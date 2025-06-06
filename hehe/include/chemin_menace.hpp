#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "space_alerte.hpp"
#include "menace.hpp"

class menace;

class chemin_menace
{
    private:
        std::vector<char> ch_chemin;
        std::vector<menace> ch_menaces;

    public:
        chemin_menace();
        ~chemin_menace();
};
