// Takes a Char, Word and Sentence from the STDIN and print it

#include <stdlib.h>
#include <stdio.h>
#define MAX_LEN 100

int main() {
    char ch;
    char s[MAX_LEN];
    char sen[MAX_LEN];

    scanf("%c", &ch);
    scanf("%s", &s);
    scanf("\n");
    scanf("%[^\n]%*c", &sen);
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);
    return 0;
}
