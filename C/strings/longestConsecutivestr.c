#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int cmpFunc(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int maxConsecutivestr(char *str) {
    if(str == NULL) return 0;

    int max_seq = INT_MIN, i, count = 1, prev;

    qsort(str, strlen(str), sizeof(char), cmpFunc);
    prev = (int)str[0];

    for(i=1; i<strlen(str)-1; i++) {
        if(((int)str[i] == prev+1)) {
            count++;
        }
        else if((int)str[i] == prev) {
            prev = (int)str[i];
            continue;
        }
        else {
            max_seq = max_seq>count ? max_seq:count;
            count = 1;
        }
        prev = (int)str[i];
    }

    if(max_seq > count) return max_seq;
    return count;
}

int main(void) {
    char *str = NULL;
    int max = 0;
    str = (char*)malloc(1024*sizeof(char));
    fgets(str, 1024, stdin);
    str = (char*)realloc(str, strlen(str)+1);

    //sortStr(str);

    max = maxConsecutivestr(str);
    printf("Sorted string %s and max consecutive char length %d\n", str, max);

    free(str);
    str = NULL;
    return 0;
}