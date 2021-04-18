#include <stdio.h>

int fibonacci(int num){
    if(num <= 1) {
        return num;
    }
    return(fibonacci(num-1) + fibonacci(num-2));
}
int main(void) {
    int num = 10, result;

    result = fibonacci(num);
    printf("%d\n", result);
    return 0;
}