#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isalpha_numeric(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
       (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

bool isPalindrome(char *s) {
    int i = 0, j = strlen(s)-1;

    while(i < j) {
        if(!isalpha_numeric(s[i])) {
            i++;
            continue;
        }
        if(!isalpha_numeric(s[j])) {
            j--;
            continue;
        }

        if(tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(void) {
    bool ret;

    char *str = (char*)malloc(1024*sizeof(char));
    scanf("%[^\n]", str);
    str = (char*)realloc(str, strlen(str)+1);

    ret = isPalindrome(str);
    printf("%d\n", ret);

    free(str);
    str = NULL;
    return 0;
}