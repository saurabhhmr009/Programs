/* Print the histogram of the input words */

#include <stdio.h>

int main(void) {
	int c = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n')
			putchar('\n');
		else
			putchar('*');
	}
	return 0;
}
