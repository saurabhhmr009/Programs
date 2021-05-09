#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j, *return_arr = NULL;
    *returnSize = 2;
    return_arr = (int*)malloc(*returnSize*sizeof(int));

    for(i=0; i<numsSize-1; i++) {
        for(j=i+1; j<numsSize; j++) {
            if(*(nums+i) + *(nums+j) == target) {
                *(return_arr+0) = i;
                *(return_arr+1) = j;
                break;
            }
        }
    }
    return return_arr;
}

int main(void) {
    int *nums = NULL, *final = NULL, *returnSize = NULL;
    int numsSize, target;

    scanf("%d %d", &numsSize, &target);

    nums = (int*)malloc(numsSize*sizeof(*nums));
    for(int i=0; i<numsSize; i++) {
        scanf("%d", nums+i);
    }

    final = twoSum(nums, numsSize, target, returnSize);
    return 0;
}