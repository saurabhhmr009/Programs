#include<stdio.h>

int main(void) {
	int c;
	c = getchar();
	while (c != EOF) {
		putchar (c);
		c = getchar();
		printf("%d\n", c);
	}
	return 0;
}

