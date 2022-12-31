#include <iostream>

#include "Chaine.hpp"

Chaine annexe(Chaine u, Chaine t) {
  return u + t;
}

void affiche(const Chaine &s){
  std::cout << "AFFICHE <";
  for(unsigned int i = 0; i < s.taille(); i++)
    std::cout << s[i];
  std::cout << ">" << std::endl;
}

int main(){
  Chaine s("un texte long");
  Chaine p("test");
  
  Chaine r(annexe(s, p));
  affiche(r);

  Chaine q = s;
  std::cout << "q: " << q << std::endl;

  q = p;
  affiche(q);

  std::cout << "s: " << s << std::endl;
}
