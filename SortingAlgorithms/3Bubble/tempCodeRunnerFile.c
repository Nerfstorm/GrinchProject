#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9999


 
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
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
    bubbleSort(arr, i);
    clkend = clock()-clkstart;

    double deltatime = ((double) clkend) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");
    printArray(arr, i);
    printf("\nEstimated Time: %f s",deltatime);
    
    fclose(fp);
    return 0;
}