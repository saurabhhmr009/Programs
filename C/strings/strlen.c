/* Program to get the length of the string without using strlen function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *input_str = NULL;
    int i = 0, count = 0;

    input_str = (char*)malloc(1024*sizeof(char));
    scanf("%[^\n]", input_str);
    //input_str = realloc(input_str, strlen(input_str+1));

    while(input_str[i] != '\0') {
        count++;
        i++;
    }

    printf("The length of the string is: %d\n", count);
    free(input_str);
    return 0;
}