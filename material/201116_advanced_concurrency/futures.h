#include <pthread.h>
#include <assert.h>

struct future {
  void *data;
  pthread_t p;
};

// Create a new future whose value is computed by the given function,
// which returns the address of the value.
typedef void* (*future_fn)(void*);
struct future* future_create(future_fn, void*);

// Get the value from the future and destroy the future.  Blocks if
// necessary.
void* future_get(struct future*);

struct future* future_create(future_fn f, void *arg) {
  struct future *future = malloc(sizeof(struct future));
  int ret = pthread_create(&future->p, NULL, f, arg);
  assert(ret == 0);
  return future;
}

void* future_get(struct future* future) {
  void *vp;
  int ret = pthread_join(future->p, &vp);
  assert(ret == 0);
  free(future);
  return vp;
}
