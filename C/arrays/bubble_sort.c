#include <stdio.h>
#include <stdlib.h>

int* bubble_sort(int *arr, int size) {
    int i, j;
    for(i=0; i<size; i++) {
        for(j = i; j<size -1; j++) {
            // Swaping using XOR
            if(*(arr+i) > *(arr+j+1)) {
                *(arr+i) = *(arr+i) ^ *(arr+j+1);
                *(arr+j+1) = *(arr+i) ^ *(arr+j+1);
                *(arr+i) = *(arr+i) ^ *(arr+j+1);
            }
        }
    }
    return arr;
}


int main(void) {
    int *arr = NULL;
    int size, i;

    printf("Enter the number of elements you want in the array: \n");
    scanf("%d", &size);

    printf("Enter the elements of the array: \n");
    arr = (int*)malloc(size*sizeof(int));
    for(i=0; i<size; i++) {
        scanf("%d", arr+i);
    }

    arr = bubble_sort(arr, size);

    for(i=0; i<size; i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");

    free(arr);
    return 0;
}