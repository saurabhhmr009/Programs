/* Find the max and min chars in a string or sentance. Exclude the 
 * special chars/int values.
 * Note..applicable only for the strings at the moment.
 * For now, using bubble sort algo
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void sort_arr(int *input, int length) {
    int i, j;
    
    for(i=0; i<length; i++) {
        for(j=0; j<length-i-1; j++) {
            if(*(input+j) > *(input+j+1)) {
                *(input+j) = *(input+j) ^ *(input+j+1);
                *(input+j+1) = *(input+j) ^ *(input+j+1);
                *(input+j) = *(input+j) ^ *(input+j+1);
            }
        }
    }
}*/

void sort_arr(char *input) {
    int i, j;
    
    for(i=0; i<strlen(input); i++) {
        for(j=0; j<strlen(input)-i-1; j++) {
            if((input[j] == ' ') && (input[j+1] == ' ')) {
                continue;
            }
            if(input[j] > input[j+1]) {
                input[j] = input[j] ^ input[j+1];
                input[j+1] = input[j] ^ input[j+1];
                input[j] = input[j] ^ input[j+1];
            }
        }
    }
}

int main(void) {
    //int length;
    //int *input_arr = NULL;
    char *input_arr = NULL;
    //int i;
    
    //scanf("%d", &length);
    //input_arr =  (int*)calloc(length, sizeof(int));
    input_arr = (char*)malloc(1024*sizeof(char));
    scanf("%[^\n]", input_arr);
    input_arr = realloc(input_arr, strlen(input_arr)+1);
    
    /*for(i=0; i<length; i++) {
        scanf("%d", input_arr+i);
    }*/
    
    //sort_arr(input_arr, length);
    sort_arr(input_arr);
    //printf("Sorted array is : ");
    
    /*for(i=0; i<length; i++) {
        printf("%d ", *(input_arr+i));
    }*/
    printf("Max and min element in the array is %c and %c\n", input_arr[0], input_arr[strlen(input_arr)-1]);
    
    free(input_arr);
    input_arr = NULL;
    
    return 0;
}
