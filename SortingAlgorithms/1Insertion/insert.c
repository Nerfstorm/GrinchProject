#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500000


void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    clock_t clkstart, clkend;
    FILE *fp;
    int num, i = 0;
    int arr[MAX_SIZE];

    fp = fopen("text.in", "r");
    if (fp == NULL) {
       printf("Could not open file");
       return 1;
    }

    while (fscanf(fp, "%d", &num) != EOF && i < MAX_SIZE) {
      arr[i++] = num;
    }
   
    clkstart = clock();
    insertionSort(arr, i);
    clkend = clock()-clkstart;

    double deltatime = ((double) clkend) / CLOCKS_PER_SEC;

    printf("\nCPU Time: %f s\n",deltatime);
    printf("Print array? (y/n)\n");
    char n; scanf("%c", &n);
    if(n=='y') printArray(arr, i);
    else printf("Fine...");
    
    fclose(fp);
    return 0;
}