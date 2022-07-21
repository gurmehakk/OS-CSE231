In the second question we were expected to make 4 functions along with the main function.
Also,we were expected to write and run a C program and an assembly program together.
The file A.c contains the main function which calls the A() function.
This A function has an unsigned long long integer that is within the range 0-18446744073709551615,i.e. the range of 
a 64 bit integer.The A function then calls another function B along with giving it a parameter as this 64 bit integer
Further, the B function has been written in assembly language By making use of 64 bit and then 8 bit registers i have
used mov statements and stored in registers the values that should get printed. Also, I have pushed the address of C 
in the stack. This stack manipulation has been done as we are expected to reach the C function after the ret statement of 
function B. Originally the ret statement of B function would have led us to the function from where B was called , i.e.
A function. But now, since the top of stack points to the C function, we reach this function.The C.c file contains the
C() function which prints the line this is C when we are in C and finally exits .
