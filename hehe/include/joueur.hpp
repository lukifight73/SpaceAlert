#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "space_alerte.hpp"
#include "carte.hpp"

class carte;

class joueur {
private:
    std::string j_nom;
    bool j_state;//eveille / KO
    int j_bots;//
    int j_number;//numero du joueur
    bool j_capitaine;
    int j_zone;//un joueur est dans une zone
    std::map<int, carte> cartes;//un joueur pose des cartes, associe au tour ou il pose ses cartes

public:
    joueur();
    joueur(std::string nom);

    //setters
    void setj_number(int input);
    void setj_state(bool input);
    void setj_bots(int input);
    void setj_capitaine(bool input);
    void setj_zone(int input);

    //autre
    void addcartes(int input, carte carte);
    void passerTour(int input);
    void print();

    //getters
    int getj_number() const;
    bool getj_state()const;
    bool getj_capitaine()const;
    std::string getj_nom() const;
    int getj_bots() const;
    int getj_zone() const;
    std::map<int, carte> getcartes() const;

    //destructeur
    ~joueur();
};
