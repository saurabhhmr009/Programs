#include <stdio.h>
#include <stdlib.h>

void shortest_dist(int catA, int catB, int mouse) {
    int cat1_dist = abs(mouse - catA);
    int cat2_dist = abs(mouse - catB);
    if(cat1_dist > cat2_dist) {
        printf("Cat B\n");
    }
    else if(cat1_dist < cat2_dist) {
        printf("Cat A\n");
    }
    else {
        printf("Mouse C\n");
    }
}

int main(void) {
    int cases, i;
    int catA, catB, mouse;
    
    scanf("%d", &cases);
    for(i=0; i<cases; i++) {
        scanf("%d %d %d", &catA, &catB, &mouse);
        shortest_dist(catA, catB, mouse);
    }
    return 0;
}
