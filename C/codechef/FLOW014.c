#include <stdio.h>

int main(void) {
    int cases, hardness, strength;
    float content;

    scanf("%d", &cases);
    while(cases--) {
        scanf("%d %f %d", &hardness, &content, &strength);
        if(hardness > 50 && content < 0.7f && strength > 5600) {
            printf("10\n");
        }
        else if(hardness > 50 && content < 0.7f && strength <= 5600) {
            printf("9\n");
        }
        else if(hardness <= 50 && content < 0.7f && strength > 5600) {
            printf("8\n");
        }
        else if(hardness > 50 && content >= 0.7f && strength > 5600) {
            printf("7\n");
        }
        else if(hardness > 50 || content < 0.7f || strength > 5600) {
            printf("6\n");
        }
        else {
            printf("5\n");
        }
    }
    return 0;
}