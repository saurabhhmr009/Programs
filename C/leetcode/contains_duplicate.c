#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmpFunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b );
}


bool containsDuplicate(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpFunc);
    for(int i = 0; i<numsSize-1; i++) {
        if(*(nums+i) == *(nums+i+1)) {
            return true;
        }
    }
    return false;
}

int main (void) {
    int *nums = NULL;
    int numsSize;
    bool result;

    scanf("%d", &numsSize);
    nums = (int*)malloc(numsSize*sizeof(*nums));
    for(int i=0; i<numsSize; i++) {
        scanf("%d", nums+i);
    }

    result = containsDuplicate(nums, numsSize);
    printf("%d\n", result);

    free(nums);
    nums = NULL;

    return 0;
}