#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#define MEMORYSIZE 1024

int main(void) {
    int shm_id;
    key_t key;
    char *shm_add;
    char buff[50];
    
    key = ftok("test.txt", 45);
    
    shm_id = shmget(key, MEMORYSIZE, 0644 | IPC_CREAT);
    if(shm_id < 0) {
        perror("Shared memory creation");
        exit(1);
    }
    
    shm_add = shmat(shm_id, NULL, 0);
    if(shm_add < 0) {
        perror("Memory attach");
        exit(1);
    }
    
    strcpy(buff, shm_add);
    printf("%s\n", buff);
    
    if(shmdt(shm_add) == -1) {
        perror("Detach failed");
        exit(1);
    }
    shmctl(shm_id,IPC_RMID,NULL);
    printf("Detached and all Done\n");
    return 0;
}

