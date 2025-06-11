#include "../include/cannon.hpp"
#include "SA_Values.hpp"
#include "menace.hpp"

cannon::cannon()
{
}
cannon::cannon(std::string cannon, int puissance, int portee, int type)
{
	nom_cannon = cannon;
	puissance_cannon = puissance;
	portee_cannon = portee;
	type_cannon = type;
}

void cannon::debuf_puissance_cannon(int debuf)
{
	puissance_cannon -= debuf;
	if (puissance_cannon < 0)
		puissance_cannon = 0;
}

void cannon::setpuissance_cannon(int input)
{
	puissance_cannon = input;
}

void cannon::setportee_cannon(int input)
{
	portee_cannon = input;
}

void cannon::setnom_cannon(std::string input)
{
	nom_cannon = input;
}

int cannon::getpuissance_cannon() const
{
	return (puissance_cannon);
}

int cannon::getportee_cannon() const
{
	return (portee_cannon);
}

int cannon::gettype_cannon() const
{
	return (type_cannon);
}

std::string cannon::getnom_cannon () const
{
	return (nom_cannon);
}

void cannon::debuf_portee_cannon(int debuf)
{
	portee_cannon -= debuf;
	if (portee_cannon < 0)
		portee_cannon = 0;
}

bool cannon::MenaceIsinCannonRange(menace *menace) const
{
	if (menace->get_m_position() <= getportee_cannon() && menace->get_m_position() >= 0) 
    {
        return true;
    }
    return false;
}

void cannon::setcanon_used(bool input)
{
	canon_used = input;
}
bool cannon::getcanon_used()
{
	return (canon_used);
}

void cannon::infligeDegats(menace *menace)
{
	// check imunity
	if(puissance_cannon > menace->get_m_etat_bouclier()) // Si la puissance du canon est supérieure à l'état du bouclier de la menace
	{
		int degatsInfliges = puissance_cannon - menace->get_m_etat_bouclier();
		std::cout << "[Le " << nom_cannon << " inflige " << degatsInfliges << " points de dégâts à la menace " << menace->get_m_name() << ".]\n";
		menace->set_m_etat_bouclier(0); // Bouclier épuisé
		menace->recoitDegats(degatsInfliges); // Inflige les dégâts restants à la menace
	}
	else // Si la puissance du canon est inférieure ou égale à l'état du bouclier de la menace
	{
		int etatBouclierRestant = menace->get_m_etat_bouclier() - puissance_cannon;
		std::cout << "[Le " << nom_cannon << " inflige " << puissance_cannon << " points de dégâts au bouclier de la menace " << menace->get_m_name() << ".]\n";
		menace->set_m_etat_bouclier(etatBouclierRestant);
	}
	canon_used = true; // Le canon a été utilisé

}

std::vector<menace*> cannon::getmenace_vulnerables(zone* zone)
{
	std::vector<menace*> menace_zone = zone->getz_chemin_menace()->get_menaces();
	std::vector<menace*> menaces_vulnerables;
	std::vector<menace*>::iterator it;
	for (it = menace_zone.begin(); it != menace_zone.end(); it++)
	{
		if ((*it)->vulnerability_check(this))
			menaces_vulnerables.push_back(*it);
	}
	return (menaces_vulnerables);
}

void casDuCanonImpulsion(menace *menaceCible)
{
	 // si le Maelstrom et Nuage d'energie prend des degats par le CANON_IMPULSION sont blindages vaut zero
	if(menaceCible->get_m_bouclier() == menaceCible->get_m_etat_bouclier()) 
		menaceCible->set_m_etat_bouclier(0); // si c etait son premier degats ca enleve juste le bouclier
	else
	{
		int degatsAbsorbeAvant = menaceCible->get_m_bouclier() - menaceCible->get_m_etat_bouclier(); // sinon les degats absorbe avant sont fait
		menaceCible->recoitDegats(degatsAbsorbeAvant);
		menaceCible->set_m_etat_bouclier(0);
	}
	wr("[Le Maelstrom s'est fait absorber son bouclier par le canon a impulsion !]");
}

void cannon::attaque_canon(zone *zone)
{
	if(!canon_used) // Le canon n'a pas été utilisé
		return;
	std::vector<menace*> VecMenaceCible = this->getmenace_vulnerables(zone);// cible potentielle ou la cible force!
	menace *menaceCible = get_closest_menace_in_vector(VecMenaceCible);
	if(!menaceCible) // Si la menace n'est pas dans la portée du canon
	{
		std::cout << "[Pas de menace a portée du " << nom_cannon << " en " << zone->getz_nom_zone() << ".]\n";
		return;
	}
	if(!MenaceIsinCannonRange(menaceCible)) // Si la menace n'est pas dans la portée du canon
	{
		std::cout << "[La menace " << menaceCible->get_m_name() << " en " <<  zone->getz_nom_zone() << " n'est pas dans la portée du " << nom_cannon << ".]\n";
		return;
	}
	if((menaceCible->get_m_name() == "Maelstrom" || menaceCible->get_m_name() == "Nuage d'energie") && this->gettype_cannon() == CANON_IMPULSION)
		casDuCanonImpulsion(menaceCible);
	infligeDegats(menaceCible); // Inflige les dégâts à la menace
}


void canon_impulsion::attaque_canon(zone *zone)
{
	cannon::attaque_canon(zone);

	cannon::attaque_canon(zone->getzone_left());

	cannon::attaque_canon(zone->getzone_right());
}


// void canon_impulsion::attaque_canon()
// {
// 	if(!canon_used) // Le canon n'a pas été utilisé
// 		return;
// 	std::vector<menace*> VecMenaceCible = this->getmenace_vulnerables(zone_cannon);// cible potentielle ou la cible force!
// 	menace *menaceCible = get_closest_menace_in_vector(VecMenaceCible);
// 	if(!menaceCible) // Si la menace n'est pas dans la portée du canon
// 	{
// 		std::cout << "[Pas de menace a portée du canon qui peut etre prise pour cible" << nom_cannon << ".]\n";
// 	}
// 	else if(!MenaceIsinCannonRange(menaceCible)) // Si la menace n'est pas dans la portée du canon
// 	{
// 		std::cout << "[La menace " << menaceCible->get_m_name() << " n'est pas dans la portée du canon " << nom_cannon << ".]\n";
// 	}
// 	VecMenaceCible = this->getmenace_vulnerables(zone_cannon->getzone_left());// cible potentielle ou la cible force!
// 	menaceCible = get_closest_menace_in_vector(VecMenaceCible);
// 	if(!menaceCible) // Si la menace n'est pas dans la portée du canon
// 	{
// 		std::cout << "[Pas de menace a portée du canon qui peut etre prise pour cible par le " << nom_cannon << ".]\n";
// 	}
// 	else if(!MenaceIsinCannonRange(menaceCible)) // Si la menace n'est pas dans la portée du canon
// 	{
// 		std::cout << "[La menace " << menaceCible->get_m_name() << " n'est pas dans la portée du canon " << nom_cannon << ".]\n";
// 	}
// 	VecMenaceCible = this->getmenace_vulnerables(zone_cannon->getzone_right());// cible potentielle ou la cible force!
// 	menaceCible = get_closest_menace_in_vector(VecMenaceCible);
// 	if(!menaceCible) // Si la menace n'est pas dans la portée du canon
// 	{
// 		std::cout << "[Pas de menace a portée du canon qui peut etre prise pour cible" << nom_cannon << ".]\n";
// 	}
// 	else if(!MenaceIsinCannonRange(menaceCible)) // Si la menace n'est pas dans la portée du canon
// 	{
// 		std::cout << "[La menace " << menaceCible->get_m_name() << " n'est pas dans la portée du canon " << nom_cannon << ".]\n";
// 	}
// 	infligeDegats(menaceCible); // Inflige les dégâts à la menace
// }

cannon::~cannon() {}
