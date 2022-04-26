#ifndef PLATEAUETJEU_HPP
#define PLATEAUETJEU_HPP
#include "graphe.hpp"


class plateauEtJeu
{
public:
    PadPlateau plateau;
    std::vector<graphe> plateauDeGraphe;

    plateauEtJeu(std::vector<graphe>graphes);
    Couleur conversionCouleur(int n);
    void initialisation(graphe G);
    void ouvrirPorteGauche(int x, int y);

};

#endif // PLATEAUETJEU_HPP
