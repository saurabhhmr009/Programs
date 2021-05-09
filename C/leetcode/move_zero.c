#include <stdio.h>
#include <stdlib.h>

void moveZeros(int *nums, int numsSize) {
    int i, j = 0;
    for(i = 0; i<numsSize; i++) {
        if(*(nums+i) != 0) {
            *(nums+(j++)) = *(nums+i);
        }
    }
    for(; j<numsSize; j++) {
        *(nums+j) = 0;
    }
    for(i = 0; i<numsSize; i++) {
        printf("%d ", *(nums+i));
    }
    printf("\n");
}

int main(void) {
    int *nums = NULL;
    int numsSize;

    scanf("%d", &numsSize);
    nums = (int*)malloc(numsSize*sizeof(*nums));
    for(int i=0; i<numsSize; i++) {
        scanf("%d", nums+i);
    }

    moveZeros(nums, numsSize);

    free(nums);
    nums = NULL;
    return 0;
}