#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <assert.h>
#include <pthread.h>
#include <errno.h>

struct work {
  unsigned char *data;
  int start;
  int end;
};

pthread_mutex_t sum_mutex = PTHREAD_MUTEX_INITIALIZER;

long sum = 0;

void* thread(void* p) {
  struct work work = *(struct work*)p;
  free(p);

  long local_sum = 0;

  for (int i = work.start; i < work.end; i++) {
    local_sum += work.data[i];
  }

  pthread_mutex_lock(&sum_mutex);
  sum += local_sum;
  pthread_mutex_unlock(&sum_mutex);

  return NULL;
}

int main(int argc, char** argv) {
  int nthreads = atoi(argv[1]);
  char *filename = argv[2];

  FILE* file = fopen(filename, "r");
  assert(file != NULL);
  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  fseek(file, 0, SEEK_SET);

  int chunk_size = (size + nthreads - 1) / nthreads;

  unsigned char *data = mmap(NULL,
                             size,
                             PROT_READ,
                             MAP_PRIVATE,
                             fileno(file), 0);
  assert(data != MAP_FAILED);

  pthread_t ptids[nthreads];

  for (int i = 0; i < nthreads; i++) {
    struct work *work = malloc(sizeof(struct work));
    work->data = data;
    work->start = i * chunk_size;
    work->end = (i+1) * chunk_size;
    if (work->end > size) {
      work->end = size;
    }

    assert(pthread_create(&ptids[i], NULL, thread, work) == 0);
  }

  for (int i = 0; i < nthreads; i++) {
    assert(pthread_join(ptids[i], NULL) == 0);
  }

  printf("sum: %ld\n", sum);
}
