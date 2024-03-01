#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	key_t key = ftok("Vowel", 69);
	int shmid = shmget (key, 1024, 0666|IPC_CREAT);
	
	char *str = (char*)shmat(shmid,(void*)0,0);
	printf("DATA READ FROM MEMORY:\n%s\n",str);
	
	int vowel=0, numbers=0, symbols=0;
	
	for (int i=0; i<strlen(str); i++) {	
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') 
			{ vowel++; }
		else if (str[i]>='0' && str[i]<='9') 
			{ numbers++; }
		else if (str[i] == '.' || str[i] == ',' || str[i] == ';' || str[i] == ':' || str[i] == '"'
				 || str[i] == '@' || str[i] == '!' || str[i] == '#' || str[i] == '%' || str[i] == '=' || str[i] == '-') 
			{ symbols++; }
		else 
			{ continue; }
	}
	
	printf ("DATA:\n1. vOWELS: %d  2. SYMBOLS: %d   3. NUMBERS: %d\n", vowel, symbols, numbers);
	
	shmdt(str);
	shmctl(shmid, IPC_RMID, NULL);

	return 0;
}
