#include "space_alerte.hpp"




// dans quelle zone on est?
// trouve montre le + proche sur chemin
// quel est le type de canon?
// a qui on le donne?
// est ce qui peut le prendre?
// distance?
// On le met dans son vector

void analyseDesDegatsCanons(t_data &data)
{
    int numZone(1);
    while (numZone < 4) 
    {
        std::vector<menace*> tmp = data.zones[numZone]->getz_chemin_menace()->get_menaces();
        for (std::vector<menace*>::iterator it = tmp.begin(); it != tmp.end(); ++it) 
        {
            std::vector<cannon*> canon = (*it)->get_m_canon_used();
            int degatsRecus(0);
            for (std::vector<cannon*>::iterator it2 = canon.begin(); it2 != canon.end(); ++it2) 
            {
                degatsRecus += (*it2)->getpuissance_cannon();
            }
            (*it)->set_m_degatsRecus(degatsRecus);
        }
        numZone++;
    }
}

bool MenaceIsinCannonRange(menace *menace, cannon *canon) 
{
    if (menace->get_m_position() <= canon->getportee_cannon() && menace->get_m_position() >= 0) 
    {
        return true;
    }
    return false;
}

void addCannonToMenaceinZone(t_data &data, cannon *canon, int zoneNumber) 
{
    menace *menaceProche = data.zones[zoneNumber]->getz_chemin_menace()->get_closest_menace();
    if (!menaceProche) 
    {
        return;
    }
    std::vector<int>::const_iterator canon_possible = std::find(menaceProche->get_m_canon_immunity().begin(), menaceProche->get_m_canon_immunity().end(), canon->gettype_cannon());
    if (canon_possible == menaceProche->get_m_canon_immunity().end() && MenaceIsinCannonRange(menaceProche, canon)) 
    {
        menaceProche->add_m_canon_used(canon);
    }
}

// fiare surcharge operator menaces + trouveer  trouver une clé à partir d’une valeur 

void assignationCannons(t_data &data) 
{
	int i(1);
    while (i < 4) 
    {
        std::vector<cannon*> canon = data.zones[i]->getz_cannon_used();
        std::vector<cannon*>::iterator it;
        for (it = canon.begin(); it != canon.end(); ++it) 
        {
            if ((*it)->gettype_cannon() == CANON_IMPULSION) // car touche toutes les zones
            {
                addCannonToMenaceinZone(data, *it, ZONE_BLUE);
                addCannonToMenaceinZone(data, *it, ZONE_RED);
                addCannonToMenaceinZone(data, *it, ZONE_WHITE);
            }
            else 
            {
                addCannonToMenaceinZone(data, *it, i);
            }
        }
        i++;
    }
}
