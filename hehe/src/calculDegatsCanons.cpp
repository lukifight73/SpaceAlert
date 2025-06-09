#include "space_alerte.hpp"
#include "menace.hpp"
#include "cannon.hpp"


menace* get_closest_menace_in_vector(std::vector<menace*> menaces) 
{
    if (menaces.empty()) {
        wr("No menaces available.");
        return nullptr; // Si il n'y a pas de menace, on retourne nullptr
    }
    int positionPlusProche = 0;
    menace *menaceProche = nullptr;
    for (auto it = menaces.begin(); it != menaces.end(); it++)
    {
        if ((*it)->get_m_presence() == false || (*it)->get_m_revele() == false) // Si la menace n'est pas presente, on passe a la suivante
        {
            continue;
        }
        if (positionPlusProche == 0)
        {
            positionPlusProche = (*it)->get_m_position(); // La position la plus prochde de la ou les menaces
            menaceProche = (*it); // La menace la plus proche
        }
        else if ((*it)->get_m_position() < positionPlusProche || ((*it)->get_m_position() == positionPlusProche && (*it)->get_m_tourDarrivee() < menaceProche->get_m_tourDarrivee())) // Si la menace est plus proche que la menace la plus proche
        {
            positionPlusProche = (*it)->get_m_position(); // On change la position de la menace la plus proche
            menaceProche = (*it); // On change la menace la plus proche
        }
    }
    return menaceProche; // On retourne la menace la plus proche
}


void attaqueDesCanons(t_data &data)
{
    int i(1);
    while (i < 4) // pour chaque zone
    {
        cannon* canon_haut = data.zones[i]->getz_cannon_haut();
        cannon* canon_bas = data.zones[i]->getz_cannon_bas();
        if (canon_haut->getcanon_used())
        {
            canon_haut->attaque_canon(data.zones[i]);
        }
        if (canon_bas->getcanon_used())
        {
            canon_bas->attaque_canon(data.zones[i]);
        }
        i++;
    }
}