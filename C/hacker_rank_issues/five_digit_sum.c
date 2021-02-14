#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int n;
	int i, sum;
	sum = 0;
	scanf("%d", &n);
	for (i = 1; i <= 5; i++) {
		sum += n % 10;
		n = n / 10;
		printf("%d %d\n", sum, n);
	}
	printf("%d\n", sum);
	return 0;
}

