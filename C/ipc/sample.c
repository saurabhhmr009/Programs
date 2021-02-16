#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int value_passed;
    value_passed = atoi(argv[1]);
    value_passed++;
    printf("PID and PPID is %d and %d\n", getpid(), getppid());
    printf("Hello from the sample program. the value passed is %d\n", value_passed);
    return 0;
}
