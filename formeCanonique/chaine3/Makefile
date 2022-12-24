CC=g++
CPPFLAGS=-Wall -Wextra -std=c++0x

prog: Chaine.o Programme.o 
	$(CC) $^ -o $@

Programme.o: Chaine.hpp

Chaine.o: Chaine.hpp

clean:
	rm -f *.o prog *.hpp~ *.cpp~ Makefile~ a.out prog_exec2 prog_exec3 prog_exec4

prog_exec2: Programme2.cpp Personne.cpp Chaine.cpp
	g++ $^ -o $@
	./$@

memcheck2:
	valgrind ./prog_exec2

prog_exec3: Etudiant.cpp Personne.cpp Chaine.cpp Programme3.cpp
	g++ $^ -o $@
	./$@

memcheck3:
	valgrind ./prog_exec3
prog_exec4: Programme4.cpp Chaine.cpp Personne.cpp Enseignant.cpp Etudiant.cpp
	g++ $^ -o $@
	./$@
memcheck4:
	valgrind ./prog_exec4
