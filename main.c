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

int mapper(char *mot, char *data){
  int i = 0;
  char *toast;

  toast = strstr(data, mot);

  while (toast != NULL){
    toast = strstr(toast + 1, mot);
    i++;
  }

  return i;
}

void reducer(char * data){
    char *toast = strtok(data, " ");

    while (toast != NULL){
      printf ("%s : %d\n", toast, mapper(toast, data));
      toast = strtok(NULL, " ");
    }
}

int main(int argc, char** argv) {
	//char text[] = " jean toast roger toast roger jean charles jean roger toast toast charles toast ";
	FILE* f = fopen("toast.txt", "r"); // toast.txt = petit fichier à la con, liste.txt -> fichier badass avec 10 000 entrées random sur 3 lettres.
	if(f == 0) {
		fclose(f);
	}

	fseek(f, 0, SEEK_END); // Tu place le "curseur" du fichier a la fin (ça sert a savoir quelle taille fait le fichier)
	size_t size = ftell(f); // Récupérer la position courante du curseur, donc la taille du fichier vu qu'on a mis le curseur à la fin (et stocker le resultat dans size)
	fseek(f, 0, SEEK_SET); // Remettre le curseur au début du fichier pour commencer à la lire

	char* data = malloc(size + 1);
	/*
	Demander à l'OS 'size + 1' octets de mémoire pour stocker toutes les données du fichier.
	data est un pointeur vers de l'espace RAM disposible qu'on a demandé à l'OS, c'est comme un tableau de char de taille 'size + 1'
	Le +1 est lié au fait qu'en C, les strings sont délimités par le caractère '\0' (0x0 en ASCII) afin de savoir où se trouve la fin du string
	Il nous faut donc 'size' octets pour les données du fichier, et 1 octet de plus pour le caractère '\0'
	*/

	size_t red = fread(data, 1, size, f);
	/*
	On lit 'size' éléments de taille '1' octet (deuxième argument) à l'emplacement 'data', c'est a dire au début du tableau (la mémoire qu'on a demandé à l'OS)
	data[size] = '\0'; // On place le caractère '\0' à la toute fin du tableau pour délimiter la fin du string
	Le tableau est de taille 'size + 1', donc 'data[size]' correspond à la dernière case du tableau (la prenière case est 'data[0]', et pas 'data[1]' !!)
	La variable 'red' contient le nombre d'octets qu'on a lu au final
	*/

	if(red != size) { // Si on a pas lu 'size' octets, c'est qu'il y a eu une erreur
		fclose(f);
	}

	//printf("Le fichier contient %zu octets \n", size);
	//printf("Son contenu est: %s \n", data);

	reducer(data);

	fclose(f); // On a fini avec le fichier, donc on le ferme, pask faut toujours fermer les fichiers, parce que tg c kom sa.
	free(data); // On libère la mémoire qu'on avait demandé à l'OS vu qu'on en a plus besoin.

	return 0;
}
