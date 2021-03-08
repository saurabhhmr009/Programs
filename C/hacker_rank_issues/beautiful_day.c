#include <stdio.h>
#include <stdlib.h>

int num_reverse(int num) {
    int reverse = 0;
    while(num) {
        reverse = (reverse*10)+(num%10);
        num = num/10;
    }
    return reverse;
}

int main(void) {
    int range1, range2, divisor;
    int i, reverse, result, beautiful_days = 0;
    //int *arr = NULL;
    scanf("%d %d %d", &range1, &range2, &divisor);
    //length = range2-range1 +1;
    
    for(i=range1; i<=range2; i++) {
        reverse = num_reverse(i);
        result = abs(i-reverse);
        if(result%divisor == 0) {
            beautiful_days++;
        }
    }
    printf("%d\n", beautiful_days);
    return 0;
}
