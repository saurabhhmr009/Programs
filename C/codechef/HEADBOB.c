#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int people, gestures;
    char *info = NULL;

    scanf("%d", &people);
    while(people--) {
        int flag = 0;
        scanf("%d", &gestures);
        info = (char*)malloc(gestures*sizeof(char));
        scanf(" %[^\n]", info);
        for(int i=0; i<gestures; i++) {
            if(*(info+i) == 'Y') {
                printf("NOT INDIAN\n");
                flag = 1;
                break;
            }
            else if(*(info+i) == 'I') {
                printf("INDIAN\n");
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            printf("NOT SURE\n");
        }
        free(info);
    }
    info = NULL;
    return 0;
}