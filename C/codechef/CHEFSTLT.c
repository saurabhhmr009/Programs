#include <stdio.h>
#include <string.h>

int main(void) {
    int cases, max_diff, min_diff;
    scanf("%d", &cases);

    while(cases--) {
        char str1[102];
        char str2[102];
        //fgets(str1, 102, stdin);
        //fgets(str2, 102, stdin);
        scanf("%s", str1);
        scanf("%s", str2);


        int i = 0;

        max_diff = min_diff = 0;
        while(str2[i] != '\0') {
            //printf("Test\n");
            if(str1[i] == '?' || str2[i] == '?') {
                max_diff++;
            }
            if(str1[i] != str2[i] && str1[i] != '?' && str2[i] != '?') {
                min_diff++;
                max_diff++;
            }
            i++;
        }
        printf("%d %d\n", min_diff, max_diff);
    }
    return 0;
}