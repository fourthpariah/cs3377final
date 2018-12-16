#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *newfile;
  
  int n;
  int size = 1024;
  char buff[ size ];
  
  int fd[2];
  pipe(fd);
  
  pid_t my_pid;
  my_pid = fork();
  
  if (my_pid == 0) 
  {
    dup2(fd[1], STDOUT_FILENO);
    execl("/bin/cat", "cat", "-b", argv[1], (char*) NULL );
  }
  else if (my_pid > 0) 
  {
    newfile = fopen(argv[2], "a");
    
    close(fd[1]);
    
    while ( (n = read(fd[0], buff, size)) > 0)
    {
    } 
    
    close(fd[0]);
  
    fprintf(stdout, buff);
    fputs(buff, newfile);
    fclose(newfile);
  
  }

}