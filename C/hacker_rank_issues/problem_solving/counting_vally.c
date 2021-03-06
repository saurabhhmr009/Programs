#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int path, i, vally_count = 0, sea_level = 0;
    char *steps = NULL;
    
    scanf("%d", &path);
    steps = (char*)malloc((path)*sizeof(char));
    scanf(" %[^\n]", steps);
    
    for(i=0; i<path; i++) {
        if(steps[i] == 'U') {
            sea_level += 1;
        }
        else if(steps[i] == 'D') {
            sea_level -= 1;
        }
        // track of coming up to sea level.
        if(sea_level == 0 && steps[i] == 'U') {
            vally_count++;
        }
    }
    printf("%d\n", vally_count);
    free(steps);
    steps = NULL;
    return 0;
}
