#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <time.h>

int 
main(int argc, char *argv[]) 
{
  extern char *optarg;
  extern int optind, optopt;
  
  int pcnt, numt;
  int pflag, vflag, nflag, oflag;
  int opt;
  
  int index;
  
  pid_t pid;
  
  pcnt = 0;
  vflag = 0;
  numt = 0;
  pflag = 0;
  nflag = 0;
  oflag = 0;
  
  FILE *binfile;

  while ((opt = getopt(argc, argv, "p:vn:o:")) != -1)
    switch (opt) {
    case 'p':
      pcnt = atoi(optarg);
      pflag = 1;
      break;
    case 'v':
      vflag = 1;
      break;
    case 'n':
      if (vflag || pflag)
      {
        numt = atoi(optarg);
        nflag = 1;
      }
      else
      { 
        fprintf(stderr, "%s: -p and/or -v must always become before <number_of_trials>", argv[0]);
        exit(1);
      } 
      break;
    case 'o':
      binfile = fopen(optarg, "a");
      oflag = 1;
      break;
    case '?':
      fprintf(stderr, "%s: Unknown input\n", argv[0]);
      exit(1);
    }
  
  if (!pflag || !nflag)
  {
    fprintf(stderr, "%s: Requires -p AND -n.\n", argv[0]);
    exit(1);
  }
  else if ((pcnt > 100))
  {
    fprintf(stderr, "%s: Invalid percentage value.\n", argv[0]);
    exit(1);
  }
  else if (numt == 0)
  {
    fprintf(stderr, "%s: Invalid number_of_trials value.\n", argv[0]);
    exit(1);
  }
    
  int result, wins, losses;
  wins = 0;
  losses = 0;
  int childs;
  childs = 0;
  
  for(index = 0; index < numt;index++) 
  {
    pid = fork();
      
    if(pid == 0) 
    {
      
      result = execv("hand", argv);
      exit(0);
    }
    else if (pid > 0)
    {
      if (vflag)
        printf("PID %i returned \n", pid); 

      // I would have wanted to implement dup2 to redirect the stdout of hand but I don't have any time left
      pid = wait(&result);   
      if (WEXITSTATUS(result) == 0)
        wins++;
      else
        losses++;
    }
    else 
    {
      fprintf(stderr, "%s: Fork failed.\n", argv[0]);
      exit(1);
    }
  }
  
  double winrate;
  winrate = wins/(float)numt;
  double lossrate;
  lossrate = losses/(float)numt;
  
  printf("\n\nCreated %i processes.\n", numt);
  printf("Success - %i%%\n", (int)(winrate*100));
  printf("Failure - %i%%\n", (int)(lossrate*100));
  
  fprintf(binfile, "%i%%\n", pcnt);
  fprintf(binfile, "Created %i processes.\n", numt);
  fprintf(binfile, "Success - %i%%\n", (int)(winrate*100));
  fprintf(binfile, "Failure - %i%%\n", (int)(lossrate*100));
  
  return 0;
}