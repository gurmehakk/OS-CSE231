#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void handler(int s,siginfo_t *info, void *extra){ 
 printf("In handler of S1\n");
 printf("%d\n",info->si_value.sival_int);
}

int main() {
  int s1;
  s1 = fork();
  int pid_t;  
  if(s1==0){
    pid_t = getpid();
    printf("The PID of S1 %d  \n", pid_t); 
    struct sigaction sa;
        memset(&sa, 0, sizeof(sa));
        sa.sa_flags=SA_SIGINFO;;
        sa.sa_sigaction =&handler;
        
        
    
    sigaction(SIGTERM,&sa,NULL);
    
    while(1)
    {sleep(1);
}
    
  }
  if(s1>0){
    int f2 = fork();
    if(f2==0){
      int pid_t = getpid();
      char pid_str[10];
      sprintf(pid_str,"%d",s1);
       //itoa(pid_t,pid_str, 10);
      printf("Now going to sr file\n");
      char *args[]={"./sr",pid_str,NULL};
      execv(args[0],args);


   } else{
       int f3 = fork();
       if(f3==0){
       int pid_t = getpid();
       char pid_str[10];
       sprintf(pid_str,"%d",s1);
       printf("Now going to st file\n");
       char *args[]={"./st",pid_str,NULL};
       execv(args[0],args);
       }
       else{
           //
           while(1){
               //
           }
       }
    }
  }
  
  return 0;
}