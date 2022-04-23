#include "graphe.hpp"
#include<iostream>

graphe::graphe()
{

}

void graphe::creerGraphe(){
   // std::cout<< xGraphe;
}

void graphe::setCoord(int x, int y){
    xGraphe = x;
    yGraphe = y;
}

void graphe::setMur(std::vector<int> M){
    murGraphe = M;
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
