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


int* inputlettre() {
    char char1, char2, char3, char4;
    char tablettre[6] = {'P', 'B', 'M', 'Y', 'O', 'G'};
    int* chiffres = malloc(4 * sizeof(int)); // Allocation dynamique

    printf("Rentrez 4 lettres comprises dans : P, B, M, Y, O, G\n");
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

    return chiffres;
}

void rangement(int tabmixresult[4], int nbcompare) {
    int positions[4] = {-1, -1, -1, -1};
    for (int i = 0; i < 4; i++) {
        int position;
        do {
            position = rand() % 4;
        } while (positions[position] != -1);
        positions[position] = i;
    }
    int mixresult[4];
    for (int i = 0; i < 4; i++) {
        mixresult[positions[i]] = tabmixresult[i];
    }
    for (int i = 0; i < 4; i++) {
        tabmixresult[i] = mixresult[i];
    }
}

void compare(int tabjoueur[], int tabresult[]) {
    int bon = 0;
    int presquebon = 0;

    // recherche des chiffres bien placés
    for (int i = 0; i < 4; i++) {
        if (tabjoueur[i] == tabresult[i]) {
            bon++;
            tabresult[i] = 0; // pour éviter de compter deux fois un chiffre
        }
    }

    // recherche des chiffres mal placés
    for (int i = 0; i < 4; i++) {
        if (tabjoueur[i] != 0) { // pour éviter de compter deux fois un chiffre
            for (int j = 0; j < 4; j++) {
                if (tabjoueur[i] == tabresult[j]) {
                    presquebon++;
                    tabresult[j] = 0; // pour éviter de compter deux fois un chiffre
                    break; // on sort de la boucle interne
                }
            }
        }
    }

    printf("Vous avez %d chiffre(s) bien place(s) et %d chiffre(s) mal place(s).\n", bon, presquebon);
}


int main() {
    srand(time(NULL));
    generate();
    int *randomptr = randomtab; // pointer to the array of random numbers

    printf("Le jeu du Mastermind commence !\n");
    printf("Le but est de trouver le nombre généré par l'ordinateur.\n");
    printf("Les chiffres sont compris entre 1 et 6, et il y a 4 chiffres.\n");

    int numtries = 0;
    bool found = false;
    while (numtries < 10 && !found) {
        printf("Tentative n°%d : \n", numtries + 1);

        int *playerptr = inputlettre(); // pointer to the array of player's numbers
        afficherlettre(playerptr, 4);

        int mixresult[4] = {5, 5, 5, 5};
        int goodplaces = 0, goodnumbers = 0;

        for (int i = 0; i < 4; i++) {
            if (randomptr[i] == playerptr[i]) {
                mixresult[i] = 2;
                goodplaces++;
            }
            else {
                for (int j = 0; j < 4; j++) {
                    if (randomptr[i] == playerptr[j] && mixresult[j] == 5) {
                        mixresult[j] = 1;
                        goodnumbers++;
                        break;
                    }
                }
            }
        }
        rangement(mixresult, goodplaces);

        printf("Résultat : ");
        for (int i = 0; i < 4; i++) {
            if (mixresult[i] == 2)
                printf("X ");
            else if (mixresult[i] == 1)
                printf("O ");
            else
                printf(". ");
        }
        printf("\n");

        if (goodplaces == 4) {
            found = true;
            printf("Félicitations, vous avez trouvé le nombre mystère en %d coups !\n", numtries + 1);
        }

        numtries++;
    }

    if (!found)
        printf("Dommage, vous avez perdu ! Le nombre était : ");
    afficherlettre(randomptr, 4);

    return 0;
}
