#include "space_alerte.hpp"

void apparitionMenaces(t_data &data) 
{
    std::vector<menace *>::iterator it;
    it = data.zones[ZONE_BLUE]->getz_chemin_menace()->get_menaces().begin();
    while (it != data.zones[ZONE_BLUE]->getz_chemin_menace()->get_menaces().end()) 
    {
        if ((*it)->get_m_tourDarrivee() == data.tour) 
        {
            (*it)->set_m_presence(true);
        } 
        ++it;
    }
}