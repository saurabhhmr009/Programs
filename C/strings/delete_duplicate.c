/* Program to eliminate all the duplicate words in a sentance.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int i, j = 0, k = 0, l;
    char *str = NULL;
    char **word_str = NULL;
    
    // Memory assigned to the user input string.
    str = (char*)malloc(1024*sizeof(char));
    scanf("%[^\n]", str);
    str = realloc(str, strlen(str)+1);
    
    // Memory assigned to the 2-D char array which will hold the words. 
    word_str = (char**)malloc(20*sizeof(char*));
    for(i=0; i<20; i++) {
        word_str[i] = (char*)malloc(20*sizeof(char));
    }
    
    // Function to copy the words from the string to the 2-D array.
    for(i=0; i<strlen(str); i++) {
        if(str[i] == ' ') {
            word_str[k][j] = '\0';
            k++;
            j = 0;
        }
        else {
            word_str[k][j] = str[i];
            //printf("%c", word_str[k][j]);
            j++;
        }
    }
    printf("\n");
    /*for(i=0; i<k+1; i++) {
        printf("%s\n", word_str[i]);
    }*/
    
    word_str[k+1][0] = '\0';
    
    j = 0;
    for(i=0; i<k+1; i++) {
        //printf("Test\n");
        for(l=1; l<k+1; l++) {
            if((word_str[l][j] == '\0') || (l == i)) {
                //printf("%s\n", word_str[i]);
                //printf("Test again\n");
                continue;
            }
            else {
                if(strcmp(word_str[i], word_str[l]) == 0) {
                    //printf("haha\n");
                    word_str[l][j] = '\0';
                }
            }
        }
    }
    
    for(i=0; i<k; i++) {
        if(word_str[i] == NULL) {
            continue;
        }
        else {
            printf("%s ", word_str[i]);
        }
    }
    printf("\n");
    
    for(i=0; i<20; i++) {
        if(word_str[i] != NULL) {
            free(word_str[i]);
            word_str[i] = NULL;
        }
    }
    free(str);
    free(word_str);
    word_str= NULL;
    str = NULL;
    
    return 0;
}
