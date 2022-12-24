#include<iostream>
#include "Personne.hpp"
#include "Etudiant.hpp"
#include "Chaine.hpp"

namespace enseirb{
  Etudiant::Etudiant(const Chaine& n, const Chaine &f, const Chaine &e):Personne(n),_filiere(f),_enseignement(e){};//!!!!
  //Personne(n) tout au début !!//\\!!.On est libre face à l'héritée.

  Chaine Etudiant::filiere() const{
    return _filiere;
  }

  Chaine Etudiant::enseignement() const{
    return _enseignement;
  }
  //les 2 getters sans valeur de retour en reference.
  //les setters par contre(mais const) prennenet des types:
  //const Chaine&.

  void Etudiant::setEnseignement(const Chaine &c){
    _enseignement=c;//l'opérateur d'affectation(tout est bon).
  }//il fait de suppression de c alerte const=>const and passage par reference.
  //(vais-je modifier l'objet?()).
  //voilà, tout est dit.

  //accesseur particulier en fait.
  Chaine Etudiant::nom(){
    return Chaine("Eleve: ")+Personne::nom();//en allocation automatique
    //aucun problème.
  }

  /*const Chaine& Etudiant::nom2(){
    Chaine* rslt=new Chaine(Chaine("Eleve: ")+Personne::nom());
    /* Chaine& ref=*rslt;
       return ref;*/ //je crois qu'on va garder la deuxieme.
    //return *rslt;//non, c'est redondant ceci tout..
    //une référence constante c'est difficile quasi equivalent à un pointeur
    //non 'statique'.
    //return *rslt;
  //}

  const Chaine& Etudiant::nom2(){
    Chaine rslt(Chaine("Eleve ")+Personne::nom());
    Chaine& ref=rslt;
    return ref;
  }
}

    
  //pas de point de virgule (seulement dans le .hpp, on avance là.).
  //opérateur de concaténation retournant une nouvelle chaine
  //avec passage de deux allocations automatiques(la fonction fait en sorte
  //que Personne::nom() soit  de type const Chaine&).

  //le retour en soit n'est pas un pointeur, on laisse largement les règles des accesseurs s'évissent ici.
				 
