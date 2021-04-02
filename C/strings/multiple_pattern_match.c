/* Find the occurence of the pattern in the string an print its index.
 */

#include "header.h"

void check_pattern(char* input_str, char* pattern) {
    int i, j = 0, index = 0, flag = 0, k = 0;
    size_t count = 0;
    int *location = NULL;

    for(i = 0; i<strlen(input_str); i++) {
        if(input_str[i] == pattern[j]) {
            if(flag != 1) {
                index = i;
                flag = 1;
            }
            count++;
            j++;
            if(count == strlen(pattern)) {
                if(location == NULL) {
                    location = (int*)malloc(1*sizeof(int));
                    *(location) = index;
                    k++;
                }
                else {
                    k++;
                    location = (int*) realloc(location, k);
                    *(location+k-1) = index;
                }
                count = flag = j = 0;
                continue;
            }
        }
        else {
            count = flag = j = 0;
        }
    }

    if(k == 0) {
        printf("Pattern not found in the string\n");
    }
    else {
        printf("Pattern is found on %d indexes\n", k);
        for(i = 0; i<k; i++) {
            printf("%d ", *(location+i));
        }
        printf("\n");
    }
}

int main(void) {
    char *input_str = NULL;
    char *pattern = NULL;

    printf("Enter the input string: \n");
    input_str = (char*)malloc(1024*sizeof(char));
    scanf("%[^\n]", input_str);
    input_str = realloc(input_str, strlen(input_str)+1);

    printf("Enter the pattern to be seached: \n");
    pattern = (char*)malloc(1024*sizeof(char));
    scanf(" %[^\n]", pattern);
    pattern = realloc(pattern, strlen(pattern)+1);

    check_pattern(input_str, pattern);

    free(input_str);
    free(pattern);
    return 0;
}