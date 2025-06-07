#include "space_alerte.hpp"

void apparitionMenaces(t_data &data) 
{
    int i = 1;
    while (i < 4) 
    {
        std::vector<menace*> tmp = data.zones[i]->getz_chemin_menace()->get_menaces();
        for (std::vector<menace*>::iterator it = tmp.begin(); it != tmp.end(); ++it) 
        {
            if ((*it)->get_m_tourDarrivee() == data.tour)
            {
                std::cout << "\n\n/!\\/!\\/!\\/!\\/!\\/!\\ Attention, en " << data.zones[i]->getz_nom_zone();
                std::cout << " une menace vient d'apparaître ! /!\\/!\\/!\\/!\\/!\\/!\\" << std::endl;
                (*it)->set_m_presence(true);
                (*it)->send_announcement_message();
            }
        }
        i++;
    }
}