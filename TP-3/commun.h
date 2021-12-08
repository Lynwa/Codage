#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#define END 666     // Limite du tableau

/* ======================================== TP3 Agent Life Cycle ======================================== */

// Valeurs possible de l'agent
#define UNKNOWN 0
#define INITIATED 1
#define WAITING 2
#define SUSPENDED 3
#define ACTIVE 4

// Taille maximale d'une chaine de caractère
#define MAX_SIM 256
#define MAX_AG 10

// Position sur un agent UNKNOWN
int position_agent(int * etat);

// Affichage des statuts/pid des threads
void thread_view(int * etat,int * pid);

// Creation ou installation d'un nouvel Agent.
void Create(int * etat,char * simulation);

// Invocation du nouvel agent par l'AP.
void Invoke(int * pid,int * etat,char * simulation);

// Force la fin d'un Agent par l'AP. Cette transition ne peut être ignorée par l'Agent.
int Destroy(int * pid,int * etat);

// Demande de fin d'un Agent pouvant être ignorée par lui-même si besoin.
int Quit(int * pid,int * etat);

// Mettre l'Agent dans un état de suspendu. Cet état peut être initié par lAgent ou l'AP.
int Suspend(int * pid,int * etat);

// Sortir l'Agent de l'état suspendu. Cela peut être initié par l'Agent.
int Resume(int * pid,int * etat);

// Mettre de l'Agent dans un état d'attente. Cet état peut être inité par l'Agent.
int Wait(int * pid,int * etat);

// Sortir l'Agent de l'état d'attente. Cela peut être inité uiniquement par l'AP.
int WakeUp(int * pid,int * etat);

/* ======================================== TP1-A Code d'Etalement ======================================== */

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

/* ======================================== TP1-B Codeur HDBn / Codeur arithmétique ======================================== */

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


/* Codage arithmetique  */

// Codage arithmétique
double ar_encode(int *msg, double **interval, int **alphabet);

// Décodage arithmetique
int *ar_decode(double msg, double *interval, int *alphabet);

/* Gestion du type de codage */

// Liste des generics, choix du type de codeur arithmetique ou HDBn2-4
void ar_hdbn_encode(double *F, int *P, int *N, int * msg, int EncoderType);

// Liste des generics, choix du type de décodeur arithmetique ou HDBn2-4
void ar_hdbn_decode(double *F, int *P, int *N, int * msg, int EncoderType);


/* ======================================== TP2 Générateur Pseudo Aléatoire ======================================== */

// Opération XOR
#define xor(a, b) (!((a) == (b)))

// Retoune la puissance d'un entier
int sqr(int n);

// Retourne le résultat de l'opération XOR entre les éléments du tableau 1 et 2
char * tab_xor(char * dest, char * t1, char * t2, int size);

// Affichage de la séquence
void display_sequence(char * sequence, int size);

// Codeur à Longueur Maximale
#define max_size(n) (sqr(n) - 1)
char * lm(char * registre, int * polynome, int size, char * sequence);

// Codeur JPL
char * jpl(char * registre, int size, char * sequence, ...);

// Codeur de GOLD
char * gold(char * registre, int * pol1, int * pol2, int size, char * sequence);

/* ======================================== SIMULATION DE TP ======================================== */

// TP1A
void simulation_tp1A(void);

// TP1B
void simulation_tp1B(void);

// TP2
void simulation_tp2(void);
