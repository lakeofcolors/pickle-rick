#include <sys/socket.h>
#include "connect.h"
#include "handler.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    int conn = InitConnection(1);
    HandleConnection(conn);
    return 0;
}
