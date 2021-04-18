#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int limit, i, arr[1000001] = {0}, num;

    scanf("%d", &limit);
    for(i=0; i<limit; i++) {
        scanf("%d", &num);
        arr[num] += 1;
    }

    for(i=0; i<1000001; i++) {
        while(arr[i] > 0) {
            printf("%d\n", i);
            arr[i]--;
        }
    }
    return 0;
}