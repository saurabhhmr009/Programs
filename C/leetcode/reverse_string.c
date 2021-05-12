#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseStr(char *str, int sSize) {
    int i = 0, j = sSize-1;
    char ch;

    while(i < j) {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i++;
        j--;
    }
    printf("%s\n", str);
}

int main(void) {
    char *str = NULL;

    str = (char*)malloc(1024*sizeof(*str));
    fgets(str, 1024, stdin);
    str = (char*)realloc(str, strlen(str)+1);

    reverseStr(str, strlen(str));

    free(str);
    str = NULL;
    return 0;
}