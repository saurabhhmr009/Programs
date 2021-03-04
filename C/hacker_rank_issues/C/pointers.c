#include <stdio.h>
#include <stdlib.h>

void update(int *ptr1, int *ptr2) {
	int max = (*ptr1) + (*ptr2);
	int min = abs((*ptr1) - (*ptr2));
	*ptr1 = max;
	*ptr2 = min;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
