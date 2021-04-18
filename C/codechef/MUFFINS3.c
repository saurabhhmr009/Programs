#include <stdio.h>

int main(void) {
    int cases, cupcakes;

    scanf("%d", &cases);

    while(cases--) {
        scanf("%d", &cupcakes);
        printf("%d\n", (cupcakes/2)+1);
    }
    return 0;
}