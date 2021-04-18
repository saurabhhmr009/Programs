#include <stdio.h>
#include <stdlib.h>

int main(void){
    int test_cases, N, K, i, j, count, max_occ;
    char *str = NULL;
    scanf("%d", &test_cases);
    
    while(test_cases){
        scanf("%d %d", &N, &K);
        str = (char*)malloc(N*sizeof(char));
        count = max_occ = 0;
        for(i=0; i<N; i++){
            if(str[i] == '*'){
                count++;
                if(count > max_occ){
                    max_occ = count;
                }
            }
            else {
                count = 0;
            }
        }
        if(max_occ >= K) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
        test_cases--;
        free(str);
        str = NULL;
    }
    return 0;
}
    