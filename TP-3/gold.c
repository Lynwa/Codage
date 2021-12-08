#include "commun.h"

// Codeur de GOLD
char * gold(char * registre, int * pol1, int * pol2, int size, char * sequence){
	return jpl(registre, size, sequence, pol1, pol2, NULL);
}
