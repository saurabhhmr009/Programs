#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int length, i, j;
    int rotate;
    
    int *arr = NULL;
    int temp;
    scanf("%d", &length);
    scanf("%d", &rotate);
    arr = (int*)malloc(length*sizeof(int));
    
    for(i=0; i<length; i++) {
        scanf("%d", arr+i);
    }
    
    for (i=0; i<rotate; i++) {
        int first = *(arr+i);
        for(j=0; j<length-1; j++) {
            *(arr+j) = *(arr+j+1);
        }
        *(arr+length-1) = first;
    }
    for(i=0; i<length; i++) {
        printf("%d", *(arr+i));
    }
    
    free(arr);
    arr = NULL;
    return 0;
}
