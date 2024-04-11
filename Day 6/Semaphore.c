#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 10;

int producer () {	
	--mutex; ++full; --empty;
	
	int x = rand();
	printf ("The number produced by the Producer is: %d", x);
	++mutex;
	
	return x;
}

void consumer (int x) {
	--mutex; --full; ++empty;
	printf ("The number cnosumed by the Consumer is: %d", x);
	++mutex;
}

int main () {
	printf ("MENU\n1. Producer\t2. Consumer\t3. Exit\n");
	
	int choice, number;
	#pragma omp critical

    for (int i = 1; i > 0; i++) {
    	printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice) {
        	case 1:
            if ((mutex == 1) && (empty != 0)) {
                number = producer();
            } else {
                printf("Buffer is full!");
            }
            break;

        case 2:
            if ((mutex == 1) && (full != 0)) {
                consumer(number);
            } else {
                printf("Buffer is empty!");
            }
            break;

        case 3:
            exit(0);
            break;
        }
    }
} 
