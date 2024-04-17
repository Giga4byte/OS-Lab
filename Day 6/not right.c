/* doesn't satisfy a few conditions of the code to be implemented in the lab, don't copy. It's wrong */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<semaphore.h>
#include<unistd.h>

#define SIZE_QUEUE 10

int in = 0;
int out = 0;
int queue[SIZE_QUEUE];

sem_t mutex, empty, full;

// Function to generate a random number
int generateRandomNumber() {
    srand(time(NULL));
    sleep(rand() % 2); // Sleep for a random time
    return rand();
}

void producer(int item) {
    sem_wait(&empty);
    sem_wait(&mutex);

    if (((in + 1) % SIZE_QUEUE) != out) {
        queue[in] = item;
        in = (in + 1) % SIZE_QUEUE;
        printf("Producer produced: %d\n", item);
    } else {
        printf("Queue is full!\n");
    }

    sem_post(&mutex);
    sem_post(&full);
}

void consumer() {
    sem_wait(&full);
    sem_wait(&mutex);

    if (in != out) {
        int item = queue[out];
        out = (out + 1) % SIZE_QUEUE;
        printf("Consumer consumed: %d\n", item);
    } else {
        printf("Queue is empty\n");
    }

    sem_post(&mutex);
    sem_post(&empty);
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, SIZE_QUEUE);
    sem_init(&full, 0, 0);

    for (int i = 0; i < 10; i++) {
        int x = generateRandomNumber();
        printf("|%d|", x);
        if (x % 2 == 0) {
            printf(" CONSUMER'S TURN\n");
            consumer();
        } else {
            printf(" PRODUCER'S TURN\n");
            producer(x);
        }
    }

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
