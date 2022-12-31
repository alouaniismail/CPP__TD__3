CC=g++
CPPFLAGS=-Wall -Wextra

SmartExample: SmartExample.o SmartPointer.o
	$(CC) $^ -o $@

SmartExample.o: SmartPointer.hpp 

SmartPointer.o: SmartPointer.hpp 

clean: 
	rm -f *.o SmartExample