#include  <stdio.h>
#include  <string.h>
#include <sys/types.h>
#include <stdlib.h>

void ChildProcess(void);
void ParentProcess(void);

void main(void){
  pid_t  pid;
  pid = fork();
  srand(time(NULL));
  if (pid == 0){
    ChildProcess();
  }
  else{
    ParentProcess();
  }
  
  
}

void  ChildProcess(void)
{
  srand(time(NULL));
  int pid = getpid();
  int ppid = getppid();
  int range_loop = (rand() % 30) + 1;
  int range_sleep = (rand() % 10) + 1;
  int i;
  for(i = 0; i < range_loop; i++){
     printf("Child PID: %d is going to sleep!\n", pid);
     sleep(range_sleep);
     printf("Child %d: I'm awake!\n Where is my Parent %d?\n", pid, ppid);
   }
 
  exit(0);
}

void  ParentProcess(void)
{
  printf("Child Pid: %d has completed!\n", wait());
}