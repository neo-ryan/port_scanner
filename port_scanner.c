# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("[!] Argumentos insuficientes");
        printf("[!] Ex.: %s [ip]\n", argv[0]);
        return 1;
    }


    struct sockaddr_in target;

    memset(&target, 0, sizeof(target));

    target.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &target.sin_addr);

    for (int i = 0; i <= 10000; i++) {

        int serverfd = socket(AF_INET, SOCK_STREAM, 0);

        if (serverfd < 0) {
            perror("[!] Falha na criação do socket");
            exit(EXIT_FAILURE);
        }
        target.sin_port = i;
        int res = connect(serverfd, (struct sockaddr *)&target, sizeof(target));
        if (res == 0) {
            printf("[/] %d Aberta\n", target.sin_port);
            }
        close(serverfd);
    }
    return 0;
}
