#include  <stdio.h>
#include  <string.h>
#include <sys/types.h>
#include <stdlib.h>

void main(void){
  int pid;
  int i;
  srand(time(NULL));
  
  for(i =0; i < 2;++i){
  pid = fork();
  
    if (pid == 0){
      int range_loop = (rand() % 30) + 1;
      int range_sleep = (rand() % 10) + 1;
      int i;
      for(i = 0; i < range_loop; i++){
         printf("Child PID: %d is going to sleep!\n", getpid());
         sleep(range_sleep);
         printf("Child %d: I'm awake!\n Where is my Parent %d?\n", getpid(), getppid());
       }
      exit(0);

    }
    else if(pid >0){
      int status = wait(&status);

      printf("Child Pid: %d has completed!\n",status);
    }
    else{
      printf("Woops, something went wrong!");

      exit(0);
    }
  }
}
