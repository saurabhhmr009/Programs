#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int ret_dd, ret_mm, ret_yy;
    int due_dd, due_mm, due_yy;
    int fine, date_diff, month_diff;
    
    scanf("%d %d %d", &ret_dd, &ret_mm, &ret_yy);
    scanf("%d %d %d", &due_dd, &due_mm, &due_yy);
    
    if(ret_yy == due_yy) {
        if(ret_mm <=due_mm) {
            if(ret_dd <= due_dd) {
                fine = 0;
            }
            else {
                date_diff = ret_dd - due_dd;
                fine  = 15*date_diff;
            }
        }
        else {
            month_diff = ret_mm - due_mm;
            fine = 500*month_diff;
        }
    }
    else if (ret_yy > due_yy) {
        fine = 10000;
    }
    printf("%d\n", fine);
    return 0;
}
