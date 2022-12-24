#include <iostream>

#include "Chaine.hpp"
#include "Personne.hpp"

using enseirb::Chaine;
using enseirb::Personne;

void affiche(const Chaine &s){//fonction annexe essentielle.
  std::cout << "AFFICHE <";
  for(unsigned int i = 0; i < s.taille(); i++)
    std::cout << s[i];
  std::cout << ">" << std::endl;
}



void afficheNom(Personne& p){//il faut les using pour acceder aux classes direct
//question d'hiéarchie en inclusion par le pré-processeur.
  affiche(p.nom());//p.nom() est de type Chaine& pour éviter les double free
//encore(le probleme majeur des 1/2 du C++).

  //même si nom a un prototype: Chaine nom() sa seule utilisation résidera dans
  //son passage à affiche qui prend un Personne& donc pas de recopie exact dans un autre block de _nom et affiche acceuille des const Chaine& ce qu'on respecte ici, donc apparemment pas de problème.
}
  

int main(){
  Personne personne1(Chaine("premiere personne"));
  afficheNom(personne1);
  Personne *personne2=new Personne{Chaine("deuxième personne")};
  //autre syntaxe: le : _nom(Chaine("??")) réservation constructreur
  //moyen mnemotechnique: linkage avec :: dans les déclarations.
  afficheNom(*personne2);
  //personne2 il faut libèrer (free() en C) car c'est dans le tas sa valeur
  //donc : delete personne2(appel au destructeur au passage..///)
  //la construction se fait par référence du coup l'instanciation via Chaine("??") libère la mémoire (comme _data) mais ceci est passé en référence, du coup on a pas une copie en soi qui va déclencher le double free mais le compilateur considère ceci comme une étiquette bavante seulement.
  //new Chaine est un pointeur;déclarons les choses à part(obligeation c++)

  Chaine *c=new Chaine("troisieme personne");
  Personne personne3(*c);//pour éviter le delete
  //classique après(comme pour personne2).
  afficheNom(personne3);//rien de si bon!
  Chaine cc(personne3.nom());//aussi le constructeur de recopie existe
  //c'est pour cela on PAS DE SOUCIS personne3.nom() est de type
  //const Chaine& donc pas de recopie nouvelle Chaine appelee cc c'est tout.

  Chaine* cc2=new Chaine(personne3.nom());//on devine un delete cc2 et c'est bon.
  delete cc2;
  delete personne2;
  delete c;//et voilà, c'est résolu; sans le const(la programmation peut indirectement faire des fautes, on est pas des experts), sans les references on aurait un enorme probleme en C++(notamment pour l'héritage(voir après)).
  return 0;
}
