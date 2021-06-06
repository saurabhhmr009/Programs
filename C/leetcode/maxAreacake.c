#include <stdio.h>
#include <stdlib.h>

int cmpFunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maxArea(int h, int w, int *horizontalCuts, int horizontalCutsSize, int *verticalCuts, int verticalCutsSize) {
    long int max_width = 0, max_height = 0, i=0, temp;
    
    qsort(horizontalCuts, horizontalCutsSize, sizeof(int), cmpFunc);
    qsort(verticalCuts, verticalCutsSize, sizeof(int), cmpFunc);
    
    if(horizontalCutsSize == 1) {
        max_height = (horizontalCuts[0] > (h-horizontalCuts[0])) ? horizontalCuts[0]:h-horizontalCuts[0];
    }
    else {
        temp = horizontalCutsSize;
        int temp_height = horizontalCuts[0];
        while(temp >= 2) {
            max_height = ((horizontalCuts[i+1]-horizontalCuts[i]) > max_height) ? horizontalCuts[i+1]-horizontalCuts[i]:max_height;
            i++;
            temp--;
        }
        max_height = ((h-horizontalCuts[horizontalCutsSize-1])>max_height) ? h-horizontalCuts[horizontalCutsSize-1]:max_height;
        max_height = temp_height>max_height?temp_height:max_height;
    }
    
    if(verticalCutsSize == 1) {
        max_width = (verticalCuts[0] > (w-verticalCuts[0])) ? verticalCuts[0]:w-verticalCuts[0];
    }
    else {
        i = 0;
        int temp_width = verticalCuts[0];
        temp = verticalCutsSize;
        while(temp >= 2) {
            max_width = ((verticalCuts[i+1]-verticalCuts[i]) > max_width) ? verticalCuts[i+1]-verticalCuts[i]:max_width;
            i++;
            temp--;
        }
        max_width = ((w-verticalCuts[verticalCutsSize-1])>max_width) ? w-verticalCuts[verticalCutsSize-1]:max_width;
        max_width = temp_width>max_width?temp_width:max_width;
    }
    
    return ((max_height*max_width)%1000000007);
}
int main(void) {
    int height, width, vcuts, hcuts, *verticalcuts = NULL, *horizontalcuts = NULL, i, max_area = 0;

    printf("Dimension of cake: \n");
    scanf("%d %d", &height, &width);

    printf("Size of cuts: \n");
    scanf("%d %d", &hcuts, &vcuts);

    verticalcuts = (int*)malloc(vcuts*sizeof(*verticalcuts));
    horizontalcuts = (int*)malloc(hcuts*sizeof(*horizontalcuts));

    for(i=0; i<hcuts; i++) {
        scanf("%d", horizontalcuts+i);
    }

    for(i=0; i<vcuts; i++) {
        scanf("%d", verticalcuts+i);
    }

    max_area = maxArea(height, width, horizontalcuts, hcuts, verticalcuts, vcuts);

    printf("%d\n", max_area);

    free(verticalcuts);
    free(horizontalcuts);
    horizontalcuts = NULL;
    verticalcuts = NULL;

    return 0;
}