#include <stdio.h>

int main(void) {
    int rounds, scoreA, scoreB, maxA = 0, maxB = 0, totA = 0, totB = 0;

    scanf("%d", &rounds);
    while(rounds--) {
        scanf("%d %d", &scoreA, &scoreB);
        
        totA += scoreA;
        totB += scoreB;
        if(totA>totB && (totA-totB) > maxA) {
            maxA=totA-totB;
        }
        else if(totB>totA && (totB-totA) > maxB) {
            maxB = totB-totA;
        }
    }
    if(maxA>maxB) {
        printf("1 %d", maxA);
    }
    else {
        printf("2 %d", maxB);
    }
    return 0;
}