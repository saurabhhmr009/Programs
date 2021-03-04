#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *str;
	int *count_arr;
	int i;
	str = (char*)malloc(1024*sizeof(char));
	scanf("%[^\n]", str);
	str = realloc(str, strlen(str) + 1);
	
	count_arr = (int*)calloc(10,sizeof(int));
	
	for(i=0; i < strlen(str); i++) {
		if((*(str+i) >= '0') && (*(str+i) <= '9')) {
			int x = (*(str+i)) - '0'; 
			(*(count_arr+x))++;
		}
	}
	for(i=0; i < 10; i++) {
		printf("%d ", *(count_arr+i));
	}
	free(count_arr);
	free(str);
	return 0;
}

