#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[10] = {10,22,1,9,99,54,23,200,66,1000};
	int max_location = 0,second_max = 0, i;
	int max = arr[0], second = arr[0];


	for(i=1; i<10; i++) {
		if(max < arr[i]) {
			second = max;
			second_max = max_location;
			max = arr[i];
			max_location = i;
		}
	}
	printf("Max element %d at the location %d, second max %d with location %d\n", max, max_location, second, second_max);
	return 0;
}