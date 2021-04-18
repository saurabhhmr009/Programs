#include <stdio.h>

int main(void) {
    // your code goes here
    long cases, num, count;
    
    scanf("%ld", &cases);
    while(cases--) {
        count = 0;
        scanf("%ld", &num);
        while(num) {
            if(num%10 == 4) {
                count++;
            }
            num = num/10;
        }
        printf("%ld\n", count);
    }
    
    return 0;
}
