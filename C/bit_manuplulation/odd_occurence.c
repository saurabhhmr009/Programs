/* Given a set of numbers where all elements occur even number of times except one number, find the odd occurring number */

#include<stdio.h>

/*int find_odd(int arr[], int size) {
	int i, res = 0;
	for (i = 0; i < size; i++){
	       res ^= arr[i];
	       printf("%d\n", res);
	}
        return res;
}*/

void find_odd(int arr[], int size) {
	int init_arr = arr[0];
	int i;
	int x = 0, y = 0;
	for (i = 1; i < size; i++){
		init_arr ^= arr[i];
	}

	for (i = 0; i < size; i++) {
		if (arr[i] & init_arr)
			x ^= arr[i];
		else
			y ^= arr[i];
	}
	printf("\n The two ODD elements are %d & %d ", x, y);
}

int main(void) {
	int arr[] = {12, 12, 13, 13, 14, 15, 15, 15, 14, 14};
	int n = sizeof(arr) / sizeof(arr[0]);
	//printf("The odd occurring element is %d\n", find_odd(arr, n));
	find_odd(arr, n);
	return 0;
}
