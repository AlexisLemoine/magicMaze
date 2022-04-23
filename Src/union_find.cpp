#include "union_find.hpp"


Union_find::Union_find(int n)
{
    int i = 0;
    while(i < n){
        pere.push_back(i);
        hauteur.push_back(1);
        i++;
    }
}

int Union_find::racine(int n){
    if (pere[n] == n){
        return n;
    }
    else{
        pere[n] = racine(pere[n]);
        return racine(pere[n]);
    }
}

void Union_find::fusion(int n1, int n2){
    if (hauteur[racine(n1)] > hauteur[racine(n2)]){
        pere[racine(n2)] = racine(n1);
    }
    else {
        if (hauteur[racine(n1)] < hauteur[racine(n2)])
            {pere[racine(n1)] = racine(n2);}
        else {
            pere[racine(n1)] = racine(n2);
            hauteur[n2]++;
        }
    }
}

bool Union_find::recherche(int n1, int n2){
    if (racine(n1) == racine(n2)){

        return true;
    }
    else{

        return false;
    }
}
