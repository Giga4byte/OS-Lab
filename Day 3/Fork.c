#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main () {
	fork();	fork();
	printf ("Checking fork()\n");
	return 0;
}

/* NOTE:
   fork() function creates a new process called the child process.
   Takes no parameters and returns an integer value.
   Return value: -ve (if unsuccessful)
   				 +ve (if it returns to the parent)
   				  0  (if successful) 
   Child process uses the same PC. 
   If n is the no of fork() calls, no of o/p->2^n */
