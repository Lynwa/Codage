# TP1-A Code d'Etalement

all: emetteur.o recepteur.o canal.o  main.c
	gcc emetteur.o recepteur.o canal.o main.c -o programme
	gcc hadamard.c -o test_hadamard

emetteur.o: emetteur.c commun.h
	gcc -c emetteur.c commun.h

recepteur.o: recepteur.c commun.h
	gcc -c recepteur.c commun.h

canal.o: canal.c commun.h
	gcc -c canal.c commun.h

clean:
	rm *.o programme test_hadamard commun.h.gch
