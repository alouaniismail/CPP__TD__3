#include<iostream>

#include "Etudiant.hpp"
#include "Chaine.hpp"

using namespace std;

using enseirb::Chaine;
using enseirb::Personne;
using enseirb::Etudiant;

//using Chaine::operator<<;(non sémantiquement cela vas pas)
//comme cela enseirb est radicalisé de l'enchainement classé² seulement dans ici.


void affiche(const Chaine& s){//fonction annexe essentielle.
  std::cout << "AFFICHE <";
  for(unsigned int i = 0; i < s.taille(); i++)
    std::cout << s[i];//car implicitement ça l'est via les opérateurs
  //le réglement nous aide en fait à mieux voir en GROS!!
  std::cout << ">" << std::endl;
}



void afficheNom(Etudiant& p){//question de polymorphisme ici se pose
  //une Personne& p pourrait etre passe en paramètre
  //mais on prefere Etudiant& en cas d'une modification interne
  //de fct.²(()) && des allocations dynamiques d'instances..
  affiche(p.nom());
}

void afficheNom2(Etudiant& p){
  std::cout<<p.nom()<<std::endl;
}


/*void afficher_2(const Chaine& s){
  std::cout<<s<<std::endl;
}
*/



int main(){
  Etudiant etudiant1{Chaine("eleve1"),Chaine("info"),Chaine("2a")};
  afficheNom(etudiant1);
  //cela affiche bien, aucune erreur de valgrind(double free dans le constructeur non).
  //afficheNom prend une Personne& (les allocations internes) par de copie
  //mais seulement une référence comme un pointeur banale.
  //qui va prend en argument une Chaine (même @ aucun souci(())).
  //et l'afficher par passage de reference en affiche.
  //en fait c'est pour cela en ultime les accesseurs ne sont pas en Chaine&
  //en ce qui concerne CETTE CLASSE ET L'AUTRE(non héritage)
  //afficheNom2(etudiant1);(non)
  //affiche2(etudiant1.filiere());
  afficheNom2(etudiant1);
  //on a peu triché vu le contexte de bête où on s'est mit.
  //on passe un Etudiant& et on affiche avec std::cout son p.nom()
  //retourne à faire ce que afficheNom mais la différence réside
  //dans le fait qu'ici on peut faire etudiant1.nom2() sans avoir d'erreurs.
  //et le but d'affichage résolu ; 2 coups voire 3 avec affiche_2 de Programme.cpp qui résoud ce conflit.(pas d'héritage multiple ici c'est pour cela, la Chaine marche mais partiellement)
  const Chaine& rslt56=etudiant1.nom2();
  //sans problemes de unvalid or incondionnal jump on un.. values...
  //et sans se preoccuper des delete.
  //et l'affichage depuis la recuperation avec Chaine.cpp et Programme.cpp
  //bien.
  //si on inverse les roles vu que dans ./prog ca marche a100%:cela
  //marcherait.
  return 0;
}
