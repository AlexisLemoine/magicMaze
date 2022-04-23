#ifndef GRAPHE_HPP
#define GRAPHE_HPP

#include<vector>

class graphe
{
public:
    int xGraphe;
    int yGraphe;
    std::vector<int> murGraphe;
    bool existeP2;
    int couleurP2;
    bool existeP4;
    int couleurP4;
    bool existeP11;
    int couleurP11;
    bool existeP13;
    int couleurP13;

    bool objectif;
    bool sortie;
    int couleurObj;
    int couleurSort;
    int caseObj;
    int caseSort;

    graphe();

    void creerGraphe();
    void setCoord(int x, int y);
    void setMur(std::vector<int> M);
    void setPortes2(int coul);
    void setPortes4(int coul);
    void setPortes11(int coul);
    void setObj(int C, int pos);
    void setSort(int C, int pos);

};

#endif // GRAPHE_HPP
