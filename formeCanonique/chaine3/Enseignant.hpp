#ifndef ENSEIGNANT_HPP
#define ENSEIGNANT_HPP

#include "Personne.hpp"

namespace enseirb {

  class Enseignant : public Personne {
  private:
    int _nbHeures;

  public:
    Enseignant(const Chaine& nom, int nbHeures);

    int nbHeures() const;

    virtual Chaine nom();//il suffit d'enlever le const pour faire la levee
    //histoire de réfléchir sur la bottée de l'exo4.
    //const peut rester apres(c'est la (de pareils situations) d'ou vient le secret, l'ambiguete avec du n'importe quoi du C++.(compilateur à faire évoluer selon NOS DEMANDES||||.
  };
}
#endif
