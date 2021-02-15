/*
 * Program to display the binary representation of a number and also
 * display the number of consecutives 1's in the binary. 
 */




#include <stdio.h>
#include <stdlib.h>

void binary_number(int input) {
	int max = 0, count = 0, result = 0, rem, position = 1;
	
	while(input != 0) {
		rem  = input%2;
		if(rem > 0) {
			count++;
		}
		else {
			if(count > max) {
				max = count;
			}
			count = 0;
		}
		result = result + (rem*position);
		position = position * 10;
		input = input/2;
	}
	printf("Binary representation %d\n", result);
	if(count >= max) {
		printf("Max number of consecutive 1's %d\n", count);
	}
	else {
		printf("Max number of consecutive 1's %d\n", max);
	}
}

int main(void)
{
	int integer;
	scanf("%d", &integer);	
	binary_number(integer);
	return 0;
}

