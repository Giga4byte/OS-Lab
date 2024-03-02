// reader file
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main() {
    int *a;

    key_t key = ftok("Write3", 69);

    int shmid = shmget(key, 2 * sizeof(int), 0666 | IPC_CREAT);

    a = (int *)shmat(shmid, NULL, 0);

    if (a[1] == a[0]) {
        printf("It is a Palindrome\n");
    } else {
        printf("It is not a Palindrome\n");
    }

    shmdt(a);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
