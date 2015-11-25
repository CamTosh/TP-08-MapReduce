#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ************
*      _   ___
*     ( `︷` ))
*     |      ||
*     |      ||
*     '------'`
 ************ */

int main(){
    char mot[255][255];
    char tmp[255];
    int i = 0;
    int j = 0;
    int k = 0; 
    int l = 0;
    int count; 

    char data[255] = "toast toast toast to to to jean to jean roger roger";
    data[strlen(data) - 1] = '\0'; // http://www.tutorialspoint.com/c_standard_library/c_function_strlen.htm

    // Le foutoir complet
    while (data[i] != '\0'){

        if (data[i] == ' '){
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

    // La partie de trie
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
    // On trouve la fréquence d'apparition et on affiche le resultat
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
    return 0;
}

