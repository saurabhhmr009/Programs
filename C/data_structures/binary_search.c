#include <stdio.h>
#include <stdlib.h>

int binary_search(int left, int right, int *arr, int num) {
    int mid_index;
    if(left >= right) {
        mid_index = left + (right-left)/2;
        if(*(arr+mid_index) == num) {
            return mid_index;
        }
        if(*(arr+mid_index) < num) {
            printf("again\n");
            return binary_search(0, mid_index-1, arr, num);
        }
        if(*(arr+mid_index) > num) {
            return binary_search(mid_index+1, right, arr, num);
        }
        printf("Test\n");
    }
    return -1;
}

int main(void) {
    int length, i, result, num = 95;
    int *arr = NULL;
    
    scanf("%d", &length);
    arr = (int*)malloc(length*sizeof(int));
    for(i=0; i<length; i++) {
        scanf("%d", arr+i);
    }
    result = binary_search(0, length-1, arr, num);
    printf("%d\n", result);
    return 0;
}
