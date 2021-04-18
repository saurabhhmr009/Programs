#include <stdio.h>

int main(void) {
    int result, num, cases;
    scanf("%d", &cases);

    while(cases) {
        result = 0;
        scanf("%d", &num);
        result = num%10;
        while(num >= 10) {
            num /= 10;
        }
        result += num;
        printf("%d\n", result);
        cases--;
    }
    return 0;
}