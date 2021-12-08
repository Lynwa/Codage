#include <stdio.h>
#include <stdlib.h>
#include "commun.h"

int main(void){

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

  return 0;
}
