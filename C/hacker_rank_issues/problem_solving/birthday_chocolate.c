#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int length;
    int *arr = NULL;
    int i, j, date, month, sum = 0, count = 0;
    
    scanf("%d", &length);
    arr = (int*)malloc(length*sizeof(int));
    for(i=0; i<length; i++){
        scanf("%d", arr+i);
    }
    scanf("%d %d", &date, &month);
    
    for(i=0; i<length-month+1; i++){
        for(j=i; j<i+month; j++) {
            sum += *(arr+j);
        }
        if(sum == date) {
            count++;
        }
        sum=0;
    }
    printf("%d", count);
    return 0;
}

