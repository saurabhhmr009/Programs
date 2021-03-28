/* Program to receive an integer, print the digits
 * prints the sum of the digits in the integer.
 */

 #include <stdio.h>

 int main(void) {
    int num, sum = 0, digit;

    printf("Enter the number: \n");
    scanf("%d", &num);

    printf("Digits in the entered number are: ");
    while(num) {
        digit = num%10;
        printf("%d ", digit);
        num = num/10;
        sum += digit;
    }

    printf("\nThe sum of the digits are %d\n", sum);
    return 0;
 }  