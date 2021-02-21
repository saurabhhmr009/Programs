/* Program to check if two numbers have same sign or different.
 * Use Xor logic for it. Xor of same bits is 1 and different is 0.
 */

#include <stdio.h>
#include <stdbool.h>


int main(void) {
    int num1, num2;
    bool result;
    
    scanf("%d", &num1);
    scanf("%d", &num2);

    
    result = ((num1 ^ num2) < 0);
    
    if(result == true) {
        printf("Numbers are opposite sign\n");
    }
    else {
        printf("Numbers are of same sign\n");
    }
    return 0;
}
