#include "space_alerte.hpp"
#include "menace.hpp"
#include "menace_externe.hpp"





// dans quelle zone on est?
// trouve montre le + proche sur chemin
// quel est le type de canon?
// a qui on le donne?
// est ce qui peut le prendre?
// distance?
// On le met dans son vector

// additionne tous les degats des canons utilisés contre la menace
// void analyseDesDegatsCanons(t_data &data)
// {
//     int numZone(1);
//     while (numZone < 4)
//     {
//         std::vector<menace*> tmp = data.zones[numZone]->getz_chemin_menace()->get_menaces();
//         for (std::vector<menace*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
//         {
//             std::vector<cannon*> canon = (*it)->get_m_canon_used();
//             int degatsRecus(0);
//             for (std::vector<cannon*>::iterator it2 = canon.begin(); it2 != canon.end(); ++it2)
//             {
//                 degatsRecus += (*it2)->getpuissance_cannon();
//             }
//             (*it)->set_m_degatsRecus(degatsRecus);
//         }
//         numZone++;
//     }
// }

// bool MenaceIsinCannonRange(menace *menace, cannon *canon)
// {
//     if (menace->get_m_position() <= canon->getportee_cannon() && menace->get_m_position() >= 0)
//     {
//         return true;
//     }
//     return false;
// }

// void addCannonToMenaceinZone(t_data &data, cannon *canon, int zoneNumber)
// {
//     menace *menaceProche = data.zones[zoneNumber]->getz_chemin_menace()->get_closest_menace();
//     if (!menaceProche)
//     {
//         return;
//     }
//     std::vector<int>::const_iterator canon_possible = std::find(menaceProche->get_m_canon_immunity().begin(), menaceProche->get_m_canon_immunity().end(), canon->gettype_cannon());
//     if (canon_possible == menaceProche->get_m_canon_immunity().end() && MenaceIsinCannonRange(menaceProche, canon))
//     {
//         menaceProche->add_m_canon_used(canon);
//     }
// }


// void assignationCannons(t_data &data)
// {
// 	int i(1);
//     while (i < 4)
//     {
//         std::vector<cannon*> canon = data.zones[i]->getz_cannon_used();
//         std::vector<cannon*>::iterator it;
//         for (it = canon.begin(); it != canon.end(); ++it)
//         {
//             if ((*it)->gettype_cannon() == CANON_IMPULSION) // car touche toutes les zones
//             {
//                 addCannonToMenaceinZone(data, *it, ZONE_BLUE);
//                 addCannonToMenaceinZone(data, *it, ZONE_RED);
//                 addCannonToMenaceinZone(data, *it, ZONE_WHITE);
//             }
//             else
//             {
//                 addCannonToMenaceinZone(data, *it, i);
//             }
//         }
//         i++;
//     }
// }


menace_externe *getMenaceLaPlusProcheTouteZones(t_data &data)
{
    menace_externe *menaceProcheB = data.zones[ZONE_BLUE]->getz_chemin_menace()->get_closest_menace_rocket_vulnerable();
    menace_externe *menaceProcheR = data.zones[ZONE_RED]->getz_chemin_menace()->get_closest_menace_rocket_vulnerable();
    menace_externe *menaceProcheW = data.zones[ZONE_WHITE]->getz_chemin_menace()->get_closest_menace_rocket_vulnerable();

    if (!menaceProcheB && !menaceProcheR && !menaceProcheW)
        return nullptr; // Si aucune menace n'est trouvée, retourner nullptr
    else if (!menaceProcheB && !menaceProcheR)
        return menaceProcheW; // Si seulement menaceProcheW est trouvée
    else if (!menaceProcheB && !menaceProcheW)
        return menaceProcheR; // Si seulement menaceProcheR est trouvée
    else if (!menaceProcheR && !menaceProcheW)
        return menaceProcheB; // Si seulement menaceProcheB est trouvée
    /// Cas ou une seule menace est manquante
    else if (!menaceProcheB)
    {
        if (menaceProcheR->get_m_position() < menaceProcheW->get_m_position())
            return menaceProcheR;
        else if (menaceProcheW->get_m_position() == menaceProcheR->get_m_position())
        {
            if (menaceProcheR->get_m_tourDarrivee() < menaceProcheW->get_m_tourDarrivee())
                return menaceProcheR; // Si menaceProcheR est plus proche ou égale mais arrivée plus tôt
            else
                return menaceProcheW; // Si menaceProcheW est arrivée plus tôt ou égale
        }
        else
            return menaceProcheW; // Si seulement menaceProcheB est absente
    }
    else if (!menaceProcheR)
    {
        if (menaceProcheB->get_m_position() < menaceProcheW->get_m_position())
            return menaceProcheB;
        else if (menaceProcheW->get_m_position() == menaceProcheB->get_m_position())
        {
            if (menaceProcheB->get_m_tourDarrivee() < menaceProcheW->get_m_tourDarrivee())
                return menaceProcheB; // Si menaceProcheB est plus proche ou égale mais arrivée plus tôt
            else
                return menaceProcheW; // Si menaceProcheW est arrivée plus tôt ou égale
        }
        else
            return menaceProcheW; // Si seulement menaceProcheR est absente
    }
    else if (!menaceProcheW)
    {
        if (menaceProcheB->get_m_position() < menaceProcheR->get_m_position())
            return menaceProcheB;
        else if (menaceProcheR->get_m_position() == menaceProcheB->get_m_position())
        {
            if (menaceProcheB->get_m_tourDarrivee() < menaceProcheR->get_m_tourDarrivee())
                return menaceProcheB; // Si menaceProcheB est plus proche ou égale mais arrivée plus tôt
            else
                return menaceProcheR; // Si menaceProcheR est arrivée plus tôt ou égale
        }
        else
            return menaceProcheR; // Si seulement menaceProcheW est absente
    }
    /// Cas ou il y a une menace par Zone
    else if(menaceProcheB->get_m_position() < menaceProcheR->get_m_position() && menaceProcheB->get_m_position() < menaceProcheW->get_m_position())
        return menaceProcheB;
    else if(menaceProcheR->get_m_position() < menaceProcheB->get_m_position() && menaceProcheR->get_m_position() < menaceProcheW->get_m_position())
        return menaceProcheR;
    else if(menaceProcheW->get_m_position() < menaceProcheB->get_m_position() && menaceProcheW->get_m_position() < menaceProcheR->get_m_position())
        return menaceProcheW;
    else if ((menaceProcheB->get_m_position() == menaceProcheR->get_m_position() && menaceProcheB->get_m_tourDarrivee() < menaceProcheR->get_m_tourDarrivee()) || (menaceProcheB->get_m_position() == menaceProcheW->get_m_position() && menaceProcheB->get_m_tourDarrivee() < menaceProcheW->get_m_tourDarrivee()))
        return menaceProcheB;
    else if ((menaceProcheR->get_m_position() == menaceProcheW->get_m_position() && menaceProcheR->get_m_tourDarrivee() < menaceProcheW->get_m_tourDarrivee()) || (menaceProcheR->get_m_position() == menaceProcheB->get_m_position() && menaceProcheR->get_m_tourDarrivee() < menaceProcheB->get_m_tourDarrivee()))
        return menaceProcheR;
    else if ((menaceProcheW->get_m_position() == menaceProcheB->get_m_position() && menaceProcheW->get_m_tourDarrivee() < menaceProcheB->get_m_tourDarrivee()) || (menaceProcheW->get_m_position() == menaceProcheR->get_m_position() && menaceProcheW->get_m_tourDarrivee() < menaceProcheR->get_m_tourDarrivee()))
        return menaceProcheW;
    else
        return nullptr; // Si aucune menace n'est trouvée, retourner nullptr
}

menace_externe *getMenaceNonNull(menace_externe* menace1, menace_externe* menace2, menace_externe* menace3)
{
    if (!menace1 && !menace2 && menace3)
        return menace3; // Si seulement menace3 est trouvée
    else if (!menace1 && menace2 && !menace3)
        return menace2; // Si seulement menace2 est trouvée
    else if (menace1 && !menace2 && !menace3)
        return menace1; // Si seulement menace1 est trouvée
    wr("ici");
    return nullptr;
}

void cumuleDegatsRocket(menace_externe *menace)
{
	if(menace->get_m_vie() <= 0)
		std::cout << "[La rocket ne fait rien, " << menace->get_m_name() << " est deja morte.]\n";
	std::string degats_str ="[La rocket inflige 3 points de dégâts à la menace " + menace->get_m_name() + ".]\n";
	menace->add_m_degats_str(degats_str);
	menace->add_m_degats(3);
}

bool menace_attract_rocket(t_data &data, int rocketNumber)
{
    menace_externe *menaceProcheB = data.zones[ZONE_BLUE]->getz_chemin_menace()->get_menace_that_attracts_rocket();
    menace_externe *menaceProcheR = data.zones[ZONE_RED]->getz_chemin_menace()->get_menace_that_attracts_rocket();
    menace_externe *menaceProcheW = data.zones[ZONE_WHITE]->getz_chemin_menace()->get_menace_that_attracts_rocket();
    menace_externe *menaceAttract = nullptr;
    if (!menaceProcheB && !menaceProcheR && !menaceProcheW)
        return false; // Si aucune menace n'est trouvée, retourner false
    if (getMenaceNonNull(menaceProcheB, menaceProcheR, menaceProcheW)) // une seule menace attire la roquette
    {
        menaceAttract = getMenaceNonNull(menaceProcheB, menaceProcheR, menaceProcheW);
    }
    else if (!menaceProcheB)
    {
        if (menaceProcheR->get_m_position() <= menaceProcheW->get_m_position())
        {
            menaceAttract = menaceProcheR; // Si menaceProcheR est plus proche ou égale
        }
        else
        {
            menaceAttract = menaceProcheW; // Si menaceProcheW est plus proche
        }
    }
    else if (!menaceProcheR)
    {
        if (menaceProcheB->get_m_position() <= menaceProcheW->get_m_position())
        {
            menaceAttract = menaceProcheB; // Si menaceProcheB est plus proche ou égale
        }
        else
        {
            menaceAttract = menaceProcheW; // Si menaceProcheW est plus proche
        }
    }
    else if (!menaceProcheW)
    {
        if (menaceProcheB->get_m_position() <= menaceProcheR->get_m_position())
        {
            menaceAttract = menaceProcheB; // Si menaceProcheB est plus proche ou égale
        }
        else
        {
            menaceAttract = menaceProcheR; // Si menaceProcheR est plus proche
        }
    }
    data.zones[ZONE_BLUE]->setz_roquete_position(rocketNumber, 4);
    std::cout << "[La roquette " << rocketNumber << " a été attirée par " << menaceAttract->get_m_name() << " !]\n";
    if (menaceAttract->get_m_vulnerable_roquette())
    {
        cumuleDegatsRocket(menaceAttract);
    }
    return (true);
}

void checkMenaceHitByRocket(t_data &data, int rocketNumber)
{
    std::map<int, int> rocketMap = data.zones[ZONE_BLUE]->getz_roquete_position();

    if (menace_attract_rocket(data, rocketNumber))
        return ;
    menace_externe *menaceProche = getMenaceLaPlusProcheTouteZones(data);
    //std::cout << menaceProche->get_m_name() << " est la menace la plus proche.\n";
    if (menaceProche && menaceProche->get_m_position() <= 10)
    {
        wait();
        std::cout << "[La roquette " << rocketNumber << " a touché " << menaceProche->get_m_name() << " !]\n";
        cumuleDegatsRocket(menaceProche);
        data.zones[ZONE_BLUE]->setz_roquete_position(rocketNumber, 4); // Set the rocket position to 4 to indicate it has hit a target
    }
    else
    {
        wait();
        data.zones[ZONE_BLUE]->setz_roquete_position(rocketNumber, 0); // Reset the rocket position
        std::cout << "[La roquette n'a touché aucune menace, elle revient a la base.]\n";
    }
}


void rocketActions(t_data &data)
{
    std::map<int, int> rocketMap = data.zones[ZONE_BLUE]->getz_roquete_position();
    int rocketNum(1);
    while (rocketNum < 4)
    {
        if (rocketMap[rocketNum] == 1)
        {
            wait();
            data.zones[ZONE_BLUE]->setz_roquete_position(rocketNum, 2);
            std::cout << "[La roquette numero " << rocketNum << " a été lancée !]\n";
        }
        else if (rocketMap[rocketNum] == 2)
        {
            checkMenaceHitByRocket(data, rocketNum);
        }
        rocketNum++;
    }
}

// void impactDegatsTotaux(t_data &data)
// {
//     int numZone(1);
//     while (numZone < 4)
//     {
//         std::vector<menace*> tmp = data.zones[numZone]->getz_chemin_menace()->get_menaces();
//         for (std::vector<menace*>::iterator it = tmp.begin(); it != tmp.end(); ++it)
//         {
//             int degatsRecus = (*it)->get_m_degatsRecus(); // tous les degats recu jusqu'ici
//             if (degatsRecus > 0)
//             {
//                 if ((*it)->get_m_immunity())
//                 {
//                     (*it)->set_m_immunity(false);
//                     continue;
//                 }
//                 int newLife((*it)->get_m_vie());
//                 if((*it)->get_m_bouclier() - degatsRecus >= 0)
//                 {
//                     (*it)->set_m_etat_bouclier((*it)->get_m_etat_bouclier() - degatsRecus);
//                     std::cout << "[La menace " << (*it)->get_m_name() << " a reçu " << degatsRecus << " points de dégâts, mais son bouclier a absorbé tous les dégâts.]\n";
//                 }
//                 else
//                 {
//                     newLife = (*it)->get_m_vie() - degatsRecus + (*it)->get_m_etat_bouclier();
//                     (*it)->set_m_etat_bouclier(0); // Bouclier épuisé
//                     std::cout << "[La menace " << (*it)->get_m_name() << " a reçu " << degatsRecus - (*it)->get_m_bouclier() << " points de dégâts.]\n";
//                 }
//                 if (newLife < 0)
//                 {
//                     newLife = 0; // Ensure life does not go below zero
//                 }
//                 (*it)->set_m_vie(newLife);
//                 (*it)->set_m_degatsRecus(0); // Reset the damage received after applying it
//                 if ((*it)->get_m_vie() <= 0)
//                 {
//                     (*it)->set_m_presence(false);
//                     (*it)->actionQuandDetruit();
//                 }
//             }
//         }
//         numZone++;
//     }
// }
