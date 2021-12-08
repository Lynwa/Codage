#include "commun.h"

/* Fonctions de message */

// Retourne la taille du message
int msg_size(int *msg){
    int i;
    for (i = 0; msg[i] != END; i++);
    return i;
}

//  Affiche le message
void msg_print(int *msg, bool format){
    int i;
    for (i = 0; msg[i] != END; i++){
        if(format){
          printf("%2c", msg[i]);
        }else{
          printf("%2d", msg[i]);
        }
    }
}

// Copie le message source vers le message de destination
void msg_copy(int *src, int *dst){
  int i;
  for(i=0; src[i]!=END; i++){
    dst[i]=src[i];
  }
  dst[i]=END;
}

// Génére un message alétoire
int * msg_random(int size, int nb){
  int i;
  srand(time(NULL));
  int * msg=malloc(sizeof(int) * (size+1));
  for(i=0; i<size+1;i++){
    msg[i]=rand()%nb;
  }
  msg[i]=END;
  return msg;
}

/* Fonctions de matrice */

// Crée une matrice d'une dimension ligne/colonne
matrix_t *matrix_create(int nb_row, int nb_col){
    matrix_t * matrix=malloc(sizeof(matrix_t));
    matrix->nb_row=nb_row;
    matrix->nb_col=nb_col;

    matrix->mat=malloc(sizeof(int *) * nb_row);
    int i;
    for(i=0; i<nb_row; i++){
      matrix->mat[i]=malloc(sizeof(int) * nb_col);
    }
    return matrix;
}

// Créer une matrice carré
matrix_t *matrix_sqr_create(int size){
    return matrix_create(size, size);
}

// Libère la mémoire qu'occupe une matrice
void matrix_free(matrix_t *matrix){
    int i;
    for(i=0; i<matrix->nb_row; i++){
      free(matrix->mat[i]);
    }
    free(matrix->mat);
    free(matrix);
}

// Affiche la matrice
void matrix_display(matrix_t *matrix){
    int i, j;
    printf("     ");
    for(i=0; i<matrix->nb_col; i++){
      printf("%3d  ", i);
    }
    printf("\n----");
    for(i=0; i<matrix->nb_col; i++){
      printf("----");
    }
    printf("\n");
    for(i=0; i<matrix->nb_row; i++){
        printf("%3d |", i);
        for(j=0; j<matrix->nb_col; j++){
            printf(" %3d ", matrix->mat[i][j]);
        }
        printf("\n");
    }
}

// Affiche la ligne de la matrice
void matrix_display_lign(matrix_t *matrix, int index){
    int i;
    for (i=0; i<matrix->nb_col; i++){
      printf("%3d ", matrix->mat[index][i]);
    }
}

// Remplie la matrice d'une valeur donné
void matrix_fill(matrix_t *matrix, int value){
    int i, j;
    for(i=0; i<matrix->nb_row; i++)
        for (j=0; j<matrix->nb_col; j++){
          matrix->mat[i][j]=value;
        }
}

// Copie une matrice source vers une matrice destination
void matrix_copy(matrix_t *src, matrix_t *dest){
    int i, j;
    for (i=0; i<src->nb_row; i++){
      for (j=0; j<src->nb_col; j++){
        dest->mat[i][j] = src->mat[i][j];
      }
    }
}

/* Fonction lié à l'intervalle */

// Affiche l'intervalle, sortie de la valeur du codage arithmetique (Port F)
void display_interval(double *tab, int size){
    int j;
    printf("[0;%g[ ", tab[0]);
    for (j = 1; j < size; j++)
        printf("[%g;%g[ ", tab[j - 1], tab[j]);
    printf("\n");
}
