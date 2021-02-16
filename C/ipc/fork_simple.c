/* A simple fork example. Fork return pid of child on successful to 
 * parent and 0 to child process. The child has its own unique process
 * ID. The child process and the parent process run in separate memory 
 * spaces. At the time of fork() both memory  spaces  have  the  same  
 * content. Memory writes, file mappings performed by one of the 
 * processes do not affect the other.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    pid_t child;
    int variable = 0;
    
    printf("The PID and PPID before fork are %d and %d\n", getpid(), getppid());
    child = fork();
    
    if(child >= 0) {
        if(child == 0) {
            printf("In the child process\n");
            printf("The PID and PPID are %d and %d\n", getpid(), getppid());
            variable++;
            variable++;
            printf("The variable in child %d\n", variable);
        }
        else {
            printf("In the parent process\n");
            printf("The PID and PPID are %d and %d\n", getpid(), getppid());
            printf("The variable in parent %d\n", variable);
        }
    }
    else {
        perror("fork");
        return 1;
    }
    printf("The PID and PPID in last %d and %d\n", getpid(), getppid());
    printf("The variable in last %d\n", variable);
    return 0;
}
