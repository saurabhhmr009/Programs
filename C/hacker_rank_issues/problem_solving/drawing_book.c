#include<stdio.h>

int main(void) {
    int n, p, min_jumps;
    
    scanf("%d",&n);
    scanf("%d",&p);
    
    // tells the number of turns from the last page and p/2 only is like number of turns from front page
    min_jumps=(n/2)-(p/2);
    if(min_jumps >= p/2) {
        min_jumps = p/2;
    }
    printf("%d\n", min_jumps);
    return 0;
}
