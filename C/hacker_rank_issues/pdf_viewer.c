#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int *freq = NULL;
    char *str = NULL;
    int i, index, tallest_letter=0;
    
    freq = (int*)malloc(26*sizeof(int));
    str = (char*)malloc(1024*sizeof(char));
    for(i=0; i<26; i++) {
        scanf("%d", freq+i);
    }
    scanf(" %[^\n]", str);
    str = realloc(str, strlen(str)+1);
    
    for(i=0; i<strlen(str); i++) {
        index = str[i] - 97;
        if(*(freq+index) >  tallest_letter) {
            tallest_letter = *(freq+index);
        }
    }
    printf("%d\n", strlen(str)*tallest_letter);
    return 0;
}
