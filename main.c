#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define limit 60000

/* ************
*      _   __
*     ( `^` ))
*     |     ||
*     |     ||
*     '-----'`
 ************ */


void mapper(char data[]){
    char mot[limit][30]= {0, 0}; // 60 000 mots avec 30 lettres au max

    char *tmp;
    tmp  = (char *) malloc(255); // OKLM Le ptit malloc des familles

    // Ahhhhh les compteurs
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int count;

    // Le foutoir complet
        while (i < limit){
            if (!isalpha(data[i])){ // Si le caractère n'est pas une lettre, on démarre un nouveau mot
                k = 0;
                j++;
                l=j;
                }
            else {
                mot[j][k++] = data[i];
            }
            i++;
        }

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
        printf("\n %d \t %s", count, mot[i]);
        // Une "incrémentation" de i avec "count" à la place de plus 1, pour passer au mot suivant
        i = i + count;
    }
}

/* à finir, fonction recherche
void value(char recherche, char data[], size_t size){
    int i;
    char search;

    for(i = 0; i <= size; i++){

        search = strstr(data[i], recherche);
        if (search != NULL){
            printf("Le mot apparait dans le fichier \n");
        }
        if(search == NULL) {
            printf("Aucun mot \n");
        }
    }
}
*/

int main() {
    FILE* f = fopen("aliceInWonderland.txt", "r"); // fichier.txt, trainspotting.txt, cupcake.txt, 42.txt

    if(f == 0) { // Si le fichier est = à 0 (null) on le ferme, ça veut dire qu'il est vide, 0 octet, kedal, nadda
        fclose(f);
    }

    fseek(f, 0, SEEK_END); // Tu place le "curseur" du fichier à la fin (ça sert a savoir quelle taille fait le fichier)
    size_t size = ftell(f); // Récupérer la position courante du curseur, donc la taille du fichier vu qu'on a mis le curseur à la fin (et stocker le resultat dans size)
    fseek(f, 0, SEEK_SET); // Remettre le curseur au début du fichier pour commencer à la lire

    char* data = (char*)malloc(size + 1); // Ptit malloc tran-tran

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

    /*
    // Pour la fonction "recherche", ça serai sympa de l'implementer !
    char recherche;

    printf("\n Recherche : ");
    scanf("%c", &recherche);

    value(recherche, data, size); // L'appel de la fonction boolean "value" avec en paramétre recherche, data et size
    */

    //printf("\n \n Debug : Le fichier contient %zu octets \n", size); // Il me semble que le "%zu" ne peut être utiliser qu'en compilant via gcc

    fclose(f); // On a fini avec le fichier, donc on le ferme, parce qu'il faut toujours fermer les fichiers, pske tg c kom sa.
    free(data); // On libère la mémoire qu'on avait demandé à l'OS vu qu'on en a plus besoin.

    return 0;
}
