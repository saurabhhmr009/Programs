#include <stdio.h>

void last_person(int prisoners, int candies, int index) {
    printf("%d\n", ((candies + index -2)%prisoners+1));
}

int main(void) {
    int total_cases, prisoners, candies, index, i;
    scanf("%d", &total_cases);
    for(i=0; i<total_cases; i++) {
        scanf("%d %d %d", &prisoners, &candies, &index);
        last_person(prisoners, candies, index);
    }
    return 0;
}
