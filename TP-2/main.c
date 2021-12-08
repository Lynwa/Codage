#include "commun.h"

int main() {

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

	return 0;
}
