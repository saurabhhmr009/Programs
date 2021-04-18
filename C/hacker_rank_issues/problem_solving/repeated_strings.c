#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char *str = NULL;
    long long length, i, total_substrings, result = 0, rem;

    str = (char*)malloc(1024*sizeof(char));
    scanf("%[^\n]", str);
    str = (char*)realloc(str, strlen(str)+1);

    scanf("%lld", &length);
    if(strlen(str) == 1) {
        if(str[0] == 'a'){
            result = length;
            printf("%lld\n", result);
            return 0;
        }
    }
    total_substrings = length/strlen(str);
    rem = length%strlen(str);

    for(i=0; i<strlen(str); i++) {
        if(str[i] == 'a') {
            result++;
        }
    }
    result = result*total_substrings;
    if(rem != 0) {
        for(i=0; i<rem; i++) {
            if(str[i] == 'a') {
                result++;
            }
        }
    }
    printf("%lld\n", result);

    free(str);
    str = NULL;
    return 0;
}