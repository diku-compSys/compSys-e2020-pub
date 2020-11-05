#include <pthread.h>
#include <stdio.h>
#include <assert.h>

void* thread_fn(void* arg) {
  (void)arg;
  printf("Hello, world!\n");

  return NULL;
}

int main() {
  pthread_t tid;

  assert(pthread_create(&tid, NULL, thread_fn, NULL) == 0);

  void *result;
  assert(pthread_join(tid, &result) == 0);

  return 0;
}
