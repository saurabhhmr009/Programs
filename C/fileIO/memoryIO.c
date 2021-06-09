#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include<sys/stat.h>


int main(void) {
    int fd = open("input.txt",O_RDWR, S_IRUSR|S_IWUSR);
    struct stat sb;

    if(fstat(fd, &sb) == -1) {
        perror("Error in getting the information from the file\n");
        exit(1);
    }

    printf("File size is %ld\n", sb.st_size);

    char *file_memory = mmap(NULL, sb.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    for(int i=0; i<sb.st_size; i++) {
        if((i%2) == 0) {
            file_memory[i] = toupper(file_memory[i]);
        }
        printf("%c", file_memory[i]);
    }
    munmap(file_memory, sb.st_size);
    close(fd);
    return 0;
}