#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int T, i, j;
    char **s = NULL;
    
    scanf("%d", &T);
    
    s = (char**)malloc(T*sizeof(char*));
    for(i=0; i<T; i++) {
        s[i] = malloc(10000*sizeof(char));
        scanf(" %[^\n]", s[i]);
        s[i] = realloc(s[i], strlen(s[i])+1);
    }
    
    for(i=0; i<T; i++) {
	for(j=0; j<strlen(s[i]); j++) {
	    printf("%c",s[i][j]);
	    j++;
	}
	printf("  ");
        for(j=1; j<strlen(s[i]); j++) {
            printf("%c",s[i][j]);
            j++;
        }
	printf("\n");
    }

    for(i=0; i<T; i++) {
	if(s[i] != NULL) {
            free(s[i]);
            s[i] = NULL;
	}
    }
    
    free(s);
    s = NULL;
    return 0;
}
