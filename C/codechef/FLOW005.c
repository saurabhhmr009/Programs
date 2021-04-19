#include <stdio.h>

int main(void) {
    int cases, minA = 0, minB = 0, minC = 0, minD = 0, minE = 0, result; 
    long total;
    scanf("%d", &cases);

    while(cases--) {
        scanf("%ld", &total);
        minA = total/100;
        total = total%100;
        minB = total/50;
        total = total%50;
        minC = total/10;
        total = total%10;
        minD = total/5;
        total = total%5;
        minE = total/2;
        total = total%2;

        result = total+minA+minB+minC+minD+minE;
        printf("%d\n", result);
    }
    return 0;
}