/* Logic is , count the occurence of all the integers in the array.
 * Then check if the addition of two consecutive elements of the occurence array
 * is greater than the max , which is initialized as 0.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int length, i, max = 0;
    int *arr = NULL;
    int freq[100] = {0};

    scanf("%d", &length);
    arr = (int*)malloc(length*sizeof(int));
    for(i=0; i<length; i++) {
        scanf("%d", arr+i);
        freq[*(arr+i)]++;
    }
    
    for(i=0; i<99; i++) {
        if(freq[i] == 0) {
            continue;
        }
        //printf("outside %d+%d \n", freq[i], freq[i+1]);
        if(freq[i]+freq[i+1] > max) {
            max = freq[i]+freq[i+1];
            //printf("adding %d+%d and max is %d\n", freq[i], freq[i+1], max);
        }
    }
    printf("%d\n", max);
    return 0;
}
