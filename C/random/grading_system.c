#include <stdio.h>
#include <stdlib.h>

int* calculate_grade(int *arr, int length) {
    int next, i;
    for(i=0; i<length; i++) {
        if(*(arr+i) >=38) {
            if(*(arr+i)%5 != 0) {
                next = (*(arr+i)/5+1)*5;
                if((next - *(arr+i)) < 3) {
                    *(arr+i) = next;
                }
            }
        }
    }
    return arr;
}


int main(void) {
    int length, i;
    int *arr = NULL, *grade = NULL;
    
    scanf("%d", &length);
    arr = (int*)malloc(length*sizeof(int));
    for(i=0; i<length; i++) {
        scanf("%d", arr+i);
    }
    
    grade = calculate_grade(arr, length);
    for(i=0; i<length; i++) {
        printf("%d\n", *(grade+i));
    }

    return 0;
}
