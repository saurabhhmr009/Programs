/* Use of wait() to make parent process wait until child is not finished
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main(void){
    pid_t child;
    int status;
    
    child = fork();
    if (child >= 0) {
        if(child == 0) {
            sleep(30);
            printf("In the child process And that's it.\n");
        }
        else {
            printf("In the parent process. Putting parent into sleep\n");
            printf("Check ps command for the child\n");
            printf("Putting  parent into wait\n");
            wait(&status);
            printf("Wait done. Child exited with the status of %d\n", WEXITSTATUS(status));
            
        }
    }
    else {
        perror("fork");
        return(1);
    }
    return 0;
}
