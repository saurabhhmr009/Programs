#include <stdio.h>
#include <stdlib.h>

int* plusOne(int *digits, int digitsSize, int *returnSize) {
    int i;

    //*returnSize = digitsSize;
    for(i = digitsSize-1; i>=0; i--) {
        if(*(digits+i) == 9) {
            *(digits+i) = 0;
        }
        else {
            *(digits+i) += 1;
            return digits;
        }
    }

    int *new_arr = (int*)calloc(digitsSize+1, sizeof(int));
    *(new_arr) = 1;
    *returnSize = digitsSize+1;

    return new_arr;
}


int main(void) {
    int *digits = NULL, *returnSize = NULL, *final = NULL;
    int digitsSize;

    scanf("%d", &digitsSize);
    digits = (int*)malloc(digitsSize*sizeof(int));
    returnSize = (int*)calloc(1, sizeof(int));
    for(int i=0; i<digitsSize; i++) {
        scanf("%d", digits+i);
    }

    final = plusOne(digits, digitsSize, returnSize);
    for(int i=0; i<=digitsSize; i++) {
        printf("%d ", *(final+i));
    }
    printf("\n");
    return 0;
}