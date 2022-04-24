#include "graphe.hpp"
#include<iostream>
#include "case.hpp"

graphe::graphe()
{
    xGraphe = 0;
    yGraphe = 0;
    existeP2 = false;
    couleurP2 = -1;
    existeP4 = false;
    couleurP4 = -1;
    existeP11 = false;
    couleurP11 = -1;
    existeP13 = false;
    couleurP13 = -1;

    objectif = false;
    sortie= false;
    couleurObj = -1;
    couleurSort = -1;
    caseObj = -1;
    caseSort = -1;
    for (int i = 0 ; i < 16; i++){
        cheminsGraphe[i].clear();
    }

}

void graphe::creerGraphe(){
    tousChemins();
}

void graphe::setCoord(int x, int y){
    xGraphe = x;
    yGraphe = y;
}

void graphe::setMur(bool M[24]){
    for (int i = 0; i < 24; i ++){
        mursGraphes[i] = M[i];
    }
}

void graphe::setBoutiques(bool boutiques[]){
    for (int i = 0; i < 16; i++){
        boutiquesGraphes[i] = boutiques[i];
    }
}

void graphe::setPortes2(int coul){
    existeP2 = true;
    couleurP2 = coul;
}

void graphe::setPortes4(int coul){
    existeP4 = true;
    couleurP4 = coul;
}

void graphe::setPortes11(int coul){
    existeP11 = true;
    couleurP11 = coul;
}

void graphe::setObj(int C, int pos){
    objectif = true;
    couleurObj = C;
    caseObj = pos;
}

void graphe::setSort(int C, int pos){
    sortie = true;
    couleurSort = C;
    caseSort = pos;
}

void graphe::tousChemins(){
    for (int i = 0 ; i < 16; i++){
        if (!boutiquesGraphes[i]){
            if (i > 3){
                bool change = true;
                int n = i;
                while ((change)&&(n > 3)){
                    Case c(n);
                    Mur m(c, c.haut());
                    if (!mursGraphes[m.index()]){
                        cheminsGraphe[i].push_back(c.haut().index());
                    }
                    else{
                        change = false;
                    }
                    n=n-4;
                }
            }
            if (i < 12){
                bool change = true;
                int n = i;
                while ((change) && (n< 12)){
                    Case c(n);
                    Mur m(c, c.bas());
                    if (!mursGraphes[m.index()]){
                        cheminsGraphe[i].push_back(c.bas().index());
                    }
                    else{
                        change = false;
                    }
                    n = n+4;
                }
            }
            if (!(i%4 == 0)){
                bool change = true;
                int n = i;
                while (change && (!(n%4 == 0))){
                    Case c(n);
                    Mur m(c, c.gauche());
                    if (!mursGraphes[m.index()]){
                        cheminsGraphe[i].push_back(c.gauche().index());
                    }
                    else{
                        change = false;
                    }
                    n--;
                }
            }
            if (!(i%4 == 3)){
                bool change = true;
                int n = i;
                while ((change) && !(n%4 == 3)){
                    Case c(n);
                    Mur m(c, c.droite());
                    if (!mursGraphes[m.index()]){
                        cheminsGraphe[i].push_back(c.droite().index());
                    }
                    else{
                        change = false;
                    }
                    n++;
                }
            }

        }
        int tmp = cheminsGraphe[i].size();
        std::cout << "case " << i << " : ";
        for (int j =0; j < tmp; j++){
            std:: cout << cheminsGraphe[i][j] << " ";
        }
        std:: cout<< std::endl;
    }

}

