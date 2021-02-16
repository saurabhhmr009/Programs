/* handling Signals in C. Use kill -l to list all the signals.
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler(int sig_num){
    printf("\nSignal caught.....exiting the program\n");
    exit(1);
}
  
int main(void) 
{
    //define the signal to be handle
    signal(SIGINT, sig_handler); 
    while (1) 
    { 
        printf("hello world\n"); 
        sleep(1); 
    } 
    return 0; 
} 
