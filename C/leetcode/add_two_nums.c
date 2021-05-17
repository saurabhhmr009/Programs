/*Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.
 */



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *new_arr = NULL, i, j;
    
    *returnSize = 2;
    new_arr = (int*)calloc(*returnSize, sizeof(int));
    
    for(i=0; i<numsSize-1; i++){
        for(j=i+1; j<numsSize; j++) {
            if(nums[i]+nums[j] == target) {
                new_arr[0] = i;
                new_arr[1] = j;
                break;
            }
        }
    }
    return new_arr;
}
