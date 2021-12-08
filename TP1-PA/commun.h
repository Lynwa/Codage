#include <stdio.h>
#include <stdlib.h>

/* Fonctions émetteur */

// Création et allocation d'une matrice carré
int ** matrice_new(int length);

// Destruction de la matrice alloué
void matrice_free(int ** mat,int length);

// Donne la taille de la matrice (nombre d'utilisateur)
int matrice_length(int length);

// Affichage de la matrice
void matrice_print(int ** mat,int nb_user);

// Création de la matrice d'Hadamard
int ** matrice_hadamard(int length);

// Donne la séquence d'étalement avec des informations supplémentaires (CM3B diapo 13-16)
void sequence_etalement(int ** mat,int length,int num);

// Donne le nombre de bits en fonction du nombre d'utilisateurs
int user_to_byte(int nb_user);

// Permet de choisir le nombre d'utilisateur (1,2,4,8 ou 16)
int gestion_user(void);

/* Fonctions canal */

// Utilisation d'un canal idéal (sans bruit/sans parasite)
int ** canal_ideal(int ** mat);

/* Fonctions récepteur */

// Donne le désatelement avec en vérifiant les séquences d'étalement avec un niveau de décision (CM3B diapo 17)
void desatelement_hadamard(int ** mat,int nb_user);
