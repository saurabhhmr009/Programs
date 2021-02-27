/* Find substrings in a string
 */

#include <stdio.h>  
#include <string.h>  
    
void substring(char s[], char sub[], int p, int len){  
   int c = 0;  
   while (c < len) {  
      sub[c] = s[p+c];  
      c++;  
   }  
   sub[c] = '\0';  
}  
   
int main()  
{  
    char c[6];
    char vowel_arr[] = "aAeEiIoOuU";  
    int i, j, len, sum, length, k; 
    int test_cases;
    
    scanf("%d", &test_cases);
    
    while(test_cases --) {
        char str[50];
        sum = 0;
        scanf(" %[^\n]", str);
        len = strlen(str);
        for(i = 0; i < len; i++){  
            for(j = 1; j <= len-i; j++){  
                substring(str,c,i,j);
                length = strlen(c);
                for(k=0; k<length; k++) {
                    if(strchr(vowel_arr, c[k])) {
                        sum += 1;
                    }
                }
            }
        }
        printf("%d\n", sum);
    }
    return 0;  
}
