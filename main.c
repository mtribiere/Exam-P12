#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"

int main(){
  char text[] = "I walk a lonely road.The only one that I have ever known.";
  Mot *words = NULL;

  Analyser_chaine(text,&words);

  afficherListe(words);

  libererChaine(words);

}
