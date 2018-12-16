#include "mytools.h"
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int 
main(int n) {

  int i;
  double x, y;
  
  int in = 0;
  
  for (i = 0; i < n; i++)
  {
    assert( init_mytool() == 0);
  
    double x = get_random_number();
    
    nanosleep((const struct timespec[]){{0, 750000000L}}, NULL);
    
    double y = get_random_number();
    
    finalize_mytool();
    
    //printf("x = %f\n", x);
    //printf("y = %f\n", y);
    
    double distance = sqrt(x*x + y*y);
    
    printf("distance = %f\n", distance);
  
    if (distance < 1)
      in++;
  }
  
  int pest;
  
  pest = 4*(in / n);
  
  printf("Pi estimate = %i\n", pest);
}