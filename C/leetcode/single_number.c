#include <stdio.h>
#include <stdlib.h>

int singleNumber(int *nums, int numsSize) {
    int result = 0;
    if(numsSize == 1) {
        return *nums;
    }

    for(int i=0; i<numsSize; i++) {
        result = result ^ *(nums+i);
    }
    return result;
}

int main(void) {
    int *nums = NULL;
    int numsSize, result;

    scanf("%d", &numsSize);
    nums = (int*)malloc(numsSize*sizeof(*nums));
    for(int i=0; i<numsSize; i++) {
        scanf("%d", nums+i);
    }

    result =  singleNumber(nums, numsSize);
    printf("%d\n", result);
    return 0;
}