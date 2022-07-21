#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

int S1process;
void st_handler(int pid_t){
  printf("In handler of st\n");
  unsigned a, b;
  asm volatile("rdtsc" : "=a"(a), "=d"(b));
  unsigned long long c = ( (unsigned long long)a)|( ((unsigned long long)b)<<32 );
  union sigval sig;
  c=c/2300000000;
  sig.sival_int=c;
  sigqueue(S1process,SIGTERM,sig);
    
}

int main(int argc, char const *argv[]){
    S1process=atoi(argv[1]);
    printf("E2(st) PID %d\n",getpid());
    signal(SIGALRM,st_handler);
    struct itimerval time;  
    time.it_value.tv_sec = 2;
    time.it_value.tv_usec = 0;   
    time.it_interval = time.it_value;
    union sigval sig;

if (setitimer(ITIMER_REAL, &time, NULL) == -1) {
 perror("setitimer");
  exit(1);
}

while(1){
  pause();
}
 
  
    //sigqueue(getpid(),SIGALRM,sig);
    //setitimer(ITIMER_REAL, &it, NULL);
    

}