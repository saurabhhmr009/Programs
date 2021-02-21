/* A program to check whether the entered date is a valid date or not.
 * Date is entered in string format and stored in a double pointer.
 * Steps: 1. Check year.
 * 2. Check month range.
 * 3. check days according to month.
 * 4. Check leapyear.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valid_date(int *split_arr) {
    int value;
    if((*(split_arr+2)>=1900) && (*(split_arr+2)<=2030)) {
        if((*(split_arr+1)>=1) && (*(split_arr+1)<=12)) {
            if(((*(split_arr)>=1) && (*(split_arr)<=31)) && ((*(split_arr+1) == 1) || (*(split_arr+1) == 3) \
            || (*(split_arr+1) == 5) || (*(split_arr+1) == 7) || (*(split_arr+1) == 8) || (*(split_arr+1) == 10) || (*(split_arr+1) == 12))) {
                value  = 0;
            }
            else if(((*(split_arr)>=1) && (*(split_arr)<=30)) && ((*(split_arr+1) == 4) || (*(split_arr+1) == 6) || (*(split_arr+1) == 9) || (*(split_arr+1) == 11))) {
                value = 0;
            }
            else if((*(split_arr)>=1) && (*(split_arr)<=28) && (*(split_arr+1) == 2)) {
                value  = 0;
            }
            else if((*(split_arr) == 29) && (*(split_arr+1)==2) && ((*(split_arr+2)%400 == 0) || ((*(split_arr+2)%4 == 0) && (*(split_arr+2)%100 != 0)))) {
                value = 0;
            }
        }
        else {
            value = 1;
        }
    }
    else {
        value = 1;
    }
    return value;
}

int main(void) {
    // Initialize variables
    int max_case;
    int i, j = 0;
    int split, result;
    int *split_date = NULL;
    char **date_arr = NULL;
    
    scanf("%d", &max_case);
    
    // Get the data for the date array pointer in dd/mm/yyyy format
    date_arr = (char**)malloc(max_case*sizeof(char*));
     for(i = 0; i<max_case; i++) {
         date_arr[i] = (char*)malloc(1024*sizeof(char));
         scanf(" %[^\n]", date_arr[i]);
         date_arr = realloc(date_arr,strlen(date_arr[i])+1);
     }
     
     // Print the contents of the date_arr pointer.
     for(i = 0; i<max_case; i++) {
         printf("%s\n", date_arr[i]);
     }
     
     split_date = (int*)calloc(3, sizeof(int));
     for(i=0; i<max_case; i++) {
         char *token = strtok(date_arr[i], "/");
         while((token != NULL) && j < 3) {
             split = atoi(token);
             *(split_date+j) = split;
             token = strtok(NULL, "/");
             j++;
         }
         //printf("%02d %02d %d\n", *(split_date), *(split_date+1), *(split_date+2));
         j = 0;
         result = valid_date(split_date);
         if(result == 0) {
             printf("%02d/%02d/%d is a valid date\n", *(split_date), *(split_date+1), *(split_date+2));
         }
         else {
             printf("%02d/%02d/%d is not a valid date\n", *(split_date), *(split_date+1), *(split_date+2));
         }
     }
     
     // Free the allocated memory to the date_arr pointer.


     for(i = 0; i<max_case; i++) {
         if(date_arr[i] != NULL) {
             free(date_arr[i]);
             date_arr[i] = NULL;
         }
     }
     free(date_arr);
     free(split_date);
     split_date = NULL;
     date_arr = NULL;
     
     return 0;
 }
