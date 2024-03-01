/* Write a shared memory program where there are two programs
a) writer b) reader. Implement IPC where the writer writes a string into
shared memory and reader reads and counts the number of vowels,
symbols and numbers it. */

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	key_t key = ftok("Vowel", 69);
	int shmid = shmget (key, 1024, 0666|IPC_CREAT);
	
	char *str = (char*)shmat(shmid,(void*)0,0);
	printf("Enter the string: ");
	gets(str);
	
	printf ("DATA IN THE SHARED MEMORY:\n%s\n", str);
	
	shmdt(str);
	
	return 0;
}
