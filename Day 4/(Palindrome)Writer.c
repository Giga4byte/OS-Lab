// writer file
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int n) {
    int reversed = 0;
    int original = n;
    while (n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return reversed;
}

int main() {
    int number;
    int *a;

    key_t key = ftok("Write3", 69);

    int shmid = shmget(key, 2 * sizeof(int), 0666 | IPC_CREAT);

    a = (int *)shmat(shmid, NULL, 0);

    printf("Enter number for checking Palindrome: ");
    scanf("%d", &number);

    a[0] = number;
    a[1] = isPalindrome(number);

    printf("Data in the shared memory:\nOriginal Number: %d   Palindrome Check: %d\n",
           a[0], a[1]);

    shmdt(a);

    return 0;
}
