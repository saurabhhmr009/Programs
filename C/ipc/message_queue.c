/* Message Queues. Asynchronous type.
 * All processes can exchange information through access to a common 
 * system message queue. The sending process places a message onto a 
 * queue which can be read by another process. Each message is given an 
 * identification or type so that processes can select the appropriate 
 * message. Process must share a common key in order to gain access to 
 * the queue in the first place.
 * Steps : Create the message structure-> get the unique id using ftok()
 * -> generate a message queue using msgget()-> then msgsnd()-> msgrcv()
 */

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
    
    msg.msg_id = 1;
    fgets(msg.msg_buff, MAXSIZE, stdin);
    msgsnd(msgid, &msg, sizeof(msg), 0);
    
    //msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
