#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomtab[4];

void generate() {
    int num;
    for (int i = 0; i < 4; i++) {
        num = rand() % 6 + 1;
        randomtab[i] = num;
    }
}

void afficher(int tab[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void afficherlettre(int tab[], int size) {
    char tablettre[6] = {'P', 'B', 'M', 'Y', 'O', 'G'};
    char lettres[4];
    for (int i = 0; i < size; i++) {
        int index = tab[i] - 1;
        lettres[i] = tablettre[index];
    }
    for (int i = 0; i < size; i++) {
        printf("%c ", lettres[i]);
    }
    printf("\n");
}

int *inputlettre() {
    char char1, char2, char3, char4;
    char tablettre[6] = {'P', 'B', 'M', 'Y', 'O', 'G'};
    int chiffres[4];

    printf("Rentrez 4 lettres comprises dans : P, B, M, Y, O ,G\n");
    scanf(" %c %c %c %c", &char1, &char2, &char3, &char4);

    switch (char1) {
        case 'P': chiffres[0] = 1; break;
        case 'B': chiffres[0] = 2; break;
        case 'M': chiffres[0] = 3; break;
        case 'Y': chiffres[0] = 4; break;
        case 'O': chiffres[0] = 5; break;
        case 'G': chiffres[0] = 6; break;
        default: chiffres[0] = 0; break;
    }

    switch (char2) {
        case 'P': chiffres[1] = 1; break;
        case 'B': chiffres[1] = 2; break;
        case 'M': chiffres[1] = 3; break;
        case 'Y': chiffres[1] = 4; break;
        case 'O': chiffres[1] = 5; break;
        case 'G': chiffres[1] = 6; break;
        default: chiffres[1] = 0; break;
    }

    switch (char3) {
        case 'P': chiffres[2] = 1; break;
        case 'B': chiffres[2] = 2; break;
        case 'M': chiffres[2] = 3; break;
        case 'Y': chiffres[2] = 4; break;
        case 'O': chiffres[2] = 5; break;
        case 'G': chiffres[2] = 6; break;
        default: chiffres[2] = 0; break;
    }

    switch (char4) {
        case 'P': chiffres[3] = 1; break;
        case 'B': chiffres[3] = 2; break;
        case 'M': chiffres[3] = 3; break;
        case 'Y': chiffres[3] = 4; break;
        case 'O': chiffres[3] = 5; break;
        case 'G': chiffres[3] = 6; break;
        default: chiffres[3] = 0; break;
    }

    printf("Chiffres correspondants : ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", chiffres[i]);
    }
    printf("\n");

    int *tab = chiffres; // suppression des crochets pour créer un pointeur vers chiffres
    return tab;
}


void rangement(int tabmixresult[4], int nbcompare) {

    int i = 0, position;

    while(i<4){
        position = rand() % 4;   
        if (tabmixresult[position] == 5){
            tabmixresult[position] = nbcompare;   
            i = i+1;
            // printf("i");
        }
    }
  
    
    // char tablettre[3] = {'.', 'W', 'R'};
    // char lettres[4];
    // for (int i = 0; i < 4; i++) {
    //     int index = tabmixresult[i] - 1;
    //     lettres[i] = tablettre[index];
    // }
    // for (int i = 0; i < 4; i++) {
    //     printf("%c ", lettres[i]);
    // }
    // printf("\n");


    printf("Tableau final : ");
    for (i = 0; i < 4; i++) {
        printf("%d ", tabmixresult[i]);
    }
    printf("\n");

}

void compare(int tabjoueur[], int tabresult[]){
    int tabnomatch[4];
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if(tabjoueur[i] == tabresult [j]){
                tabnomatch[i] = 1;
                // printf("%d ", tabnomatch[i]);
            }
        }
    }
    for (int i=0; i<4; i++){
        if(tabjoueur[i] == tabresult [i]){
            tabnomatch[i] = 2;
            // printf("%d ", tabnomatch[i]);
        }
    }
    for (int i=0; i<4; i++){
        if(tabjoueur[i] != tabresult [i]){
            tabnomatch[i] = 0;
            // printf("%d ", tabnomatch[i]);
        }
    }
}


int main() {
    srand(time(NULL));
    generate();
    afficher(randomtab, 4);
    afficherlettre(randomtab, 4);
    inputlettre();
    int tab[4] = {5, 5, 5, 5};
    int *essaiejoueur = inputlettre();
    rangement(tab,2);
    compare(essaiejoueur, randomtab);
    return 0;
}
