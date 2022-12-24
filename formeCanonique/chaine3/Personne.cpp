#include<iostream>

#include "Personne.hpp"
#include "Chaine.hpp"

#include <memory>


namespace enseirb {//re-déclaration comme d'hab.
  //là les fonctions d'une façon ordinaire.
  Personne::Personne(const Chaine& c){
    _nom=c;//opérateur d'affectation(forme canonique).
    //de même avec une Chaine constante.(appel aux modifs. linkage
    //enseirb::Personne et non pas Chaine.(c'est pour cela)
  }
  Chaine Personne::nom(){//accesseur classique.
    return _nom;//comme cela on ne crée pas une autre instance
    //double free evitement(Chaine& retour)*
  }
}
