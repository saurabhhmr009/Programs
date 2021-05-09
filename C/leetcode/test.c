#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int *new = NULL;
	int i, j=0;
	new = (int*)calloc(20, sizeof(*new));

	for(i=0; i<3; i++) {
		j++;
		*(new+i) += i;
	}
	printf("%d\n", j);
	
	return 0;

}
