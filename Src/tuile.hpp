#ifndef MMAZE_TUILE_HPP
#define MMAZE_TUILE_HPP
#include "draw.hpp"
#include "union_find.hpp"
#include "graphe.hpp"

#include<vector>
#include <random>
#include <string>
using namespace MMaze ;

struct site{
public :
    int couleurP; //(entre -1 et 4)
    bool existeP;
    int joueurC;
};

class tuile : public Union_find
{
public:

    graphe G;
    PadPlateau pad;
    site tabCases[16];
    std::vector<int> tuile_CoorX;
    std::vector<int> tuile_CoorY;

    std::vector<int> murs;

    // 0 : aucune (couleur grise), 1 : jaune, 2 : violet, 3 : orange, 4 : vert
    bool jaune, violet, orange, vert, aucune;
    bool classique;

    // un booléen pour chaque objectif et sortie.
    bool objectif[5];
    bool sortie[5];
    // on stocke leurs numéros de cases
    int objectifNumCase[5];
    int sortieNum[5];
    // on stocke le nombre d'objectifs et de sorties qui sont présents
    int nbObjectif;
    int nbSortie;

    // ou sont chaque joueur
    int joueurCase[5];
    // on stocke si on a placé un objectif et/ou une sortie dans la dernière tuile
    bool obj;
    bool sort;
    int couleurObj;
    int couleurSort;
    int caseObjectif;
    int caseSortie;

    // constructeur
    tuile(int n);

    // dire ou sont les objectifs et sorties
    void objectifP(int x, int y);
    void sortieP(int x, int y);

    // on créé la tuile
    void ajouterFonctionPad(int x, int y);

    // on ajoute une nouvelle tuile
    void tuileSuivante(int x, int y);
    
    // détruit les murs
    void quelMur();
    bool toutRelies(Union_find C);

    // associer un chiffre a une couleur
    Couleur conversionCouleur(int n);

    // afficher le pad
    void dessiner();

    // quelles portes et couleurs sont présentes
    int quellePorte();
    void quellesCouleurs(int nbP);

    // on associe chaque porte à une couleur
    void associerCouleurs(int nbP);

    void ajouterAuGraphe();
    graphe getGraphe();

    PadPlateau sauver();
    // fonction de pile ou face
    std::default_random_engine m_random ;
    std::bernoulli_distribution m_piece ;
    bool pile_ou_face() ;

};

#endif // TUILE_H
