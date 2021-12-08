#include "commun.h"

// hand_ler pour Quit()

// hand_ler pour Suspend()

// hand_ler pour Wait()


int main(int argc, char const *argv[]) {

  if(argc!=2 || atoi(argv[1]) < 1 || atoi(argv[1]) > 3){
      printf("%s Choisir la simulation de TP de 1 à 3\n", argv[0]);
      exit(1);
  }

  int nb_exec = 0;

  while(1){   // Thread

  printf("Nombre d'execution : %i\n",nb_exec);

  // Un sigaction soit être fait pour savoir si on reçoit des signaux de la part de l'AP

  if(atoi(argv[1]) == 1)
    simulation_tp1A();

  else if(atoi(argv[1]) == 2)
    simulation_tp1B();

  else if(atoi(argv[1]) == 3)
    simulation_tp2();

  sleep(5);
  }

return 0;
}
