#include<cstring>

#include "Chaine.hpp"

#include <memory>


namespace enseirb {

  static char* copie(const char* src, unsigned int taille) {
    char *tmp = new char[taille + 1];
    std::strcpy(tmp, src);
    return tmp;
  } 

  Chaine::Chaine():_taille(0) {
    _donnees    = copie("",0);
  }

  Chaine::Chaine(const char *s) {
    // Cas s==NULL a gerer plus tard.
    _taille = strlen(s);
    _donnees = copie(s, _taille);
  }

  Chaine::~Chaine() {
    delete[] _donnees;
    _donnees=NULL;
  }


  Chaine::Chaine(const Chaine &c):_taille(c._taille){
    _donnees = copie(c._donnees, c._taille);
  }

  const Chaine &Chaine::operator=(const Chaine &c){
    if (this == &c) 
      return *this;

    delete [] _donnees;
    _taille = c._taille;
    _donnees = copie(c._donnees, c._taille);
    return *this;
  }

  unsigned int Chaine::taille() const {
    return _taille;
  }

  char Chaine::operator[](unsigned int i) const{
    if (i>_taille) 
      return '\0';
    return _donnees[i];
  }

  Chaine Chaine::operator+(const Chaine &c) const {
    int tailleTmp = _taille + c._taille;
    
    if (this==&c) return *this;

    if (0 == tailleTmp)
      return *this;
  
    char *donneesTmp = new char[tailleTmp + 1];
    std::unique_ptr<char []> autoDelete(donneesTmp);

    if (_taille != 0)
      std::strcpy(donneesTmp, _donnees);

    if (c._taille !=0)
      std::strcpy(donneesTmp + _taille, c._donnees);
  
    return Chaine(donneesTmp);
  }
}
