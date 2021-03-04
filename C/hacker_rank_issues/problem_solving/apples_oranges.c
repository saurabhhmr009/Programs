#include <stdio.h>
#include <stdlib.h>

int cal_apples(int *arr, int location, int length, int range1, int range2) {
    int i, total_apples = 0;
    for(i=0; i<length; i++) {
        if((*(arr+i)+location >= range1) && (*(arr+i)+location <= range2)) {
            total_apples++;
        }
    }
    return total_apples;
}

int cal_oranges(int *arr, int location, int length, int range1, int range2) {
    int i, total_oranges = 0;
    for(i=0; i<length; i++) {
        if((*(arr+i)+location >= range1) && (*(arr+i)+location <= range2)) {
            total_oranges++;
        }
    }
    return total_oranges;
}

int main(void) {
    int house_range1, house_range2;
    int apple, orange;
    int no_of_apples, no_of_oranges;
    int *apples_arr = NULL, *oranges_arr = NULL;
    int apples_range = 0, oranges_range = 0, i;
    
    scanf("%d %d", &house_range1, &house_range2);
    scanf("%d %d", &apple, &orange);
    scanf("%d %d", &no_of_apples, &no_of_oranges);
    apples_arr = (int*)malloc(no_of_apples*sizeof(int));
    oranges_arr = (int*)malloc(no_of_oranges*sizeof(int));
    for(i=0; i<no_of_apples; i++) {
        
        scanf("%d", apples_arr+i);
    }
    for(i=0; i<no_of_oranges; i++) {
        scanf("%d", oranges_arr+i);
    }

    apples_range = cal_apples(apples_arr, apple, no_of_apples, house_range1, house_range2);
    oranges_range = cal_oranges(oranges_arr, orange, no_of_oranges, house_range1, house_range2);
    printf("%d\n", apples_range);
    printf("%d\n", oranges_range);
    
/*    for(i = 0; i<no_of_apples; i++) {
        if((apples_arr+i) != NULL) {
            free(apples_arr+i);
            (apples_arr+i) = NULL;
        }
    }
    free(apples_arr);
    apples_arr = NULL;
    
    for(i = 0; i<no_of_oranges; i++) {
        if((oranges_arr+i) != NULL) {
            free(oranges_arr+i);
            (oranges_arr+i) = NULL;
        }
    }*/
    free(oranges_arr);
    oranges_arr = NULL;

    return 0;
}
