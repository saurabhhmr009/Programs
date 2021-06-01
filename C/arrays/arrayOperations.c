#include <stdio.h>
#include <stdlib.h>

void searchOperation(int *arr, int *size) {
    int data;

    printf("Enter the data to be searched: \n");
    scanf("%d", &data);

    for(int i=0; i<*size; i++) {
        if(arr[i] == data) {
            printf("Data found at location %d\n", i);
            return;
        }
    }
    printf("Data not found in the given array\n");
}

void addOperation(int *arr, int *size) {
    int data;

    printf("Enter the data to add: \n");
    scanf("%d", &data);

    *size += 1;
    arr = (int*)realloc(arr, *size);
    *(arr+(*(size)-1)) = data;

    printf("New Array: ");
    for(int i=0; i<*size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertOperation(int *arr, int *size) {
    int data, location;

    printf("Enter the location at which data to insert: \n");
    scanf("%d %d", &location, &data);

    *size += 1;
    arr = (int*)realloc(arr, *size);

    for(int i=*size-1; i>=location; i--) {
        *(arr+i) = *(arr+i-1);
    }

    *(arr+location) = data;

    printf("New Array: ");
    for(int i=0; i<*size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deleteOperation(int *arr, int *size) {
    int location;

    printf("Enter the location whose data you wish to delete: \n");
    scanf("%d", &location);

    for(int i=location; i<*size-1; i++) {
        *(arr+i) = *(arr+i+1);
    }

    *size -= 1;
    //arr = (int*)realloc(arr, *size);

    printf("New Array: ");
    for(int i=0; i<*size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int *size = NULL, *arr = NULL;

    size = (int*)malloc(sizeof(*size));
    scanf("%d", size);
    arr = (int*)malloc(*size*sizeof(*arr));
    for(int i=0; i<*size; i++) {
        scanf("%d", arr+i);
    }

    searchOperation(arr, size);
    printf("++++++++++++++++\n");
    addOperation(arr, size);
    printf("++++++++++++++++\n");
    insertOperation(arr, size);
    printf("++++++++++++++++\n");
    deleteOperation(arr, size);

    free(arr);
    arr = NULL;
    return 0;
}