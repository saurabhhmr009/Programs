#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int x1, v1, x2, v2;S
    scanf("%d %d %d %d", &x1, &v1, &x2, &v2);
    
    // v2 > v1 , and same speed, they will never match.
    if((v2 > v1) || (v2 == v1)) {
        printf("NO\n");
    }
    else {
        if(((x1-x2)%(v2-v1)) == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}
