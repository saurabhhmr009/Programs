#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int length, initial_jump, i, max, dose=0;
    int *hurdle = NULL;
    
    scanf("%d %d", &length, &initial_jump);
    hurdle = (int*)malloc(length*sizeof(int));
    for(i=0; i<length; i++) {
        scanf("%d", hurdle+i);
    }
    
    max = *hurdle;
    for(i=1; i<length; i++) {
        if(*(hurdle+i) > max) {
            max = *(hurdle+i);
        }
    }
    dose = max - initial_jump;
    if (dose < 0) {
        dose = 0;
        printf("%d\n", dose);
    }
    else {
        printf("%d\n", dose);
    }
    return 0;
}
