#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int myAtoi(char *s) {
    long result = 0;
    int sign = 0;

    while(isspace(*s)) {
        s++;
    }

    if((*s == '+') || (*s == '-')) {
        if(*s == '+') {
            sign = 0;
        }
        else {
            sign = 1;
        }
        s++;
    }

    if(!isdigit(*s)) {
        //printf("in\n");
        return 0;
    }

    while(isdigit(*s) && (result <= INT_MAX))
    {
        result = result * 10 + *s - '0';
        s++;
    }

    //printf("%ld\n", result);
    if(result > INT_MAX && sign == 0) {
        return INT_MAX;
    }
    if(result < INT_MIN && sign == 1) {
        return INT_MIN;
    }

    return sign == 0 ? result : -result;
}


int main(void) {
    char *str = NULL;
    int result = 0;

    str = (char*)malloc(1024*sizeof(*str));
    fgets(str, 1024, stdin);
    str = (char*)realloc(str, strlen(str)+1);

    result = myAtoi(str);
    printf("%d\n", result);

    free(str);
    str = NULL;
    return 0;
}
