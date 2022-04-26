#ifndef GRAPHE_HPP
#define GRAPHE_HPP

#include <vector>
#include "draw.hpp"
using namespace MMaze ;

/*
struct chemins{
    std::vector<int> casesAcces;
};
*/

class graphe
{
public:
    int xGraphe;
    int yGraphe;
    bool mursGraphes[24];
    bool boutiquesGraphes[16];
    std::vector<int> cheminsGraphe[16];
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
    void setMur(bool M[24]);
    void setBoutiques(bool boutiques[]);
    void setPortes2(int coul);
    void setPortes4(int coul);
    void setPortes11(int coul);
    void setObj(int C, int pos);
    void setSort(int C, int pos);
    void tousChemins();
    int Case_accesible();
    void add_edge(std::vector<int> adj[], int src, int dest);
    void displayAdjList(std::vector<int> adj[], int v);
      bool BFS(std::vector<int> adj[], int src, int dest, int v,
		int pred[], int dist[]);
    void printShortestDistance( int s,
						int dest, int v);
    

};

#endif // GRAPHE_HPP
