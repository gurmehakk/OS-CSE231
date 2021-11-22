//Assignement1-ques1
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *source,*dest;
    char buf[1];
    char m1[100];
    char m2[100];
    scanf("%s",m1);
    scanf("%s",m2);
    source = fopen(m1, "r");
    dest   =fopen(m2,"w");
    if (source!= NULL) {
        while(fread(buf, 1, 1, source)==1){
        fwrite(buf,1,1,dest);
        }
    fclose(source);
    fclose(dest);
    }
}