#include "commun.h"

// Codeur HDBn
int *HDBn_encode(int n, int * msg, int *P, int *N, bool first_pol, bool first_v){
    // Vérification
    if (n < 2){
        printf("n doit être supérieur à > 2\n");
        exit(1);
    }

    // Initialisation
    int i, zero_chain = 0;
    int viol = (first_v) ? 1 : -1;
    int last_pol = (first_pol) ? -1 : 1;
    int *output_msg = malloc(sizeof(int) * (msg_size(msg) + 1));

    for(i=0; msg[i]!=END;i++){
        if(msg[i]==1){
            output_msg[i]=-last_pol;
            last_pol=-last_pol;
            zero_chain=0;
        }else{
            zero_chain++;
            output_msg[i] = 0;
            if(zero_chain>n){
                if(viol==1){
                    if(last_pol==1){
                        output_msg[i-n]=-1;
                        N[i-n]=1;
                    }
                    output_msg[i]=-1;
                    last_pol=-1;
                }else{
                    if(last_pol==-1){
                        output_msg[i-n]=1;
                        P[i-n]=1;
                    }
                    output_msg[i]=1;
                    last_pol=1;
                }
                viol=-viol;
                zero_chain=0;
            }
        }
        P[i]=(output_msg[i]==1)? 1: 0;
        N[i]=(output_msg[i]==-1)? 1: 0;
    }
    output_msg[i]=END;
    P[i]=END;
    N[i]=END;

    return output_msg;
}

// Decodeur HDBn
int *HDBn_decode(int n, int *P, int *N, bool first_pol){

    if (n < 2){
        printf("n doit être supérieur à 2\n");
        exit(1);
    }

    int i;
    int size = msg_size(P) + 1;
    int last_pol = (first_pol) ? -1 : 1;
    int *decoded_msg = malloc(sizeof(int) * size);

    for (i=0; i<size-1; i++){
        if ((last_pol==1 && N[i]==1) || (last_pol==-1 && P[i]==1)){
            decoded_msg[i]=1;
            last_pol=-last_pol;
        }else if(P[i]==0 && N[i]==0){
            decoded_msg[i]=0;
        }else{
            decoded_msg[i]=0;
            decoded_msg[i-n]=0;
        }
    }
    decoded_msg[i]=END;
    return decoded_msg;
}
