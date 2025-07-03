#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <regex>
#include "webserv.hpp"
#include "space_alerte.hpp"

void insertThreatRecap(const std::string& filePath, const std::string& threatText) {
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier en lecture : " << filePath << std::endl;
        return;
    }

    std::string line;
    std::string content;
    bool inserted = false;

    while (std::getline(inFile, line)) {
        content += line + "\n";

        // On insère après la ligne qui contient <!--Start-->
        if (!inserted && line.find("<!--Start-->") != std::string::npos) {
            content += threatText + "\n";
            inserted = true;
        }
    }

    inFile.close();

    if (!inserted) {
        std::cerr << "Erreur : balise <!--Start--> non trouvée dans le fichier HTML." << std::endl;
        return;
    }

    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier en écriture : " << filePath << std::endl;
        return;
    }

    outFile << content;
    outFile.close();
}


void mettreAJourDegatsHTML(int degat_rouge, int degat_bleu, int degat_blanc, const std::string& cheminFichier) {
    std::ifstream fichierEntree(cheminFichier);
    if (!fichierEntree) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier HTML en lecture.\n";
        return;
    }

    std::stringstream buffer;
    buffer << fichierEntree.rdbuf();
    std::string contenu = buffer.str();
    fichierEntree.close();

    // Remplacer les valeurs avec des regex robustes
    contenu = std::regex_replace(contenu,
        std::regex(R"(Dégâts reçus zone rouge\s*:\s*\d+)"),
        "Dégâts reçus zone rouge : " + std::to_string(degat_rouge)
    );

    contenu = std::regex_replace(contenu,
        std::regex(R"(Dégâts reçus zone blanche\s*:\s*\d+)"),
        "Dégâts reçus zone blanche : " + std::to_string(degat_blanc)
    );

    contenu = std::regex_replace(contenu,
        std::regex(R"(Dégâts reçus zone bleue\s*:\s*\d+)"),
        "Dégâts reçus zone bleue : " + std::to_string(degat_bleu)
    );

    std::ofstream fichierSortie(cheminFichier);
    if (!fichierSortie) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier HTML en écriture.\n";
        return;
    }

    fichierSortie << contenu;
    fichierSortie.close();

}

void insererLignesAvecCouleur(const std::string& filename, const std::string& texte, int couleurIndex) {
    std::ifstream fileIn(filename);
    if (!fileIn.is_open()) {
        std::cerr << "Erreur d'ouverture du fichier HTML." << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << fileIn.rdbuf();
    std::string contenu = buffer.str();
    fileIn.close();

    // Liste des couleurs disponibles
    const std::string couleurs[] = {"white", "red", "green", "yellow", "orange", "violet", "blue", "white", "blue", "rose"};
    if (couleurIndex < 0 || couleurIndex > 9) {
        std::cerr << "Indice de couleur invalide." << std::endl;
        return;
    }
    std::string couleur = couleurs[couleurIndex];
    // Prépare les lignes à insérer
    std::stringstream ss(texte);
    std::string line;
    std::string lignesFormatees;

    while (std::getline(ss, line)) {
        lignesFormatees += "    <div class=\"" + couleur + "\">" + line + "</div><!--Next-->\n";
    }

    std::string baliseSection = "</div><!--Next-->";
    size_t pos = contenu.rfind(baliseSection);

    // Trouve la fin de la balise <div class="section section-global">
    size_t insertionPos = contenu.find("\n", pos);
    if (insertionPos == std::string::npos) insertionPos = pos + baliseSection.length();

    // Insère les lignes formatées juste après l'ouverture de la section globale
    contenu.insert(insertionPos + 1, lignesFormatees);

    std::ofstream fileOut(filename);
    if (!fileOut.is_open()) {
        std::cerr << "Erreur d'écriture dans le fichier HTML." << std::endl;
        return;
    }

    fileOut << contenu;
    fileOut.close();
}


void insererTexteAvecCouleurs(const std::string& filename, std::string& texteComplet) {
    std::stringstream ss(texteComplet);
    std::string line;
    int couleurCourante = 0;

    std::vector<std::string> blocLignes;

    auto insererBloc = [&](const std::vector<std::string>& lignes, int couleur) {
        if (lignes.empty()) return;
        std::string blocTexte;
        for (const auto& l : lignes) {
            blocTexte += l + "\n";
        }
        insererLignesAvecCouleur(filename, blocTexte, couleur);
    };

    while (std::getline(ss, line)) {
        std::string ligneTraitee = line;
        int derniereCouleurTrouvee = -1;

        // Tant qu'on trouve un marqueur |nombre| au début, on le retire et stocke la dernière valeur
        while (ligneTraitee.size() >= 3 && ligneTraitee[0] == '|' && ligneTraitee.find('|', 1) != std::string::npos) {
            size_t secondPipe = ligneTraitee.find('|', 1);
            std::string nombreStr = ligneTraitee.substr(1, secondPipe - 1);
            try {
                derniereCouleurTrouvee = std::stoi(nombreStr) % 10;
            } catch (...) {
                derniereCouleurTrouvee = 0;
            }
            ligneTraitee = ligneTraitee.substr(secondPipe + 1);
        }

        // Si on a trouvé un marqueur : on change de couleur = nouveau bloc
        if (derniereCouleurTrouvee != -1) {
            insererBloc(blocLignes, couleurCourante);
            blocLignes.clear();
            couleurCourante = derniereCouleurTrouvee;
        }

        blocLignes.push_back(ligneTraitee);
    }

    // Dernier bloc restant
    insererBloc(blocLignes, couleurCourante);
}



std::string supprimerContenuEntreMarqueurs(const std::string& contenu) {
    const std::string debut = "</div><!--Next-->";
    const std::string fin = "</div><!--STOP-->";

    std::size_t pos_debut = contenu.find(debut);
    if (pos_debut == std::string::npos)
        return contenu;

    // Trouver la fin de la ligne où se trouve debut (position du saut de ligne juste après)
    std::size_t pos_debut_ligne_fin = contenu.find('\n', pos_debut);
    if (pos_debut_ligne_fin == std::string::npos)
        pos_debut_ligne_fin = pos_debut + debut.length();

    std::size_t pos_fin = contenu.find(fin, pos_debut_ligne_fin);
    if (pos_fin == std::string::npos)
        return contenu;

    // Trouver le début de la ligne où se trouve fin (position du saut de ligne avant)
    std::size_t pos_fin_ligne_debut = contenu.rfind('\n', pos_fin);
    if (pos_fin_ligne_debut == std::string::npos)
        pos_fin_ligne_debut = pos_fin;

    std::string resultat = contenu;

    // Supprimer entre pos_debut_ligne_fin et pos_fin_ligne_debut (exclu)
    resultat.erase(pos_debut_ligne_fin + 1, pos_fin_ligne_debut - pos_debut_ligne_fin);

    return resultat;
}

// Fonction principale qui prend le chemin du fichier HTML
bool nettoyerFichierHtml(const std::string& chemin) {
    std::ifstream fichier_entree(chemin);
    if (!fichier_entree) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier en lecture : " << chemin << std::endl;
        return false;
    }

    std::stringstream buffer;
    buffer << fichier_entree.rdbuf(); // Lecture entière du fichier
    fichier_entree.close();

    std::string contenu_modifie = supprimerContenuEntreMarqueurs(buffer.str());

    std::ofstream fichier_sortie(chemin);
    if (!fichier_sortie) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier en écriture : " << chemin << std::endl;
        return false;
    }

    fichier_sortie << contenu_modifie;
    fichier_sortie.close();

    return true;
}

// Fonction générique pour remplacer le contenu textuel d'une balise contenant un identifiant unique
void remplacerContenuBalise(std::string& contenu, const std::string& baliseOuvrante, const std::string& nouveauTexte) {
    std::size_t debutBalise = contenu.find(baliseOuvrante);
    if (debutBalise == std::string::npos) return;

    // Cherche la fin de la balise ouvrante
    std::size_t debutContenu = contenu.find('>', debutBalise);
    if (debutContenu == std::string::npos) return;

    debutContenu += 1; // se placer après le '>'

    // Cherche la balise fermante correspondante
    std::size_t finContenu = contenu.find('<', debutContenu);
    if (finContenu == std::string::npos) return;

    // Remplace le contenu entre les balises
    contenu.replace(debutContenu, finContenu - debutContenu, nouveauTexte);
}

// Fonction principale
void mettreAJourCartesHTML(const std::string& nomJoueur, int numeroTour, const std::string& cheminFichier = "./www/webservSite/card_choice.html") {
    std::ifstream fichierEntree(cheminFichier);
    if (!fichierEntree) {
        std::cerr << "Erreur : Impossible d’ouvrir le fichier HTML : " << cheminFichier << std::endl;
        return;
    }

    // Lire le contenu
    std::ostringstream buffer;
    buffer << fichierEntree.rdbuf();
    std::string contenu = buffer.str();
    fichierEntree.close();

    // Modifier les balises
    remplacerContenuBalise(contenu, "<h1>", "TOUR " + std::to_string(numeroTour));
    remplacerContenuBalise(contenu, "<h2>", "Joueur " + nomJoueur + ", quelle carte avez-vous joué ce tour ?");

    // Écriture dans le fichier
    std::ofstream fichierSortie(cheminFichier);
    if (!fichierSortie) {
        std::cerr << "Erreur : Impossible d’écrire dans le fichier HTML." << std::endl;
        return;
    }

    fichierSortie << contenu;
    fichierSortie.close();
}


int update_card_choice(t_globalData &dataStruct)
{
    int tour = dataStruct.data->tour;
    int i(1);
    while (i <= dataStruct.data->nb_joueur && dataStruct.data->joueurs[i]->getcartes()[tour].getc_action() != TODO)
        i++;
    if (i > dataStruct.data->nb_joueur)
        return (0);
    mettreAJourCartesHTML(dataStruct.data->joueurs[i]->getj_nom(), tour);
    return (1);
}

const std::string cheminFichier = "./www/webservSite/joueurs.html";

// Fonction pour lire tout le fichier dans une string
std::string lireFichier(const std::string& chemin) {
    std::ifstream file(chemin);
    if (!file) {
        std::cerr << "Erreur: fichier introuvable " << chemin << std::endl;
        return "";
    }
    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

// Fonction pour écrire dans le fichier
bool ecrireFichier(const std::string& chemin, const std::string& contenu) {
    std::ofstream file(chemin);
    if (!file) {
        std::cerr << "Erreur: impossible d'écrire dans " << chemin << std::endl;
        return false;
    }
    file << contenu;
    return true;
}

// 1. Supprimer tous les joueurs (vider le contenu entre <div class="joueurs-container"> et </div>)
void supprimerJoueurs(std::string& html) {
    std::string baliseDebut = "<div class=\"joueurs-container\">";
    std::string baliseFin = "    </div><!--stop-->";

    std::size_t posDebut = html.find(baliseDebut);
    if (posDebut == std::string::npos) return;

    std::size_t posFin = html.find(baliseFin, posDebut);
    if (posFin == std::string::npos) return;

    posFin += baliseFin.length();

    // On remplace tout entre debut de la div et fin de la div par la div vide
    html.replace(posDebut, posFin - posDebut, baliseDebut + "\n    \n    </div><!--stop-->");
}

// 2. Ajouter un joueur avec nom et chemin photo dans la div joueurs-container
void ajouterJoueur(std::string& html, const std::string& nom, const std::string& cheminPhoto) {
    std::string baliseDebut = "<div class=\"joueurs-container\">";
    std::size_t pos = html.find(baliseDebut);
    if (pos == std::string::npos) return;

    pos += baliseDebut.length();

    // Le nouveau bloc joueur à insérer (indentation pour la lisibilité)
    std::string nouveauJoueur = "\n        <div class=\"joueur\">\n"
                               "            <p>" + nom + "</p>\n"
                               "            <img src=\"" + cheminPhoto + "\" alt=\"Carte du joueur " + nom + "\" />\n"
                               "        </div>";

    html.insert(pos, nouveauJoueur);
}

std::string get_chemin_carte(int carte)
{
    if (carte == ACT_A)
        return "/Photos/ACT_A.jpg";
    else if (carte == ACT_B)
        return "/Photos/ACT_B.jpg";
    else if (carte == ACT_C)
        return "/Photos/ACT_C.jpg";
    else if (carte == ACT_R)
        return "/Photos/ACT_R.jpg";
    else if (carte == ACT_RH)
        return "/Photos/ACT_RH.jpg";
    else if (carte == ACT_AH)
        return "/Photos/ACT_AH.jpg";
    else if (carte == ACT_BH)
        return "/Photos/ACT_BH.jpg";
    else if (carte == DIR_R)
        return "/Photos/DIR_R.jpg";
    else if (carte == DIR_B)
        return "/Photos/DIR_B.jpg";
    else if (carte == DIR_A)
        return "/Photos/DIR_A.jpg";
    else if (carte == DIR_RB)
        return "/Photos/DIR_RB.jpg";
    else if (carte == DIR_RH)
        return "/Photos/DIR_RH.jpg";
    else if (carte == DIR_WH)
        return "/Photos/DIR_WH.jpg";
    else if (carte == DIR_WB)
        return "/Photos/DIR_WB.jpg";
    else if (carte == DIR_BH)
        return "/Photos/DIR_BH.jpg";
    else if (carte == DIR_BB)
        return "/Photos/DIR_BB.jpg";
    else if (carte == INACTIF)
        return "/Photos/INACTIF.jpg";
    else if (carte == ASSOME)
        return "/Photos/ASSOME.jpg";
    else
        return ("");
}

// 3. Modifier le numéro de tour dans le titre h1 : "Actions joueurs tour X"
void modifierNumeroTour(std::string& html, int nouveauTour) {
    std::string debutTitre = "<h1>";
    std::string finTitre = "</h1>";

    std::size_t posDebut = html.find(debutTitre);
    if (posDebut == std::string::npos) return;

    posDebut += debutTitre.length();
    std::size_t posFin = html.find(finTitre, posDebut);
    if (posFin == std::string::npos) return;

    std::string nouveauTexte = "Actions joueurs tour " + std::to_string(nouveauTour);

    html.replace(posDebut, posFin - posDebut, nouveauTexte);
}

void modifier_fichier_bilan_tour_joueur(std::string chemin_html, t_globalData &dataStruct)
{
    std::string contenu = lireFichier(chemin_html);
    if (contenu.empty())
        return;
    supprimerJoueurs(contenu);  // vide la section joueurs
    int i(dataStruct.data->nb_joueur);
    while (i >= 1)
    {
        int carte = dataStruct.data->joueurs[i]->getcartes()[dataStruct.data->tour].getc_action();
        ajouterJoueur(contenu, dataStruct.data->joueurs[i]->getj_nom(), get_chemin_carte(carte));
        i--;
    }
    modifierNumeroTour(contenu, dataStruct.data->tour);
    if (!ecrireFichier(chemin_html, contenu))
        return;
    return;
}


