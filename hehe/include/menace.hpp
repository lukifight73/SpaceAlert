#pragma once

#include <string>    // pour std::string
#include <map>
#include <stdexcept>
#include "space_alerte.hpp"

class menace
{
    protected:
    std::string m_name;
    int m_tourDarrivee;
    bool m_presence;
    int m_vitesse;
    int m_vie;
    int m_bouclier;
    int m_difficulte;

    public:
        menace();
        menace(std::string input, int tourDarrivee);
        std::string get_m_name() const {
            return m_name;
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
        void set_m_presence(bool input) {
            m_presence = input;
        };
        void send_announcement_message() const;
        ~menace();
};
