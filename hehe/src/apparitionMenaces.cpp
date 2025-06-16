#include "space_alerte.hpp"
#include "menace.hpp"
#include "menace_externe.hpp"
#include "menace_interne.hpp"

void remove_dead_or_outdated_menaces(t_data &data)
{
    int i = 1;
    while (i < 4) 
    {
        chemin_menace *chemin = data.zones[i]->getz_chemin_menace();
        std::vector<menace_externe*> tmp = data.zones[i]->getz_chemin_menace()->get_menacesExte();
        for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end();) 
        {
            if ((*it)->get_m_position() <= 0 || (*it)->get_m_vie() <= 0) 
            {
                chemin->remove_menace(*it); // Suppression de la menace du chemin
            }
            ++it; // Avance l'itérateur si l'élément n'est pas supprimé
        }
        i++;
    }
    chemin_menace *chemin_interne = data.chemin_menace_interne;
    std::vector<menace_interne*> tmp = data.chemin_menace_interne->get_menacesInte();
	for (std::vector<menace_interne*>::iterator it2 = tmp.begin(); it2 != tmp.end(); ++it2) 
	{
		if ((*it2)->get_m_position() <= 0 || (*it2)->get_m_vie() <= 0) 
        {
            chemin_interne->remove_menace(*it2); // Suppression de la menace du chemin
        }
	}
}

void revelerMenace(menace_externe* menace)
{
    if (menace->get_m_name().find("Satellite") != std::string::npos && menace->get_m_position() <= 10) // SURCHARGE
        menace->set_m_revele(true);
}


void mouvement_menaces(t_data &data)
{
    int i = 1;
    while (i < 4) 
    {
        std::vector<menace_externe*> tmp = data.zones[i]->getz_chemin_menace()->get_menacesExte();
        for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it) 
        {
            if ((*it)->get_m_presence()) 
            {
                int positionBefore = (*it)->get_m_position();
                int positionAfter = (*it)->get_m_position() - (*it)->get_m_vitesse();
                (*it)->checkIfCrossActionZone(positionBefore, positionAfter);
                (*it)->setm_position(positionAfter); // update position
                //std::cout << (*it)->get_m_name() << " a croise X >>> " << (*it)->checkNombreInputCrossed('X') << std::endl;
            }
            if (!(*it)->get_m_revele())
                revelerMenace(*it);
        }
        i++;
    }
    chemin_menace *chemin_interne = data.chemin_menace_interne;
    std::vector<menace_interne*> tmp = chemin_interne->get_menacesInte();
	for (std::vector<menace_interne*>::iterator it = tmp.begin(); it != tmp.end(); ++it) 
	{
		if ((*it)->get_m_presence()) 
        {
            int positionBefore = (*it)->get_m_position();
            int positionAfter = (*it)->get_m_position() - (*it)->get_m_vitesse();
            (*it)->checkIfCrossActionZone(positionBefore, positionAfter);
            (*it)->setm_position(positionAfter); // update position
        }
	}
}

void apparitionMenaces(t_data &data) 
{
    int i = 1;
    while (i < 4) 
    {
        std::vector<menace_externe*> tmp = data.zones[i]->getz_chemin_menace()->get_menacesExte();
        for (std::vector<menace_externe*>::iterator it = tmp.begin(); it != tmp.end(); ++it) 
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
    std::vector<menace_interne*> tmp = data.chemin_menace_interne->get_menacesInte();
	for (std::vector<menace_interne*>::iterator it = tmp.begin(); it != tmp.end(); ++it) 
	{
		if ((*it)->get_m_tourDarrivee() == data.tour)
        {
            std::cout << "\n\n/!\\/!\\/!\\/!\\/!\\/!\\ Attention une menace interne vient d'apparaître ! /!\\/!\\/!\\/!\\/!\\/!\\" << std::endl;
            (*it)->set_m_presence(true);
            (*it)->send_announcement_message();
        }
	}
}