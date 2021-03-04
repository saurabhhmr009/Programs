/* Calculate the hourglass sum for every hourglass in array
 * and then print the maximum hourglass sum.
 * Max number of hourglass in a 2D array is (R-2)*(C-2).
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int size = 6, i, j, sum = 0;
    int **arr_ptr = NULL;
    int max_sum = -50000;
    
    //scanf("%d", &size);
    
    arr_ptr = (int**)malloc(size*sizeof(int*));
    for(i=0; i<size; i++) {
        arr_ptr[i] = (int*)malloc(size*sizeof(int));
        for(j=0; j<size; j++) {
            scanf("%d", arr_ptr[i]+j);
        }
    }

    /*for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            printf("%d ", *(arr_ptr[i]+j));
        }
        printf("\n");
    }*/
    
    for(i=0; i<size-2; i++) {
        for(j=0; j<size-2; j++) {
            sum = (*(arr_ptr[i]+j)+*(arr_ptr[i]+j+1)+*(arr_ptr[i]+j+2)+*(arr_ptr[i+1]+j+1)+*(arr_ptr[i+2]+j)+*(arr_ptr[i+2]+j+1)+*(arr_ptr[i+2]+j+2));
            if(sum > max_sum){
                max_sum = sum;
            }
        }
    }
    printf("%d\n", max_sum);
    
    for(i=0; i<size; i++) {
        if(arr_ptr[i] != NULL) {
            free(arr_ptr[i]);
            arr_ptr[i] = NULL;
        }
    }
    free(arr_ptr);
    arr_ptr = NULL;
    return 0;
}
