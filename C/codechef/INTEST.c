#include <stdio.h>

int main(void) {
    int n, k, i, result = 0, val;
    scanf("%d %d", &n, &k);

    for(i=0; i<n; i++) {
        scanf("%d", &val);
        if(val%k == 0) {
            result++;
        }
    }
    printf("%d\n", result);
    return 0;
}