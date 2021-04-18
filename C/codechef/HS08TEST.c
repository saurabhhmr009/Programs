#include <stdio.h>

int main(void) {
    int r;
    float b;
    scanf("%d%f", &r, &b);
    if(r+ 0.5 > b) {
        printf("%.2f\n", b);
    }
    else if (r%5 != 0) {
        printf("%.2f\n", b);
    }
    else {
        printf("%.2f\n", b-r-0.5);
    }
    return 0;
}