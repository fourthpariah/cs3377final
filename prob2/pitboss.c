#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <time.h>

int main(int argc, char *argv[])
{
  extern char *optarg;
  extern int optind, optopt;
  int opt;
  
  int pcnt;
  FILE *binfile;
  char data[1024];
  
  int line;
  
  while((opt = getopt(argc, argv, "p:")) != -1)
  {
    switch(opt) {
    case 'p':
      pcnt = atoi(optarg);
      break;
    case '?':
      fprintf(stderr, "%s: Unknown input\n", argv[0]);
      exit(1);
    }
  }
  
  binfile = fopen(argv[3], "r");
  printf("\nReading results from %s ... \n", optarg);
    
  int index = 0;
  
  printf("\nChecking results for -p = %i ... \n", pcnt);
  
  int values[4];
  
  int test;
  
  //this is a probably a roundabout way of going about it, but this while loop is essentially supposed to grab the actual integers from the
  //entire .bin file and puts them into an array representing data for a single -p simulation
  while(fgets(data, 3, binfile) != NULL)
  {
    if (atoi(data) != 0) {
      values[index] = atoi(data);
      index++;
    }
        
    // if the array is full, itll check if the first element (-p percentage) matches the requested persentage so it will break the while loop
    // if not it will get the data for the next percentage simulation
    if (index == 4 && values[0] == pcnt)
    {
      break;
    }
    else if (index == 4)
    {
      index = 0;
    }
  }
  
  printf("Found %i trials.\n\n", values[1]);
  printf("Success - %i%%\n", values[2]);
  printf("Failure - %i%%\n", values[3]);

  
  
  
  
  


}