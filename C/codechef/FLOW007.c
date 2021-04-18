#include <stdio.h>

int main(void) {
    int cases, rem;
    long int num, rev;

    scanf("%d", &cases);

    while(cases--) {
        rev = 0;
        scanf("%ld", &num);
        while(num) {
            rem = num%10;
            rev = rev*10 + rem;
            num = num/10;
        }
        printf("%ld\n", rev);
    }
    return 0;
}