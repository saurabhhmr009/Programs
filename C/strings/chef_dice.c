#include <stdio.h>

int main(void) {
    long int test_cases, dice_num, result = 0, rem, stacks;
    
    scanf("%ld", &test_cases);

    while(test_cases){
        scanf("%ld", &dice_num);
        stacks = dice_num/4;
        rem = dice_num%4;
        
        if(dice_num == 1) {
            result = 20;
        }
        else if(dice_num == 2) {
            result = 36;
        }
        else if(dice_num == 3) {
            result = 51; 
        }
        else if(dice_num >= 4) {
            if(rem == 0) {
                result = 44*stacks;
                result += 16;
            }
            else if(rem == 1) {
                result = 44*stacks;
                result += 20+12;
            }
            else if(rem == 2) {
                result = 44*stacks;
                result += 36+8;
            }
            else if(rem == 3) {
                result = 44*stacks;
                result += 51+4;
            }
        }
        test_cases--;
        printf("%ld\n", result);
    }
    return 0;
}