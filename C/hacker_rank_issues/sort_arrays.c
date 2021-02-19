#include <stdio.h>
#include <stdlib.h>

void duplicate(int *arr, int length) {
    int *occurence = NULL;
    int i, j;
    occurence = (int*)calloc(length,sizeof(int));
    
    for(i=0; i<length; i++) {
        for(j=i+1; j<length; j++) {
            if (*(arr+i) == *(arr+j)) {
                *(occurence+i) += 1;
            }
        }
    }
    
    for(i=0;i<length;i++) {
        printf("%d\n", *(occurence+i));
    }
}


int main(void) {
    int *arr = NULL;
    int length, i;
    int acending = 1, decending = 1;
    
    scanf("%d", &length);
    
    arr = (int*)malloc(length*sizeof(int));
    //occurence = (int*)calloc(length, sizeof(int));
    
    for(i=0; i<length; i++) {
        scanf("%d", arr+i);
    }
    
    i = 0;
    while(i < length-1) {
        if(*(arr+i) < *(arr+i+1)) {
            decending = 0;
        }
        else if(*(arr+i) > *(arr+i+1)) {
            acending = 0;
        }
        i++;
    }
    if(acending == 1) {
        printf("The array is in the acending order\n");
    }
    else if(decending == 1) {
        printf("The array is in the decending order\n");
    }
    else {
        printf("It is an unsorted array\n");
    }
    duplicate(arr, length);

    return 0;
}
            
            
