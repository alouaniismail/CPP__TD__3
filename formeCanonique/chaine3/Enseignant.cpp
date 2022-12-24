
#include "Enseignant.hpp"
#include "Chaine.hpp"

namespace enseirb {

  static Chaine enseignant("Enseignant: ");

  Enseignant::Enseignant(const Chaine& nom, int nbHeures) : 
    //  Personne(enseignant + nom)
    Personne(nom), _nbHeures(nbHeures) {
  }

  int Enseignant::nbHeures() const {
    return _nbHeures;
  }

  Chaine Enseignant::nom(){
    return Chaine("Enseignant: ") + Personne::nom();//héritage de personne.
  }
}
