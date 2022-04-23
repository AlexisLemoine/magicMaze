#ifndef UNION_FIND_H
#define UNION_FIND_H

#include<iostream>
#include<vector>

class Union_find
{
public:
    std::vector<int> pere;
    std::vector<int> hauteur;

    Union_find(int n);

    int racine(int n);
    void fusion(int n1, int n2);
    bool recherche(int n1, int n2);
};

#endif // UNION_FIND_H
