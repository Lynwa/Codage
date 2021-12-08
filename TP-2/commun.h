#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

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
