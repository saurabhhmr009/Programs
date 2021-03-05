#include <stdio.h>

int main(void) {
    int year;
    
    scanf("%d", &year);
    
    if(year <= 1917) {
        if((year%4) == 0) {
            printf("12.09.%d\n", year);
        }
        else {
            printf("13.09.%d\n", year);
        }
    }
    else if (year > 1918) {
        if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0)){
            printf("12.09.%d\n", year);
        }
        else {
            printf("13.09.%d\n", year);
        }
    }
    else {
        printf("26.09.%d\n", year);
    }
    return 0;
}
