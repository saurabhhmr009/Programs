#include <stdio.h>


int factorial(int n) {
	static int fac = 1;
	if(n == 0) {
		return fac;
	}
	else {
		fac *= n;
		factorial(n-1);
	}
	return fac;
}

int main(void)
{
	int n, result;
	scanf("%d", &n);
	result = factorial(n);
	printf("%d\n", result);
	return 0;
}
