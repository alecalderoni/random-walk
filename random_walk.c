#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numero_passi() {

    int passi;

    do {
        printf("Inserire numero di passi:\n");
        scanf("%d", &passi);
    } while ( passi < 1000 || passi > 100000);

    return passi;
}

void move(int *pos) {
    int x = lrand48() % 4 + 1;
    if (x == 1) { 
        pos[0] += 1; 
    }
    else if (x == 2) {
        pos[1] -= 1;
    }
    else if (x == 3) {
        pos[0] -= 1;
    }
    else if (x == 4) {
        pos[1] += 1;
    }
}

int main() {

    srand48(time(NULL));

    int passi = numero_passi();

    int pos[2] = {0};

    FILE *output = fopen("walk.dat", "w");

    fprintf(output, "%d %d\n", pos[0], pos[1]);

    for (int i = 0; i < passi; i++){

        move(pos);

        fprintf(output, "%d %d\n", pos[0], pos[1]);

    }

    fclose(output);

    return 0;
}