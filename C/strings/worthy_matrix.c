#include <stdio.h>
#include <stdlib.h>

long long get_min(long long m, long long n) {
    if(n < m) {
        return n;
    }
    return m;
}

int main(void) {
    int test_cases;

    scanf("%d", &test_cases);

    while(test_cases) {
        long long int n, m, k;

        scanf("%lld %lld %lld", &n, &m, &k);
        double arr[n+1][m+1];

        for(long long i = 0; i<=n; i++) {
            for(long long j = 0; j<=m; j++) {
                if(i == 0 || j == 0) {
                    arr[i][j] = 0;
                }
                else {
                    scanf("%lf", &arr[i][j]);
                }
            }
        }

        for(long long i = 0; i<=n; i++) {
            double previous = 0;
            for(long long j = 0; j<=m; j++) {
                arr[i][j] += previous;
                previous = arr[i][j];
            }
        }

        for(long long i = 0; i<=m; i++) {
            double previous = 0;
            for(long long j = 0; j<=n; j++) {
                arr[j][i] += previous;
                previous = arr[j][i];
            }
        }

        long long min = get_min(m,n);
        long long result = 0;
        for(long long l = 1; l<=min; l++) {
            for(long long i = l; i<=n; i++) {
                for(long long j = l; j<=m; j++) {
                    if((arr[i][j]+arr[i-l][j-l]-arr[i][j-l]-arr[i-l][j])/(l*l) >=k) {
                        result++;
                    }
                }
            }
        }
        test_cases--;
        printf("%lld\n", result);
    }
    return 0;
}