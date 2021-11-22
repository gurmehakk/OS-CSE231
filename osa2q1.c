#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>



void handler(int pid_t){
write(STDOUT_FILENO , "exiting", 7);
exit(EXIT_FAILURE);
}
void DoStuff(void) {

  printf("Timer went off.\n");

}

int main() {
  int s1;
  s1 = fork();
  int pid_t = getpid();
  if(s1==0){
    signal(SIGTERM,handler);
   
    printf("%d  \n", pid_t); 
    sleep(2);

    
    
  }
  if(s1>0){
    int st = fork();
    int sr = fork();
    if(st==0){
      #define INTERVAL 500
      void DoStuff(void);
      struct itimerval it_val;
       if (signal(SIGALRM, (void (*)(int)) DoStuff) == SIG_ERR) {
    perror("Unable to catch SIGALRM");
    exit(1);
  }it_val.it_value.tv_sec =     INTERVAL/1000;
  it_val.it_value.tv_usec =    (INTERVAL*1000) % 1000000;   
  it_val.it_interval = it_val.it_value;
  if (setitimer(ITIMER_REAL, &it_val, NULL) == -1) {
    perror("error calling setitimer()");
    exit(1);
  }while (1) 
    pause();
      signal(SIGALRM,handler);
     // int setitimer(int which, struct itimerval *value, struct itimerval *ovalue);
    }if(sr==0){
      kill(pid_t,SIGTERM);
      signal(SIGALRM,handler);
    }
  }
  return 0;
}
