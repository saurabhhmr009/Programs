#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if(a%b == 0) {
        return b;
    }
    return gcd(b, a%b);
}

int main(void) {
    int cases, ingredients, min_factor;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d", &ingredients);
        int ingredients_arr[ingredients];
        for(int i=0; i<ingredients; i++) {
            scanf("%d", &ingredients_arr[i]);
        }
        if(ingredients == 2) {
            min_factor = gcd(ingredients_arr[0], ingredients_arr[1]);
        }
        else {
            min_factor = gcd(ingredients_arr[0], ingredients_arr[1]);
            for(int i=2; i<ingredients; i++) {
                min_factor = gcd(min_factor, ingredients_arr[i]);
            }
        }
        //printf("%d\n", min_factor);
        for(int i=0; i<ingredients; i++) {
            printf("%d ", ingredients_arr[i]/min_factor);
        }
        printf("\n");
    }
    return 0;
}