#include<stdio.h>

void swap(int *x, int *y) {
	int temp_var;
	temp_var = *y;
	*y = *x;
	*x = temp_var;
}

void selection_sort(int arr[], int length){
	int i = 0, j = 0;
	int min_index;

	for(i = 0; i < length-1; i++) {
		min_index = i;
		for(j = i+1; j < length; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		printf("%d\n", min_index);
		swap(&arr[min_index], &arr[i]);
	}
}
int main(void) {
	int i = 0;
	int arr[] = {10,9,6,90,60,70,2,12};
	int arr_length = 0;
	arr_length = sizeof(arr)/sizeof(int);
	selection_sort(arr, arr_length);
	for (i = 0; i < arr_length; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
