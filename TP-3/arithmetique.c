#include "commun.h"

// Variable globales utilisés pour les fonctions ar_hdbn_en/decode
double *interval;
int *alphabet;

/* Codage arithmetique */

// Codage arithmétique du message
double ar_encode(int *msg, double **interval, int **alphabet){
    // P1 - Compte chaque unique lettre dans le message
    bool done = false;
    int i, j, tmp_letter;
    matrix_t *alpha = NULL, *tmp_aplha = NULL;
    for(i = 0; msg[i] != END; i++){
        for(j = 0; alpha && j<alpha->nb_col && alpha->mat[0][j]!=msg[i]; j++);
        if(alpha == NULL){
            alpha = matrix_create(2, 1);
            alpha->mat[0][0]=msg[i];
            alpha->mat[1][0]=1;
        }else if(j >= alpha->nb_col){
            tmp_aplha = matrix_create(alpha->nb_row, alpha->nb_col + 1);
            matrix_copy(alpha, tmp_aplha);
            matrix_free(alpha);
            alpha = tmp_aplha;
            alpha->mat[0][j] = msg[i];
            alpha->mat[1][j] = 1;
        }else{
            alpha->mat[0][j] = msg[i];
            alpha->mat[1][j] += 1;
        }
    }
    tmp_aplha = matrix_create(alpha->nb_row, alpha->nb_col + 1);
    matrix_copy(alpha, tmp_aplha);
    matrix_free(alpha);
    alpha = tmp_aplha;
    alpha->mat[0][alpha->nb_col - 1] = END;
    alpha->mat[1][alpha->nb_col - 1] = 1;

  // Trie l'alphabet reçu par nombre d'occurence de chaque lettre
    while (!done){
        done = true;
        for(j = 1; alpha->nb_col > 2 && j < alpha->nb_col - 1; j++){
            if(alpha->mat[1][j] > alpha->mat[1][j - 1]){
                tmp_letter = alpha->mat[0][j];
                alpha->mat[0][j] = alpha->mat[0][j - 1];
                alpha->mat[0][j - 1] = tmp_letter;
                tmp_letter = alpha->mat[1][j];
                alpha->mat[1][j] = alpha->mat[1][j - 1];
                alpha->mat[1][j - 1] = tmp_letter;
                done = false;
            }
        }
    }

// Créer une interval pour chaque lettre
    *interval = malloc(sizeof(double) * alpha->nb_col);
    int size = msg_size(msg) + 1;

    (*interval)[0] = alpha->mat[1][0] / (double)size;
    for(j = 1; j < alpha->nb_col; j++)
        (*interval)[j] = (*interval)[j - 1] + alpha->mat[1][j] / (double)size;

// Binf et BSup représentent les bordures de l'interval
    double BInf, BSup;
    for(j = 0; msg[0] != alpha->mat[0][j]; j++);
    BInf = (j == 0) ? 0 : (*interval)[j - 1];
    BSup = (*interval)[j];

// Algorithme du CM2 diapo 23-25
    double BI = -1;
    double BS = -1;
    double prev_inter = -1;
    for(i = 1; i < size; i++){
        for(j = 0; msg[i] != alpha->mat[0][j]; j++);
        BI = (j == 0) ? 0 : (*interval)[j - 1];
        BS = (*interval)[j];

        prev_inter = BSup - BInf;
        BSup = BInf + prev_inter * BS;
        BInf = BInf + prev_inter * BI;
    }
    *alphabet = malloc(sizeof(int) * alpha->nb_col);
    for(i = 0; i < alpha->nb_col; i++){
      (*alphabet)[i] = alpha->mat[0][i];
    }
    matrix_free(alpha);
    return BInf;
}

// Décodage arithmetique du message
int *ar_decode(double msg, double *interval, int *alphabet){
    int *output_msg = NULL;
    int i, j = -1;
    double n = msg;
    double BI, BS;

    for(i = 0; j == -1 || alphabet[j] != END; i++){
        for(j = 0; n >= interval[j]; j++);
        output_msg = realloc(output_msg, sizeof(int) * (i + 1));
        output_msg[i] = alphabet[j];
        BI = (j == 0) ? 0.0 : interval[j - 1];
        BS = interval[j];
        n = (n - BI) / (BS - BI);
    }
    return output_msg;
}

/* Gestion du type de codage */

// Liste des generics, choix du type de codeur arithmetique ou HDBn2-4
void ar_hdbn_encode(double *F, int *P, int *N, int * msg, int EncoderType){

  int nb;

  switch(EncoderType){
    case 1:
            printf("\nVous avez choisi le code arithmetique.\nEntrer un entier (Nombre de lettre souhaitée) qui va généré un message aléatoire : ");
            scanf("%d",&nb);
            printf("\n===================== START =====================\nInput message : ");
            msg = msg_random(15,nb);
            msg_print(msg,false);
            printf("\n");
            interval = NULL;
            alphabet = NULL;
            *F = ar_encode(msg, &interval, &alphabet);
            printf("Coded output  :  %.29f\n", *F);
            break;

    default:
            printf("\n================Coding method: HDB%d ============\n", EncoderType);
            printf("\n===================== START ====================\nInput message  :");
            msg = msg_random(15,2);
            msg_print(msg, false);
            int *output_msg=HDBn_encode(EncoderType, msg, P, N, true, false);
            printf("\nCoded output   :");
            msg_print(output_msg, false);
            printf("\nPulse +1       :");
            msg_print(P, false);
            printf("\nPulse -1       :");
            msg_print(N, false);
            break;
  }
}

// Liste des generics, choix du type de décodeur arithmetique ou HDBn2-4
void ar_hdbn_decode(double *F, int *P, int *N, int * msg, int EncoderType){

  int *decoded_msg;

  switch(EncoderType){
    case 1:
            msg = ar_decode(*F, interval, alphabet);
            printf("Decoded output: ");
            msg_print(msg,false);
            printf("\n=====================  END  =====================\n");
            break;

    default:
            decoded_msg=HDBn_decode(EncoderType, P, N, true);
            printf("\nDecoded output :");
            msg_print(decoded_msg, false);
            printf("\n=====================  END  ====================\n");
            break;
  }
}
