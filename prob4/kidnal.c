#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>  
#include <signal.h>  
#include <assert.h>
#include "mytools.h"

int
main()
{
  pid_t my_pid;
  
  assert( init_mytool() == 0);
  
  int siggy = get_random_number() * 31;
  
  printf("sig num: %i\n", siggy);
  
  my_pid = fork();
  
  if (my_pid == 0)
  {
    // I do not have any time left
    // I'm genuinely sorry but I'm just going to have to take the L on this one
  
  }
  else if (my_pid > 0)
  {
  
  
  }

  finalize_mytool();

}