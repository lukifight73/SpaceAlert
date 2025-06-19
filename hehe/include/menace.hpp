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
    int m_max_vie; // vie maximale de la menace
    int m_position; // position dans le chemin
    bool m_immunity;
    int m_difficulte;
    int m_buff_attack;
    
    chemin_menace *m_chemin; // chemin de la menace
    zone *m_zone; // zone de la menace
    int m_zoneInt;
    

    public:
        menace();
        menace(std::string input, int tourDarrivee);
        // Surcharge de l'opérateur d'affectation
        menace &operator=(const menace &other);

        // Getters et Setters
        std::string get_m_name() const {
            return m_name;
        };
        void increase_m_buff_attack(int input)
        {
            m_buff_attack += input;
        };
        void set_m_immunity(bool input) {
            m_immunity = input;
        };
        bool get_m_immunity() const {
            return m_immunity;
        };
        
        void set_m_zone(zone *input) {
            m_zone = input;
        };
        zone *get_m_zone() const {
            return m_zone;
        };

        void set_m_zoneInt(int input) {
            m_zoneInt = input;
        };
        
        int get_m_zoneInt() const {
            return m_zoneInt;
        };
        chemin_menace *get_m_chemin() const {
            return m_chemin;
        };
        void set_m_chemin(chemin_menace *input) {
            m_chemin = input;
        };
        void setm_buff_attack(int input) {
            m_buff_attack = input;
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
        int get_m_max_vie() const {
            return m_max_vie;
        };
        
        int get_m_difficulte() const {
            return m_difficulte;
        };
        bool get_m_presence() const {
            return m_presence;
        };
        void set_m_vie(int input) {
            m_vie = input;
        };
        void set_m_presence(bool input) {
            m_presence = input;
        };

        // autres fonctions

        virtual void recoitDegats(int input);

        int checkNombreInputCrossed(char input) const;

        void checkIfCrossActionZone(int positionBefore, int positionAfter);
        void send_announcement_message() const;
        virtual void print_menace() const;

        // Action de la menace
        virtual void actionMenace(char input);

        virtual void actionQuandDetruit();

        virtual bool vulnerability_check(cannon* input) {
            input->getcanon_used(); // pour pas avoir de prob de compilation
            return (true);
        };

        void draineEnergieBouclier(int input);

        void makedegatsInZone(int input);

        void makedegatsInZoneIgnoreBouclier(int input);

        void makedegatsLeft(int input);

        void makedegatsRight(int input);

        void regeneration(int input);

        virtual void effetDebutTour() {};
        
        virtual ~menace();

        void messageAttaqueMenace(int degats);
        
        void messageBufferMenace(std::string &string, int degats);
        void messageMenaceZone(int degats, zone *zone);
};
