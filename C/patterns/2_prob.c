/* program to print half pyramids
 */

#include <stdio.h>

int main(void) {
    int i, j, t;
    int size = 0;
    
    scanf("%d", &size);
    
    //mid = size/2;
    
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            if(j >= size-i-1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    printf("\n");
    
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            if(j <= i) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    printf("\n");
    
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            if(j <= size-i-1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    printf("\n");
    
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            if(j >= i) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    printf("\n");
    
    for(i=0; i<size; i++,t = 0) {
        for(j=0; j<size-i; j++, t = 0) {
            printf(" ");
        }
        
        while(t != 2*i+1) {
            printf("*");
            t++;
        }
        printf("\n");
    }
    
    return 0;
}
