#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int length, i, even = 0, odd = 0;
    int *soldier = NULL;

    scanf("%d", &length);
    soldier = (int*)malloc(length*sizeof(int));
    for(i = 0; i<length; i++) {
        scanf("%d", soldier+i);
        if(*(soldier+i)%2 == 0) {
            even++;
        }
        else {
            odd++;
        }
    }
    if(even>odd) {
        printf("READY FOR BATTLE\n");
    }
    else {
        printf("NOT READY\n");
    }
    return 0;
}