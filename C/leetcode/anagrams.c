#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int cmpFunc(const void *a, const void *b) {
    int s_count[26] = {0}, t_count[26] = {0};
    assert(s_count[10] == 0);
    assert(t_count[10] == 0);
    int i, slen = strlen(s), tlen = strlen(t);
    
    for (i = 0; i < slen; i++) {
        int c = s[i] - 'a';
        s_count[c] += 1;
    }
    
    for (i = 0; i < tlen; i++) {
        int c = t[i] - 'a';
        t_count[c] += 1;
    }
    
    for (i = 0; i < 26; i++) {
        if (s_count[i] != t_count[i])
            return false;
    }
    
    return true;

int main(void) {
    char *s = NULL, *t = NULL;
    bool result;

    s = (char*)malloc(1024*sizeof(*s));
    scanf("%[^\n]", s);
    s = (char*)realloc(s, strlen(s)+1);

    t = (char*)malloc(1024*sizeof(*t));
    scanf(" %[^\n]", t);
    t = (char*)realloc(t, strlen(t)+1);

    result = isAnagram(s, t);
    printf("%d\n", result);

    free(s);
    s = NULL;
    return 0;
}