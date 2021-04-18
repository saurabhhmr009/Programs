#include <stdio.h>

int main() {
    int cases;
    long A, B, C, second, max;

    scanf("%d", &cases);

    while(cases--) {
        scanf("%ld %ld %ld", &A, &B, &C);
        if(A>B && A>C) {
            if(B>C){
                printf("%ld\n", B);
            }
            else {
                printf("%ld\n", C);
            }
        }
        if(B>A && B>C) {
            if(A>C){
                printf("%ld\n", A);
            }
            else {
                printf("%ld\n", C);
            }
        }
        if(C>A && C>B) {
            if(A>B){
                printf("%ld\n", A);
            }
            else {
                printf("%ld\n", B);
            }
        }
    }
    return 0;
}