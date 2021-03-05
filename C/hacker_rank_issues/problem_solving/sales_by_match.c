#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int total_socks, i, j, pairs = 0;
    int *socks = NULL;
    
    scanf("%d", &total_socks);
    socks = (int*)malloc(total_socks*sizeof(int));
    for(i=0; i<total_socks; i++) {
        scanf("%d", socks+i);
    }
// Logic is to make the matched element in the array 0 so that we don't 
// iterate the matched elements again.
    for(i=0; i<total_socks-1; i++) {
        if(*(socks+i) != 0) {
            for(j = i+1; j<total_socks; j++) {
                if(*(socks+i) == *(socks+j)) {
                    pairs += 1;
                    *(socks+j) = 0;
                    break;
                }
            }
        }
    }
    printf("%d\n", pairs);
    return 0;
}
