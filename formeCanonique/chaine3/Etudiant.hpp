#ifndef __ETUDIANT__HPP
#define __ETUDIANT__HPP

#include "Personne.hpp"
#include "Chaine.hpp"//et aussi(voir la remarque ci-dessus)
//using namespace enseirb;ici on déclare
//ça se retrouverait dans namespace donc namespace enseirb puis ajout
//de la classe Etudiant.

//#include "Chaine.hpp" //la source..(deja fait etudiant.hpp avec ces deux-là dans etudiant.cpp.).//////////.///

#include<iostream>
using namespace std;//ca empeche pas d'avoir std::??.

namespace enseirb{//on doit redéfinir la variable nom()=>Personne doit acceuillir
  //des virtuelles à partir de now.
  
  class Etudiant : public Personne{
  private:
    Chaine _filiere;
    Chaine _enseignement;
  public:
    //et le constructeur??
    //d'abord analysons le constructeur de Personne qui prend
    //un const Chaine&
    //et c'est tout.()<=>{} dans la déclaration non assistance direct(construct.)
    //retournons à l'analyse: Un etudiant va hériter de Personne donc il va avoir un attribut private _nom à initialiser aussi si on veut faire les choses bien. d'où le constructeur suivant:
    //rappel rapide mais important: si on veut pas faire using Personne::Personne() on doit specifier des le debut du constructeur de la classe qui hérite l'initialisation comment ca se fera avec Personne(const Char& n) par exemple.En general l'attribution reste limitee dans le constructeur aux attributs privés de la classe héritante.
    
    Etudiant(const Chaine& n, const Chaine& f, const Chaine& e);
    //ne pas oublier les {}!!!!

    
    Chaine filiere() const;//pour les mêmes raisons que précédemment.
    Chaine enseignement() const;//pour les mêmes raisons que précédémment.
    //les 2 const pour bien programmer.
    //des setters en plus...///
    //pour des accesseurs en lien a-un pas de reference retournee(astuce).
    void setEnseignement(const Chaine&);
    virtual Chaine nom();//le nom précédé de la mention: "Elève".
    //et les setters passage par référence car nouveau objet indépendant avant et crée avant(donc non soumis à contrôle vis-à-vis de la classe dans notre démarche de tests(testing.//)).
    //const Chaine& nom2();
    //const Chaine& nom2();
    const Chaine& nom2();//on a réussi à le traiter comme virtual
    //et bien oui! c'est permit.
  };
}







#endif
