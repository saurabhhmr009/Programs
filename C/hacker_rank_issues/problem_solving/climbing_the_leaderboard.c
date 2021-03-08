#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int total_players, individual, i, j, k;
    int *players_scores = NULL;
    int *individual_score = NULL;
    
    scanf("%d", &total_players);
    players_scores = (int*)malloc(total_players*sizeof(int));
    for(i=0; i<total_players; i++) {
        scanf("%d", players_scores+i);
    }
    scanf("%d", &individual);
    individual_score = (int*)malloc(individual*sizeof(int));
    for(i=0; i<individual; i++) {
        scanf("%d", individual_score+i);
    }
    
    for(i=0; i<total_players; i++) {
        for(j=i+1; j<total_players; j++) {
            if(*(players_scores+i) == *(players_scores+j)) {
                for(k=j; k<total_players-1; k++) {
                    *(players_scores+k) = *(players_scores+k+1);
                }
                total_players--;
                j--;
            }
        }
    }
    //players_scores = realloc(players_scores, total_players);
    
    for(i=0; i<individual; i++) {
        for(j=0; j<total_players; j++) {
            if(*(individual_score+i) >= *(players_scores+j)) {
                printf("%d\n", j+1);
                break;
            }
            else if(*(individual_score+i) < *(players_scores+total_players-1)) {
                printf("%d\n", total_players+1);
                break;
            }
            else {
                continue;
            }
        }
    }
    return 0;
}
