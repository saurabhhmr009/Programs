#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include<ctype.h>

int main(int argc, char *argv[])
{
    int sockfd, port_num, check, enable = 1, choice;
    float num1, num2, result;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[1024];

    if (argc < 3)
    {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    port_num = atoi(argv[2]);
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    // To flush the server_addr struct with 0.
    bzero((char *) &server_addr, sizeof(server_addr));

    // Creates the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Resuse the port which is already in use.
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &enable, sizeof(int)) < 0) {
        perror("setsockopt failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the memebers of the struct server_addr
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_num);
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    // Make connect call to the server.
    if (connect(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr)) < 0) {
        perror("ERROR connecting\n");
        exit(EXIT_FAILURE);
    }

    // Code section for data transfer.
    while(1) {
        memset(buffer, 0, 1024);
        check = read(sockfd, buffer, 1024);
        if(check < 0) {
            perror("Option read failed\n");
            exit(EXIT_FAILURE);
        }
        printf("Server: %s\n", buffer);

        scanf("%d", &choice);
        check = write(sockfd, &choice, sizeof(int));
        if(check < 0) {
            perror("choice write failed\n");
            exit(EXIT_FAILURE);
        }
        if(choice == 5) {
            printf("Exiting the calculator\n");
            break;
        }

        memset(buffer, 0, 1024);
        check = read(sockfd, buffer, 1024);
        if(check < 0) {
            perror("num1 read failed\n");
            exit(EXIT_FAILURE);
        }
        printf("Server: %s\n", buffer);

        scanf("%f", &num1);
        check = write(sockfd, &num1, sizeof(float));
        if(check < 0) {
            perror("num1 write failed\n");
            exit(EXIT_FAILURE);
        }

        memset(buffer, 0, 1024);
        check = read(sockfd, buffer, 1024);
        if(check < 0) {
            perror("num2 read failed\n");
            exit(EXIT_FAILURE);
        }
        printf("Server: %s\n", buffer);

        scanf("%f", &num2);
        check = write(sockfd, &num2, sizeof(float));
        if(check < 0) {
            perror("num2 write failed\n");
            exit(EXIT_FAILURE);
        }

        check = read(sockfd, &result, sizeof(result));
        if(check < 0) {
            perror("result read failed\n");
            exit(EXIT_FAILURE);
        }
        printf("Result: %.2f\n\n", result);
    }

    close(sockfd);
    return 0;
}