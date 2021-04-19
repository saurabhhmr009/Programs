#include <stdio.h>

int main(void) {
    int cases, D, N, result = 0;

    scanf("%d", &cases);

    while(cases--) {
        scanf("%d %d", &D, &N);
        while(D--) {
            N = N*(N+1)/2;
        }
        printf("%d\n", N);
    }
    return 0;
}