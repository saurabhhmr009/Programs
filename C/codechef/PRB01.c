#include <stdio.h>
#include <math.h>

int main(void) {
    int cases, i, flag, num;

    scanf("%d", &cases);

    while(cases--) {
        scanf("%d", &num);
        flag = 0;
        for(i = 2; i <= sqrt(num); i++) {
            if(num%i == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
    return 0;
}