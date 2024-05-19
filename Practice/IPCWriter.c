#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    key_t key = ftok("Palindrome", 129);
    int shmid = shmget(key, 1024, 0666|IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    
    char *str = (char *)shmat(shmid, (void *)0, 0);
    if (str == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }
    
    printf("Enter the number: ");
    scanf("%s", str);
    
    printf("DATA BEING WRITTEN INTO THE SHM: %s\n", str);
    
    shmdt(str);
    
    return 0;
}
