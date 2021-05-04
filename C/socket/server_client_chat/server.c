#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv) {
    int sockfd, new_sockfd, port_num, check, enable = 1;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[255];

    if (argc < 2) {
        printf("Port number not provided. Terminating!!!\n");
        exit(EXIT_FAILURE);
    }

    // To flush the server_addr struct with 0.
    bzero((char*)&server_addr, sizeof(server_addr));

    port_num = atoi(argv[1]);

    // Creates the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("sockid failed\n");
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
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Binds the created socket to the port number and address.
    if(bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed\n");
        exit(EXIT_FAILURE);
    }

    // Making socket listen
    if(listen(sockfd, 4) < 0) {
        perror("listen failed\n");
        exit(EXIT_FAILURE);
    }

    // Accepts the incoming socket connections , total number is 4.
    new_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
    if(new_sockfd < 0) {
        perror("accept failed\n");
        exit(EXIT_FAILURE);
    }

    // Code section for ttansfering the data between server and client.
    while(1) {
        memset(buffer, 0, 255);
        check = read(new_sockfd, buffer, 255);
        if(check < 0) {
            perror("Error in reading\n");
        }
        printf("Client: %s\n", buffer);

        memset(buffer, 0, 255);
        fgets(buffer, 255, stdin);
        check = write(new_sockfd, buffer, strlen(buffer));
        if(check < 0) {
            perror("Error in writing\n");
        }

        int comp = strncmp("bye", buffer, 3);
        if(comp == 0) {
            break;
        }
    }

    close(new_sockfd);
    close(sockfd);
    return 0;
}
