#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[10] = {10,22,1,100,99,54,23,200,66,90};
	int location = 0, i;
	int max = arr[0];

	for(i=1; i<10; i++) {
		if(max < arr[i]) {
			max = arr[i];
			location = i;
		}
	}
	printf("Max element %d at the location %d\n", max, location);
	return 0;
}