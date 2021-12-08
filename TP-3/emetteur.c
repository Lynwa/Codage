#include "commun.h"

// Création et allocation d'une matrice carré
int ** matrice_new(int length){
    int ** mat = malloc(sizeof(int *) * length);
    for(int i = 0; i < length; i++)
        mat[i] = malloc(sizeof(int) * length);
    return mat;
}

// Destruction de la matrice alloué
void matrice_free(int ** mat,int length){
    for(int i=0;i<length;i++)
        free((mat)[i]);
    free(mat);
}

// Donne la taille de la matrice (nombre d'utilisateur)
int matrice_length(int length){
  int cpt = 1;
  for(int i=0;i<length;++i)
    cpt *= 2;
    return cpt;
}

// Affichage de la matrice
void matrice_print(int ** mat,int nb_user){
  for(int i=0;i<nb_user;i++){
    for(int j=0;j<nb_user;j++){
      printf("%2d ",mat[i][j]);
    }
    printf("\n");
  }
}

// Création de la matrice d'Hadamard
int ** matrice_hadamard(int length){

    int ** mat,i,j;
    if(length==0){
        mat = matrice_new(1);
        mat[0][0] = 1;
    }
    else{
      int ** matH = matrice_hadamard(length-1);
      int nb_user = matrice_length(length),i,j;

      mat = matrice_new(nb_user);

      for(i=0;i<nb_user;i++){
        for(j=0;j<nb_user;j++){
          if(i<(nb_user/2)||j<(nb_user/2))
            mat[i][j] = matH[i%(nb_user/2)][j%(nb_user/2)];
          else
            mat[i][j] = -matH[i%(nb_user/2)][j%(nb_user/2)];
        }
      }
      matrice_free(matH,nb_user/2);
    }
  return mat;
}

// Donne la séquence d'étalement avec des informations supplémentaires (diapo 13-16 CM3B)
void sequence_etalement(int ** mat,int length,int num){

    int i,letter = 97; // Lettre a
    printf("\nUtilisateur %i\n",num+1);
    printf("bit à transmettre:\t\t  %c = {%i}\n",letter,length);
    printf("séquence d'étalement\t\t ");

    for(i=0;i<matrice_length(length);i++)
      printf("%2d ",mat[num][i]);

    printf("\nchips émis durant un temps bit:\t ");
    for(i=0;i<matrice_length(length);i++){
      if(mat[num][i] == 1)
        printf("+%c ",letter);
      else
        printf("-%c ",letter);
      letter++;
    }
    printf("\n\n");
}

// Donne le nombre de bits en fonction du nombre d'utilisateurs
int user_to_byte(int nb_user){
  int i = 1,nb_byte = 0;
  while(i != nb_user){
    i *= 2;
    nb_byte++;
  }
  return nb_byte;
}

// Permet de choisir le nombre d'utilisateur (1,2,4,8 ou 16)
int gestion_user(void){
  int nb_user = 0;
  while(nb_user != 1 && nb_user != 2 && nb_user != 4 && nb_user != 8 && nb_user != 16){
    printf("Donner un nombre d'utilisateurs compris entre 1,2,4,8 et 16 : ");
    scanf("%i",&nb_user);
    printf("\n");
  }
  return nb_user;
}
