#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	int *arr = NULL;
	int i, size, temp = 0;
	
	scanf("%d", &size);
	arr = (int*)malloc(size*(sizeof(int)));
	
	for(i=0; i<size; i++) {
		scanf("%d", arr + i);
	}
	
	//printf("%d", arr);
	for(i=0; i<(size/2); i++) {
		temp = *(arr + i);
		*(arr + i) = *(arr + (size - i - 1));
		*(arr + (size -i -1)) =  temp;
	}
	
	for (i= 0; i<size; i++) {
		printf("%d", *(arr+i));
	}
	free(arr);
	arr = NULL;
	return 0;
}

