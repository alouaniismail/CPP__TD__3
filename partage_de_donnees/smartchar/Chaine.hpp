#ifndef CHAINE_HPP
#define CHAINE_HPP

#include <iostream>

#include "SmartPointer.hpp"

class Chaine {
 private:
  unsigned int _taille;
  enseirb::SmartPointer _donnees;//demandee (instruction)
  //dans l'exo7.
  
  //pas de using namespace enseirb.
  //on implemente pas dedans ; c'est logique de l'ignorer.

 public:
  Chaine();//constructeur par défaut
  Chaine(const char*);//constructeur à partir d'un char* comme d'hab.//

  unsigned int taille() const ;//getter_1.
  
  char operator[](unsigned int i) const;//opérateur [].
  Chaine operator+(const Chaine &) const;//opérateur de concaténation(+) renvoyant une nouvelle instance de Chaine soit retour en Chaine.

  friend std::ostream &operator<<(std::ostream &stream, const Chaine &s);
  //friendly function for displaying char's class value .

  //jusqu'à là tout est bon !
  //le destructeur en plus des fonctions qui définissent des références
  //des 2 côtés autre que le constructeur par défaut
  //sont ignored over there.
  
  //operator char const *(void) const; //in Chaine4
};
/* supprimer car pris en charge par SmartPointer
  Chaine(const Chaine& s); //constructeur par copie
  ~Chaine(); //destructeur
  Chaine& operator=(const Chaine&); //affectation
*/
#endif
