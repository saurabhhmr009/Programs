#include <stdio.h>
#include <stdlib.h>

void max_bird(int *bird, int *count_bird, int length) {
    int i, min_freq, index = 0, min_index = 0;
    for(i=0; i<length; i++) {
        *(count_bird + *(bird+i) -1) += 1;
    }
    min_freq = *count_bird;
    for(i=1; i<5 ; i++) {
        if(*(count_bird+i) > min_freq) {
            min_freq = *(count_bird+i);
            index = i;
        }
    }
    printf("%d\n", index+1);

}

int main(void) {
    int count_bird[5] = {0};
    int length, i;
    int *bird = NULL;
    
    scanf("%d", &length);
    bird = (int*)malloc(length*sizeof(int));
    for(i=0; i<length; i++) {
        scanf("%d", bird+i);
    }
    max_bird(bird, count_bird, length);
    return 0;
}
