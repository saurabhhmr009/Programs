#include<stdio.h>
int main(void) {
	int a = 0;
	int b = 0;
	a = -3--3;
	b = -3--(-3);
	printf("%d %d\n", a, b);
	return 0;
}
