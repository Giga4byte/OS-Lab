#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 10
#define PRODUCERS 2
#define CONSUMERS 2

int buffer[SIZE];
int in = 0, out = 0, counter = 0;
sem_t mutex, full, empty;

void producer() {
    int item;
    // empty-mutex mutex-full
    while (1) {
        item = rand() % 100;
        sem_wait(&empty); sem_wait(&mutex);
        
        buffer[in] = item;
        in = (in + 1) % SIZE;
        counter++;
        printf("Produced item: %d\n", item);
        
        sem_post(&mutex); sem_post(&full);
        
        usleep(100000); // Sleep for 100000 microseconds
    }
}

void consumer() {
    int item;
    while (1) {
        sem_wait(&full); sem_wait(&mutex);
        
        item = buffer[out];
        out = (out + 1) % SIZE;
        counter--;
        printf("Consumed item: %d\n", item);
        
        sem_post(&mutex); sem_post(&empty);
        
        usleep(200000); // Sleep for 200000 microseconds
    }
}

int main() {
    pthread_t producer[PRODUCERS];
    pthread_t consumer[CONSUMERS];

    sem_init(&mutex, 0, 1); sem_init(&full, 0, 0);
    sem_init(&empty, 0, SIZE);

    for (int i = 0; i < PRODUCERS; i++) {
        pthread_create (&producer[i], NULL, (void *)producer, NULL);
    }

    for (int i = 0; i < CONSUMERS; i++) {
        pthread_create (&consumer[i], NULL, (void *)consumer, NULL);
    }

    // Wait for a total of 2n activities
    while (counter < 2 * (PRODUCERS + CONSUMERS)) {
        usleep(1000000); 
    }

    // Cancel threads
    for (int i = 0; i < PRODUCERS; i++) {
        pthread_cancel (producer[i]);
    }

    for (int i = 0; i < CONSUMERS; i++) {
        pthread_cancel (consumer[i]);
    }

    sem_destroy(&mutex);
    
    return 0;
}
