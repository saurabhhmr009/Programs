/* Program to set, reset , and toggle a bit according to the user.
 */

#include <stdio.h>
#include <stdlib.h>

void set_bit(int *input, int *rotation) {
    *input = *input | (1<<(*rotation-1));
}

void clear_bit(int *input, int *rotation) {
    *input = *input & (~(1<<(*rotation-1)));
}

void toggle_bit(int *input, int *rotation) {
    *input = *input ^ (1<<(*rotation-1));
}
int main(void) {
    int input;
    int rotation;
    //int choice;
    
    scanf("%d", &input);
    scanf("%d", &rotation);
    
    set_bit(&input, &rotation);
    printf("Output after setting the %dth bit %d\n", rotation, input);
    clear_bit(&input, &rotation);
    printf("Output after setting the %dth bit %d\n", rotation, input);
    toggle_bit(&input, &rotation);
    printf("Output after setting the %dth bit %d\n", rotation, input);
    
    return 0;
}
