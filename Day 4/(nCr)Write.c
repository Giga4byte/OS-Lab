// writer for nCr

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int factorial(int u)
{
	int f=1,i;
	for (i=1;i<=u;i++)
	{ f=f*i; }
	return f;
}


int main () {
	int number, rad; 
	int *a, *b, *c;
	
	key_t key = ftok ("Write1", 89);
	
	int shmid1 = shmget(key, sizeof(int), 0666|IPC_CREAT);
	int shmid2 = shmget(key, sizeof(int), 0666|IPC_CREAT);
	int shmid3 = shmget(key, sizeof(int), 0666|IPC_CREAT);
	
	a = (int*) shmat(shmid1,(void*)0,0);
	b = a+1; c = b+1;
	
	printf ("Enter N and R: ");
	scanf ("%d%d", &number, &rad);
	
	*a = factorial (number);
	*b = factorial (rad);
	*c = factorial (number-rad);
	
	printf ("DATA IN THE SHARED MEMORY:\nN! = %d   R! = %d   (N-R)! = %d\n", *a, *b, *c);
	
	shmdt(a); shmdt(b); shmdt(c);
	
	return 0;
}
