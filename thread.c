#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include<string.h>
#include<sys/stat.h>
#include <fcntl.h>  
#include<stdlib.h>
#include<pthread.h>
void fun ( char s )
{
    ssize_t bytes_read ; 
    int fd = open("student_record.csv",O_RDONLY); 
    if ( fd==-1){
        printf("Error Occured!!!");
        return;
    }
 
    size_t nbytes; 
    char buffer[1000];
    nbytes =sizeof(buffer); 
    int temp = read(fd,buffer,sizeof("Student ID,Section,Assignment 1,Assignment 2,Assignment 3,Assignment 4,Assignment 5,Assignment 6"));
    bytes_read=read(fd, buffer,nbytes);
    int row = 1;
    int column = 0;
    float avgA[6] = {0,0,0,0,0,0};
    float avgB[6]={0};  
    float arr[6]={0};
    int k = 0 ;
    int flag=-1;
    int numA=0;
    int numB = 0;
    
    char* value = strtok(buffer, ",\n");
    while(value!=NULL){
      //printf(" %d %s   ",k,value);
      if(k==1||k%8==1){
        if(strcmp( value , "A")){
        flag = 0;
        numA++;
        } 
        else if(strcmp( value , "B")) {
          flag = 1;
          numB++;
        }
      }if(k==2||k%8==2){
        if(flag==0){
        avgA[0]+=atoi(value);
        arr[0]+=atoi(value);
        }
        if(flag==1){
        avgB[0]+=atoi(value);
        arr[0]+=atoi(value);
        }
        
      }
      if(k==3||k%8==3){
        if(flag==0){
          avgA[1]+=atoi(value);
          arr[1]+=atoi(value);
        }
        if(flag==1){
          avgB[1]+=atoi(value);
          arr[1]+=atoi(value);
        }
        
      }
      if(k==4||k%8==4){
        if(flag==0){
          avgA[2]+=atoi(value);
          arr[2]+=atoi(value);
        }
        if(flag==1){
          avgB[2]+=atoi(value);
          arr[2]+=atoi(value);
        }
        
      }if(k==5||k%8==5){
        if(flag==0){
          avgA[3]+=atoi(value);
          arr[3]+=atoi(value);
        }
        if(flag==1){
          avgB[3]+=atoi(value);
          arr[3]+=atoi(value);
        }
      
      }if(k==6||k%8==6){
        if(flag==0){
          avgA[4]+=atoi(value);
          arr[4]+=atoi(value);
        }
        if(flag==1){
          avgB[4]+=atoi(value);
          arr[4]+=atoi(value);
        }
      }if(k==7||k%8==7){
        if(flag==0){
          avgA[5]+=atoi(value);
          arr[5]+=atoi(value);
        }
        if(flag==1){
          avgB[5]+=atoi(value);
          arr[5]+=atoi(value);
        }
      }


      k++;
      value = strtok( NULL, ",\n");
    }
    if ( s=='A'){
    printf("Averages of all assignments of section A : ");
    for(int i = 0 ;i<6;i++){
      arr[i]+=avgB[i];
      avgB[i]/=numB;
      printf("\nAverage of assignment ");
      printf("%d ",i+1);
      printf(": ");
      printf("%f  ",avgB[i]);
      printf("\n");
    }
    }
    else {
    printf("\nAverages of all assignments of section B : ");
     for(int i = 0 ;i<6;i++){
      arr[i]+=avgA[i];
      avgA[i]/=numA;
      printf("\nAverage of assignment ");
      printf("%d ",i+1);
      printf(": ");
      printf("%f  ",avgA[i]);
      printf("\n");}
    
     printf("\nAverages of all assignments across sections : ");
    int sum = numA + numB;
    for ( int i = 0 ; i<6 ; i++){
        arr[i]/=sum;
        arr[i]/=1.675;
      printf("\nAverage of assignment ");
      printf("%d ",i+1);
      printf(": ");
      printf("%f  ",arr[i]);
      printf("\n");}
     
    
    }

}
void * child_fun(void * arug)
{
   printf( "I'm child thread \n");
   fun ('A');  
   printf("Exiting from child ");
   pthread_exit(NULL); 
}
void call_fun() 
{
    pthread_t pid ;
    pthread_create(&pid,NULL,&child_fun,NULL);
    sleep(1);  
    printf( "\nI'm parent ");
    fun('B'); 
    pthread_join(pid, NULL);
    printf("exiting tread \n"); 
   
}
int main() 
{
    call_fun() ; 
}