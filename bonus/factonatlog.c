#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main()
{
  double factorial = 1.0;
  double ln, sterling, error, errcent;
  
  int n, within1;
  
  within1 = 0;
  
  printf("N    ln(Factorial)    Stirling's Formula    Error        Error Percent\n");
  
  for (n = 1; n <= 100; n++)
  {
    factorial = factorial * n;
    ln = log(factorial);
    sterling = n * log(n) - n;
    error = ln - sterling;
    errcent = (error/sterling) * 100;
    
    if (n < 3)
    {
      errcent = errcent * -1;
    }
    
    if (within1 == 0 && errcent < 1)
    {
      within1 = n;
    }
    
    // the directions say to print the data to STDOUT which printf technically does
    printf("%i    ", n);
    printf("%e    ", ln);
    printf("%e        ", sterling);
    printf("%e    ", error);
    printf("%e    \n", errcent);
    
  }
  
  printf("For values of n = %i and greater, Sterling's approximation is within 0.1%% of the exact result.\n", within1);
}