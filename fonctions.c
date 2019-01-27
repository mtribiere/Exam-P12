#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void test(){
  printf("test\n");
}

int Compter_caractere(char *text,char c){
  int total = 0;
  int index = 0;

  //Tant que la chaine n'est pas fini
  while(text[index] != '\0'){
    //Si on rencontre le même caractère
    if(text[index] == c)
      total++;
    index++;
  }

  return total;
}

char *Sous_chaine(char *text,char c){
  char *toReturn = NULL;
  int index = 0;

  //Tant que la chaine n'est pas fini est que on a rien trouvé
  while(text[index] != '\0' && toReturn == NULL){
    //Si on rencontre caractère voulu
    if(text[index] == c)
      toReturn = text+index;

    index++;
  }

  return toReturn;
}

int Remplacer_caractere(char *text,char firstCharacter,char secondCharacter){
  int index = 0;
  int total = 0;
  //Tant que la chaine n'est pas fini
  while(text[index] != '\0'){
    //Si on rencontre une occurence
    if(text[index] == firstCharacter){
      text[index] = secondCharacter;
      total++;
    }

    index++;
  }

  return total;
}

int Majuscule(char *text){
  int total = 0;

  //Mettre en majucule le premier caractère
  text[0] = toupper(text[0]);
  int index = 1;

  //Tant que la chaine n'est pas finie
  while(text[index] != '\0'){
    //Si on trouve un point et un espace et que on n'est pas en bout de chaine
    if(text[index] == '.' && text[index+1] == ' ' && text[index+2] != '\0'){
      text[index+2] = toupper(text[index+2]);
      total++;
    }

    index++;
  }

  return total;
}

char *numberToString(int n){
  char *toReturn = malloc(sizeof(char)*8);

  switch(n){
      case 0:
        strcpy(toReturn,"zero");
        break;
      case 1:
        strcpy(toReturn,"un");
        break;
      case 2:
        strcpy(toReturn,"deux");
        break;
      case 3:
        strcpy(toReturn,"trois");
        break;
      case 4:
        strcpy(toReturn,"quatre");
        break;
      case 5:
        strcpy(toReturn,"cinq");
        break;
      case 6:
        strcpy(toReturn,"six");
        break;
      case 7:
        strcpy(toReturn,"sept");
        break;
      case 8:
        strcpy(toReturn,"huit");
        break;
      case 9:
        strcpy(toReturn,"neuf");
        break;
  }

  return toReturn;
}

int Remplacer_chiffre(char *sourceText,char *destinationText){
  int indexSource = 0;
  int indexDest = 0;

  //Tant que la chaine n'est pas finie
  while(sourceText[indexSource] != '\0'){

    //Si on trouve un chiffre
    if(sourceText[indexSource]>=48 && sourceText[indexSource]<=57){
      //Le convertir en nombre
      char *currentConverted = numberToString((int)(sourceText[indexSource] - 48));
      //Copier le nombre converti
      int i = 0;
      while(currentConverted[i] != '\0'){
        destinationText[indexDest] = currentConverted[i];
        i++;
        indexDest++;
      }

      //Liberer l'emplacement
      free(currentConverted);

      //Passer au caractère suivant
      indexSource++;

    }else{//Sinon simplement copier le caractère
      destinationText[indexDest] = sourceText[indexSource];
      indexSource++;
      indexDest++;
    }
  }

  //Placer la sentinelle sur la destination
  destinationText[indexDest] = '\0';
  return indexDest;
}

int Analyser_chaine(char *sourceText,Mot **words){
  int indexSource = 0;
  int counter = 0;

  //Tant que la chaine n'est pas fini
  while(sourceText[indexSource] != '\0'){
    //Determier la taille du mot
    int wordSize = 0;
    while(sourceText[indexSource+wordSize] != ' ' && sourceText[indexSource+wordSize] != ',' && sourceText[indexSource+wordSize] != '.')
      wordSize++;

    //Isoler le mot
    char *currentWord = malloc(sizeof(char)*(wordSize+1));
    int i = 0;
    while(i<wordSize){
      currentWord[i] = sourceText[indexSource+i];
      i++;
    }
    currentWord[i] = '\0';

    //Chercher le mot dans la liste chainée
    int found = 0;
    Mot *currentPointer = *words;

    //Tant que on a pas atteient la fin de la liste ou que on a trouvé le mot
    while(currentPointer != NULL && found == 0){
      //Si on trouve le mot dans la liste
      if(strcmp(currentPointer->texte,currentWord) == 0){
        found = 1;
        (currentPointer->nombre)++;
      }

      //Avancer dans la liste
      currentPointer = currentPointer->suivant;
    }

    //Si le mot n'a pas été trouvé
    if(found == 0){
      //Insertion tête
      Mot *toInsert = malloc(sizeof(Mot));
      strcpy(toInsert->texte,currentWord);
      toInsert->nombre = 1;

      toInsert->suivant = *words;
      *words = toInsert;
    }

    free(currentWord);
    indexSource += (wordSize+1);
  }

  return counter;
}

void libererChaine(Mot *words){
  Mot *currentToFree = words;
  Mot *currentNext;
  //Si la chaine n'est pas vide
  if(currentToFree != NULL){
      currentNext = words->suivant;
      //Tant que l'on a pas atteient la fin
      while(currentToFree != NULL){
        //Liberer l'emplacement
        free(currentToFree);

        //Avancer si possible
        currentToFree = currentNext;
        if(currentNext != NULL){
          currentNext = currentNext->suivant;
        }
      }
    }
  }


/* DEBUG */
void afficherListe(Mot *words){
  Mot *currentPointer = words;
  while(currentPointer != NULL){
    printf("%s -> %d\n",currentPointer->texte,currentPointer->nombre);
    currentPointer = currentPointer->suivant;
  }
}
