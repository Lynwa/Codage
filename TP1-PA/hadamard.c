#include <stdio.h>
#include <stdlib.h>


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

int main(int argc, char *argv[]){

    if(argc!=2||atoi(argv[1])<0){
      printf("%s <Insérer une taille strictement positive>\n",argv[0]);
      exit(1);
    }

    int ** mat = matrice_hadamard(atoi(argv[1]));
    int nb_user = matrice_length(atoi(argv[1]));

    matrice_print(mat,nb_user);

    matrice_free(mat,nb_user);
    return 0;
}
