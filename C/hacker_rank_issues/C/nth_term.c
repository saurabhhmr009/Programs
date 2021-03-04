#include <stdlib.h>
#include <stdio.h>

int find_nth(int n, int a, int b, int c)
{
	int num = a + b + c;
	if(n > 4) {
		num = find_nth(n-1, b, c, a+b+c);
	}
	return num;
}
int main(void)
{
	int n, num1, num2, num3;
	int nth = 0;
	scanf("%d", &n);
	scanf("%d %d %d", &num1, &num2, &num3);
	if((n<1) && (n>20)) {
		return 1;
	}
	
	if(n<=4) {
		if(n == 1) {
			nth = num1;
		}
		else if(n == 2) {
			nth = num2;
		}
		else if(n == 3) {
			nth = num3;
		}
		else if(n==4) {
			nth = num1+num2+num3;
		}
	}
	else {
		nth = find_nth(n, num1, num2, num3);
	}
	printf("%d\n", nth);
	return 0;
}

