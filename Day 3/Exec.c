/* NOTE:
   Replaces the current running process with a new one.
   Runs C program using another C program.
   execvp(): created child process doesn't run the same prog as the parent */


// program 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
	char *args[]={"./day3bop",NULL};
	execvp(args[0],args); /*All statements are ignored after execvp() call as this whole process(day3b.c) is replaced by another process(day3bop.c)*/
	printf("Ending-----");
	return 0;
}

// program 2
#include<stdio.h>
#include<unistd.h>

int main() {
	int i;
	printf("I am day3bop.c called by execvp() ");
	printf("\n");
	return 0;
}
