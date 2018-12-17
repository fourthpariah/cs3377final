#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(int argc, char *argv[])
{
  int n = atoi(argv[1]);
  int i, sum, abun, def;
  
  for (i = 0; i < n; i++)
  {
    if (i != 0 && n % i == 0)
    {
      sum = sum + i;
    }
  
  }
  
  if (sum == n)
  {
    printf("%i is a perfect number.\n", n);
  }
  else if (sum > n)
  {
   abun = sum - n;
   printf("%i is an abundant number with an abundance of %i.\n", n, abun); 
  }
  else
  {
  sum = sum + n;
  def = 2*n - sum;
  printf("%i is a deficient number with a deficiency of %i.\n", n, def);
  }


}