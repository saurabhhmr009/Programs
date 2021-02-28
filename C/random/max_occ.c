/* A function to calculate the max number of the occurence of a element in a array.
 * You can also calculate the max number by this.
 *
 * candles_count is the array size and candles is the int pointer to the array
 */

int birthdayCakeCandles(int candles_count, int* candles) {
    int tallest = 0, occurence = 0;
    int i, j;
    for(i=0; i<candles_count; i++) {
        if(*(candles+i) > tallest) {
            tallest = *(candles +i);
        }
    }
    for(i=0; i<candles_count; i++) {
        if(tallest == *(candles+i)) {
            occurence += 1;
        }
    }
    return occurence;
}
