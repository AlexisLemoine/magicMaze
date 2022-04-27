#include "graphe.hpp"
#include <iostream>
#include "case.hpp"
#include <vector>
#include <queue>
#include <fstream>
#include <limits>
#include <bits/stdc++.h>



using namespace std;


vector<int> adj [16];
std::vector<graphe>tabgraphe;
int graphe_Counter=0;

//construre une liste de contiguïté
void graphe:: add_edge(vector<int> adj[], int src, int dest)
{
    
	adj[src].push_back(dest);

}

// affichage de la liste  de contiguïté

void graphe::displayAdjList(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++) {
        cout << i << "->";
        for (int& x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}


// a modified version of BFS that stores predecessor
// of each vertex in array p
// and its distance from source in array d
bool graphe:: BFS(vector<int> adj[], int src, int dest, int v,
		int pred[], int dist[])
{
	// a queue to maintain queue of vertices whose
	// adjacency list is to be scanned as per normal
	// DFS algorithm
	list<int> queue;

	
	bool visited[v];

	// initially all vertices are unvisited
	// so v[i] for all i is false
	// and as no path is yet constructed
	// dist[i] for all i set to infinity
	for (int i = 0; i < v; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
		pred[i] = -1;
	}

	// On commennce par la source st c'est la premiere dans notre graphe
	visited[src] = true;
	dist[src] = 0;
	queue.push_back(src);

	// standard BFS algorithm
	while (!queue.empty()) {
		int u = queue.front();
		queue.pop_front();
		for (int i = 0; i < adj[u].size(); i++) {
			if (visited[adj[u][i]] == false) {
				visited[adj[u][i]] = true;
				dist[adj[u][i]] = dist[u] + 1;
				pred[adj[u][i]] = u;
				queue.push_back(adj[u][i]);

				// We stop BFS when we find
				// destination.
				if (adj[u][i] == dest)
					return true;
			}
		}
	}

	return false;
}

// utility function to print the shortest distance
// between source vertex and destination vertex
void graphe::printShortestDistance(int s,int dest, int v)
{
	// predecessor[i] array stores predecessor of
	// i and distance array stores distance of i
	// from s
	int pred[v], dist[v];

	if (BFS(adj, s, dest, v, pred, dist) == false) {
		cout << "lA Source et la destination ne sont pas connecté"
            << std::endl;
		return;
	}

	// vector path stores the shortest path
	vector<int> path;
	int crawl = dest;
	path.push_back(crawl);
	while (pred[crawl] != -1) {
		path.push_back(pred[crawl]);
		crawl = pred[crawl];
	}

	// distance from source is in distance array
	cout << "La longeur du plus court chemin est : "
		<< dist[dest];

	// printing path from source to destination
	cout << "\nLe plus Court chemin est::   ";
	for (int i = path.size() - 1; i >= 0; i--){
        cout << path[i] << " ";
    }

    cout<<endl;


}

// on initialise le graphe
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
         adj[i].clear();
    }
    int graphe_num=0;
  

}

// fonction qui créé le graphe des chemins de chaque case à une autre.
void graphe::creerGraphe(){

    tousChemins();
}

// tous les sets sont là pour récupérer les données de tuile.cpp.
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

void graphe::setPortes13(int coul){
    existeP13 = true;
    couleurP13 = coul;
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

// donne toutes les cases qui ne sont pas des boutiques
int graphe::Case_accesible(){

    int count=0;
    for (int i = 0; i < 16; i++)
    {
            if(!boutiquesGraphes[i]){

                count++;
                
            }
            
    }
    return count;
}


// donne toutes les cases accessibles entre chaques cases sur une tuile.
void graphe::tousChemins(){ 

    for (int i = 0 ; i < 16; i++){
        // si la case n'est pas une boutiques, on regarde quels sont ses voisins
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
         //std::cout << "case " << i << " : ";
        for(int j =0; j < tmp; j++){
         add_edge(adj,i,cheminsGraphe[i][j]);
          //std:: cout << cheminsGraphe[i][j] << " ";
        }
        //std:: cout<< std::endl;
    }
    

    displayAdjList(adj,16);

    

}

