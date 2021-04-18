#include <stdio.h>

int main(void) {
    int cases, i, num, result;
    scanf("%d", &cases);
    
    for(i=0; i<cases; i++) {
        scanf("%d", &num);
        result = 0;
        while(num) {
            result = result + (num%10);
            num = num/10;
        }
        printf("%d\n", result);
    }

    return 0;
}