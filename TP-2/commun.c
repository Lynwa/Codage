#include "commun.h"

// Retoune la puissance d'un entier
int sqr(int n){
	int i, res = 1;
	for(i=1; i<=n; i++)
		res*=2;
	return res;
}

// Retourne le résultat de l'opération XOR entre les éléments du tableau 1 et 2
char * tab_xor(char * dest, char * tab1, char * tab2, int size){
	int i;
	for(i = 0; i<size; i++){
		dest[i] = xor(tab1[i], tab2[i]);
	}
	return dest;
}

// Affichage de la séquence
void display_sequence(char * sequence, int size){
	int i;
	for(i = 0; i<size; i++){
		sequence[i]?printf("1"):printf("0");
	}
}
