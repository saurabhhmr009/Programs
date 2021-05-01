#include <stdio.h>

int factorial(int num) {
    static int result = 1;
    if(num == 0) {
        return result;
    }
    result = result*num;
    num--;
    return factorial(num);
}

int main(void) {
	int num = 6, result;

    result = factorial(num);
    printf("%d\n", result);
	return 0;
}
