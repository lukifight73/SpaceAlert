#pragma once

#include <stdexcept>
#include "space_alerte.hpp"

class cannon; // Forward declaration pour éviter les dépendances circulaires
class chemin_menace; // Forward declaration pour éviter les dépendances circulaires
class zone; // Forward declaration pour éviter les dépendances circulaires

class menace
{
    protected:
    std::string m_name;
    int m_tourDarrivee;
    bool m_presence;
    int m_vitesse;
    int m_vie;
    int m_position; // position dans le chemin
    int m_bouclier;
    int m_etat_bouclier;
    int m_difficulte;
    int m_degatsRecus;
    chemin_menace *m_chemin; // chemin de la menace
    zone *m_zone; // zone de la menace
    std::vector<cannon *> m_canon_used; // pour les menaces qui utilisent des canons
    std::vector<int>    m_canon_immunity; // pour les menaces qui sont immunisées contre certains canons

    public:
        menace();
        menace(std::string input, int tourDarrivee);
        // Surcharge de l'opérateur d'affectation
        menace &operator=(const menace &other);

        // Getters et Setters
        std::string get_m_name() const {
            return m_name;
        };
        void set_m_zone(zone *input) {
            m_zone = input;
        };
        zone *get_m_zone() const {
            return m_zone;
        };
        chemin_menace *get_m_chemin() const {
            return m_chemin;
        };
        void set_m_chemin(chemin_menace *input) {
            m_chemin = input;
        };

        void setm_position(int input) {
            m_position = input;
        };
        int get_m_position() const {
            return m_position;
        };
        int get_m_tourDarrivee() const {
            return m_tourDarrivee;
        };
        int get_m_vitesse() const {
            return m_vitesse;
        };
        int get_m_vie() const {
            return m_vie;
        };
        int get_m_bouclier() const {
            return m_bouclier;
        };
        int get_m_difficulte() const {
            return m_difficulte;
        };
        bool get_m_presence() const {
            return m_presence;
        };
        int get_m_degatsRecus() const {
            return m_degatsRecus;
        };

        int get_m_etat_bouclier() const {
            return m_etat_bouclier;
        };
        void set_m_vie(int input) {
            m_vie = input;
        };

        void set_m_etat_bouclier(int input) {
            m_etat_bouclier = input;
        };

        void set_m_degatsRecus(int input) {
            m_degatsRecus = input;
        };
        std::vector<int> get_m_canon_immunity() const {
            return m_canon_immunity;
        };

        void set_m_presence(bool input) {
            m_presence = input;
        };
        std::vector<cannon *> get_m_canon_used() const {
            return m_canon_used;
        };

        // autres fonctions

        void checkIfCrossActionZone(int positionBefore, int positionAfter);

        void add_m_canon_immunity(int input) {
            m_canon_immunity.push_back(input);
        };

        void add_m_canon_used(cannon *input) {
            m_canon_used.push_back(input);
        };
        void clear_m_canon_used() {
            m_canon_used.clear();
        };
        void send_announcement_message() const;
        void print_menace() const;

        // Action de la menace
        virtual void actionMenace(char input);

        virtual void actionQuandDetruit();


        void augmenteVie(int input) {
            m_vie += input;
        };

        void augmenteBouclier(int input) {
            m_bouclier += input;
        };

        void draineEnergieBouclier(int input);

        void makedegatsInZone(int input);

        void makedegatsLeft(int input);

        void makedegatsRight(int input);

        
        virtual ~menace();
};
