#include "connect.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX 80
#define PORT 8080
#define BUFFSIZE 1024


int InitConnection(int DEBUG)
{
    int sockfd;
    const char BUFF[BUFFSIZE] = "[FCONN]";
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("%i", sockfd);
    if (sockfd < 0) {
        if (DEBUG) {
            printf("socket creation failed...\n");
        }
        exit(0);
    }
    printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    printf("connected to the server..\n");

    if (send(sockfd, BUFF, sizeof(BUFF), 0) < 0)
    {
        printf("Socket send err..\n");
        exit(5);
    }

    printf("[*] Client connect to server\n");

    return sockfd;
}
