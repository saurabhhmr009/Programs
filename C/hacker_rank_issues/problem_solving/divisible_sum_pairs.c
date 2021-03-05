#include <stdio.h>
#include <stdlib.h>

int cal_pairs(int *arr, int length, int k) {
    int i, j;
    int count = 0;
    for(i=0; i<length-1; i++) {
        for(j=i+1; j<length; j++) {
            if((*(arr+i)+ *(arr+j))%k == 0) {
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    int length, k, pairs, i;
    int *arr = NULL;
    
    scanf("%d %d", &length, &k);
    arr = (int*)malloc(length*sizeof(int));
    for(i=0; i<length; i++) {
        scanf("%d", arr+i);
    }
    pairs = cal_pairs(arr, length, k);
    printf("%d\n", pairs);
    return 0;
}
