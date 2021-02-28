/* Program to calculate the max and min sum in the arrays.
 */


#include <stdio.h>
#include <stdlib.h>

void max_min(int *arr, int size) {
    int i, j;
    long int max_sum = 0, min_sum = 0;
    for(i=0; i<size; i++) {
        for(j=0; j<size-i-1; j++){
            if(*(arr+j) > *(arr+j+1)) {
                *(arr+j) = *(arr+j) ^ *(arr+j+1);
                *(arr+j+1) = *(arr+j) ^ *(arr+j+1);
                *(arr+j) = *(arr+j) ^ *(arr+j+1);
            }
        }
    }
    for(i=1; i<size; i++) {
        max_sum += *(arr+i);
    }
    for(i = 0; i<size-1; i++) {
        min_sum += *(arr+i);
    }
    printf("%ld %ld\n", min_sum, max_sum);
}

int main(void) {
    int *arr = NULL;
    int size, i;
    
    scanf("%d", &size);
    arr = (int*)malloc(size*sizeof(int));
    for(i=0; i<size; i++) {
        scanf("%d", arr+i);
    }
    max_min(arr, size);
    return 0;
}
