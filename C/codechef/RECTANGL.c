#include <stdio.h>

void sort_print(int *arr) {
    int i, j;
    for(i=0; i<4; i++) {
        for(j = i; j<4 -1; j++) {
            // Swaping using XOR
            if(*(arr+i) > *(arr+j+1)) {
                *(arr+i) = *(arr+i) ^ *(arr+j+1);
                *(arr+j+1) = *(arr+i) ^ *(arr+j+1);
                *(arr+i) = *(arr+i) ^ *(arr+j+1);
            }
        }
    }
    if((*arr == *(arr+1)) && (*(arr+2) == *(arr+3))) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}

int main (void) {
    int cases;

    scanf("%d", &cases);

    while(cases--) {
        int arr[4] = {0};
        scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
        sort_print(arr);
    }
    return 0;
}
