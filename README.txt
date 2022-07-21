In the given question we are given a csv file where comma-separated data is given for each student.
We use the read system call to read the data. Further I use strtok to split the data at commas or at new line.
Then I used strcmp to compare the splitted string that is in the value pointer.Depending on that I separed the the assignment marks in 2 arrays
 , avgA and avgB. These 2 are 6 sized arrays where the 0th index stores the sum of assignment1 of respective section. similarily other assignment
  sums are also stored.Initially I had a counter to store the number of students in section A and section B . 
later I divide each element of the avgA int array by numA and each element of avgB array by numB. All these operations are performed in the fun() 
function which takes a string 'A' or 'B' as a parameter and then based on this it runs in the child and parent process.
In the main function, the fork creates a process.It gives a brand new process, which is a copy of the current process.
 it first executes the child process which prints all averages of section-A and then the parent process begins to execute . 
Similary another file implements the same thing with the use of threads.Threads have there own stack space and process
First the child thread gets executed and then the parent and the parent also executes the average across sections for each assignment.