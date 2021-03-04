#include <stdio.h>
#include <stdlib.h>

void print_reverse(int *arr_ptr, int size) {
	int i;
	for(i = size -1; i>=0; i--) {
		printf("%d ", *(arr_ptr+i));
	}
}


int main(void)
{
	int size, i;
	int *arr;
	
	scanf("%d", &size);
	if((size<1) && (size>1000)){
		return 1;
	}
	
	arr = (int*)calloc(size, sizeof(int));
	
	for(i=0; i<size; i++) {
		scanf("%d", (arr+i));
		if((*(arr+i)<1) && (*(arr+i)>10000)) {
			return 1;
		}
	}
	
	print_reverse(arr, size);
	free(arr);
	arr = NULL;
	return 0;
}

