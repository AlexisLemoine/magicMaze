#include "draw.hpp"
#include "tuile.hpp"
#include "graphe.hpp"
#include "plateauetjeu.hpp"

#include <iostream>

using namespace MMaze ;

int main() {
  //PadPlateau pad ;
/*
  pad.ajouter_tuile(0,0) ;
  pad.ajouter_boutique(0,0,Case(0)) ;
  pad.ajouter_sortie(0,0, Case(15), Couleur::JAUNE) ;
  pad.ajouter_mur(0,0,Mur(Case(0), Case(1))) ;
  pad.ajouter_mur(0,0,Mur(Case(0), Case(4))) ;
  pad.ajouter_porte(0,0, Case(11), Couleur::JAUNE) ;

  pad.ajouter_tuile(0,1) ;
  pad.ajouter_sortie(0,1, Case(0), Couleur::VIOLET) ;
  pad.ajouter_porte(0,1, Case(4), Couleur::AUCUNE) ;
  pad.ajouter_porte(0,1, Case(11), Couleur::VIOLET) ;
  pad.ajouter_porte(0,1, Case(13), Couleur::VERT) ;
  pad.ajouter_mur(0,1, Mur(Case(4), Case(5))) ;
  pad.ajouter_mur(0,1, Mur(Case(4), Case(8))) ;

  pad.ajouter_tuile(1,0) ;
  pad.ajouter_porte(1,0,Case(11), Couleur::AUCUNE) ;
  pad.ajouter_vortex(1,0,Case(6), Couleur::JAUNE) ;

  pad.ajouter_tuile(1,1) ;
  pad.ajouter_porte(1,1,Case(2), Couleur::AUCUNE) ;
  pad.ajouter_porte(1,1,Case(4), Couleur::JAUNE) ;

  pad.placer_joueur(0,0,Case(5),Couleur::JAUNE) ;
  pad.placer_joueur(0,0,Case(6),Couleur::VERT) ;
  pad.placer_joueur(0,0,Case(9),Couleur::VIOLET) ;
  pad.placer_joueur(0,0,Case(10),Couleur::ORANGE) ;



#ifndef NO_CAIRO
  pad.dessiner("/tmp/plateau.svg") ;
  pad.dessiner("/tmp/plateau.png") ;
#endif

  std::cout << pad << std::endl ;

  pad.save("/tmp/pad.json") ;

  PadPlateau cpy ;
  cpy.load("/tmp/pad.json") ;
  std::cout << cpy << std::endl ;

  // tests ds tuiles

  tuile T1;
  tuile T2;
  tuile T3;
  tuile T4;
  tuile T5;
  
  tuile T6;
  tuile T7;
  tuile T8;
  tuile T9; 
  tuile T10; 
*/

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

  T.tuileSuivante(-1, 1);
  tabgraphe.push_back(T.getGraphe());
  T.raffraichirGraphe();

  

/*
  for (int i = -2;i < 3; i++){
      for (int j = -2; j < 3; j++){
          if (!((i ==0)&&(j==0))){
            T.tuileSuivante(i, j);
            //tabgraphe.push_back(T.getGraphe());
      }
      }
  }
  */
/*
  plateauEtJeu plateau(tabgraphe);

  plateau.plateau.save("/tmp/jeu.json");
  plateau.plateau.load("/tmp/jeu.json");
  std::cout << plateau.plateau << std:: endl;

  plateau.ouvrirPorteGauche(0, 0);
  plateau.plateau.save("/tmp/jeu.json");
  plateau.plateau.load("/tmp/jeu.json");
  std::cout << plateau.plateau << std:: endl;
*/
  T.dessiner();


/*
  PadPlateau cpy = T.sauver();
  cpy.save("/tmp/T.json") ;

  cpy.load("/tmp/T.json") ;
  std::cout << cpy; */
  return 0 ;
}
