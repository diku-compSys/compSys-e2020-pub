#include "csapp.h"

char **ptr;  /* global var */

void *thread(void *vargp)
{
  long myid = (long)vargp;
  static int cnt = 0;

  printf("[%ld]:  %s (cnt=%d)\n",
         myid, ptr[myid], ++cnt);
  return NULL;
}

int main()
{
  long i;
  pthread_t tid;
  char *msgs[2] = {
    "Hello from foo",
    "Hello from bar"
  };

  ptr = msgs;
  for (i = 0; i < 2; i++)
    Pthread_create(&tid,
                   NULL,
                   thread,
                   (void *)i);
  Pthread_exit(NULL);
}
