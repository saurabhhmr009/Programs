#include <stdio.h>
#include <stdlib.h>

int cmpFunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maximumGap(int *nums, int numsSize) {
    int max_difference = 0, i, j = 1;
    if(numsSize < 2) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), cmpFunc);

    for(i=0; i<numsSize-1; i++, j++) {
        if(nums[j]-nums[i] > max_difference) {
            max_difference = nums[j]-nums[i];
            //printf("%d\n", max_difference);
        }
    }
    return max_difference;
}

int main(void) {
    int arr[4] = {3,6,9,1};
    int result = 0;

    result = maximumGap(arr, 4);
    printf("%d\n", result);
    return 0;
}