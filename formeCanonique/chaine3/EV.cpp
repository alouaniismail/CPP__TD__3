
#include"EV.hpp"

namespace enseirb{
  EV::EV(const Chaine& nom, int service, const Chaine& filiere, const Chaine& enseignement):Enseignant(nom,service),Etudiant(nom,filiere,enseignement){}
  //comme la fin d'une définition d'une fonction(pas de point de virgule).


  Chaine EV::nom(){
    return Enseignant::nom()+Chaine(" ")+Etudiant::nom();
  }

}
  
