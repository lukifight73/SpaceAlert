#include "space_alerte.hpp"

void remove_dead_or_outdated_menaces(t_data &data)
{
    int i = 1;
    while (i < 4) 
    {
        chemin_menace *chemin = data.zones[i]->getz_chemin_menace();
        std::vector<menace*> tmp = data.zones[i]->getz_chemin_menace()->get_menaces();
        for (std::vector<menace*>::iterator it = tmp.begin(); it != tmp.end();) 
        {
            if ((*it)->get_m_position() <= 0) 
            {
                chemin->remove_menace(*it); // Suppression de la menace du chemin
            }
            ++it; // Avance l'itérateur si l'élément n'est pas supprimé
        }
        i++;
    }
}

void mouvement_menaces(t_data &data)
{
    int i = 1;
    while (i < 4) 
    {
        std::vector<menace*> tmp = data.zones[i]->getz_chemin_menace()->get_menaces();
        for (std::vector<menace*>::iterator it = tmp.begin(); it != tmp.end(); ++it) 
        {
            if ((*it)->get_m_presence()) 
            {
                (*it)->setm_position((*it)->get_m_position() - (*it)->get_m_vitesse());
            }
        }
        i++;
    }
}

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