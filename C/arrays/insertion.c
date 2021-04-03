/* Program to insert an element in the array.
 */

#include <stdio.h>
#include <stdlib.h>

int* insertion(int *arr, int *length);
int* deletion(int *arr, int *length);

int main(void) {
    int *arr = NULL;
    int *length;
    int i;

    length = (int*)malloc(sizeof(int));
    printf("Enter the number of elements in the array: \n");
    scanf("%d", length);
    printf("Enter the elements: ");

    arr = (int*)malloc(*length*sizeof(int));
    for(i=0; i< *length; i++) {
        scanf("%d", arr+i);
    }

    /*if(insertion(arr, length) == NULL) {
        return -1;
    }*/
    if(deletion(arr, length) == NULL) {
        return -1;
    }
    else {
        for(i=0; i<*length; i++) {
            printf("%d ", *(arr+i));
        }
        printf("\n");
    }

    free(arr);
    free(length);
    return 0;
}


int* insertion(int *arr, int *length) {
    int position, i, data;

    printf("Enter the index where do you want to insert the element: \n");
    scanf("%d", &position);
    if((position > *length -1) || (position < 0)) {
        printf("Out of range.\n");
        return NULL;
    }

    printf("Enter the data to be inserted: \n");
    scanf("%d", &data);

    arr = (int*) realloc(arr, *length+1);
    *length += 1;
    for(i= *length -1; i>=position; i--) {
        *(arr+i) = *(arr+i-1);
    }
    *(arr+position) = data;

    return arr; 
}

int* deletion(int *arr, int *length) {
    int position, i;

    printf("Enter the location/index which you want to delete: \n");
    scanf("%d", &position);

    if((position < 0) ||(position > *length -1)) {
        printf("Invalid index.\n");
        return NULL;
    }

    for(i=position; i<*length-1; i++){
        *(arr+i) = *(arr+i+1);
    }

    *length -= 1;

    arr = (int*)realloc(arr, *length);
    return arr;
}