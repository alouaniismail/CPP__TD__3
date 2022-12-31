#include"SmartPointer.hpp"

#include<cstdio>
#include<cstring>

void f(const char *p){
  std::printf("%s\n",p);
}

int main(){
  using enseirb::SmartPointer;
  SmartPointer p(new char[10]);

  std::strcpy(p, "coucou");
  
  std::printf("conversion %s\n", (const char *) p);
  std::printf("conversion %c\n", ((const char*) p)[1]);

  std::printf("get %s\n", p.get());

  std::printf("operateur* %c\n", *p);
  
  std::strcpy(p.get(), "BYE");

  SmartPointer q(p);
  f(q);

  std::printf("(operator->())[2] %c\n", (q.operator->())[2]);
  std::printf("operator->() %s\n", q.operator->());

  SmartPointer r(new char[7]);
  std::strcpy(r.get(), "encore");
  q = r;

  //q = "moi"; // probleme

  const SmartPointer s(r);
  f(s);
}
