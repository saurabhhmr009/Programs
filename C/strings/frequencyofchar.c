/* Frequency of each character in a sentance/string.
 * Logic : 1. Take input from the User. By default, this calculates the 
 * occurence of both lower and upper case alphabets.
 * 
 * 2. Initialize a 26 bit array to store the occurence of each char. 
 * 
 * 3. If the lower case then ch -97 and for upper. ch - 65.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *input_str = NULL;
    int *arr = NULL;
    int i, value, special_char = 0;
    
    input_str = (char*)malloc(1024*sizeof(char));
    scanf("%[^\n]", input_str);
    input_str = realloc(input_str, strlen(input_str)+1);
    
    arr = (int*)calloc(26, sizeof(int));
    
    for(i=0; i<strlen(input_str); i++) {
        if((input_str[i] >= 'a') && (input_str[i] <= 'z')) {
            value = (int)input_str[i] - 97;
            arr[value] += 1;
        }
        else if((input_str[i] >= 'A') && (input_str[i] <= 'Z')) {
            value = (int)input_str[i] - 65;
            arr[value] += 1;
        }
        else {
            //printf("Faced a special character like space\n");
            special_char++;
        }
    }
        
    for(i=0; i<26; i++) {
        if(arr[i] != 0) {
            printf("Occurence of the Charcters are %c, %d times\n", i+65, arr[i]);
        }
    }
    printf("Faced %d times the special character\n", special_char);
    free(arr);
    free(input_str);
    arr = NULL;
    input_str = NULL;
    
    return 0;
}
