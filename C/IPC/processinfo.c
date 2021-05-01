#include "headers.h"

int main() {
    printf("Process id is %d\n", getpid());
    printf("Parent process id is %d\n", getppid());

    printf("\n");
    system("ps -ax | grep processinfo");
    return 0;
}
