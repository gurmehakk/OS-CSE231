#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t forks[5];
sem_t bowl;
int bowlcount=0;
void * philos(void *);
void eat(int);
int main()
 {
         int i,n[5];
         pthread_t T[5];
         for(i=0;i<5;i++)
         sem_init(&forks[i],0,1);
         for(int j=0;j<4;j++){
            sem_init(&bowl,0,4);
         }
         while(1){
         for(i=0;i<5;i++){
                 n[i]=i;
                 pthread_create(&T[i],NULL,philos,(void *)&n[i]);
                 }
         for(i=0;i<5;i++)
                 pthread_join(T[i],NULL);
         }
 }
void * philos(void * n){
         int phil=*(int *)n;
         printf("P%d wants to eat\n",phil);
         printf("P%d tries to pick a fork\n",phil);
         sem_wait(&forks[phil]);
         printf("P%d picks a fork\n",phil);
         printf("P%d tries to pick a bowl\n",phil);
         sem_wait(&bowl);
         printf("P%d picks a bowl\n",phil);
          bowlcount++;
         printf("The number of bowls in use right now is %d\n",bowlcount);
         eat(phil);
         sleep(10);
         printf("P%d has finished eating\n",phil);
         sem_post(&bowl);
         printf("P%d leaves the bowl\n",phil);
        bowlcount--;
         printf("The number of bowls in use right now is %d\n",bowlcount);
         sem_post(&forks[phil]);
         printf("P%d leaves the fork\n",phil);
         
 }
 void eat(int phil)
 {
         printf("P%d begins to eat\n",phil);
 }