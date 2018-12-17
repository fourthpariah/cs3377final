#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main()
{
  int i, n, pretty;
  pretty = 0;
  
  for (i = 1; i < 10000; i++)
  {
    n = i;
      
    while (n != 1) 
    {
      if (n % 5 == 0)
      {
        n = n / 5;
      }
      else if (n % 3 == 0)
      {
        n = n / 3;
      }
      else if (n % 2 == 0)
      {
        n = n / 2;
      }
      else
      {
        pretty = 1;
        break;
      }
    }
    
    if(!pretty)
    {
      printf("%i\n", i);
    }
    
    pretty = 0; 
  }
  
}