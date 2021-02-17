/* Pipes in IPC :-
 * 
 * Way to communicate b/w two or more processes. Could be different processes or parent child of the same.
 * One way communication. One writes,other reads. Opens a virtual file in the main memory for that. fd1 is for write and fd0 for read.
 * If one tries to read before write, read process goes on hang.
 * Returns 0 when successfully created, negative when error.
 * You can write a chunck of data in the pipe at one time but you can read one one by one at the receiving end.
 * Process :- Create pipe fds using int pipe(fd). Fd could be a array of two ints. the use fd1 for write and fd0 for read. Close Fd after process is done.
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
    int return_val, i;
    char *input_string;
    char *output_string;
    
    return_val = pipe(pipe_fd);
    if(return_val < 0) {
        perror("Pipe creation failled!!!");
        exit(1);
    }
    else {
        // Pipe write operation.
        input_string = (char*)malloc(MAXLENGTH*sizeof(char));
        scanf("%[^\n]", input_string);
        write(pipe_fd[1], input_string, strlen(input_string));
        
        output_string = (char*)malloc(MAXLENGTH*sizeof(char));
        read(pipe_fd[0], output_string, strlen(input_string));
        
        //for(i=0; i<strlen(output_string); i++) {
        printf("%s", output_string);
    }
    close(pipe_fd[1]);
    close(pipe_fd[0]);
    free(input_string);
    free(output_string);
    input_string = output_string = NULL;
    return 0;
}
