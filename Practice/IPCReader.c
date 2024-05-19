#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main () {
    key_t key = ftok ("Palindrome", 129);
    int shmid = shmget (key, 1024, 0666|IPC_CREAT);
    if (shmid == -1) {
        perror ("shmid");
        exit (1);
    }
    
    char *str = (char *)shmat(shmid, (void *)0, 0);
    if (str == (char *)(-1)) {
        perror ("shmat");
        exit(1);
    }
    
    printf ("DATA BEING READ FROM THE SHM: %s\n", str);
    
    int n = strlen(str);
    int a[n]; int j = n-1; int flag = 0;
    
    for (int i=0; i<n; i++) {
        if (a[i] != a[j]) {
            flag = 1;
            break;
        } else {
            j--;
        }
    }
    
    if (flag == 0) {
        printf ("The number was a palindrome");
    } else { 
        printf ("The number was not a palindrome");
    }
    
    shmdt (str);
    shmctl (shmid, IPC_RMID, NULL);
    return 0;
}
