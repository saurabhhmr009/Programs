#include<stdio.h>

void swap(int *x, int *y) {
	int temp = *y;
	*y = *x;
	*x = temp;
}

void bubble_sort(int arr[], int length) {
	int i;
	int j;
	for (i = 0; i < length -1; i++) {
		for (j=0; j < length-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}


int main(void) {
	int z;
	int arr[] = {10,1,20,40,50,15,13};
	int arr_length = sizeof(arr)/sizeof(int);
	bubble_sort(arr, arr_length);
	printf("%d\n", arr_length);
	for( z=0; z < arr_length; z++) {
		printf("%d\n", arr[z]);
	}
	return 0;
}
