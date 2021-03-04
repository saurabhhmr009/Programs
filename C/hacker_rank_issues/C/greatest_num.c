#include<stdio.h>

int greatest (int a, int b, int c, int d) {
	int max1 = ((a > b) ? a : b);
	int max2  = ((c > d) ? c : d);
	return ((max1 > max2) ? max1 : max2);
}

int main (void) {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int max_num = greatest(a, b, c, d);
	printf("%d\n", max_num);
	return 0;
}
