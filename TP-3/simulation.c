#include "commun.h"

// TP1A
void simulation_tp1A(void){

  // Gestion de 1,2,4,8 ou 16 utilisateurs
  int nb_user = gestion_user();
  int nb_byte = user_to_byte(nb_user);


  /* EMETTEUR */
  printf("---------------------EMETTEUR---------------------\n\n");

  // Création de la matrice d'Hadamard en fonction du nombre d'utilisateur
  int ** mat = matrice_hadamard(nb_byte);
  printf("Matrice d'Hadamard obtenu: \n\n");
  matrice_print(mat,nb_user);

  // Séquence d'étalement (CM3B diapo 13-16)
  for(int i = 0;i < nb_user;i++)
    sequence_etalement(mat,nb_byte,i);

  /* CANAL */
  printf("\n-----------------------CANAL----------------------\n\n");

  // Utilisation du canal idéal
  int ** mat_canal;
  if(mat_canal = canal_ideal(mat))
    printf("\tUtilisation du canal idéal\n");
  //matrice_print(mat_canal,nb_user);

  /* RECEPTEUR */
  printf("\n--------------------RECEPTEUR---------------------\n\n");

  // Désatelement des utilisateurs avec niveau de décision
  desatelement_hadamard(mat_canal,nb_user);

  printf("Matrice d'Hadamard reçu: \n\n");
  matrice_print(mat_canal,nb_user);
  printf("\n");
  /* FIN */
  // Libération de la mémoire occupé par la matrice
  matrice_free(mat,nb_user);
}

// TP1B
void simulation_tp1B(void){

    int EncoderType = 0;

    while(EncoderType < 1 || EncoderType > 4){
      printf("Choisir le type d'encodage entre 1 et 4 :");
      scanf("%i",&EncoderType);
    }

    // Message
    int *msg;

    // Ports de sortie P,N et F
    int P[17], N[17];
    double *F=malloc(sizeof(double));

    // Choix du type de codage et application
    ar_hdbn_encode(F, P, N, msg, EncoderType); //code
    ar_hdbn_decode(F, P, N, msg, EncoderType); //decode

    /* FIN */
    // Libération de la mémoire occupé par le port F;
    free(F);
}

// TP2
void simulation_tp2(void){

  int n,l;
	printf("\n============ CODEUR LM =============\n-> Polynôme de Génération: [5; 2]\n");

	char registre[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	n = 5;
	l = max_size(n);
	char seq2[l];
	int polL1[] = {5, 2, 0};
	lm(registre, polL1, l, seq2);
	display_sequence(seq2, l);
  printf("\n");

	printf("-> Polynôme de Génération : [6; 3; 2; 1]\n");
	n = 5;
	l = max_size(n);
	char seq3[l];
	int polL2[] = {6, 3, 2, 1, 0};
	lm(registre, polL2, l, seq3);
	display_sequence(seq3, l);
	printf("\n====================================\n");


	printf("\n=========== CODEUR GOLD ============\n-> Polynômes: [3; 2], [7; 3; 2; 1]\n");
	n = 5;
	l = max_size(n);
	char seq4[l];
	int polG1[] = {3, 2, 0};
	int polG2[] = {7, 3, 2, 1, 0};
	gold(registre, polG1, polG2, l, seq4);
	display_sequence(seq4, l);
	printf("\n====================================\n");

	printf("\n=========== CODEUR JPL =============\n-> Polynômes: [2; 1], [3; 1], [5; 2]\n");
	n = 5;
	l = max_size(n);
	char seq5[l];
	int polJ1[] = {2, 1, 0};
	int polJ2[] = {3, 1, 0};
	int polJ3[] = {5, 2, 0};
	jpl(registre, l, seq5, polJ1, polJ2, polJ3, NULL);
	display_sequence(seq5, l);
	printf("\n====================================\n");
}
