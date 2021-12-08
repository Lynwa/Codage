# TP3 Agent Life Cycle

all: emetteur.o recepteur.o canal.o arithmetique.o hdbn.o commun.o gold.o lm.o jpl.o simulation.o agentlifecycle.o
	gcc emetteur.o recepteur.o canal.o arithmetique.o hdbn.o commun.o gold.o lm.o jpl.o simulation.o main.c -o programme
	gcc emetteur.o recepteur.o canal.o arithmetique.o hdbn.o commun.o gold.o lm.o jpl.o simulation.o agentlifecycle.o applicationplatform.c -o applicationplatform

agentlifecycle.o: agentlifecycle.c commun.h
	gcc -c agentlifecycle.c commun.h

simulation.o: simulation.c commun.h
	gcc -c simulation.c commun.h

commun.o: commun.c commun.h
	gcc -c commun.c commun.h

emetteur.o: emetteur.c commun.h
	gcc -c emetteur.c commun.h

recepteur.o: recepteur.c commun.h
	gcc -c recepteur.c commun.h

canal.o: canal.c commun.h
	gcc -c canal.c commun.h

hdbn.o: hdbn.c commun.h
		gcc -c hdbn.c commun.h

arithmetique.o: arithmetique.c commun.h
		gcc -c arithmetique.c commun.h

gold.o: gold.c commun.h
		gcc -c gold.c commun.h

lm.o: lm.c commun.h
		gcc -c lm.c commun.h

jpl.o: jpl.c commun.h
		gcc -c jpl.c commun.h

clean:
	rm *.o programme applicationplatform commun.h.gch
