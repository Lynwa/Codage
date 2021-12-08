# TP2 Générateur Pseudo Aléatoire

all: gold.o lm.o jpl.o commun.o main.c
	gcc gold.o lm.o jpl.o commun.o main.c -o programme

commun.o: commun.c commun.h
	gcc -c commun.c commun.h

gold.o: gold.c commun.h
	gcc -c gold.c commun.h

lm.o: lm.c commun.h
	gcc -c lm.c commun.h

jpl.o: jpl.c commun.h
	gcc -c jpl.c commun.h

clean:
	rm *.o programme commun.h.gch
