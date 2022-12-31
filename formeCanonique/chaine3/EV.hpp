#ifndef __EV__
#define __EV__

#include "Enseignant.hpp"
#include "Etudiant.hpp"

namespace enseirb{
  class EV: public Enseignant, public Etudiant{
  private:
  public:
    //on rappelle..
    //on passe des références tjrs (accesseurs retour non..)
    EV(const Chaine& nom, int service, const Chaine& filiere, const Chaine& enseignement);

    //re-définition:
    virtual Chaine nom();
    //à cause d'un simple const il peut râler INDEFINIMENT
    //voir tjrs la signature des autres.

    
  };//point de virgule
}//ici-non.

#endif //__EV__
