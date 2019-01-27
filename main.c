#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

int main(){
  char text[] = "J'ai 2 voitures et 4 chiens";
  char *text2 = malloc(sizeof(char)*500);

  Remplacer_chiffre(text,text2);
  printf("%s -> %s\n",text,text2);

  free(text2);
}
