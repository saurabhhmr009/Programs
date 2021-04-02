/* Find the occurence of the pattern first's location in the string an print its index.
 */

#include "header.h"

int check_pattern(char* input_str, char* pattern) {
    int i, j = 0, index = 0, flag = 0; 
    size_t count = 0;

    for(i = 0; i<strlen(input_str); i++) {
        if(input_str[i] == pattern[j]) {
            if(flag != 1) {
                index = i;
                flag = 1;
            }
            count++;
            j++;
            if(count == strlen(pattern)) {
                return index;
            }
        }
        else {
            count = flag = j = 0;
        }
    }

    return -1;
}

int main(void) {
    char *input_str = NULL;
    char *pattern = NULL;
    int result_index;

    printf("Enter the input string: \n");
    input_str = (char*)malloc(1024*sizeof(char));
    scanf("%[^\n]", input_str);
    input_str = realloc(input_str, strlen(input_str)+1);

    printf("Enter the pattern to be seached: \n");
    pattern = (char*)malloc(1024*sizeof(char));
    scanf(" %[^\n]", pattern);
    pattern = realloc(pattern, strlen(pattern)+1);

    result_index = check_pattern(input_str, pattern);
    if(result_index >= 0) {
        printf("Pattern found at index: %d\n", result_index);
    }
    else {
        printf("Pattern not found.\n");
    }

    free(input_str);
    free(pattern);
    return 0;
}