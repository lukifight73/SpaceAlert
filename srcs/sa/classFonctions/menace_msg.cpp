#include "menace.hpp"
#include "menace_externe.hpp"

// void messageAttaque(std::string nom)
// {
//     std::cout << "\033[1;35m[ACTION MENACE " << nom << "!]\033[0m" << std::endl;
// }

void menace::messageMenaceZone(int degats, zone *zone)
{
    //messageAttaque(m_name);
    start_color(m_zone, *m_zone->getz_data());
    std::string msg = "[La menace " + m_name + " lance une attaque de puissance " + std::to_string(degats + m_buff_attack) + "]\n";
    m_zone->getz_data()->text_robot += msg;
    printSlowly(msg, *m_zone->getz_data());
    start_color(zone, *m_zone->getz_data());
    msg = " sur la " + zone->getz_nom_zone() + "!]\n";
    m_zone->getz_data()->text_robot += msg;
    printSlowly(msg, *m_zone->getz_data());
    end_color(*m_zone->getz_data());
}

void menace::messageAttaqueMenace(int degats)
{
    //messageAttaque(m_name);
    start_color(m_zone, *m_zone->getz_data());
    std::string msg = "[La menace " + m_name + " lance une attaque de puissance " + std::to_string(degats + m_buff_attack) + "]\n";
    m_zone->getz_data()->text_robot += msg;
    printSlowly(msg, *m_zone->getz_data());
    end_color(*m_zone->getz_data());
}

void menace::messageBufferMenace(std::string &string, int degats)
{
    //messageAttaque(m_name);
    std::string msg;
    start_color(m_zone, *m_zone->getz_data());
    if (degats < 0)
        msg = string + "\n";
    else
        msg = string + std::to_string(degats) + "\n";
    m_zone->getz_data()->text_robot += msg;
    printSlowly(msg, *m_zone->getz_data());
    end_color(*m_zone->getz_data());
}

void menace::messageRecapCapitaine()
{
    m_zone->getz_data()->text_recap += m_degats_totaux_str;
    end_color(*m_zone->getz_data());
}
