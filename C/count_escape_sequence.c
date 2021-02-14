#include <stdio.h>

int main(void) {
	int a = 0;
	int count_char = 0;
	int count_lines = 0;
	int count_blanks = 0;
	int count_tabs = 0;
	int count_newline = 0;

	while ((a = getchar()) != EOF) {
		if (a == '\n')
			++count_newline;
	}
	printf("%d\n", count_newline);
}
