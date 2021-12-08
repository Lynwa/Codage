#include "commun.h"

// Donne le désatelement avec en vérifiant les séquences d'étalement avec un niveau de décision (CM3B diapo 17)
void desatelement_hadamard(int ** mat,int nb_user){

  int i,j,k,ligne = 0,letter = 97;
  int calcul = 0,mult,sum = 0;

  printf("Signal reçu R :  R = ( ");

  for(i=0;i<nb_user;i++){
    for(j=0;j<nb_user;j++){
      if(mat[i][j] == 1)
        printf("+%c ",letter);
      else
        printf("-%c ",letter);
      letter++;
    }
    if(i == nb_user-1)
      printf(")\n\n");
    else if((1+i) % 4 == 0 && nb_user == 8)
      printf(")\n\n\n\t\t     (");
    else if(((1+i) % 2 == 0) && nb_user == 16)
      printf(")\n\n\n\t\t     (");
    else
      printf(") ( ");
    letter = 97;
  }

  calcul = 0;
  letter = 97;

  printf("Désatelement : \n");
  // Detection de niveau de décision (Algorithme du signal reçu (diapo 17))
  for(i=0;i<nb_user;i++){
    for(j=0;j<nb_user;j++){

      mult = mat[i][j];         // Valeur qui sera multiplié par la somme de la parenthèse

      for(k=0;k<nb_user;k++)    // Somme de la parenthèse en fonction du nombre d'utilisateur(s)
        sum += mat[ligne][k];

      mult *= sum;              // Exemple 1.(a+b+c+d) pour 4 utilisateur

      calcul += mult/nb_user;   // Division de la sequence par le nombre d'utilisateur(s)

      ligne++;
      sum = 0;

      if(ligne == nb_user)
        ligne = 0;
    }
    if(calcul == 1)             // La séquence doit être égale à 1 pour justifier (décider) que le signal a été parfaitement reçu.
      printf("Niveau %i est correct:  %c == %i(%c)\n",i+1,letter,calcul,letter);  // Niveau de décision correct (1) Etat 1
    else
      printf("Niveau %i est incorrect:  %c != %i(%c)\n",i+1,letter,calcul,letter);// Niveau de décision incorrect (!=1) Etat 0

    printf("\n");
    calcul = 0;
    letter++;
  }
  printf("\n");
}
