#include <stdio.h>

int main(void) {
    int cases;
    int N, K, temp, i;

    scanf("%d", &cases);
    while(cases--) {
        temp = 0;
        scanf("%d %d", &N, &K);
        for(i=2; i<=K; i++) {
            printf("%d\n", N%i);
            if(N%i > temp) {
                temp = N%i;
            }
        }
        printf("%d\n", temp);
    }
    return 0;
}