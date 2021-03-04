#include <stdio.h>
#include <stdlib.h>

void cal_streaks(int *scores, int games) {
    int highest_score, highest_streak = 0;
    int lowest_score, lowest_streak = 0;
    int i;
    highest_score = lowest_score = *scores;

    for(i=1; i<games; i++) {
        if(*(scores+i) > highest_score) {
            highest_streak += 1;
            highest_score = *(scores+i);
        }
        else if(*(scores+i) < lowest_score) {
            lowest_streak += 1;
            lowest_score = *(scores+i);
        }
    }
    printf("%d %d\n", highest_streak, lowest_streak);
}

int main(void) {
    int games, i;
    int *scores = NULL;
    
    scanf("%d", &games);
    scores = (int*)malloc(games*sizeof(int));
    for(i=0; i<games; i++) {
        scanf("%d", scores+i);
    }
    cal_streaks(scores, games);
    return 0;
} 
