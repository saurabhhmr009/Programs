/* given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in the list. One of the integers is missing in the list. Write an efficient code to find the missing integer.*/

#include <stdio.h>

int miss (int arr[], int size) {
	int i, missing;
	int x1 = arr[0], x2 = 1;

	for (i = 1; i < size; i++) {
		x1 ^= arr[i];
	}
	for (i = 0; i <= size ; i++) {
		x2 ^= arr[i];
	}
	missing = x1 ^ x2;
	return missing;
}


int main (void) {
	int arr[] = {1, 2, 3, 4, 6, 7, 9, 8, 10, 11, 13, 12};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Missing Number is %d\n", miss(arr, size));
	return 0;
}
