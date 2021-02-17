/* Parent will try to write and child will try to read.
 * Points taken. Free the memory oin the parent. Because things before return 0 are executed by both child and parent.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
# define MAXLENGTH 1024

int main(void) {
    int pipe_fd [2] = {0};
    pid_t child;
    int return_val, status;
    char *input_string;
    char *output_string;
    
    return_val = pipe(pipe_fd);
    if(return_val < 0) {
        perror("Pipe creation failled!!!");
        exit(1);
    }
    child = fork();
    if(child >= 0) {
        if(child == 0) {
            printf("In the Child process\n");
            printf(" Parent PID and PPID %d %d \n", getpid(), getppid());
            output_string = (char*)malloc(MAXLENGTH*sizeof(char));
            read(pipe_fd[0], output_string, MAXLENGTH);
            printf("%s\n", output_string);
            printf("Child completed\n");
            free(output_string);
            output_string = NULL;
            
        }
        else {
            // Pipe write operation.
            printf("In the parent process\n");
            printf("PArent PID and PPID %d %d \n", getpid(), getppid());
            input_string = (char*)malloc(MAXLENGTH*sizeof(char));
            scanf("%[^\n]", input_string);
            write(pipe_fd[1], input_string, strlen(input_string));
            wait(&status);
            close(pipe_fd[1]);
            close(pipe_fd[0]);
            free(input_string);
            input_string = NULL;
            printf("PArent completed\n");
            
        }
    }
    else {
        perror("Fork creation");
        exit(1);
    }
    
    
    printf("PID and PPID %d %d \n", getpid(), getppid());

    return 0;
}
