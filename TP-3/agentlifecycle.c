#include "commun.h"

// Position sur un agent UNKNOWN
int position_agent(int * etat){
	for(int i = 0;i < MAX_AG;i++)
		if(etat[i] == UNKNOWN)
			return i;
}

// Affichage des statuts/pid des threads
void thread_view(int * etat,int * pid){
	printf("Statuts des threads :\n");
	for (int i = 0; i < MAX_AG; i++){
		printf("Thread [%i] pid [%i]-> ",i,pid[i]);
		if(etat[i] == UNKNOWN)
			printf("UNKNOWN\n");
		else if(etat[i] == INITIATED)
			printf("INITIATED\n");
		else if(etat[i] == WAITING)
			printf("WAITING\n");
		else if(etat[i] == SUSPENDED)
			printf("SUSPENDED\n");
		else if(etat[i] == ACTIVE)
			printf("ACTIVE\n");
	}
}

// Création ou installation d'un nouvel Agent.
void Create(int * etat,char * simulation){

	int choix;

	while(choix < 1 || choix > 3){
		printf("Quelle TP vous voulez simuler (1-TP1A/2-TP1B/3-TP2): ");
		scanf("%i",&choix);
	}

	int nb_ag = position_agent(etat);

	if (choix == 1)
		strcpy(&simulation[nb_ag],"xterm -hold -e './programme 1' &");
	else if (choix == 2)
		strcpy(&simulation[nb_ag],"xterm -hold -e './programme 2' &");
	else if (choix == 3)
		strcpy(&simulation[nb_ag],"xterm -hold -e './programme 3' &");

	etat[nb_ag] = INITIATED;
}

// Invocation du nouvel agent par l'AP. Retourne le pid du processus.
void Invoke(int * pid,int * etat,char * simulation){

	for(int i = 0; i < MAX_AG; i++)
		if(etat[i] == INITIATED)
			printf("Thread [%i] -> INITIATED",i);

	int choix;
	printf("Choissisez un tread initialisé à activer : ");
	scanf("%i",&choix);
	system(&simulation[choix]);
	pid[choix] = atoi("ps -l | grep 'xterm' | tail -1 | awk '{print $4}'");
	etat[choix] = ACTIVE;
}

// Force la fin d'un Agent par l'AP. Cette transition ne peut être ignorée par l'Agent.
int Destroy(int * pid,int * etat){
	for(int i = 0; i < MAX_AG; i++)
		if(pid[i] != 0)
			printf("Thread [%i] pid %i",i,pid[i]);
	int choix;
	printf("Choissisez un tread à détruire : ");
	scanf("%i",&choix);
	etat[choix] = UNKNOWN;
	return kill(choix,SIGKILL);
}

// Demande de fin d'un Agent pouvant être ignorée par lui-même si besoin.
int Quit(int * pid,int * etat){
	for(int i = 0; i < MAX_AG; i++)
		if(pid[i] != 0)
			printf("Thread [%i] pid %i",i,pid[i]);
	int choix;
	printf("Choissisez un tread à quitter : ");
	scanf("%i",&choix);
	//etat[choix] = UNKNOWN;
	return kill(choix,SIGQUIT);
}

// Mettre l'Agent dans un état de suspendu. Cet état peut être initié par lAgent ou l'AP.
int Suspend(int * pid,int * etat){
	for(int i = 0; i < MAX_AG; i++)
		if(pid[i] != 0)
			printf("Thread [%i] pid %i",i,pid[i]);
	int choix;
	printf("Choissisez un tread à susprendre : ");
	scanf("%i",&choix);
	etat[choix] = SUSPENDED;
	return kill(choix,SIGSTOP);
}

// Sortir l'Agent de l'état suspendu. Cela peut être initié par l'Agent.
int Resume(int * pid,int * etat){
	for(int i = 0; i < MAX_AG; i++)
		if(pid[i] != 0)
			printf("Thread [%i] pid %i",i,pid[i]);
	int choix;
	printf("Choissisez un tread à sortir de l'état suspendu : ");
	scanf("%i",&choix);
	etat[choix] = ACTIVE;
	return kill(choix,SIGCONT);
}

// Mettre de l'Agent dans un état d'attente. Cet état peut être inité par l'Agent.
int Wait(int * pid,int * etat){
	for(int i = 0; i < MAX_AG; i++)
		if(pid[i] != 0)
			printf("Thread [%i] pid %i",i,pid[i]);
	int choix;
	printf("Choissisez un tread à attendre : ");
	scanf("%i",&choix);
	etat[choix] = WAITING;
	return kill(choix,SIGUSR1);
}

// Sortir l'Agent de l'état d'attente. Cela peut être inité uiniquement par l'AP.
int WakeUp(int * pid,int * etat){
	for(int i = 0; i < MAX_AG; i++)
		if(pid[i] != 0)
			printf("Thread [%i] pid %i",i,pid[i]);
	int choix;
	printf("Choissisez un tread à sortir de l'état d'attente : ");
	scanf("%i",&choix);
	etat[choix] = ACTIVE;
	return kill(choix,SIGUSR2);
}
