#include "commun.h"

// Codeur à Longueur Maximale
char * lm(char * registre, int * polynome, int size, char * sequence){
	int n=polynome[0], i, seq_i;
	char reg[n];
	char next_reg[n];

	memcpy(reg, registre, n);
	sequence[0]=1;

	for(seq_i = 1; seq_i<size; seq_i++) {
		for(i = 0; i<(n-1); i++){
      next_reg[i+1] = reg[i];
    }

		next_reg[0] = 0;
		for(i=0; polynome[i]!=0; i++){
      next_reg[0]=xor(next_reg[0], reg[polynome[i]-1]);
    }


		memcpy(reg, next_reg, n); // next_reg -> reg
		sequence[seq_i]=reg[n-1]; // reg -> seq
	}
	return sequence;
}
