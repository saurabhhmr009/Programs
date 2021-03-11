#include <stdio.h>

int main(void) {
    int people = 5;
    int shared = 0;
    int liked = 0;
    int cumulative = 0, i, days;
    
    scanf("%d", &days);
    for(i=0; i<days; i++) {
        liked = people/2;
        people = liked*3;
        cumulative += liked;
    }
    printf("%d\n", cumulative);
    return 0;
}

