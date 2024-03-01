// reader for nCr

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
int main()
{
	int *a,*b,*c;
	
	key_t key=ftok("Write1",89);
	
	int shmid1=shmget(key,sizeof(int),0666|IPC_CREAT);
	int shmid2=shmget(key,sizeof(int),0666|IPC_CREAT);
	int shmid3=shmget(key,sizeof(int),0666|IPC_CREAT);
	
	a=(int*)shmat(shmid1,(void*)0,0);
	b=a+1;
	c=b+1;
	
	float fact;
	fact=(float)(*a/((*b)*(*c)));
	printf("nCr = %dC%d = %f\n",*a,*b,fact);
	
	shmdt(a); shmdt(b); shmdt(c);
	
	shmctl(shmid1,IPC_RMID,NULL);
	shmctl(shmid2,IPC_RMID,NULL);
	shmctl(shmid3,IPC_RMID,NULL);
	
	return 0;
}


