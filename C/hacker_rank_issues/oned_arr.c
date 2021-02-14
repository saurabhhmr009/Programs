#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int range, i, sum = 0;
    int *arr = NULL;
    
    scanf("%d", &range);
    arr = (int*)malloc(range * sizeof(arr));
    
    for (i = 0; i < range; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    printf("%d\n", sum);
    free(arr);
    arr = NULL;
    return 0;
}
