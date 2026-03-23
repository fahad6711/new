#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sfd, cfd;
    struct sockaddr_in saddr, caddr;
    char buf[1024];
    socklen_t len = sizeof(caddr);

    sfd = socket(AF_INET, SOCK_STREAM, 0);

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(9090);
    saddr.sin_addr.s_addr = INADDR_ANY;

    bind(sfd, (struct sockaddr*)&saddr, sizeof(saddr));
    listen(sfd, 5);

    while (1) {
        cfd = accept(sfd, (struct sockaddr*)&caddr, &len);
        read(cfd, buf, sizeof(buf));
        printf("Client: %s\n", buf);
        write(cfd, "Hello from server", 17);
        close(cfd);
    }

    return 0;
}