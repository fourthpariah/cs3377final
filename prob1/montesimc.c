#include "mytools.h"
#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


int 
main(int argc, char *argv[]) 
{

  int i;
  double x, y;
  
  int in = 0;
  
  int n = atoi(argv[1]);
  
  // this for loop will repeat for as many points as desired
  for (i = 0; i < n; i++)
  {
    assert( init_mytool() == 0);
  
    double x = get_random_number();
    
    double y = get_random_number();
    
    // this is what ive been using instead of nanosleep, though it functionally works the same
    // until y gets a unique random num from gsl_rng, this while loop will keep getting another one
    // now that I think of it I can't say exactly if this is more efficient but it's too late to change now
    while (x == y)
    {
      y = get_random_number();
    }
    
    finalize_mytool();
    
    //printf("x = %f\n", x);
    //printf("y = %f\n", y);
    
    double distance = sqrt(x*x + y*y);
    
    //printf("distance = %f\n", distance);
  
    // if the distance of this point from (0,0) is greater than 1 (meaning it is outside of the unit circle)
    // this conditional will increment a variable representing the number of points inside the unit circle
    if (distance <= 1.0)
      in++;

  }
  
  
  double pest, deviation, errcnt;
  
  pest = ((float)in / n);
  pest = 4*pest;
  
  deviation = M_PI - pest;
  
  errcnt = (deviation / M_PI)*100;
  
  printf("Pi estimate = %f\n", pest);
  printf("Deviation = %f\n", fabs(deviation));
  printf("%% Error = %f\n", fabs(errcnt));
}