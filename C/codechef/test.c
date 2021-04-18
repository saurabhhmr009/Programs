#include <stdio.h>

int main (void) {
	int num= 12345;
	while(num >= 10) {
		num /= 10;
		printf("%d\n",num);
	}
	return 0;
}
