#include <stdio.h>
#include <stdlib.h>

void schedule(int *class, int threshold, int total) {
    int result = 0, i;
    for(i=0; i<total; i++) {
        if(*(class+i) <= 0) {
            result++;
        }
    }
    if(result < threshold) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}

int main (void) {
    int cases, total_students, threshold, i, j;
    int *class = NULL;
    
    scanf("%d", &cases);
    for(i=0; i<cases; i++) {
        scanf("%d %d", &total_students, &threshold);
        class = (int*)malloc(total_students*sizeof(int));
        for(j=0; j<total_students; j++) {
            scanf("%d", class+j);
        }
        schedule(class, threshold, total_students);
        free(class);
        class = NULL;
    }
    return 0;
}

