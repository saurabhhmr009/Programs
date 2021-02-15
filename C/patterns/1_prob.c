/* 
 * Print hollow and solid rectangles.
 */

#include <stdio.h>

int main(void) {
    int i, j;
    int length, breadth;
    
    scanf("%d", &length);
    scanf("%d", &breadth);
    if(breadth > length) {
        printf("Breadth must be less than length\n");
        return 1;
    }
    
    // Solid rectangle
    for (i=0; i<breadth; i++) {
        for(j=0; j<length; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    printf("\n");
    
    // Hollow rectangle
    for(i=0; i<breadth; i++) {
        for(j=0; j<length; j++) {
            if((i == 0) || (i == breadth-1) || (j == 0) || (j == (length-1))) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
