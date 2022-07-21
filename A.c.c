#include<stdio.h>

extern void B(unsigned long long a);
int A()
{
    unsigned long long a = 184467440737095516;
    printf("IN function A \n");
    printf("%lld \n",a );
    B(a);
}
int main() 
{
    A(); 
}