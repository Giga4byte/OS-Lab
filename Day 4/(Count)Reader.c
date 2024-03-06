#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main () {
    key_t key = ftok("Vowel", 69);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }
    
    char *str = (char*)shmat(shmid, NULL, 0);
    if (str == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }
    
    printf("DATA READ FROM MEMORY:\n%s\n", str);
    
    int vowel = 0, numbers = 0, symbols = 0;
    
    for (int i = 0; i < strlen(str); i++) {
        char c = tolower(str[i]);
        
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowel++;
            }
        } else if (c >= '0' && c <= '9') {
            numbers++;
        } else if (c != ' ') {
            symbols++;
        }
    }
    
    printf("DATA:\n1. Vowels: %d  2. Symbols: %d   3. Numbers: %d\n", vowel, symbols, numbers);
    
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}
