#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "csapp.h"

void message()
{
  printf("So you think you can stop the bomb with ctrl-c, do you?\n");
  sleep(2);
  printf("Well...");
  fflush(stdout);
  sleep(1);
  printf("OK. :-)\n");
  exit(0);
}

volatile sig_atomic_t pending = 0;

void sigint_handler(int sig) /* SIGINT handler */
{
  pending = 1;
}

int main()
{
  /* Install the SIGINT handler */
  if (signal(SIGINT, sigint_handler) == SIG_ERR)
    unix_error("signal error");
  /* Wait for the receipt of a signal */
  while (1) {
    pause();
    while (pending) {
      message();
      pending = 0;
    }
  }

  return 0;
}
