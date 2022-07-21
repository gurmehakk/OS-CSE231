#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
int S1process;
int random_no(){
    int ran_num;
    int i=0;
    const int timeout = 10;
    while (1){
        asm("rdrand %0\n\t":"=a"(ran_num)::);
        if (ran_num) 
        break;
        i++;
    }
    return ran_num;
    
}
void handler(int pid_t){
    signal(SIGALRM,handler);
    int rand=random_no();
    union sigval sig;
    sig.sival_int=rand;
    sigqueue(S1process,SIGTERM,sig);
    
}

int main(int argc, char const *argv[])
{   
    S1process=atoi(argv[1]);
    printf("E1 PID(sr) %d\n",getpid());
    signal(SIGALRM,handler);
    struct itimerval time;  
    time.it_value.tv_sec = 2;
    time.it_value.tv_usec = 0;   
    time.it_interval = time.it_value;
    setitimer(ITIMER_REAL, &time, NULL);

    while(1){
        //do nothing
    }
    
////
    return 0;
}