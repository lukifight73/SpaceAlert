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
        std::string          ch_nom;
        std::map<int,char> ch_chemin;
        int                 ch_chemin_size;
        std::vector<menace*> ch_menaces;

    public:
        chemin_menace();
        chemin_menace(std::string input);
        void add_menace(menace *input);
        menace* get_closest_menace();
        void remove_menace(menace *input);
        std::string get_ch_nom() const {
            return ch_nom;
        };
        int  get_ch_chemin_size() const {
            return ch_chemin_size;
        };
        std::map<int,char> get_ch_chemin() const {
            return ch_chemin;
        };
        std::vector<menace*> get_menaces() const {
            return ch_menaces;
        };
        ~chemin_menace();
};
