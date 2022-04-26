#include "draw.hpp"
#include "tuile.hpp"
#include "graphe.hpp"
#include "plateauetjeu.hpp"

#include <iostream>

using namespace MMaze ;

int main() {


/*

#ifndef NO_CAIRO
  pad.dessiner("/tmp/plateau.svg") ;
  pad.dessiner("/tmp/plateau.png") ;
#endif

  std::cout << pad << std::endl ;

  pad.save("/tmp/pad.json") ;

  PadPlateau cpy ;
  cpy.load("/tmp/pad.json") ;
  std::cout << cpy << std::endl ;
*/



   // Décommentez cette partie pour avoir un affichage de tuiles une par une, comme si on mimait une partie.

  std::vector<graphe>tabgraphe;

  tuile T(24);

  tabgraphe.push_back(T.getGraphe());
  T.raffraichirGraphe();

  T.tuileSuivante(0, 1);
  tabgraphe.push_back(T.getGraphe());
  T.raffraichirGraphe();

  T.tuileSuivante(0,2);
  tabgraphe.push_back(T.getGraphe());
  T.raffraichirGraphe();

  T.tuileSuivante(1, 0);
  tabgraphe.push_back(T.getGraphe());
  T.raffraichirGraphe();

  T.tuileSuivante(-1, 0);
  tabgraphe.push_back(T.getGraphe());
  T.raffraichirGraphe();

  T.tuileSuivante(0,-1);
  tabgraphe.push_back(T.getGraphe());
  T.raffraichirGraphe();

  T.tuileSuivante(1, 2);
  tabgraphe.push_back(T.getGraphe());
  T.raffraichirGraphe();

  T.tuileSuivante(-1, 1);
  tabgraphe.push_back(T.getGraphe());
  T.raffraichirGraphe();



  T.tuileSuivante(1, 1);
  tabgraphe.push_back(T.getGraphe());
  T.raffraichirGraphe();

  plateauEtJeu plateau(tabgraphe);

  plateau.plateau.save("/tmp/jeu.json");
  plateau.plateau.load("/tmp/jeu.json");
  std::cout << plateau.plateau << std:: endl;

  plateau.ouvrirPorteGauche(0, 0);
  plateau.plateau.save("/tmp/jeu.json");
  plateau.plateau.load("/tmp/jeu.json");
  std::cout << plateau.plateau << std:: endl;

  plateau.ouvrirPorteHaute(0, 0);
  plateau.plateau.save("/tmp/jeu.json");
  plateau.plateau.load("/tmp/jeu.json");
  std::cout << plateau.plateau << std:: endl;

  plateau.ouvrirPorteDroite(0, 0);
  plateau.plateau.save("/tmp/jeu.json");
  plateau.plateau.load("/tmp/jeu.json");
  std::cout << plateau.plateau << std:: endl;

  plateau.ouvrirPorteBas(0, 0);
  plateau.plateau.save("/tmp/jeu.json");
  plateau.plateau.load("/tmp/jeu.json");
  std::cout << plateau.plateau << std:: endl;

  plateau.ouvrirPorteDroite(-1, 0);
  plateau.plateau.save("/tmp/jeu.json");
  plateau.plateau.load("/tmp/jeu.json");
  std::cout << plateau.plateau << std:: endl;

  plateau.ouvrirPorteDroite(0, 1);
  plateau.plateau.save("/tmp/jeu.json");
  plateau.plateau.load("/tmp/jeu.json");
  std::cout << plateau.plateau << std:: endl;

  plateau.ouvrirPorteBas(0, 1);
  plateau.plateau.save("/tmp/jeu.json");
  plateau.plateau.load("/tmp/jeu.json");
  std::cout << plateau.plateau << std:: endl;

  plateau.ouvrirPorteBas(0, 2);
  plateau.plateau.save("/tmp/jeu.json");
  plateau.plateau.load("/tmp/jeu.json");
  std::cout << plateau.plateau << std:: endl;

  T.dessiner();

  // On utilise ici les fonctions json, pour sauvegarder le plateau.
  PadPlateau cpy = T.sauver();
  cpy.save("/tmp/T.json") ;

  cpy.load("/tmp/T.json") ;
  std::cout << cpy;



// Decommenter cette partie pour obtenir un plateau de taille 7*7. Possibilité de changer la taille du plateau.
// Ici, on ne stocke que l'affichage. decommenter les lignes sous T.tuileSuivante(i, j) pour stocker les données.

/*
  std::vector<graphe>tabgraphe;

  tuile T(24);
    for (int i = -3;i < 4; i++){
        for (int j = -3; j < 4; j++){
            if (!((i ==0)&&(j==0))){
              T.tuileSuivante(i, j);
              // tabgraphe.push_back(T.getGraphe());
              // T.raffraichirGraphe();
        }
        }
    }
    T.dessiner();
*/
  return 0 ;
}
