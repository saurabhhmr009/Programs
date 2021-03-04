#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double calculate_area(triangle *tr) {
	double p, area;
	p = (tr->a +tr->b + tr->c)/2;
	area = (p*(p-tr->a)*(p-tr->b)*(p-tr->c));
	return area;
}

void swap_struct(triangle *tr1, triangle *tr2) {
	triangle temp = *tr1;
	*tr1 = *tr2;
	*tr2 = temp;
}

void sort_by_area(triangle* tr, int n) {
	int i, j;
	for(i=0; i<n; i++) {
		for(j=0; j<n-i-1; j++) {
			if(calculate_area(tr+j) > calculate_area(tr+j+1)) {
				swap_struct(tr+j, tr+j+1);
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
