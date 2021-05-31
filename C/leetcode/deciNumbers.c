#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minPartitions(char* n) {
    int max = 0, i = 0;
    if(strlen(n)-1 == 1) {
        return (atoi(n));
    }
    int length = strlen(n);
    while(length--) {
        if(n[i]-'0' > max) {
            max = n[i]-'0';
        }
        i++;
    }
    return max;
}

int main(void) {
    char *number = NULL;
    int result;

    number = (char*)malloc(100*sizeof(*number));
    fgets(number, 100, stdin);
    number = (char*)realloc(number, strlen(number)+1);
    result = minPartitions(number);

    printf("%d\n", result);
    free(number);
    return 0;
}