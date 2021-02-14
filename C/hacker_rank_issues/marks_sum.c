#include <stdio.h>
#include <stdlib.h>

int marks_summation(int *arr, int total_students, char gender) {
	int i;
	int index, sum = 0;
	
	if(gender == 'b') {
		index = 0;
	}
	else if (gender == 'g') {
		index = 1;
	}
	else {
		return 1;
	}
	
	for(i=index; i<=total_students-1; i++) {
		sum += *(arr+i);
		i++;
	}
	return sum;
}

int main(void)
{
	int length, i, sum = 0;
	int *marks = NULL;
	char gender;
	
	scanf("%d", &length);
	marks = (int*)calloc(length, sizeof(int));
		
	for(i=0; i<length; i++) {
		scanf("%d", (marks+i));
	}
	
	scanf(" %c", &gender);
	sum = marks_summation(marks, length, gender);
	printf("%d\n", sum);
	free(marks);
	marks = NULL;
	
	return 0;
}

