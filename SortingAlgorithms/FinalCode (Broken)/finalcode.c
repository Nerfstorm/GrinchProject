#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_VAL 1
#define MAX_VAL 999999

double Bubbleavg[10], Insertavg[10], Selectavg[10], Heapavg[10], Mergeavg[10], Quickavg[10];
 
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
    int num, i,j,c;
    int arr1k[1000], arr10k[10000], arr100k[100000], arr1m[1000000];
    srand(time(NULL));
    
    for(i = 1000; i<=1000000; i*=10){
        printf("For arrays of %d ellements:\n", i);
        for(c = 0; c<10; c++){
            switch (i){
            case 1000:
            
                for(j = 0; j < i; j++) {
                    arr1k[j] = (rand() * RAND_MAX + rand()) % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;}
                
    
                clkstart = clock();
                bubbleSort(arr1k, i);
                clkend = clock()-clkstart;
                Bubbleavg[c] = ((double) clkend) / CLOCKS_PER_SEC;
                printf("CPU Time %d elements bubble Sort %d: %f\n" ,i,c,((double) clkend) / CLOCKS_PER_SEC);

                clkstart = clock();
                insertionSort(arr1k, i);
                clkend = clock()-clkstart;
                Insertavg[c] = ((double) clkend) / CLOCKS_PER_SEC;
                printf("CPU Time %d elements insertion Sort %d: %f\n" ,i,c,((double) clkend) / CLOCKS_PER_SEC);

                clkstart = clock();
                selectionSort(arr1k, i);
                clkend = clock()-clkstart;
                Selectavg[c] = ((double) clkend) / CLOCKS_PER_SEC;
                printf("CPU Time %d elements selection Sort %d: %f\n" ,i,c,((double) clkend) / CLOCKS_PER_SEC);

                clkstart = clock();
                heapSort(arr1k, i);
                clkend = clock()-clkstart;
                Heapavg[c] = ((double) clkend) / CLOCKS_PER_SEC;
                printf("CPU Time %d elements heap Sort %d: %f\n" ,i,c,((double) clkend) / CLOCKS_PER_SEC);

                clkstart = clock();
                mergeSort(arr1k,0, i-1);
                clkend = clock()-clkstart;
                Mergeavg[c] = ((double) clkend) / CLOCKS_PER_SEC;
                printf("CPU Time %d elements merge Sort %d: %f\n" ,i,c,((double) clkend) / CLOCKS_PER_SEC);

                clkstart = clock();
                quicksort(arr1k,0, i-1);
                clkend = clock()-clkstart;
                Quickavg[c] = ((double) clkend) / CLOCKS_PER_SEC;
                printf("CPU Time %d elements quick Sort %d: %f\n" ,i,c,((double) clkend) / CLOCKS_PER_SEC);
                break;
            
            case 10000:
                for(int j = 0; j < i; j++) {
                    arr10k[j] = (rand() * RAND_MAX + rand()) % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;}
                //sortmanager(arr10k,i);
                break;
            
            case 100000:
                for(int j = 0; j < i; j++) {
                    arr100k[j] = (rand() * RAND_MAX + rand()) % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;}
                //sortmanager(arr100k,i);
                break;

            case 1000000:
                for(int j = 0; j < i; j++) {
                    arr1m[j] = (rand() * RAND_MAX + rand()) % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;}
                //sortmanager(arr1m,i);
                break;
            default:
                break;
            }
        }
    }
    return 0;
    }
