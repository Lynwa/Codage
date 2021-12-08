# TP1-B Codeur HDBn / Codeur arithmétique

all: arithmetique.o hdbn.o commun.o main.c
	gcc arithmetique.o hdbn.o commun.o main.c -o programme

commun.o: commun.c commun.h
	gcc -c commun.c commun.h

hdbn.o: hdbn.c commun.h
	gcc -c hdbn.c commun.h

arithmetique.o: arithmetique.c commun.h
	gcc -c arithmetique.c commun.h

clean:
	rm *.o programme commun.h.gch
