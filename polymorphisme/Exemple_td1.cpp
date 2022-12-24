#include<cstdio>


class Mere {//constructeur par defaut pour les 2.
public:
   virtual ~Mere(){
    printf("destructeur appelé\n");
  }
  void message(){//classe virtuelle implémentable par la classe
    //qui hérite par pûre(=0).
    //destinée à être redéfinie dans les classes héritantes.
    printf("je suis la classe Mere\n");
  }
};


class Fille : public Mere {//syntaxe héritage.
public:
   virtual ~Fille(){
    printf("appel au destructeur(2).\n");
  }
   void message(){//reste à part sans le virtual de Mere pas comme le cas
    //numero 2.(et mere passe a 1 en sizeof qui est un pointeur seulement)
    printf("je suis la classe Fille\n");
  }//2ieme cas d'allocation automatique même que le 2ieme du precedent cas
  //general.
};

class C{};


//on a un pointeur de type Mere qui s'associe à un pointeur de type
//fille en allocation automatique=>l'appel de mere->message entrainera
//l'appel a la methode fille en adressage.

//si on enleve virtual de fille ce marche aussi(**** dans resume.txt)
//si on enleve virtual de mere cela enleve le caractere
//de redefition polymorphe classique
//la classe fille va faire ce qu'elle a faire
//mais la mere ne vas pas faire de saut vu le virtual pas dans la signature
//d'où les affichages comme on a vu.


/*
int main(){
  //si on enlève devant la Fille uniquement, cela voudrait dire:
  //qu'il y a redéfinition comme avant mais sans le mot clef de redéfinition
  //pour les prochaines(@override).(classement de point de vue sur ce concept
  //de signature );(regarder les sizeof(s)).
  
  Fille *fille= new Fille;
  //uniquement devant la fille veut dire que la mère ne permet de polymorphisme
  //sur cette méthode d'où le 2ieme appel correspond à: je suis la classe Mère.
  //(virtual qui  autorisent les polymorphismes)
  //les classes héritantes de Fille peuvent surcharger cette méthode aussi.
  

  
  fille->message();//affichage je suis la classe Fille.

  Mere *mere=fille;
  mere->message();//là on manipule via des pointeurs références
  //uniquement.
  //l'héritage est public voir une mère comme une fille est l'inverse
  //est possible.
  //ainsi on l'a affecté à fille donc le type est ''casté''
  //puis on a recopie traditionnelle d'où affichage du même message précédent.
  

  printf("Mere: %ld\n",sizeof(Mere));//ca alourdit ca passe de 1 à 4 à 8 directement à 8(prédéfinition incluse) pour une classe en soit. 
  printf("Fille: %ld\n",sizeof(Fille));

  printf("C:%ld\n",sizeof(C));
  delete mere;
  }

*/

/*
int main(){
  Fille fille;
  fille.message();//je suis la classe fille.
  Mere mere=fille;//pas de pointeurs=>pas d'@ ultimes.
  //la classe est virtuelle il doit choisir
  //elle est declaree en mere, c'est la Mere::message() qui gagne(polymorphisme
  //publique)
  //avant c'était la fille car les @ signifient dans le saut vers le tas
  //d'ou Fille::message().
  mere.message();


  //pas de delete.
  //on enleve le virtual de mere la classe Fille affiche normalement
  //et la classe mere (Mere mere=fille possible(public heritage))
  //affiche je suis la classe Mere il n'y plus d'appel a la résolution surcharge
  //au niveau type Mere qui ne declare pas de virtual en allocation automatique
  //en plus()=>d'où l'affichage qu'on a vu.
  }
*/

/*
int main(){
Mere *mere=NULL;
//en virtual vu NULL comme un pointeur d'affectation polymorphe en valeur
//ca va sauter dans le tas -> segmentation fault dans les 2 derniers cas.

//si on enleve le virtual l'adresse de mere->message() existe et ne vas faire
//de saut en méthode de sous-classe à cause de virtual d'où terminaison de
//valgrind sans erreurs.(tous types confondus)
mere->message();(on a pas alloué de ressources pas redéfinit le destructeur ça va alors pour le Heap Summary.(pas de new surTOUT) mais le comportement de saut reste pareil vu l'empilement des adresses de fcts pointantes vers la pile avec virtual.)
}
*/

/*int main(){
  return 0;
  }*/

//des tests de l'exo2 pour en finir avec ce foutu polymorphisme.

int main (){
  Fille * f = new Fille ();//allocation dynamique
  Mere & m =* f ;
  //allocation automatique par recopie (un nouvel(@###) élément)
  //3 en total (l'adrese du tas ou se trouve *f dans une adresse de la pile;
  //classique).
  //en tout un appel direct à un constructeur.(instanciations)
  
  //la reference se comporte comme une étiquette soit un alias soit indirectement
  //un pointeur avec f en allocation dynamique, l'algo de résolution se penche vers la fonction générée dans le tas soit Fille::message().
  m . message ();
  //la reference même si elle s'utilise comme une valeur entierement direct primitive"" , elle se voit comme une étiquette vers l'objet d'origine(un warning plûtot ayraît été ajouté dans ce cas).
  delete &m;//appel au destructeur pour libérer les bonnes ressources
  //de la seule vraie instance (par héritage, on s'en moque vue la remarque précédente). delete &m reference une adresse de Mere donc appel au destructeur de la //mere(pas de virtual), cela revient au même(memcheck1), l'un entraîne l'autre.
  //l'ajout permet de respecter cela, d'élargir nos utilisations, (td2 format/td1 aussi) via des destructeurs virtuelles devenues necessaires. (car là cela semble à une @uniquement, on pas une batterie de tests quand meme..)
  
  //libération de f,m dans la pile automatique.
  //delete &m entraine un appel au destructeur bien sûr, on enlève tous les
  //virtual, cela nous ramène à appel au (1er sous-cas) via affichage de: ->
  //je suis la classe Mere.

  //Mais au niveau de la libération(valgrind ne râle surtout pas(héritage)) mais on doit vérifier le bon ordre pour tracer sans gdb (demande) l'execution et tirer de bonnes regles(pratiques) de programmation c++.

  //en delete f appel a destructeur(2) puis le 1. c'est correct.
  //mais qu'en est pour &m? sachant que &m est un pointeur non pas une référence
  //écrite maladroitement ici. Il y a un héritage bon sens! donc appel vis-à-vis du destructeur de la fille avant d'en finir avec la mere d'ou le scenario observe.



  //regle a apprendre plutot:
  //tjrs mettre le destructeur en virtuel dans les classes dérivables(notamment pour du debug(sert a qlq chose de fort dans les allocations dynamique et l'utilisation par recopie via des pointeurs/references.))
}
