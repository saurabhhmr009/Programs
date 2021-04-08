#include <stdio.h>
#include <stdlib.h>

int* bubble_sort(int *arr, int size) {
    int i, j;
    for(i=0; i<size; i++) {
        for(j = i; j<size -1; j++) {
            // Swaping using XOR
            if(*(arr+i) > *(arr+j+1)) {
                *(arr+i) = *(arr+i) ^ *(arr+j+1);
                *(arr+j+1) = *(arr+i) ^ *(arr+j+1);
                *(arr+i) = *(arr+i) ^ *(arr+j+1);
            }
        }
    }
    return arr;
}

int binary_search(int *arr, int start, int end, int data) {
    int mid;

    while(end >= start) {
        mid  = start + (end - start)/2;
        if(*(arr+mid) == data) {
            return mid;
        }

        if(*(arr+mid) > data) {
            end = mid -1;
            return binary_search(arr, start, end, data);
        }
        else {
            start = mid+1;
            return binary_search(arr, start, end, data);
        }
    }

    return -1;
}

int main(void) {
    int *arr;
    int i, length, data, result;

    scanf("%d", &length);
    arr = (int*)malloc(length*sizeof(int));

    for(i=0; i<length; i++) {
        scanf("%d", arr+i);
    }

    arr = bubble_sort(arr, length);

    printf("Enter the data to be searched: \n");
    scanf("%d", &data);
    result = binary_search(arr, 0, length -1, data);

    if(result == -1) {
        printf("Data not found in the array.\n");
    }
    else {
        printf("Data found at location: %d\n", result);
    }

    free(arr);
    return 0;
}