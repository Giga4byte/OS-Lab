#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mutex = 1;
int full = 0;
int empty = 10;

int randomNumber() {
    srand(time(NULL));
    return rand();
}

int producer () {    
    --mutex; ++full; --empty;
    
    int x = randomNumber();
    printf ("The number produced by the Producer is: %d\n", x);
    ++mutex;
    
    return x;
}

void consumer (int x) {
    --mutex; --full; ++empty;
    printf ("The number consumed by the Consumer is: %d\n", x);
    ++mutex;
}

int main () {
    printf ("MENU\n1. Producer\t2. Consumer\t3. Exit\n");
    
    int choice, number;
    for (int i = 1; i > 0; i++) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                number = randomNumber();
                if ((mutex == 1) && (empty != 0) && (number % 2 != 0)) {
                    producer();
                } else {
                    printf("Buffer is full or not the producer's turn!\n");
                }
                break;

            case 2:
                number = randomNumber();
                if ((mutex == 1) && (full != 0) && (number % 2 == 0)) {
                    consumer(number);
                } else {
                    printf("Buffer is empty or not the consumer's turn!\n");
                }
                break;

            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
