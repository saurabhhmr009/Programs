#include <stdio.h>

int cal_and(int N, int K) {
    int i, j;
    int min = 0, temp;
    
    for(i=1; i<N; i++) {
        for(j=i+1; j<=N; j++) {
            if((i<j) && ((i & j) < K)) {
                temp = i&j;
            }
            if(temp > min) {
                min = temp;
                //printf("%d\n", min);
            }
        }
    }
    return min;
}

int main(void) {
    int total_cases, N, K, i;
    int max_and = 0;
    scanf("%d", &total_cases);
    
    for(i=0; i<total_cases; i++) {
        scanf("%d %d", &N, &K);
        max_and = cal_and(N, K);
        printf("%d\n", max_and);
    }
    return 0;
}
