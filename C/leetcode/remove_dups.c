/* Remove duplicates from a sorted int array. */

#include <stdio.h>
#include <stdlib.h>

int remove_dups(int *arr, int length) {
    int i, j = 0;
    if(length == 0) {
        return j;
    }

    for(i=0; i<length-1; i++) {
        if(*(arr+i) != *(arr+i+1)) {
            *(arr+j) = *(arr+i);
            j++;
        }
    }
    *(arr+(j++)) = *(arr+length-1);
    return j;
}

int main(void) {
    int *arr = NULL;
    int i, length, new_length;

    scanf("%d", &length);
    arr = (int*)malloc(length*(sizeof(*arr)));
    for(i = 0; i<length; i++) {
        scanf("%d", arr+i);
    }

    new_length = remove_dups(arr, length);
    for(i=0; i< new_length; i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");
    free(arr);
    arr = NULL;
    return 0;
}
