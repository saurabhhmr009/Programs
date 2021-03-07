#include <stdio.h>
#include <stdlib.h>

int most_expensive(int *keyboard, int *usb, int budget, int n, int m) {
    int i, j, init = -1, temp = 0;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            temp = *(keyboard+i) + *(usb+j);
            if(temp <= budget && temp >init) {
                init = temp;
            }
        }
    }
    return init;
}

int main(void) {
    int budget, n, m, i, expensive;
    int *keyboard = NULL;
    int *usb = NULL;
    
    scanf("%d %d %d", &budget, &n, &m);
    keyboard = (int*)malloc(n*sizeof(int));
    usb = (int*)malloc(m*sizeof(int));
    for(i=0; i<n; i++) {
        scanf("%d", keyboard+i);
    }
    for(i=0; i<m; i++) {
        scanf("%d", usb+i);
    }
    expensive = most_expensive(keyboard, usb, budget, n, m);
    printf("%d\n", expensive);
    return 0;
}
