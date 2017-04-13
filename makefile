a.out: main.o compte.o pile.o SP.o paire.o arbre.o
	gcc -Wall main.o compte.o pile.o SP.o paire.o arbre.o

main.o: main.c compte.h
	gcc -Wall -c main.c

compte.o: compte.c compte.h pile.h SP.h definition.h
	gcc -Wall -c compte.c

pile.o: pile.c pile.h SP.h definition.h
	gcc -Wall -c pile.c

SP.o: SP.c SP.h paire.h definition.h
	gcc -Wall -c SP.c

paire.o: paire.c paire.h arbre.h definition.h
	gcc -Wall -c paire.c

arbre.o: arbre.c arbre.h definition.h
	gcc -Wall -c arbre.c
