#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main() {
	pid_t cpid;

	if (fork()== 0)
		exit(0); // terminate child
	else
		cpid = wait(NULL); // waiting parent

	printf("Parent pid = %d\n", getpid());
	printf("Child pid = %d\n", cpid);
	return 0;
}

/* NOTE:
   wait(): blocks the calling process until one of its child processes
   		   exits or signal is received. It continues right where it was
   		   interrupted */
