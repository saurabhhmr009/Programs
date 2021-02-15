#include <stdio.h>

int x = 0;

int f() {
	return x;
}
int y() {
	//int x = 1;
	x = 1;
	return f();
}

int main (void) {
	printf("%d\n", y());
	printf("\n");
	getchar();
}             
