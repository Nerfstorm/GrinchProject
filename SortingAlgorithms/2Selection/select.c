#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500000


 
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
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
    selectionSort(arr, i);
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