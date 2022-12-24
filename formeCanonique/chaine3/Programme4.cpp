#include <iostream>

#include "Personne.hpp"
#include "Etudiant.hpp"
#include "Enseignant.hpp"

using namespace enseirb;

void affiche(const Chaine &s){
  //std::cout << "AFFICHE <";
  std::cout << '<';
  for(unsigned int i = 0; i < s.taille(); i++)
    std::cout << s[i];
  std::cout << ">" << std::endl;
}

int main() {
  Personne un("Moi");//transfert(conversion implicite aussi direct.)
  affiche(un.nom());

  Personne deux = un;//héritage direct.OK.
  affiche(deux.nom());

  deux = Personne("Trois");//jouer sur les syntaxes pour déranger valgrind.
  affiche(deux.nom());

  Etudiant z(Chaine("un"),Chaine("zorglub"), Chaine("info2"));
  //Etudiant de Personne transfert non ok cette fois-ci (attention a ce piege)
  //c'est ca la logique du c++.
  z.setEnseignement("poo, C++");
  affiche(z.nom());

  Enseignant g("Georgy", 10);
  affiche(g.nom());

  affiche(z.Personne::nom());//appeler la méthode non pas de z elle meme
  //=>implique un seulement.
  affiche(g.Personne::nom());//et Georgy seulement ici.
  //pas d'erreurs apparentes de valgrind, on verifie, tout est OK.
}
