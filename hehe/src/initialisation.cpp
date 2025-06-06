
#include "space_alerte.hpp"
#include "space_alerte_values.hpp"

void init_carte_joueur_test(t_data& data)
{
	int i(0);
	carte carte_ACT_A(ACT_A);
	carte carte_ACT_B(ACT_B);
	carte carte_ACT_C(ACT_C);
	carte carte_DIR_A(DIR_A);
	carte carte_DIR_B(DIR_B);
	carte carte_DIR_R(DIR_R);
	carte carte_ACT_R(ACT_R);
	carte carte_ACT_AH(ACT_AH);
	carte carte_ACT_BH(ACT_BH);
	carte carte_INACTIF(INACTIF);
	data.joueurs[i]->addcartes(1, carte_ACT_C);
	data.joueurs[i]->addcartes(2, carte_ACT_C);
	data.joueurs[i]->addcartes(3, carte_INACTIF);
	data.joueurs[i]->addcartes(4, carte_ACT_C);
	data.joueurs[i]->addcartes(9, carte_DIR_B);
	data.joueurs[i]->addcartes(6, carte_ACT_R);
	data.joueurs[i]->addcartes(7, carte_ACT_A);
	data.joueurs[i]->addcartes(8, carte_DIR_A);
	data.joueurs[i]->addcartes(9, carte_DIR_A);
	data.joueurs[i]->addcartes(10, carte_ACT_B);
	data.joueurs[i]->addcartes(11, carte_ACT_A);
	data.joueurs[i]->addcartes(12, carte_INACTIF);
	i++;
	data.joueurs[i]->addcartes(1, carte_DIR_R);
	data.joueurs[i]->addcartes(2, carte_ACT_B);
	data.joueurs[i]->addcartes(3, carte_DIR_A);
	data.joueurs[i]->addcartes(4, carte_ACT_B);
	data.joueurs[i]->addcartes(5, carte_ACT_AH);
	data.joueurs[i]->addcartes(6, carte_ACT_R);
	data.joueurs[i]->addcartes(7, carte_DIR_A);
	data.joueurs[i]->addcartes(8, carte_DIR_B);
	data.joueurs[i]->addcartes(9, carte_ACT_C);
	data.joueurs[i]->addcartes(10, carte_ACT_B);
	data.joueurs[i]->addcartes(11, carte_ACT_A);
	data.joueurs[i]->addcartes(12, carte_ACT_A);
	i++;
	data.joueurs[i]->addcartes(1, carte_DIR_A);
	data.joueurs[i]->addcartes(2, carte_ACT_A);
	data.joueurs[i]->addcartes(3, carte_ACT_B);
	data.joueurs[i]->addcartes(4, carte_ACT_C);
	data.joueurs[i]->addcartes(5, carte_ACT_B);
	data.joueurs[i]->addcartes(6, carte_DIR_B);
	data.joueurs[i]->addcartes(7, carte_ACT_B);
	data.joueurs[i]->addcartes(8, carte_DIR_R);
	data.joueurs[i]->addcartes(9, carte_ACT_B);
	data.joueurs[i]->addcartes(10, carte_ACT_A);
	data.joueurs[i]->addcartes(11, carte_ACT_A);
	data.joueurs[i]->addcartes(12, carte_ACT_A);
	i++;
	data.joueurs[1]->setj_capitaine(true);
	data.joueurs[i]->addcartes(1, carte_DIR_B);
	data.joueurs[i]->addcartes(2, carte_DIR_A);
	data.joueurs[i]->addcartes(3, carte_ACT_B);
	data.joueurs[i]->addcartes(4, carte_ACT_A);
	data.joueurs[i]->addcartes(5, carte_DIR_A);
	data.joueurs[i]->addcartes(6, carte_DIR_A);
	data.joueurs[i]->addcartes(7, carte_DIR_A);
	data.joueurs[i]->addcartes(8, carte_ACT_B);
	data.joueurs[i]->addcartes(9, carte_DIR_A);
	data.joueurs[i]->addcartes(10, carte_DIR_A);
	data.joueurs[i]->addcartes(11, carte_ACT_B);
	data.joueurs[i]->addcartes(12, carte_DIR_A);
}

void init_data(t_data& data)
{
	data.nb_joueur = 4;
	int i(0);
	data.tour = 1;
	cannon *cannon_zone_blue = new cannon("Cannon laser lourd lateral", 4, 3, CANON_LOURD);
	cannon *cannon_zone_red = new cannon("Cannon laser lourd lateral", 4, 3, CANON_LOURD);
	cannon *cannon_zone_white = new cannon("Cannon laser lourd central", 5, 3, CANON_LOURD);
	cannon *cannon_leger_zone_blue = new cannon("Cannon laser leger lateral", 2, 3, CANON_LATERAUX);
	cannon *cannon_leger_zone_red = new cannon("Cannon laser leger lateral", 2, 3, CANON_LATERAUX);
	cannon *cannon_impulsion_zone_white = new cannon("Cannon a impulsion central", 1, 2, CANON_IMPULSION);
	chemin_menace *menace_zone_blanche = new chemin_menace();
	while (i < data.nb_joueur)
	{
		data.joueurs[i] = new joueur;
		i++;
	}
	data.zones[ZONE_WHITE] = new zone(ZONE_WHITE);
	data.zones[ZONE_BLUE] = new zone(ZONE_BLUE);
	data.zones[ZONE_RED] = new zone(ZONE_RED);
	data.zones[ZONE_BLUE]->setzone_white(data.zones[ZONE_WHITE]);
	data.zones[ZONE_BLUE]->setzone_red(data.zones[ZONE_RED]);
	data.zones[ZONE_BLUE]->setzone_blue(data.zones[ZONE_BLUE]);
	data.zones[ZONE_BLUE]->setzone_right(NULL);
	data.zones[ZONE_BLUE]->setzone_left(data.zones[ZONE_WHITE]);
    data.zones[ZONE_BLUE]->setcannon_haut(cannon_zone_blue);
    data.zones[ZONE_BLUE]->setcannon_bas(cannon_leger_zone_blue);
    data.zones[ZONE_BLUE]->setz_nom_zone("zone bleue");
    data.zones[ZONE_BLUE]->setz_chemin(menace_zone_blanche);
    data.zones[ZONE_BLUE]->setz_bots(true);
    data.zones[ZONE_BLUE]->setz_temps(1);
    data.zones[ZONE_BLUE]->setz_capsule_energie(0);
    data.zones[ZONE_BLUE]->setz_ascenseur(true);
    data.zones[ZONE_BLUE]->setz_reacteur(2);
    data.zones[ZONE_BLUE]->setz_max_energie_reservoir(3);
    data.zones[ZONE_BLUE]->setz_bouclier(1);
    data.zones[ZONE_BLUE]->setz_max_energie_bouclier(2);

	data.zones[ZONE_WHITE]->setzone_blue(data.zones[ZONE_BLUE]);
	data.zones[ZONE_WHITE]->setzone_red(data.zones[ZONE_RED]);
	data.zones[ZONE_WHITE]->setzone_white(data.zones[ZONE_WHITE]);
	data.zones[ZONE_WHITE]->setzone_right(data.zones[ZONE_BLUE]);
	data.zones[ZONE_WHITE]->setzone_left(data.zones[ZONE_RED]);
    data.zones[ZONE_WHITE]->setcannon_haut(cannon_zone_white);
    data.zones[ZONE_WHITE]->setcannon_bas(cannon_impulsion_zone_white);
    data.zones[ZONE_WHITE]->setz_nom_zone("zone blanche");
    data.zones[ZONE_WHITE]->setz_chemin(menace_zone_blanche);
    data.zones[ZONE_WHITE]->setz_bots(true);
    data.zones[ZONE_WHITE]->setz_temps(1);
    data.zones[ZONE_WHITE]->setz_capsule_energie(3);
    data.zones[ZONE_WHITE]->setz_ascenseur(true);
    data.zones[ZONE_WHITE]->setz_reacteur(3);
    data.zones[ZONE_WHITE]->setz_max_energie_reservoir(5);
    data.zones[ZONE_WHITE]->setz_bouclier(1);
    data.zones[ZONE_WHITE]->setz_max_energie_bouclier(3);
	i = 0;
	while (i < data.nb_joueur)
	{
		data.zones[ZONE_WHITE]->addz_joueurs_haut(data.joueurs[i]);
		i++;
	}
	data.zones[ZONE_RED]->setzone_white(data.zones[ZONE_WHITE]);
	data.zones[ZONE_RED]->setzone_red(data.zones[ZONE_RED]);
	data.zones[ZONE_RED]->setzone_blue(data.zones[ZONE_BLUE]);
	data.zones[ZONE_RED]->setzone_right(data.zones[ZONE_WHITE]);
	data.zones[ZONE_RED]->setzone_left(NULL);
    data.zones[ZONE_RED]->setcannon_haut(cannon_zone_red);
    data.zones[ZONE_RED]->setcannon_bas(cannon_leger_zone_red);
    data.zones[ZONE_RED]->setz_nom_zone("zone rouge");
    data.zones[ZONE_RED]->setz_chemin(menace_zone_blanche);
    data.zones[ZONE_RED]->setz_bots(true);
    data.zones[ZONE_RED]->setz_temps(1);
    data.zones[ZONE_RED]->setz_capsule_energie(0);
    data.zones[ZONE_RED]->setz_ascenseur(true);
    data.zones[ZONE_RED]->setz_reacteur(2);
    data.zones[ZONE_RED]->setz_max_energie_reservoir(3);
    data.zones[ZONE_RED]->setz_bouclier(1);
    data.zones[ZONE_RED]->setz_max_energie_bouclier(2);
}