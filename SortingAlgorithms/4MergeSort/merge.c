#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500000


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *) malloc(n1* sizeof(int));
    int *R = (int *) malloc(n2 * sizeof(int));
  
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
  
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
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
    mergeSort(arr, 0, i- 1);
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