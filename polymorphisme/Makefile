virtual: Exemple_td1.cpp
	g++ $< -o $@
exec1: virtual
	./$^
memcheck1:
	valgrind ./virtual
clean:
	rm -f a.out virtual Makefile~ *.txt~ *.gch *.hpp~ *.cpp~
