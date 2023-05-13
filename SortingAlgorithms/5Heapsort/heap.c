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

void heapify(int arr[], int N, int i)
{
    int largest = i;
 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    if (left < N && arr[left] > arr[largest])
        largest = left;
 
    if (right < N && arr[right] > arr[largest])
        largest = right;
 
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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
    heapSort(arr, i);
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