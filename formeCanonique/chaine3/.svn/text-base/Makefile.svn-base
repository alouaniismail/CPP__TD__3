CC=g++
CPPFLAGS=-Wall -Wextra -std=c++0x

prog: Chaine.o Programme.o 
	$(CC) $^ -o $@

Programme.o: Chaine.hpp

Chaine.o: Chaine.hpp

clean:
	rm -f *.o prog