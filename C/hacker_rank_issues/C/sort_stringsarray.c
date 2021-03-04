#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHARS   26


int lexicographic_sort(const char *a, const char *b) {
	return strcmp(a,b);
}

int lexicographic_sort_reverse(const char *a, const char *b) {
	return strcmp(b,a);

}

int sort_by_length(const char *a, const char *b) {
	int length = 0;
	length = strlen(a) - strlen(b);
	printf("%d\n", length);
	//return length;
	return (length)?length:lexicographic_sort(a, b);
}

int distinct_chars(const char *a)
{
    int dist = 0;
    int chars[CHARS] = {0};

    while (*a != '\0') {
        int chr = (*a++) - 'a';
        printf("%d\n", chr);
        if (chr < CHARS)
            chars[chr]++;
    }
    
    for (int i = 0; i < CHARS; i++)
        if (chars[i])
            dist++;

    return dist;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int res = distinct_chars(a) - distinct_chars(b);
    return (res) ? res : lexicographic_sort(a, b);
}
// Quick Bubble sort on the strings first element
void string_sort(char **arr, const int length, int (*cmp_func) (const char *a, const char *b)) {
	int i, j;
	char *temp = NULL;
	
	for(i=0; i<length; i++) {
		for(j=0; j<length-1; j++) {
			if(cmp_func(arr[j], arr[j+1]) > 0) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(void) {
	
	char **char_arr = NULL;
	int i;
	int max_trials;
	
	scanf("%d", &max_trials);
	
	char_arr = (char**)malloc(max_trials*(sizeof(char*)));
	for(i=0; i<max_trials; i++) {
		char_arr[i] = (char*)malloc(1024*sizeof(char));
		scanf("%s", char_arr[i]);
	}
	
	
	string_sort(char_arr, max_trials, lexicographic_sort);
	for(i=0; i<max_trials; i++) {
		printf("%s\n", char_arr[i]);
	}
	
	string_sort(char_arr, max_trials, lexicographic_sort_reverse);
	for(i=0; i<max_trials; i++) {
		printf("%s\n", char_arr[i]);
	}
	
	string_sort(char_arr, max_trials, sort_by_length);
	for(i=0; i<max_trials; i++) {
		printf("%s\n", char_arr[i]);
	}
	
	string_sort(char_arr, max_trials, sort_by_number_of_distinct_characters);
	for(i=0; i<max_trials; i++) {
		printf("%s\n", char_arr[i]);
	}
	
	for(i=0; i<max_trials; i++) {
		if(char_arr[i] != NULL) {
			free(char_arr[i]);
			char_arr[i] = NULL;
		}
	}
	free(char_arr);
	char_arr = NULL;
	return 0;
}
