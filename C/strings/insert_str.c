#include "header.h"

void insertion(char *main_str, char *insert_str, int insert_point) {
	int i = 0, j = 0, k = 0;
	int final_buff = strlen(main_str) + strlen(insert_str) + 1;
	char *final = (char*)malloc(final_buff*sizeof(char));

	while(i <= insert_point -1) {
		final[i] = main_str[j];
		i++;
		j++;
	}
	while(i < (insert_point + strlen(insert_str))) {
		final[i] = insert_str[k];
		i++;
		k++;
	}
	while( i < final_buff) {
		final[i] = main_str[j];
		i++;
		j++;
	}
	printf("Final string is %s\n", final);
}

void deletion(char *main_str, int index, int length) {
	int end = index + length;
	int i, j = 1;

	for(i = index; i < strlen(main_str); i++, j++) {
		main_str[i] = main_str[end + j];
	}
	main_str[i] = '\0';
	printf("Final string is %s\n", main_str);
}

int main(void) {
	char *main_str = NULL;
	char *insert_str = NULL;
	int insert_point, index, length;

	printf("Enter the main string: \n");
	main_str = (char*)malloc(1024*sizeof(char));
	scanf("%[^\n]", main_str);
	main_str = realloc(main_str, strlen(main_str) + 1);

	printf("Enter the substring: \n");
	insert_str = (char*)malloc(1024*sizeof(char));
	scanf(" %[^\n]", insert_str);
	insert_str = realloc(insert_str, strlen(insert_str) + 1);

	printf("Enter the index from where you want to insert the string: ");
	scanf("%d", &insert_point);
	printf("Enter the index from where you want to delete the string: ");
	scanf("%d", &index);
	printf("Enter the length of char you want to delete: ");
	scanf("%d", &length);


	if((insert_point == strlen(main_str)-1) || ((insert_point+strlen(insert_str)) > strlen(main_str))) {
		printf("Either you choose last index as the insertion point or the length of the insertion string is greater than main_str\n");
		return 1;
	}

	//insertion(main_str, insert_str, insert_point);
	deletion(main_str, index, length);

	free(main_str);
	free(insert_str);
	return 0;
}