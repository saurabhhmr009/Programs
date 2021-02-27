/* Program to add two large numbers in C.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse the string.
void reverser_string(char *str) {
    int i, length;
    char temp;
    
    length = strlen(str);
    
    for(i=0; i<length/2; i++) {
        temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }
}

// Function to add the strings.
void add_strings(char* num1, char* num2, char *result) {
    int i, carry  = 0, sum  = 0, dec = 0;
    char *small =  NULL;
    char *big = NULL;

    //stupid method but saves time. Can make a swap function for it. 
    if(strlen(num1) > strlen(num2)) {
        big = num1;
        small = num2;
    }
    else {
        big = num2;
        small = num1;
    }

    for(i=0; i<strlen(small); i++) {
        sum = (small[i] -'0') + (big[i] - '0') + carry;
        if (sum > 9) {
            dec = sum%10;
            result[i] = dec + '0';
            carry  = sum/10;
        }
        else {
            result[i] = sum + '0';
            carry = 0;
        }
    }

    for(i = strlen(small); i<strlen(big); i++) {
        sum = (big[i] - '0') + carry;
        if (sum > 9) {
            dec = sum%10;
            result[i] = dec+'0';
            carry = sum/10;
        }
        else {
            result[i] = sum + '0';
            carry = 0;
        }
    }

    if(carry) {
        result[i] = carry +'0';
    }
    result = realloc(result,strlen(result)+1);
    
    reverser_string(result);
    printf("%s\n", result);

}

int main(void) {
    char *num1 = NULL, *num2 = NULL, *result = NULL;
    
    num1 = (char*)malloc(1024*sizeof(char));
    num2 = (char*)malloc(1024*sizeof(char));
    result = (char*)malloc(1024*sizeof(char));
    
    scanf(" %[^\n]", num1);
    scanf(" %[^\n]", num2);
    
    num1 = realloc(num1, strlen(num1)+1);
    num1 = realloc(num1, strlen(num2)+1);
    
    reverser_string(num1);
    reverser_string(num2);
    add_strings(num1, num2, result);
    
    free(num1);
    free(num2);
    free(result);
    num1 = num2 = result = NULL;

    return 0;
}
