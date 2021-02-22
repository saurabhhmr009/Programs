/* Program to check if a particular bit is set or not.
 * 
 */


#include <stdio.h>


int main(void)
{
    int number;
    int bit_position;
    
    scanf("%d", &number);
    scanf("%d", &bit_position);
    
    if(number & (1<<(bit_position-1))) {
        printf("The bit is set\n");
    }
    else {
        printf("The bit is not set\n");
    }
    return 0;
}

