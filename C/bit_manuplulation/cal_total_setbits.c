//Calculate the total number of set bits in a number.

#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);
    int count = 0;
    
    while(num) {
        num = num & (num-1);
        count ++;
    }
    printf("%d\n", count);
    return 0;
}
