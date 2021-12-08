#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#define END 666     // Limite du tableau


/* Fonctions de message */

// Retourne la taille du message
int msg_size(int *msg);

//  Affiche le message
void msg_print(int *msg, bool format);

// Copie le message source vers le message de destination
void msg_copy(int *src, int *dst);

// Génére un message alétoire
int * msg_random(int size, int nb);

/* Fonctions de matrice */

// Structure de la matrice
typedef struct
{
    int nb_row, nb_col;
    int **mat;
}matrix_t;

// Crée une matrice d'une dimension ligne/colonne
matrix_t * matrix_create(int rows, int columns);

// Créer une matrice carré
matrix_t * matrix_sqr_create(int size);

// Libère la mémoire qu'occupe une matrice
void matrix_free(matrix_t * matrix);

// Affiche la matrice
void matrix_display(matrix_t * matrix);

// Affiche la ligne de la matrice
void matrix_display_lign(matrix_t * matrix, int index);

// Remplie la matrice d'une valeur donné
void matrix_fill(matrix_t * matrix, int value);

// Copie une matrice source vers une matrice destination
void matrix_copy(matrix_t *src, matrix_t *dest);

/* Codage HDBn */

// Codeur HDBn
int *HDBn_encode(int n, int * msg, int *P, int *N, bool first_pol, bool first_v);

// Décodeur HDBn
int *HDBn_decode(int n, int *P, int *N, bool first_pol);


/* Codage arithmetique */

// Codage arithmétique
double ar_encode(int *msg, double **interval, int **alphabet);

// Décodage arithmetique
int *ar_decode(double msg, double *interval, int *alphabet);

/* Gestion du type de codage */

// Liste des generics, choix du type de codeur arithmetique ou HDBn2-4
void ar_hdbn_encode(double *F, int *P, int *N, int * msg, int EncoderType);

// Liste des generics, choix du type de décodeur arithmetique ou HDBn2-4
void ar_hdbn_decode(double *F, int *P, int *N, int * msg, int EncoderType);
