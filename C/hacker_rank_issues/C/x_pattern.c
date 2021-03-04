#include <stdio.h>

void print_func(int count){
	int i, j;
	for (i = 1; i <= count; i++) {
		for (j = 1; j <= count; j++) {
			if ((i == j) || ( j == count - i + 1)) 
			{
				printf("*");
			}
			else 
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main(void)
{
	int size, total;
	scanf("%d", &size);
	total = size*2 -1;
	print_func(total);
	return 0;
}

