#include "commun.h"

int main(void){

	int i;

	// Etat de l'agent
	int * etat[MAX_AG];
	for(i = 0;i < MAX_AG;i++){
		etat[i] = malloc(sizeof(int));
		etat[i] = UNKNOWN;
	}

	// PIDs
	int * pid[MAX_AG];
	for(i = 0;i < MAX_AG;i++){
		pid[i] = malloc(sizeof(int));
		pid[i] = 0;
	}

	// Simulation de l'agent;
	char * simulation[MAX_AG];
	for(i = 0;i < MAX_AG;i++)
		simulation[i] = malloc(sizeof(char)* MAX_SIM);

	int choix = -1;

	while(choix != 0){
		//system("clear");
		printf("Plateforme d'application capacité de 10 Threads: \nCreate : 1\nInvoke : 2\nDestroy : 3\nQuit : 4\nSuspend : 5\nResume : 6\nWake up : 7\nPrint Thread : 8\nQuitter : 0\n");
		printf("Votre choix : ");
		scanf("%i",&choix);
		switch (choix) {
			case 1: Create(etat,simulation); break;
			case 2: Invoke(pid,etat,simulation); break;
			case 3: Destroy(pid,etat); break;
			case 4: Quit(pid,etat); break;
			case 5: Suspend(pid,etat); break;
			case 6: Resume(pid,etat); break;
			case 7: WakeUp(pid,etat); break;
			case 8: thread_view(etat,pid); break;
			case 0: break;
			default:
				printf("Choix invalide\n");
		}
		printf("\n\n\n\n\n");
	}

	// Libération de la mémoire
	for(i = 0;i < MAX_AG;i++)
		free(etat[i]);

	for(i = 0;i < MAX_AG;i++)
		free(pid[i]);

	for(i = 0;i < MAX_AG;i++)
		free(simulation[i]);

	return 0;
}
