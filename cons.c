#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
//#include <prod.c>
int main(){
    int i = 0;
    char st[8];
    int call=syscall(451,st);
    if(call==-1){
        printf("\nReader has error\n");
        exit(1);
    }
    while(i<8){
        printf(" %d ",st[i]);
        i++;
    }
    
    return 0;
}