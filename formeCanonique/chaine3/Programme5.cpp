#include <iostream>

#include "EV.hpp"//seulement

using namespace enseirb;//simplicitee

void affiche(const Chaine &s){
  //std::cout << "AFFICHE <";
  std::cout << '<';
  for(unsigned int i = 0; i < s.taille(); i++)
    std::cout << s[i];
  std::cout << ">" << std::endl;
}

int main(){
  /*Enseignant g("Georgy", 10);
    Etudiant z(Chaine("Georgy"),Chaine("info"), Chaine("c++"));*/
  
  EV ev1(Chaine("Georgy"),10,Chaine("info"),Chaine("c++"));
  affiche(ev1.nom());//aucune erreur mémoire.
  //le const à gérer..//!!!
  return 0;
}
