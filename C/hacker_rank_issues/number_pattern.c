#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int n, row, col, center_distance;
    scanf("%d", &n);
  	int init_row = n - 1;
    int init_col = 1 - n;

    for (row = init_row; row > -n; row--) {
        for (col = init_col; col < n; col++) {
            center_distance = (abs(row) > abs(col)) ? abs(row) : abs(col);
            printf("%d ", center_distance + 1);
        }
    puts("");
    }
	return 0;
}

