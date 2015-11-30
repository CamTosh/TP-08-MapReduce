#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ************
*      _   __
*     ( `^` ))
*     |     ||
*     |     ||
*     '-----'`
 ************ */


void mapper(char data[]){
    char mot[255][255]= {0, 0};
    char tmp[255] = {0};
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int count;

    data[strlen(data) - 1] = 0; // http://www.tutorialspoint.com/c_standard_library/c_function_strlen.htm

    // Le foutoir complet
    while (i < strlen(data) && data[i] != '\0'){
        if (!isalpha(data[i])){ // Si le caractère n'est pas une lettre, on démarre un nouveau mot
            mot[j][k] = '\0';
            k = 0;
            j++;
        } 
        else {
            mot[j][k++] = data[i];
        }
            i++;
    }
    
    mot[j][k] = 0;
    l = j;

    // La partie de tri
    for (i = 0; i < l; i++) {
        strcpy(tmp, mot[i]); // http://www.tutorialspoint.com/c_standard_library/c_function_strcpy.htm
        for (j = i + 1; j <= l; j++) {
            if (strcmp(mot[i], mot[j]) > 0) { // http://www.tutorialspoint.com/c_standard_library/c_function_strcmp.htm
                strcpy(tmp, mot[j]);
                strcpy(mot[j], mot[i]);
                strcpy(mot[i], tmp);
            }
        }
    }
    printf("Frequence apparition des mots : \n");
    i = 0;
    // On trouve la fréquence d'apparition et on affiche le résultat
    while (i <= l) {
        count = 1;
        if (i != l) {
            for (j = i + 1; j <= l; j++) {
                if (strcmp(mot[i], mot[j]) == 0) {
                    count++;
                }
            }
        }
        printf("\n %s \t %d", mot[i], count);
        // Une "incrémentation" de i avec "count" à la place de plus 1, pour passer au mot suivant
        i = i + count;
    }
}

int main() {
    FILE* f = fopen("toast.txt", "r"); // toast.txt = petit fichier à la con, liste.txt -> fichier badass avec 10 000 entrées random sur 3 lettres.
    if(f == 0) {
        fclose(f);
    }

    fseek(f, 0, SEEK_END); // Tu place le "curseur" du fichier à la fin (ça sert a savoir quelle taille fait le fichier)
    size_t size = ftell(f); // Récupérer la position courante du curseur, donc la taille du fichier vu qu'on a mis le curseur à la fin (et stocker le resultat dans size)
    fseek(f, 0, SEEK_SET); // Remettre le curseur au début du fichier pour commencer à la lire

    //char* data = malloc(size + 1);
    char* data = (char*)malloc(size + 1);
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

    mapper(data); // L'appel de la fonction mapper avec en paramétre data

    printf("\nDebug :\t Le fichier contient %zu octets \n", size); // Il me semble que le "%zu" ne peut être qu'utiliser en compilant via gcc
    //printf("Son contenu est: %s \n", data);

    fclose(f); // On a fini avec le fichier, donc on le ferme, parce qu'il faut toujours fermer les fichiers, pske tg c kom sa.
    free(data); // On libère la mémoire qu'on avait demandé à l'OS vu qu'on en a plus besoin.

    return 0;
}
