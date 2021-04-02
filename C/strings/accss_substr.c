#include "header.h"

void print_sub(char* input_str, int index, int length) {
	int new_length = index+length;
	int i;
	for(i = index; i<=new_length; i++) {
		printf("%c", input_str[i]);
	}
	printf("\n");
}

int main(void) {
	char *input_str = NULL;
	int index, length;

	input_str = (char*)malloc(1024*sizeof(char));
	scanf("%[^\n]", input_str);
	input_str = realloc(input_str, strlen(input_str)+1);
	printf("Enter the index and the point upto you want to print the string: ");
	scanf("%d %d", &index, &length);
	
	if((index+length) > (strlen(input_str)-1)) {
		printf("The length is exceeding the strlen. So, the length is chipped off.\n");
		length = strlen(input_str)-1-index;
	}

	print_sub(input_str, index, length);
	free(input_str);
	return 0;
}