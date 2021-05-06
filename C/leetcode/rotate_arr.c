/* Rotate array right by K */

#include <stdlib.h>
#include <stdio.h>

void reverse_array(int *nums, int start, int end) {
    while(start<end) {
        *(nums+start) = *(nums+start) ^ *(nums+end);
        *(nums+end) = *(nums+end) ^ *(nums+start);
        *(nums+start) = *(nums+start) ^ *(nums+end);
        start++;
        end--;
    }
}

void rotate(int *nums, int numsSize, int k) {
    int i;
    
    if((k < 0) || (numsSize == 1)) {
        printf("%d ", *nums);
        return;
    }

    if(k > numsSize) {
        k = k%numsSize;
    }

    reverse_array(nums, 0, numsSize-1);
    reverse_array(nums, 0, k-1);
    reverse_array(nums, k, numsSize-1);
    for(i = 0; i<numsSize; i++) {
        printf("%d ", *(nums+i));
    }
    printf("\n");
}

int main(void) {
    int *nums = NULL;
    int numsSize, k, i;

    scanf("%d %d", &numsSize, &k);
    //scanf("%d", &k);
    nums = (int*)malloc(numsSize*sizeof(*nums));
    for(i = 0; i<numsSize; i++) {
        scanf("%d", nums+i);
    }
    //k = 3;
    rotate(nums, numsSize, k);
    /*for(i = 0; i<numsSize; i++) {
        printf("%d", *(nums+i));
    }*/

    free(nums);
    nums = NULL;
    return 0;
}
