#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char **char_arr = NULL;
	int i, length;
	
	scanf("%d", &length);
	if((length<2) && (length>9)) {
		return 1;
	}
	
	char_arr = (char**)malloc(length*sizeof(char*));
	for(i=0; i<length; i++) {
		char_arr[i] = (char*)malloc(10*sizeof(char));
		scanf("%s", char_arr[i]);
		if((strlen(char_arr[i])<1) && (strlen(char_arr[i])>10)) {
			return 1;
		}
	}
	
	for(i=0; i<length; i++) {
		if(char_arr[i] != NULL) {
			free(char_arr[i]);
			char_arr[i] = NULL;
		}
	}
	free(char_arr);
	char_arr = NULL;
	return 0;
}

