/* In IPC/ Linux, process replacement is done using exec families. The 
 * replaces the current process image with a new process image. It loads
 * the program into the current process space and runs it from the entry
 *  point.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    pid_t child;
    int i = 0;
    char arg[10];
    
    child = fork();
    if(child >= 0) {
        if(child == 0) {
            printf("In the child process block\n");
            printf("Child PID and PPID is %d and %d\n", getpid(), getppid());
            i++;
            sprintf(arg, "%d", i);
            printf("String %s\n", arg);
            char * argv_list[] = {"./sample",arg,NULL};
            //execv("/home/saurabh/Documents/C/ipc/sample",argv_list);
            execvp("./sample", argv_list);
            printf("Commands after this will not get printed\n");
            
        }
        else {
            printf("In the parent process block\n");
            printf("Child PID and PPID is %d and %d\n", getpid(), getppid());
            printf("%d\n", i);
        }
    }
    else {
        perror("Fork error");
        return(1);
    }
    return 0;
}
