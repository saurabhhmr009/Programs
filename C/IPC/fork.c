#include "headers.h"

int main(void) {
    pid_t child;

    child = fork();
    //printf("Main block PID %d PPID %d\n", getpid(), getppid());
    printf("\n");
    int var = 1;
    if(child < 0) {
        perror("fork() failed.\n");
        return 1;
    }
    if(child > 0) {
        int a = 10, b = 20;
        printf("In the parent block. PID %d PPID %d\n", getpid(), getppid());
        var--;
        printf("%d %d\n", a*b, var);
    }
    if(child == 0) {
        int a = 10, b = 20;
        printf("In the child block. PID %d PPID %d\n", getpid(), getppid());
        var++;
        printf("%d %d\n", a+b, var);
    }
    return 0;
}