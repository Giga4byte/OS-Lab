#include <stdio.h>
#include <unistd.h>

int main() {
	int pid;
		
	pid = fork();
	if (pid == 0) {
		//printf("\nProcess id : %d", check);
		printf("\nProcess id : %d", getpid());
		printf("\nProcess id : %d\n", getppid());
	}
	return 0;
}

/* NOTE:
   getpid(): process id
   getppid(): parent process id */
