#include <stdio.h>
#include <stdlib.h>

void rotateByone(int *arr, int size) {
    int temp = arr[0];
    int i;
    for(i=0; i<size-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[i] = temp;
}

void printLeft(int *arr, int size, int rotation) {
    int index;
    int start_point = rotation%size;

    for(int i=0; i<size; i++) {
        index = (start_point+i)%size;
        printf("%d ", *(arr+index));
    }
    printf("\n");
}

void rotateLeft(int *arr, int size, int rotation) {
    for(int i =0; i<rotation; i++) {
        rotateByone(arr, size);
    }

    for(int i=0; i<size; i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

int main(void) {
    int *arr = NULL, size, rotation;

    scanf("%d %d", &size, &rotation);
    arr = (int*)malloc(size*sizeof(int));
    for(int i=0; i<size; i++) {
        scanf("%d", arr+i);
    }
    //printLeft(arr, size, rotation);
    rotateLeft(arr, size, rotation);

    free(arr);
    arr = NULL;
    return 0;
}