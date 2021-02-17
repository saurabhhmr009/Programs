/* Named pipes(FIFO) in Linux.
 */
 
 #include <stdlib.h>
 #include <stdio.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <string.h>
 #include <sys/stat.h>
 
 
 #define MAXSIZE 1024
 
 int main(void) {
     char *temp_file = "/tmp/fifo";
     int fifo_fd;
     char *send_buffer = NULL;
     char *read_buffer = NULL;
     
     mkfifo(temp_file, 0666);
     send_buffer = (char*)malloc(100*sizeof(char));
     read_buffer = (char*)malloc(100*sizeof(char));
     
     while(1) {
         fifo_fd = open(temp_file, O_RDONLY) ;
         read(fifo_fd, read_buffer, MAXSIZE);
         printf("USER1: %s\n", read_buffer);
         if(strcmp(read_buffer, "Quit") == 0) {
             printf("Okay bye\n");
             break;
         }
         close(fifo_fd);
         
         fifo_fd = open(temp_file, O_WRONLY);
         fgets(send_buffer, 100, stdin);
         //scanf("%[^\n]", send_buffer);
         write(fifo_fd, send_buffer, 80);
         
         close(fifo_fd);
     }
     return 0;
 }
