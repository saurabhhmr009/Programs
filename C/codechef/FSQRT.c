#include <stdio.h>
#include <math.h>

int main(void) {
    int cases, num;

    scanf("%d", &cases);
    
    while(cases--) {
        int result;
        scanf("%d", &num);
        result = sqrt(num);
        printf("%d\n", result);
    }
    return 0;
}