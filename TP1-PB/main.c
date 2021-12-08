#include "commun.h"

int main(int argc, char *argv[]){

    // Vérification
    if(argc!=2){
        printf("%s <EncoderType>\nEncoderType values:\n1 = arithmetic coding\n2-4 = HDB2-4\n", argv[0]);
        exit(1);
    }

    // Choix du type de codage
    int EncoderType = atoi(argv[1]);
    if(EncoderType < 1 || EncoderType > 4){
        fprintf(stderr, "<EncoderType> est compris entre 1 et 4\n");
        exit(1);
    }

    // Message
    int *msg;

    // Ports de sortie P,N et F
    int P[17], N[17];
    double *F=malloc(sizeof(double));

    // Choix du type de codage et application
    ar_hdbn_encode(F, P, N, msg, EncoderType); //code
    ar_hdbn_decode(F, P, N, msg, EncoderType); //decode

    /* FIN */
    // Libération de la mémoire occupé par le port F;
    free(F);

    return 0;
}
