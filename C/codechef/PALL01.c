#include <stdio.h>

int main(void) {
    int cases, num, result, rem, init;

    scanf("%d", &cases);

    while(cases--) {
        scanf("%d", &num);
        result = 0;
        init = num;
        while(num) {
            rem = num%10;
            result = result*10+rem;
            num = num/10;
        }
        if(result == init) {
            printf("wins\n");
        }
        else {
            printf("loses\n");
        }
    }
    return 0;
}