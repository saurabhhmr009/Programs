#include <stdio.h>
#include <stdlib.h>

#define HASHSIZE 1000
/*int k = 0;

int cmpFunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* findNum(int *secArr, int *priArr, int secSize, int priSize) {
    int *new_arr = NULL, *item = NULL;
    //int k = 0;
    
    new_arr = (int*)malloc(priSize*sizeof(int));
    for(int i=0; i<priSize; i++) {
        item = (int*)bsearch(priArr+i, secArr, secSize, sizeof(int), cmpFunc);
        if(item != NULL){
            *(new_arr+k) = *item;
            k++;
        }
    }

    new_arr = (int*)realloc(new_arr, k);

    
    return new_arr;
}

int* intersect(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int *result_arr = NULL;

    qsort(nums1, nums1Size, sizeof(int), cmpFunc);
    qsort(nums2, nums2Size, sizeof(int), cmpFunc);

    if(nums1Size > nums2Size) {
        result_arr = findNum(nums1, nums2, nums1Size, nums2Size);
    }
    else if (nums1Size < nums2Size) {
        result_arr = findNum(nums2, nums1, nums2Size, nums1Size);
    }
    else {
        result_arr = findNum(nums1, nums2, nums2Size, nums2Size);
    }

    return result_arr;
}*/

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *hash_arr = NULL, *ret_arr = NULL, i = 0, j = 0, ret_size, key;

    hash_arr = (int*)calloc(HASHSIZE, sizeof(int));
    ret_size = nums1Size < nums2Size ? nums1Size:nums2Size;
    ret_arr = (int*)malloc(ret_size*sizeof(int));

    while(i < nums1Size) {
        key = get_hash(nums1[i]);
        hash_arr[key] += 1;
        i++;
    }

    i = 0;
    while(i < nums2Size) {
        key = get_hash(nums2[i]);
        if(hash_arr[key] > 0) {
            ret_arr[j] = key;
            hash_arr[key] = 0;
            j++;
        }
        i++;
    }
    *returnSize = j;
    return ret_arr;
}


int main(void) {
    int *nums1 = NULL, *nums2 = NULL, *final_arr = NULL;
    int nums1Size, nums2Size, i;

    scanf("%d %d", &nums1Size, &nums2Size);
    nums1 = (int*)malloc(nums1Size*sizeof(int));
    nums2 = (int*)malloc(nums2Size*sizeof(int));
    for(i=0; i<nums1Size; i++) {
        scanf("%d", nums1+i);
    }

    for(i=0; i<nums2Size; i++) {
        scanf("%d", nums2+i);
    }

    final_arr = intersect(nums1, nums1Size, nums2, nums2Size);
    for(int i=0; i<k; i++) {
        printf("%d ", *(final_arr+i));
    }

    free(nums1);
    free(nums2);
    nums1 = NULL;
    nums2 = NULL;

    return 0;
}
