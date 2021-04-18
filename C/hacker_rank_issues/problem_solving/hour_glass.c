#include <stdio.h>
#include <stdlib.h>

int max_sum(int **arr) {
    int i, j, result = -111111, temp = 0;
    for(i=0; i<4; i++) {
        for(j=0; j<4; j++) {
            temp = *(arr[i]+j) + *(arr[i]+j+1) + *(arr[i]+j+2) + *(arr[i+1]+j+1) + *(arr[i+2]+j) + *(arr[i+2]+j+1) + *(arr[i+2]+j+2);
            if(temp > result) {
                result = temp;
            }
        }
    }
    return result;
}

int main(void) {
    int **arr = NULL;
    int i, j, result;

    arr = (int**)malloc(6*sizeof(int*));
    for(i=0; i<6; i++) {
        arr[i] = (int*)malloc(6*sizeof(int));
        for(j=0; j<6; j++) {
            scanf("%d", arr[i]+j);
        }
    }

    result = max_sum(arr);
    printf("%d\n", result);

    for(i=0; i<6; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
    return 0;
}