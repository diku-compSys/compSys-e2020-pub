/*
 * iVar-server.c
 */
#include "csapp.h"
#include <assert.h>

void *thread(void *vargp);

// I should protect my shared state
pthread_cond_t cond;
pthread_mutex_t mutex;

char* store;
int storeNotSet = 1;

int main(int argc, char **argv)
{
    int listenfd, *connfdp;
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;
    pthread_t tid;
    char client_hostname[MAXLINE], client_port[MAXLINE];

    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(0);
    }
    listenfd = Open_listenfd(argv[1]);

    while (1) {
        clientlen=sizeof(struct sockaddr_storage);
        connfdp = Malloc(sizeof(int)); //line:conc:echoservert:beginmalloc
        *connfdp = Accept(listenfd, (SA *) &clientaddr, &clientlen); //line:conc:echoservert:endmalloc

        Pthread_create(&tid, NULL, thread, connfdp);
        Getnameinfo((SA *) &clientaddr, clientlen, client_hostname, MAXLINE,
                    client_port, MAXLINE, 0);
        printf("Connected to (%s, %s) via thread %lu\n",
           client_hostname, client_port, (long) tid);
    }
}

/* Thread routine */
void *thread(void *vargp)
{
    int connfd = *((int *)vargp);
    Pthread_detach(pthread_self()); //line:conc:echoservert:detach
    Free(vargp);                    //line:conc:echoservert:free

    size_t n;
    char buf[MAXLINE];
    rio_t rio;
    char* reply;

    Rio_readinitb(&rio, connfd);
    n = Rio_readlineb(&rio, buf, MAXLINE);
    // NB, this does not handle short counts!!!! Inputs larger than MAXLINE
    if (strncmp("PUT ", buf, 4) == 0) {
        assert(pthread_mutex_lock(&mutex) == 0);
        if (storeNotSet) {
            storeNotSet = 0;
            store = Malloc(sizeof(buf)-4);
            strncpy(store, buf+4, sizeof(buf)-4);
            pthread_cond_broadcast(&cond);
            reply = "OK\n"; // Remember line termination for Rio_written
        }
        else {
            reply = "ALREADY SET\n"; // Remember line termination for Rio_written
        }
        assert(pthread_mutex_unlock(&mutex) == 0);
    }
    else if (strncmp("GET", buf, 3) == 0) {
        // NB, this does not handle if message is "GETTT". That is accepted
        assert(pthread_mutex_lock(&mutex) == 0);
        while (storeNotSet) {
            pthread_cond_wait(&cond, &mutex);
        }
        assert(pthread_mutex_unlock(&mutex) == 0);
        reply = store;
    }
    else {
        reply = "WRONG COMMAND\n"; // Remember line termination for Rio_written
    }

    strncpy(buf,reply,strlen(reply));
    Rio_writen(connfd, buf, strlen(buf));

    Close(connfd);
    return NULL;
}
