#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 500000

int main() {
    int  i,c;

    printf("Enter 1 for sorted and 2 for reversed\n");
    scanf("%d",&c);
    int arr[ARRAY_SIZE];
    if(c==1){
        for(i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i;
        }
    }else{
        for(i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = ARRAY_SIZE-i;
        }
    }


    FILE *fp;
    fp = fopen("list.out", "w");

    for(i = 0; i < ARRAY_SIZE; i++) {
        fprintf(fp, "%d ", arr[i]);
    }

    fclose(fp);

    printf("Sorted array written to file successfully!\n");
    return 0;
}