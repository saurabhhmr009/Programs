#include <stdio.h>

int cal_height(int cycle) {
    int i, height = 1;
    for(i=1; i<=cycle; i++) {
        if(i%2 == 0) {
            height += 1;
        }
        else {
            height *= 2;
        }
    }
    return height;
}

int main(void) {
    int cycles, cases, result, i;
    scanf("%d", &cases);
    for(i=0; i<cases; i++) {
        scanf("%d", &cycles);
        result = cal_height(cycles);
        printf("%d\n", result);
    }
    return 0;
}
