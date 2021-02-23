#include <stdio.h>
#include <stdlib.h>


unsigned int reverseBits(unsigned int num) 
{ 
    unsigned int count = sizeof(num) * 8 - 1; 
    unsigned int reverse_num = num; 
      
    num >>= 1;  
    while(num) 
    { 
       reverse_num <<= 1;        
       reverse_num |= num & 1; 
       num >>= 1;
       count--;
    } 
    reverse_num <<= count; 
    return reverse_num; 
}   
  
/* Driver function to test above function */
int main() 
{ 
    unsigned int x = 4;
    printf("%u\n", reverseBits(x)); 
    return 0;
} 
