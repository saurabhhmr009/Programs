
#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAXSIZE 50

struct message {
    long msg_id;
    char msg_buff[MAXSIZE];
}msg;

int main(void) {
    key_t msg_key;
    int msgid;
    
    msg_key = ftok("test.txt", 30);
    if(msg_key < 0) {
        perror("ftok creation error");
        exit(1);
    }
    
    msgid = msgget(msg_key, 0644 | IPC_CREAT);
    if(msgid < 0) {
        perror("Message Queue failed");
        exit(1);
    }
    
    msgrcv(msgid, &msg, sizeof(msg), 1, 0); 
    printf("Data Received is : %s \n",  msg.msg_buff);
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
