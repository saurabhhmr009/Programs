#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int test, length, i,left, right;

    scanf("%d", &test);

    while(test--) {
        char str[1001];
        int set1[27] = {0}, set2[27] = {0};
        int flag = 0;

        scanf("%s", str);
        length = strlen(str);
        left = (length/2)-1;
        if(length%2 == 0) {
            right = left+1;
        }
        else {
            //skip the middle char
            right = left+2;
        }
        for(i=0; i<=left; i++) {
            set1[str[i]-97]++;
            set2[str[i+right]-97]++;
        }

        for(i=0; i<=26; i++) {
            if(set1[i] != set2[i]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}