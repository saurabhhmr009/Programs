#include<stdio.h>
#include<string.h>

int length(char s[]) {
	int i = 0;

	while(s[i] != '\0') {
		++i;
	}
	return i;
}


int main(void) {
	int len = 0;
	int str_len = 0;
	char str[] = "This is the test. Again test.";
	len = length(str);
	printf("%d\n", len);
	str_len = strlen(str);
	printf("%d\n", str_len);
	return 0;
}
