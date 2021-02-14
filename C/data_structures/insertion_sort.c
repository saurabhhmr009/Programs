#include<stdio.h>

void insertion_sort(int arr[], int length){
	int i, j, key;
	for (i = 1; i < length; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
int main(void) {
	int i = 0;
	int arr[] = {10,9,6,90,60,70,2,12};
	int arr_length = 0;
	arr_length = sizeof(arr)/sizeof(int);
	insertion_sort(arr, arr_length);
	for (i = 0; i < arr_length; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
