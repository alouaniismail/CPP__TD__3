CC=g++
CPPFLAGS=-Wall -Wextra

SmartExample: SmartExample.o SmartPointer.o
	$(CC) $^ -o $@

SmartExample.o: SmartPointer.hpp 

SmartPointer.o: SmartPointer.hpp 

clean: 
	rm -f *.o SmartExample *.cpp~ *.hpp~ exec_final Makefile~

exec_final: SmartPointer.cpp Chaine.cpp Programme.cpp
	g++ -o $@ $^
exec: exec_final
	./$<
memcheck: exec_final
	valgrind ./$<
