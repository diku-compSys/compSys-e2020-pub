/*
 * put.c - Puts a value to an iVar
 */
#include "csapp.h"

int main(int argc, char **argv)
{
    int clientfd;
    char *host, *port, buf[MAXLINE];
    rio_t rio;

    if (argc != 3) {
        fprintf(stderr, "Puts a value to an iVar, given by stdin\n");
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }
    host = argv[1];
    port = argv[2];

    clientfd = Open_clientfd(host, port);
    Rio_readinitb(&rio, clientfd);

    char* cmd = "PUT  ";
    strncpy(buf,cmd,4);

    Fgets(buf+4, MAXLINE-4, stdin);
    // I get the line ending from stdin, so I don't have to add it

    Rio_writen(clientfd, buf, strlen(buf));
    Rio_readlineb(&rio, buf, MAXLINE);

    Fputs(buf, stdout);

    Close(clientfd); //line:netp:echoclient:close
    exit(0);
}
