#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(void)
{
	//enum number{1 = one, 2 = two, 3 = three, 4 = four, 5 = five, 6 = six, 7 = seven, 8 = eight, 9 = nine};
	int a, b, n;
	scanf("%d %d", &a, &b);
	if (a == 0) {
		return 1;
	}
	char nums [9][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	for (n = a; n <= b; n++) {
		if ((1 <= n) &&(n <= 9)) {
			printf("%s\n", nums[n-1]);
		}
		else if (n % 2 == 0) {
			printf("even\n");
		}
		else {
			printf("odd\n");
		}
	}
	return 0;
}

