#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ************
*      _   __
*     ( `^` ))
*     |     ||
*     |     ||
*     '-----'`
 ************ */

int mapper(char *mot, char *text){
  int i = 0;
  char *toast;

  toast = strstr(text, mot);

  while (toast != NULL){
    toast = strstr(toast + 1, mot);
    i++;
  }

  return i;
}

void reducer(char * text){
    char *toast = strtok(text, " ");

    while (toast != NULL){
      printf ("%s : %d\n", toast, mapper(toast, text));
      toast = strtok(NULL, " ");
    }
}

int main(){
    FILE *fichier;
    fichier = fopen("liste.txt", "r");
    char text;
    text = fread(1024, sizeof(char), 1024, fichier);

    int j = 0;

    if (fichier == NULL){
        printf("Y a une couille dans le toast");
    }
    for (j = 0; j < 10000; j++){
        fscanf(fichier, "%s", &text[j]);
        printf("%s\n\n", text[j]);
    }

    fclose(fichier);
    reducer(&text);
};


//char text[] = " jean toast roger toast roger jean charles jean roger toast toast charles toast ";

