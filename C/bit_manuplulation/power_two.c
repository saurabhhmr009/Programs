/*Program to check if a number is a power of two. Logic is 
 *bitwise and of the number whose power of two is to be determined 
 * and one less than the number is always 0.
 */
  
#include <stdio.h>

int main(void) {
    int flag,data;
    scanf("%d", &data);
    
    flag = data & (data - 1);
    printf("%d\n", flag);
    if(flag == 0)
    {
        printf("Number is a power of 2 \n");
    }
    else
    {
        printf("Enter number is not power of 2 \n");
    }
    return 0;
}
