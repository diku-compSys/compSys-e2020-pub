#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_fn(void* arg) {
  FILE *file = (FILE*)arg;
  char c;
  int cont = 1;


  while (cont) {
    pthread_mutex_lock(&mutex);
    r = fread(&c, sizeof(c), 1, file);
    if (r == 0) {
      cont = 0;
    } else {
      putchar(c);
    }
    pthread_mutex_unlock(&mutex);
  }

  return NULL;
}

int main(int argc, char** argv) {
  FILE *file = fopen(argv[1], "r");
  pthread_t tid1, tid2;
  pthread_create(&tid1, NULL, thread_fn, (void*)file);
  pthread_create(&tid2, NULL, thread_fn, (void*)file);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
}
