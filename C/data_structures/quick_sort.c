/* Quick sort in C.
 */

#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *arr, int left, int right) {
    int i, j, pivot, temp;
 
    if(left < right) {
        pivot = left;
        i = left;
        j = right;

        while(i < j) {
            while((*(arr+i) <= *(arr+pivot)) && (i < right)) {
                i++;
            }
            while((*(arr+j) >= *(arr+pivot)) && (j > left)) {
                j--;
            }

            if(i < j) {
                temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
        }

        // Point to split the array is found.
        temp = *(arr+j);
        *(arr+j) = *(arr+pivot);
        *(arr+pivot) = temp;

        // Sort the left and right half of the array.
        quick_sort(arr, left, j-1);
        quick_sort(arr, j+1, right);
    }
}

int main(void) {
    int *arr = NULL;
    int length, i;

    printf("Enter the length of the array: \n");
    scanf("%d", &length);

    arr = (int*)malloc(length*sizeof(int));
    for(i=0; i<length; i++) {
        scanf("%d", arr+i);
    }

    quick_sort(arr, 0, length-1);

    for(i=0; i<length; i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");

    free(arr);
    return 0;
}