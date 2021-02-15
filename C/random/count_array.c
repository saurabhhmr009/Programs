/* count digits, white space, others */

#include <stdio.h>

int main(void) {
	int c , i , nwhite, nothers;
	int digit_array[10];
	nwhite = nothers = 0;

	for (i = 0; i <= 9; i++) {
		digit_array[i] = 0;
	}

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9')
			++digit_array[c - '0'];
		else if (c == ' ' || c == '\t' || c == '\n')
			++nwhite;
		else
			++nothers;
	printf("Digits counter ");
	for (i = 0; i <= 9; i++) {
                printf("%d ", digit_array[i]);
        }
	printf("White spaces %d others %d\n", nwhite, nothers);
}
