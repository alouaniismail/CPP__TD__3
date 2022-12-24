#ifndef CHAINE_HPP
#define CHAINE_HPP

#include<iostream>
using namespace std;

namespace enseirb {

  class Chaine {
  private:
    char* _donnees;
    unsigned int _taille;

  public:
    Chaine();
    Chaine(const char*);
    Chaine(const Chaine &);
    ~Chaine();
    const Chaine &operator=(const Chaine &);

    unsigned int taille() const ;
    char operator[](unsigned int i) const;
    Chaine operator+(const Chaine &) const;
    friend ostream& operator<<(ostream& os, const Chaine& c);//(apres..)non!!
    //toujours de cette facon:
    //friend ostream& operator<<(ostream& os, const Chaine& c).
    //et là on a le concept de const Chaine& qui se degage avec
    //le friend et l'ostream& et l'operator<< et l'ostream& os et voilà.
  };
}

//static OK.
//namespace && using namespace OK.
//on a un constructeur, un destructeur, un constructeur par recopie
//et par affectation, aucun problème là-dessus(destination surtout
//les allocations dynamique de enseirb::Chaine).voilà.On vérifie c'est tout.
//on appelle cela la forme canonique. 
#endif
