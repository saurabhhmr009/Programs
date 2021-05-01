#include <stdio.h>
#include <math.h>

int main(void) {
    int cases, x1, y1, x2, y2, x3, y3, r;
    float xy,yz,zx;

    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&r);
        scanf("%d %d",&x1,&y1);  
        scanf("%d %d",&x2,&y2);  
        scanf("%d %d",&x3,&y3);  
        
        xy = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        yz = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
        zx = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));

        if((xy <= r && yz <= r) || (yz <= r && zx <= r) || (xz <= r && zx <= r)) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
    return 0;
}
