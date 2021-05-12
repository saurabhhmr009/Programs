#include <stdio.h>
#include <stdlib.h>

void reverse(int x) {
    int rev = 0, rem;
    while(x) {
        rem = x%10;
        rev = rev*10+rem;
        x = x/10;
    }
    printf("%d\n", rev);
}

int main(void) {
    int num;

    scanf("%d", &num);
    reverse(num);

    return 0;
}