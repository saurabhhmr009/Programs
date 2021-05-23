#include <stdio.h>
#include <stdlib.h>

/* brute-force method------O(n^2)*/
/*int* twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int *ret_arr = NULL, i, j;

    *returnSize = 2;
    ret_arr = (int*)malloc(*returnSize*sizeof(*ret_arr));
    for(i=0; i<numsSize-1; i++) {
        for(j=i+1; j<numsSize; j++) {
            if(nums[i]+nums[j] == target) {
                ret_arr[0] = i;
                ret_arr[1] = j;
                break;
            }
        }
    }

    return ret_arr;
}*/

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

/* Efficient than brute-force, Only when it is mentioned things are sorted, calculate diff and then search for the item. O(nlog(n))*/
int* twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int *ret_arr = NULL, i, *item = NULL, diff;

    *returnSize = 2;
    ret_arr = (int*)malloc(*returnSize*sizeof(*ret_arr));
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    for(i=0; i<numsSize; i++) {
        diff = target - *(nums+i);
        item = (int*)bsearch(&diff, nums, numsSize, sizeof(int), cmpfunc);
        if(item != NULL) {
            ret_arr[0] = i;
            ret_arr[1] = ((long)item-(long)nums) / sizeof(int);
            break;
        }
    }
    return ret_arr;
}

int main(void) {
    int *arr = NULL, *returnSize = NULL, *new_arr = NULL;
    int arrSize, i, target;

    scanf("%d %d", &arrSize, &target);
    arr = (int*)malloc(arrSize*sizeof(*arr));
    returnSize = (int*)malloc(sizeof(*returnSize));
    for(i=0; i<arrSize; i++) {
        scanf("%d", arr+i);
    }

    new_arr = twoSum(arr, arrSize, target, returnSize);

    for(i=0; i<*returnSize; i++) {
        printf("%d ", *(new_arr+i));
    }
    printf("\n");
    return 0;
}