#include "plateauetjeu.hpp"
#include<iostream>
plateauEtJeu::plateauEtJeu(std::vector<graphe>graphes)
{
    plateauDeGraphe = graphes;

    initialisation(graphes[0]);
}

// petite fonction pour convertir un entier en une couleur
Couleur plateauEtJeu::conversionCouleur(int n){
    switch (n){
        case 0 :{return Couleur::AUCUNE;}
        case 1 :{return Couleur::JAUNE;}
        case 2 :{return Couleur::ORANGE;}
        case 3 :{return Couleur::VIOLET;}
        case 4 :{return Couleur::VERT;}
        default :{ std::cout<< "erreur lors de la conversion de couleur" << std::endl;
                return Couleur::AUCUNE;}
    }
}

// on initialise avec le graphe
void plateauEtJeu::initialisation(graphe G){
    plateau.ajouter_tuile(0, 0);
    plateau.placer_joueur(0, 0, Case(5), Couleur::JAUNE);
    plateau.placer_joueur(0, 0, Case(6), Couleur::ORANGE);
    plateau.placer_joueur(0, 0, Case(9), Couleur::VIOLET);
    plateau.placer_joueur(0, 0, Case(10), Couleur::VERT);
    for (int i = 0; i < 24; i++){
        if (G.mursGraphes[i]){
            plateau.ajouter_mur(0, 0, Mur(i));
        }
    }
    for (int i = 0; i < 16; i++){
        if (G.boutiquesGraphes[i]){
            plateau.ajouter_boutique(0, 0, Case(i));
        }
    }

    plateau.ajouter_porte(0, 0, Case(2), conversionCouleur(G.couleurP2));
    plateau.ajouter_porte(0, 0, Case(4), conversionCouleur(G.couleurP4));
    plateau.ajouter_porte(0, 0, Case(11), conversionCouleur(G.couleurP11));
    plateau.ajouter_porte(0, 0, Case(13), conversionCouleur(G.couleurP13));
}

// fonction impressionnante, mais simple à comprendre
void plateauEtJeu::ouvrirPorteGauche(int x, int y){
    std::cout<< "Ouverture de la porte gauche de la tuile (" << x << ", " << y << ") :" << std ::endl;
    int i = 0;

    int j = 0;
    int l =  plateauDeGraphe.size();

    // on récupère les deux tuiles qui nous intéressent (celles de part et d'autres de la porte.
    while((plateauDeGraphe[j].xGraphe != x || plateauDeGraphe[j].yGraphe != y)&&(j <= l++)){
        j++;
    }
    y--;


    while((plateauDeGraphe[i].xGraphe != x || plateauDeGraphe[i].yGraphe != y)&&(i <= l++)){
        i++;
    }
    if ((i == l++)||(!plateauDeGraphe[j].existeP4)){
        std::cout<< "Impossible d'ouvrir cette porte." << std::endl;
        return;
    }
    plateau.ajouter_tuile(x, y);

    // on utilise tout le long des entiers temporels pour échanger les placements des différents sites et murs.
    bool tmpPorte;
    int tmpCouleur;
    tmpPorte = plateauDeGraphe[i].existeP4;
    tmpCouleur = plateauDeGraphe[i].couleurP4;

    plateauDeGraphe[i].existeP4 =  plateauDeGraphe[i].existeP2;
    plateauDeGraphe[i].existeP2 =  plateauDeGraphe[i].existeP11;
    plateauDeGraphe[i].existeP11 =  plateauDeGraphe[i].existeP13;
    plateauDeGraphe[i].existeP13 =  tmpPorte;

    plateauDeGraphe[i].couleurP4 = plateauDeGraphe[i].couleurP2;
    plateauDeGraphe[i].couleurP2 = plateauDeGraphe[i].couleurP11;
    plateauDeGraphe[i].couleurP11 = plateauDeGraphe[i].couleurP13;
    plateauDeGraphe[i].couleurP13 = tmpCouleur;

    if (plateauDeGraphe[i].existeP2){
        plateau.ajouter_porte(x, y, Case(2), conversionCouleur(plateauDeGraphe[i].couleurP2));
    }
    if (plateauDeGraphe[i].existeP4){
        plateau.ajouter_porte(x, y, Case(4), conversionCouleur(plateauDeGraphe[i].couleurP4));
    }
    if (plateauDeGraphe[i].existeP11){
        plateau.ajouter_porte(x, y, Case(11), conversionCouleur(plateauDeGraphe[i].couleurP11));
    }
    if (plateauDeGraphe[i].existeP13){
        plateau.ajouter_porte(x, y, Case(13), conversionCouleur(plateauDeGraphe[i].couleurP13));
    }

    if (plateauDeGraphe[i].objectif){
        Case tmp(plateauDeGraphe[i].caseObj);
        plateauDeGraphe[i].caseObj = tmp.tourne(1).index();
    }
    if (plateauDeGraphe[i].sortie){
        Case tmp(plateauDeGraphe[i].caseSort);
        plateauDeGraphe[i].caseSort = tmp.tourne(1).index();
    }

    if (plateauDeGraphe[i].objectif){
        plateau.ajouter_objectif(x, y, Case(plateauDeGraphe[i].caseObj), conversionCouleur(plateauDeGraphe[i].couleurObj));
    }
    if (plateauDeGraphe[i].sortie){
        plateau.ajouter_sortie(x, y, Case(plateauDeGraphe[i].caseSort), conversionCouleur(plateauDeGraphe[i].couleurSort));
    }

    bool tmpMur[24];
    for (int j = 0; j < 24; j++){
        tmpMur[j] = false;
    }

    for (int j = 0; j < 24; j++){
        if (plateauDeGraphe[i].mursGraphes[j]){
            Mur m(j);
            int tmp = m.tourne(1).index();
            tmpMur[tmp] = true;
        }
    }

    for (int j = 0; j < 24; j++){
        plateauDeGraphe[i].mursGraphes[j] = tmpMur[j];
    }
    for (int j = 0; j < 24; j++){
        if (plateauDeGraphe[i].mursGraphes[j]){
            Mur m(j);
            plateau.ajouter_mur(x, y, m);
        }
    }

    bool tmpBoutiques[16];
    for (int j = 0; j < 16; j++){
        tmpBoutiques[j] = false;
    }

    for (int j = 0; j < 16; j++){
        if (plateauDeGraphe[i].boutiquesGraphes[j]){
            Case c(j);
            int tmp = c.tourne(1).index();
            tmpBoutiques[tmp] = true;
        }
    }

    for (int j = 0; j < 16; j++){
        plateauDeGraphe[i].boutiquesGraphes[j] = tmpBoutiques[j];
    }
    for (int j = 0; j < 16; j++){
        if (plateauDeGraphe[i].boutiquesGraphes[j]){
            Case c(j);
            plateau.ajouter_boutique(x, y, c);
        }
    }
}
// les 3 fonctions qui suivent sont identiques, pour chaque porte.
void plateauEtJeu::ouvrirPorteHaute(int x, int y){
    std::cout<< "Ouverture de la porte haute de la tuile (" << x << ", " << y << ") :" << std ::endl;
    int i = 0;
    int j = 0;
    int l =  plateauDeGraphe.size();

    while((plateauDeGraphe[j].xGraphe != x || plateauDeGraphe[j].yGraphe != y)&&(j <= l++)){
        j++;
    }
    x--;

    while((plateauDeGraphe[i].xGraphe != x || plateauDeGraphe[i].yGraphe != y)&&(i <= l++)){
        i++;
    }
    if ((i == l++)||(!plateauDeGraphe[j].existeP2)){
        std::cout<< "Impossible d'ouvrir cette porte." << std::endl;
        return;
    }
    plateau.ajouter_tuile(x, y);

    if (plateauDeGraphe[i].existeP2){
        plateau.ajouter_porte(x, y, Case(2), conversionCouleur(plateauDeGraphe[i].couleurP2));
    }
    if (plateauDeGraphe[i].existeP4){
        plateau.ajouter_porte(x, y, Case(4), conversionCouleur(plateauDeGraphe[i].couleurP4));
    }
    if (plateauDeGraphe[i].existeP11){
        plateau.ajouter_porte(x, y, Case(11), conversionCouleur(plateauDeGraphe[i].couleurP11));
    }
    if (plateauDeGraphe[i].existeP13){
        plateau.ajouter_porte(x, y, Case(13), conversionCouleur(plateauDeGraphe[i].couleurP13));
    }
    if (plateauDeGraphe[i].objectif){
        plateau.ajouter_objectif(x, y, Case(plateauDeGraphe[i].caseObj), conversionCouleur(plateauDeGraphe[i].couleurObj));
    }
    if (plateauDeGraphe[i].sortie){
        plateau.ajouter_sortie(x, y, Case(plateauDeGraphe[i].caseSort), conversionCouleur(plateauDeGraphe[i].couleurSort));
    }
    for (int j = 0; j < 24; j++){
        if (plateauDeGraphe[i].mursGraphes[j]){
            Mur m(j);
            plateau.ajouter_mur(x, y, m);
        }
    }
    for (int j = 0; j < 16; j++){
        if (plateauDeGraphe[i].boutiquesGraphes[j]){
            Case c(j);
            plateau.ajouter_boutique(x, y, c);
        }
    }
}

void plateauEtJeu::ouvrirPorteDroite(int x, int y){
    std::cout<< "Ouverture de la porte droite de la tuile (" << x << ", " << y << ") :" << std ::endl;
    int i = 0;
    int j = 0;
    int l =  plateauDeGraphe.size();

    while((plateauDeGraphe[j].xGraphe != x || plateauDeGraphe[j].yGraphe != y)&&(j <= l++)){
        j++;
    }
    y++;

    while((plateauDeGraphe[i].xGraphe != x || plateauDeGraphe[i].yGraphe != y)&&(i <= l++)){
        i++;
    }
    if ((i == l++)||(!plateauDeGraphe[j].existeP11)){
        std::cout<< "Impossible d'ouvrir cette porte." << std::endl;
        return;
    }

    plateau.ajouter_tuile(x, y);
    bool tmpPorte;
    int tmpCouleur;
    tmpPorte = plateauDeGraphe[i].existeP4;
    tmpCouleur = plateauDeGraphe[i].couleurP4;

    plateauDeGraphe[i].existeP4 =  plateauDeGraphe[i].existeP13;
    plateauDeGraphe[i].existeP13 =  plateauDeGraphe[i].existeP11;
    plateauDeGraphe[i].existeP11 =  plateauDeGraphe[i].existeP2;
    plateauDeGraphe[i].existeP2 =  tmpPorte;

    plateauDeGraphe[i].couleurP4 = plateauDeGraphe[i].couleurP13;
    plateauDeGraphe[i].couleurP13 = plateauDeGraphe[i].couleurP11;
    plateauDeGraphe[i].couleurP11 = plateauDeGraphe[i].couleurP2;
    plateauDeGraphe[i].couleurP2 = tmpCouleur;

    if (plateauDeGraphe[i].existeP2){
        plateau.ajouter_porte(x, y, Case(2), conversionCouleur(plateauDeGraphe[i].couleurP2));
    }
    if (plateauDeGraphe[i].existeP4){
        plateau.ajouter_porte(x, y, Case(4), conversionCouleur(plateauDeGraphe[i].couleurP4));
    }
    if (plateauDeGraphe[i].existeP11){
        plateau.ajouter_porte(x, y, Case(11), conversionCouleur(plateauDeGraphe[i].couleurP11));
    }
    if (plateauDeGraphe[i].existeP13){
        plateau.ajouter_porte(x, y, Case(13), conversionCouleur(plateauDeGraphe[i].couleurP13));
    }

    if (plateauDeGraphe[i].objectif){
        Case tmp(plateauDeGraphe[i].caseObj);
        plateauDeGraphe[i].caseObj = tmp.tourne(3).index();
    }
    if (plateauDeGraphe[i].sortie){
        Case tmp(plateauDeGraphe[i].caseSort);
        plateauDeGraphe[i].caseSort = tmp.tourne(3).index();
    }

    if (plateauDeGraphe[i].objectif){
        plateau.ajouter_objectif(x, y, Case(plateauDeGraphe[i].caseObj), conversionCouleur(plateauDeGraphe[i].couleurObj));
    }
    if (plateauDeGraphe[i].sortie){
        plateau.ajouter_sortie(x, y, Case(plateauDeGraphe[i].caseSort), conversionCouleur(plateauDeGraphe[i].couleurSort));
    }

    bool tmpMur[24];
    for (int j = 0; j < 24; j++){
        tmpMur[j] = false;
    }

    for (int j = 0; j < 24; j++){
        if (plateauDeGraphe[i].mursGraphes[j]){
            Mur m(j);
            int tmp = m.tourne(3).index();
            tmpMur[tmp] = true;
        }
    }

    for (int j = 0; j < 24; j++){
        plateauDeGraphe[i].mursGraphes[j] = tmpMur[j];
    }
    for (int j = 0; j < 24; j++){
        if (plateauDeGraphe[i].mursGraphes[j]){
            Mur m(j);
            plateau.ajouter_mur(x, y, m);
        }
    }

    bool tmpBoutiques[16];
    for (int j = 0; j < 16; j++){
        tmpBoutiques[j] = false;
    }

    for (int j = 0; j < 16; j++){
        if (plateauDeGraphe[i].boutiquesGraphes[j]){
            Case c(j);
            int tmp = c.tourne(3).index();
            tmpBoutiques[tmp] = true;
        }
    }

    for (int j = 0; j < 16; j++){
        plateauDeGraphe[i].boutiquesGraphes[j] = tmpBoutiques[j];
    }
    for (int j = 0; j < 16; j++){
        if (plateauDeGraphe[i].boutiquesGraphes[j]){
            Case c(j);
            plateau.ajouter_boutique(x, y, c);
        }
    }
}

void plateauEtJeu::ouvrirPorteBas(int x, int y){
    std::cout<< "Ouverture de la porte basse de la tuile (" << x << ", " << y << ") :" << std ::endl;
    int i = 0;
    int j = 0;
    int l =  plateauDeGraphe.size();

    while((plateauDeGraphe[j].xGraphe != x || plateauDeGraphe[j].yGraphe != y)&&(j <= l++)){
        j++;
    }
    x++;

    while((plateauDeGraphe[i].xGraphe != x || plateauDeGraphe[i].yGraphe != y)&&(i <= l++)){
        i++;
    }
    if ((i == l++)||(!plateauDeGraphe[j].existeP13)){
        std::cout<< "Impossible d'ouvrir cette porte." << std::endl;
        return;
    }

    plateau.ajouter_tuile(x, y);
    bool tmpPorte;
    int tmpCouleur;
    tmpPorte = plateauDeGraphe[i].existeP4;
    tmpCouleur = plateauDeGraphe[i].couleurP4;

    plateauDeGraphe[i].existeP4 =  plateauDeGraphe[i].existeP11;
    plateauDeGraphe[i].existeP11 =  tmpPorte;
    tmpPorte =  plateauDeGraphe[i].existeP2;
    plateauDeGraphe[i].existeP2 =  plateauDeGraphe[i].existeP13;
    plateauDeGraphe[i].existeP13 = tmpPorte;

    plateauDeGraphe[i].couleurP4 = plateauDeGraphe[i].couleurP11;
    plateauDeGraphe[i].couleurP11 = tmpCouleur;
    tmpCouleur = plateauDeGraphe[i].couleurP2;
    plateauDeGraphe[i].couleurP2 = plateauDeGraphe[i].couleurP13;
    plateauDeGraphe[i].couleurP13 =tmpCouleur;

    if (plateauDeGraphe[i].existeP2){
        plateau.ajouter_porte(x, y, Case(2), conversionCouleur(plateauDeGraphe[i].couleurP2));
    }
    if (plateauDeGraphe[i].existeP4){
        plateau.ajouter_porte(x, y, Case(4), conversionCouleur(plateauDeGraphe[i].couleurP4));
    }
    if (plateauDeGraphe[i].existeP11){
        plateau.ajouter_porte(x, y, Case(11), conversionCouleur(plateauDeGraphe[i].couleurP11));
    }
    if (plateauDeGraphe[i].existeP13){
        plateau.ajouter_porte(x, y, Case(13), conversionCouleur(plateauDeGraphe[i].couleurP13));
    }

    if (plateauDeGraphe[i].objectif){
        Case tmp(plateauDeGraphe[i].caseObj);
        plateauDeGraphe[i].caseObj = tmp.tourne(2).index();
    }
    if (plateauDeGraphe[i].sortie){
        Case tmp(plateauDeGraphe[i].caseSort);
        plateauDeGraphe[i].caseSort = tmp.tourne(2).index();
    }

    if (plateauDeGraphe[i].objectif){
        plateau.ajouter_objectif(x, y, Case(plateauDeGraphe[i].caseObj), conversionCouleur(plateauDeGraphe[i].couleurObj));
    }
    if (plateauDeGraphe[i].sortie){
        plateau.ajouter_sortie(x, y, Case(plateauDeGraphe[i].caseSort), conversionCouleur(plateauDeGraphe[i].couleurSort));
    }

    bool tmpMur[24];
    for (int j = 0; j < 24; j++){
        tmpMur[j] = false;
    }

    for (int j = 0; j < 24; j++){
        if (plateauDeGraphe[i].mursGraphes[j]){
            Mur m(j);
            int tmp = m.tourne(2).index();
            tmpMur[tmp] = true;
        }
    }

    for (int j = 0; j < 24; j++){
        plateauDeGraphe[i].mursGraphes[j] = tmpMur[j];
    }
    for (int j = 0; j < 24; j++){
        if (plateauDeGraphe[i].mursGraphes[j]){
            Mur m(j);
            plateau.ajouter_mur(x, y, m);
        }
    }

    bool tmpBoutiques[16];
    for (int j = 0; j < 16; j++){
        tmpBoutiques[j] = false;
    }

    for (int j = 0; j < 16; j++){
        if (plateauDeGraphe[i].boutiquesGraphes[j]){
            Case c(j);
            int tmp = c.tourne(2).index();
            tmpBoutiques[tmp] = true;
        }
    }

    for (int j = 0; j < 16; j++){
        plateauDeGraphe[i].boutiquesGraphes[j] = tmpBoutiques[j];
    }
    for (int j = 0; j < 16; j++){
        if (plateauDeGraphe[i].boutiquesGraphes[j]){
            Case c(j);
            plateau.ajouter_boutique(x, y, c);
        }
    }
}
