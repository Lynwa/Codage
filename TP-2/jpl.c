#include "commun.h"

// Codeur JPL
char * jpl(char * registres, int size, char * sequence, ...){
	memset(sequence, 0, size);
	char seq_tmp[size];
	va_list pol_param;
	va_start(pol_param, sequence);
	int * pol=va_arg(pol_param, int *);

	while(pol!=NULL){
		lm(registres, pol, size, seq_tmp);
		tab_xor(sequence, sequence, seq_tmp, size);
		pol=va_arg(pol_param, int *);
	}
	va_end(pol_param);

	return sequence;
}
