#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int total_items, nshared, charged, actual_charge = 0, i;
    int *items = NULL;

    scanf("%d %d", &total_items, &nshared);
    items = (int*)malloc(total_items*sizeof(int));
    for(i=0; i<total_items; i++) {
        scanf("%d", items+i);
    }
    scanf("%d", &charged);

    for(i=0; i<total_items; i++) {
        if(i != nshared) {
            actual_charge += *(items+i);
        }
    }
    actual_charge = actual_charge/2;
    if(charged == actual_charge) {
        printf("Bon Appetit\n");
    }
    else {
        printf("%d\n", charged - actual_charge);
    }
    return 0;
}
