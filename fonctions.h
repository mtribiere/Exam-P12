#ifndef FONCTIONS
#define FONCTIONS


  typedef struct Mot Mot;
  typedef struct Mot{
    int nombre;
    Mot *suivant;
    char texte[20];
  } Mot;

  void test();

  int Compter_caractere(char *text,char c);
  char *Sous_chaine(char *text,char c);
  int Remplacer_caractere(char *text,char firstCharacter,char secondCharacter);
  int Majuscule(char *text);
  int Remplacer_chiffre(char *sourceText,char *destinationText);
  char *numberToString(int n);
  int Analyser_chaine(char *sourceText,Mot **words);

  void afficherListe(Mot *words);
  void libererChaine(Mot *words);


#endif
