/* Concatenate two strings using strcat and without it.
 */ 

#include "header.h"

void concat_wthout(char* str1, char* str2, int final_str) {
	char *final = (char*)malloc(final_str*sizeof(char));
	int i = 0, j = 0;

	while(str1[i] != '\0') {
		final[j] = str1[i];
		j++;
		i++;
	}

	i = 0;
	final[j] = ' ';
	j++;

	while(str2[i] != '\0') {
		final[j] = str2[i];
		j++;
		i++; 
	}

	printf("Final string %s\n", final);
	free(final);
}

// Way around is make the size of str1 big so that only one strcat command could be used.
void concat_withfunc(char *str1,char *str2, int final_str) {
	char *final = (char*)malloc(final_str*sizeof(char));

	final = strncat(final, str1, strlen(str1));
	final = strcat(final, " ");
	final = strncat(final, str2, strlen(str2));

	printf("Final string %s\n", final);
	free(final);
}

int main(void) {
    char *str1 = NULL;
    char *str2 = NULL;
    int final_str;

	printf("Enter the first string: \n");
    str1 = (char*)malloc(1024*sizeof(char));
    scanf("%[^\n]", str1);
    str1 = realloc(str1, strlen(str1)+1);

    printf("Enter the second string: \n");
    str2 = (char*)malloc(1024*sizeof(char));
    scanf(" %[^\n]", str2);
    str2 = realloc(str2, strlen(str2)+1);

    final_str = strlen(str1) + strlen(str2) + 2;

    //concat_wthout(str1, str2, final_str);
    concat_withfunc(str1, str2, final_str);

    free(str1);
    free(str2);
    return 0;
}