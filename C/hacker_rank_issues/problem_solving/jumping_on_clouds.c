#include <stdio.h>
#include <stdlib.h>

int min_jumps(int *arr, int length) {
    int result = 0, i = 0;
    while(1) {
        if(i >= length -1) {
            break;
        }
        if(*(arr+i+2) != 1) {
            result++;
            i += 2;
            continue;
        }
        if(*(arr+i+1) != 1) {
            result++;
            i++;
            continue;
        }
    }
    return result;
}

int main(void) {
    int *arr = NULL;
    int length, i, result;

    scanf("%d", &length);
    arr = (int*)malloc(length*sizeof(length));

    for(i=0; i<length; i++) {
        scanf("%d", arr+i);
    }

    result = min_jumps(arr, length);
    printf("%d\n", result);

    free(arr);
    arr = NULL;
    return 0;
}