/* Find the maximum occurring character in a given sentance
 * 
 * Logic: 1. Take the input from the user.
 * 
 * 2. Define a another array of 255 size and increment the index of that 
 * array according to the elements found in the user input string.
 * 
 * 3. Find the max number in the char array and print its char value.
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 255

int main(void) {
    char *str = NULL;
    int *value = NULL;
    int i, max = 0, convert;
    
    str = (char*)malloc(1024*sizeof(char));
    value = (int*)calloc(MAX_CHAR, sizeof(int));
    
    scanf("%[^\n]", str);
    str = realloc(str, strlen(str)+1);
    
    printf("%s\n", str);
    
    for(i=0; i<strlen(str); i++) {
        if(str[i] == ' ') {
            continue;
        }
        else {
            convert = (int)str[i];
            value[convert] += 1;
            //printf("%d\n", value[convert]);
        }
    }
    
    for(i=0; i<MAX_CHAR; i++) {
        if(value[i] > value[max]) {
            max = i;
        }
    }
    printf("%d\n", max);
    printf("The max occuring character is %c and it occured %d times in the string\n", max, value[max]);
    
    free(value);
    free(str);
    value = NULL;
    str = NULL;
    
    return 0;
}
