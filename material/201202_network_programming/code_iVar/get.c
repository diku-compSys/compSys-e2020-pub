/*
 * get.c - retrives a values from a iVar
 */
#include "csapp.h"

int main(int argc, char **argv)
{
    int clientfd;
    char *host, *port, buf[MAXLINE];
    rio_t rio;

    if (argc != 3) {
        fprintf(stderr, "Retrieves a value from an iVar\n");
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }
    host = argv[1];
    port = argv[2];

    clientfd = Open_clientfd(host, port);
    Rio_readinitb(&rio, clientfd);

    // Rio_written writes a line (ending with \n). even though the protocol doesn't specify this, I should add it here.
    char* cmd = "GET\n";
    strncpy(buf,cmd,strlen(cmd));

    Rio_writen(clientfd, buf, strlen(buf));
    Rio_readlineb(&rio, buf, MAXLINE);

    Fputs(buf, stdout);

    Close(clientfd); //line:netp:echoclient:close

    exit(0);
}
