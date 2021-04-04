#include <stdio.h>
#include <stdlib.h>

void linear_search(int *arr, int length) {
    int i, data;
    printf("The number to be searched: \n");
    scanf("%d", &data);

    for(i=0; i<length; i++) {
        if(*(arr+i) == data) {
            printf("Found at location %d\n", i);
            return;
        }
    }
    printf("Not found.\n");
}

int main(void) {
    int *arr = NULL;
    int i, length;

    scanf("%d", &length);
    arr = (int*)malloc(length*sizeof(int));
    for(i=0; i<length; i++) {
        scanf("%d", arr+i);
    }

    linear_search(arr, length);

    free(arr);
    return 0;
}