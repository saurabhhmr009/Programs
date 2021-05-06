/* Best Time to Buy and Sell Stock II */

#include <stdio.h>
#include <stdlib.h>

int maxProfit(int *price, int pricesSize) {
    int max_profit = 0, i;
    if(pricesSize == 1) {
        return max_profit;
    }
    for(i = 0; i<pricesSize-1; i++) {
        if(*(price+i) < *(price+i+1)) {
            max_profit += *(price+i+1) - *(price+i);
        }
    }
    return max_profit;
}


int main (void) {
    int *price = NULL;
    int pricesSize, i, max_profit = 0;

    scanf("%d", &pricesSize);
    price = (int*)malloc(pricesSize*sizeof(*price));
    for(i=0; i<pricesSize; i++) {
        scanf("%d", price+i);
    }

    max_profit = maxProfit(price, pricesSize);
    printf("%d\n", max_profit);
    free(price);
    price = NULL;
    return 0;
}