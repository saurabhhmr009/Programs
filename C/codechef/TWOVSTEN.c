#include <stdio.h>

int main(void) {
    int cases;
    long num;

    scanf("%d", &cases);

    while(cases--) {
        scanf("%ld", &num);
        if(num%10 == 0) {
            printf("0\n");
        }
        else if(num%5 == 0) {
            printf("1\n");
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}