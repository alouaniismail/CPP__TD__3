#include<iostream>
#include<cstring>

#include <memory>

#include "Chaine.hpp"

static char* copie(const char* src, unsigned int taille){
  char* tmp=new char[taille+1];
  std::strcpy(tmp,src);
  return tmp;
}

static enseirb::SmartPointer vide(copie("",0));

Chaine::Chaine(): _taille(0),_donnees(vide){}

Chaine::Chaine(const char* s): Chaine(){
  if(s==nullptr)
    return;
  _taille=std::strlen(s);
  _donnees=enseirb::SmartPointer(copie(s,_taille));
}

unsigned int Chaine::taille() const{
  return _taille;
}

char Chaine::operator[](unsigned int i) const{
  if(i>_taille)
    return '\0';
  return _donnees.get()[i];
  //ou
  //return _donnees[i];//_donnees.operator const char*()[i].
}

std::ostream &operator<<(std::ostream &stream, const Chaine &s){
  return stream<<s._donnees.get();
}

Chaine Chaine::operator+(const Chaine& c)const{
  int tailleTmp=_taille+c._taille;
  if(0==tailleTmp)
    return *this;//le smartPointer gere les failles ici...
  //il faut retourner une Chaine!!!

  std::unique_ptr<char[]> autoDelete(new char[tailleTmp+1]);
  if(_taille!=0)
    std::strcpy(autoDelete.get(),_donnees);
  if(c._taille!=0)
    std::strcpy(autoDelete.get()+_taille,c._donnees.get());
  return Chaine(autoDelete.get());//voilà, tout est bon jusqu'à là.
  //on fait le retour demandé.
  //à ce stade, le td est considéré fini.(comme pour la prog. système)

  //on fera une extension prochainement, notamment sur les shared--ptr
  //(pointeurs malins) ainsi que le type prochainement pour les templates
  //<vector>.
}


/*
Chaine::operator char const *(void) const { //in chaine4
  return _donnees; //appel operateur conversion 
}
*/
