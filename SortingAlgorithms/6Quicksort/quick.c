#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000


 
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
    int j;
	for (j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);  
	return (i + 1);
}

void quicksort(int Arr[], int low, int high)
{
	if (low < high) {
		// pi = Partition index
		int pi = partition(Arr, low, high);
		quicksort(Arr, low, pi - 1);
		quicksort(Arr, pi + 1, high);           
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
    quicksort(arr, 0, i - 1);
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