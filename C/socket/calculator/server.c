#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

float cal_result(float num1, float num2, int choice) {
    float result;

    switch(choice) {
        case 1: {
            result = num1 + num2;
            break;
        }
        case 2: {
            result = num1 - num2;
            break;
        }
        case 3: {
            result = num1 * num2;
            break;
        }
        case 4: {
            result = num1 / num2;
            break;
        }
        case 5: {
            printf("This will never run, need corrections\n");
            break;
        }
        default: {
            printf("Wrong Input\n");
            exit(EXIT_FAILURE);
        }
    }
    return result;
}

int main(int argc, char **argv) {
    int sockfd, new_sockfd, port_num, check, enable = 1, choice;
    float num1, num2, result;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);


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
        check = write(new_sockfd,"Enter your choice: \n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n",
            strlen("Enter your choice: \n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n"));
        if(check < 0) {
            perror("Error in writing");
            exit(EXIT_FAILURE);
        }

        check = read(new_sockfd, &choice, sizeof(int));
        if(check < 0) {
            perror("Error in reading\n");
            exit(EXIT_FAILURE);
        }
        if(choice == 5) {
            break;
        }

        check = write(new_sockfd, "Enter first number: ", strlen("Enter first number: "));
        if(check < 0) {
            perror("Error in writing\n");
            exit(EXIT_FAILURE);
        }

        check = read(new_sockfd, &num1, sizeof(float));
        if(check < 0) {
            perror("Error in reading\n");
            exit(EXIT_FAILURE);
        }

        check = write(new_sockfd, "Enter second number: ", strlen("Enter second number: "));
        if(check < 0) {
            perror("Error in writing\n");
            exit(EXIT_FAILURE);
        }

        check = read(new_sockfd, &num2, sizeof(float));
        if(check < 0) {
            perror("Error in reading\n");
            exit(EXIT_FAILURE);
        }

        result = cal_result(num1, num2, choice);

        check = write(new_sockfd, &result, sizeof(result));
        if(check < 0) {
            perror("Answer write failled\n");
            exit(EXIT_FAILURE);
        }
    }

    close(new_sockfd);
    close(sockfd);
    return 0;
}
