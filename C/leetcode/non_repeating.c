#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int firstUniqChar(char *s) {
    int i, alpabets[26] = {0};
    
    for(i = 0; s[i] != '\0'; i++) {
        alpabets[s[i] - 'a'] += 1;
    }

    for(i=0; s[i] != '\0'; i++) {
        if(alpabets[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}
int main(void) {
    char *s = NULL;
    int index;

    s = (char*)malloc(1024*sizeof(*s));
    scanf("%[^\n]", s);
    s = (char*)realloc(s, strlen(s)+1);
    index = firstUniqChar(s);
    printf("%d\n", index);

    free(s);
    s = NULL;
    return 0;
}