/* Program to show about the zombie and orphan process.
 * Orphan process is when parent process exits before the completion of
 * the child proces.
 * Zombie is when child has finished its execution and its entry is
 * still in the ID table. Example is parent goes on sleep while child is
 * done
 * 
 * Uncomment the sleep in child if block if want to check orphan process
 * Uncomment the sleep in the parent else block if want to check the 
 * zombie process.  
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    pid_t child;
    int variable = 0;
    
    child = fork();
    if (child >= 0) {
        if(child == 0) {
            //sleep(30);
            printf("In the child process And that's it.\n");
        }
        else {
            printf("In the parent process. Putting parent into sleep\n");
            printf("Check ps command for the child\n");
            sleep(30);
            printf("After sleep, check the ps command\n");
        }
    }
    else {
        perror("fork");
        return(1);
    }
    return 0;
}
