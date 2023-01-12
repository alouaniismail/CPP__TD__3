#ifndef __PERSONNE_HPP
#define __PERSONNE_HPP

#include "Chaine.hpp"
//inclure le namespace(direct dans une implémentation classique).
namespace enseirb{
  class Personne{
  private:
    Chaine _nom;
  public:
    Personne(const Chaine &);
    virtual Chaine nom();//potentiellent ré-éecrite(@override pas @overload).
  };
}//sans la virgule ### d'une classe ordinaire ou d'un ss type type structure
//ou tout est publique(extension publique du C).

//celle-ci marque une petite différence de syntaxe au moins.
#endif
