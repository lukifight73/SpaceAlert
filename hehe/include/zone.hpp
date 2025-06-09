#pragma once


#include <stdexcept>
#include "joueur.hpp"
#include "SA_Values.hpp"
#include "chemin_menace.hpp"
#include "cannon.hpp"
#include <random>

class joueur;
class chemin_menace;

class zone
{
    private:
        cannon *z_cannon_haut;
        cannon *z_cannon_bas;
        std::string z_nom_zone;
        chemin_menace *z_chemin_menace;
        bool z_bots;
        int z_zone;//NUMERO DE La ZONE
        int z_temps;//chelou ici
        int z_capsule_energie;
        bool z_ascenseur;
        int z_reacteur;
        int z_max_reacteur;
        int z_bouclier;
        int z_max_energie_bouclier;
        int z_degats_recu;
        std::map<int, int> z_ordre_degats; // 0 = degats recu, 1 = degats infliges, 2 = degats infliges aux menaces, 3 = degats infliges aux canons, 4 = degats infliges aux joueurs, 5 = degats infliges aux robots
        std::vector<cannon*> z_cannon_used;  // degats[3] += 4 // degats[3] += 2
        std::vector<int> z_maintenance_ordinateur;
        std::vector<int> z_observations;
        std::map<int, int> z_roquete_position;
        zone *zone_blue;
        zone *zone_red;
        zone *zone_white;
        zone *zone_right;
        zone *zone_left;
        std::string z_joueur_playing;//chelou ici
        std::vector<joueur*> z_joueurs_haut;
        std::vector<joueur*> z_joueurs_bas;
        std::vector<int>    z_actions_bas;
        std::vector<int>    z_actions_haut;
        std::vector<int>    z_actions_used_ce_tour_bas;
        std::vector<int>    z_actions_used_ce_tour_haut;
        chemin_menace *z_chemin_menace_interne;

    public:
        //constr & destr
        zone();
        zone(int nb_zone);
        virtual ~zone();

        //setters
        void setz_zone(int input);
        void setz_joueur_playing(std::string input);
        void setzone_white(zone* zone);
        void setzone_red(zone* zone);
        void setzone_blue(zone* zone);
        void setz_degats_recu(int input);
        void setzone_right(zone* zone);
        void setzone_left(zone* zone);
        void setz_cannon_haut(cannon *input);
        void setz_cannon_bas(cannon *input);
        void setz_nom_zone(std::string input);
        void setz_chemin(chemin_menace *input);
        void setz_bots(bool input);
        void setz_temps(int input);
        void setz_capsule_energie(int input);
        void setz_ascenseur(bool input);
        void setz_reacteur(int input);
        void setz_max_energie_reservoir(int input);
        void setz_bouclier(int input);
        void setz_max_energie_bouclier(int input);
        void setz_roquete_position(int, int);
        void setz_ordre_degats();

        //getters
        std::map<int, int> getz_roquete_position();
        int getz_reacteur() const;
        int getz_degats_recu() const;
        int getz_max_energie_reservoir() const;
        int getz_capsule_energie() const;
        bool getz_bots() const;
        int getz_bouclier() const;
        int getz_max_energie_bouclier() const;
        int getz_zone() const;
        std::string getz_nom_zone() const;
        bool getz_ascenseur() const;
        chemin_menace *getz_chemin_menace() const;
        chemin_menace *getz_chemin_menace_interne() const;
        cannon *getz_cannon_haut() const;
        cannon *getz_cannon_bas() const;
        std::string getz_joueur_playing() const;
        int getz_temps() const;
        std::vector<joueur*> getz_joueurs_bas() const;
        std::vector<joueur*> getz_joueurs_haut() const;
        std::vector<cannon*> getz_cannon_used() const;
        std::vector<int>    getz_actions_bas() const;
        std::vector<int>    getz_actions_haut() const;
        std::vector<int>    getz_actions_used_ce_tour_bas() const;
        std::vector<int>    getz_actions_used_ce_tour_haut() const;
        std::vector<int>    getz_maintenance_ordinateur() const;
        std::vector<int>    getz_observations() const;
        zone* getzone_white() const;
        zone* getzone_red() const;
        zone* getzone_blue() const;
        zone* getzone_right() const;
        zone* getzone_left() const;

        //degats
        void calculateDegatsCanons();
        void etatdesdegats();
        void getdegats(int input);
        void getdegatsIgnoreBouclier(int input);

        //autre
        joueur* getz_joueur_haut(std::string nom);
        joueur* getz_joueur_bas(std::string nom);
        void addz_maintenance_ordinateur(int input);
        void addz_observations(int input);
        void print();
        void printZone();
        void addtemps();
        void addz_joueurs_bas(joueur* input);
        void removez_joueurs_bas(std::string input);
        void addz_actions_bas(int input);
        void removez_actions_bas(int input);
        void addz_actions_used_ce_tour_bas(int input);
        void clearz_actions_used_ce_tour_bas();
        void clearz_cannon_used();
        void addz_cannon_used(cannon* input);
        void addz_joueurs_haut(joueur* input);
        void removez_joueurs_haut(std::string input);
        void addz_actions_haut(int input);
        void removez_actions_haut(int input);
        void addz_actions_used_ce_tour_haut(int input);
        void clearz_actions_used_ce_tour_haut();
        void actionA();
        void actionB();
        void actionAHeros();
        void actionBHeros();
        void actionC();
        void ascenseur();
        void retarderactionZoneHaut();
        void retarderactionZoneBas();
        void assomerjoueursZoneHaut();
        void assomerjoueursZoneBas();
        void assomerjoueursZone();
        void retarderactionZone();

        //Deplacement
        void flechesRouge();
        void flechesBleue();
};
