#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *input = NULL, *new_Arr = NULL;
    int rotations, elements, queries, i, index;
    
    scanf("%d %d %d", &elements, &rotations, &queries);
    input = (int*)malloc(elements*sizeof(int));
    new_Arr = (int*)malloc(elements*sizeof(int));
    for(i=0; i<elements; i++) {
        scanf("%d", input+i);
    }

    for(i = 0; i<elements; i++) {
        *(new_Arr+(i+rotations)%elements) = *(input+i);
    }
    for(i=0; i<queries; i++) {
        scanf("%d", &index);
        printf("%d\n", *(new_Arr+index));
    }
    return 0;
}
