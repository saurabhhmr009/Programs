/* Given an integer array nums, find the contiguous subarray (containing at least one number) 
 * which has the largest sum and return its sum.
 */



int maxSubArray(int* nums, int numsSize){
    int i, max = nums[0], temp;
    
    for (i = 0, temp = 0; i < numsSize; i++) {
        if(temp >= 0)
            temp += nums[i];
        else
            temp = nums[i];
        if(temp > max)
            max = temp;
    }
    return max;
}
