#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 499999
#define MIN_VAL 1
#define MAX_VAL 499999

int main() {
    int  i;

    srand(time(NULL));

    int arr[ARRAY_SIZE];
    for(i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = (rand() * RAND_MAX + rand()) % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;
    }

    FILE *fp;
    fp = fopen("rnd.out", "w");

    for(i = 0; i < ARRAY_SIZE; i++) {
        fprintf(fp, "%d ", arr[i]);
    }

    fclose(fp);

    printf("Random array written to file successfully!\n");
    return 0;
}