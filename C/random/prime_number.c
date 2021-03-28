#include <stdio.h>

int main (void) {
	int num, i, j, flag = 0;
	scanf("%d", &num);

	if((num == 1) || (num == 0)) {
		printf("No prime numbers in that range.\n");
		return num;
	}

	for(i=2; i<=num; i++) {
		flag = 0;
		for(j=2; j <= i/2; j++){
			if(i%j == 0) {
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			printf("%d\n", i);
		}
	}
	return 0;
}