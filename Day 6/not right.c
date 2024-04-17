#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <semaphore.h>

#define QUEUE_SIZE 5

int queue[QUEUE_SIZE];
int front = 0, rear = -1, itemCount = 0;

sem_t mutex, full, empty;

int generateRandomNumber() {
    srand(time(NULL));
    return rand();
}

void initSemaphores() {
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, QUEUE_SIZE);
}

void producer() {
    while (1) {
        int item = generateRandomNumber();
        if (item % 2 != 0) { // Producer's turn
            sem_wait(&empty); // Wait for an empty slot in the queue
            sem_wait(&mutex); // Lock the mutex for critical section
            rear = (rear + 1) % QUEUE_SIZE;
            queue[rear] = item;
            printf("Produced item: %d\n", item);
            sem_post(&mutex); // Release the mutex
            sem_post(&full);  // Signal that the queue is no longer empty
            sleep(1); // Sleep for a short time
        }
    }
}

void consumer() {
    while (1) {
        int item = generateRandomNumber();
        if (item % 2 == 0) { // Consumer's turn
            sem_wait(&full);  // Wait for a full slot in the queue
            sem_wait(&mutex); // Lock the mutex for critical section
            int consumedItem = queue[front];
            front = (front + 1) % QUEUE_SIZE;
            printf("Consumed item: %d\n", consumedItem);
            sem_post(&mutex); // Release the mutex
            sem_post(&empty); // Signal that the queue is no longer full
            sleep(1); // Sleep for a short time
        }
    }
}

int main() {
    initSemaphores();

    // Create child processes for producer and consumer
    pid_t pid_producer = fork();
    if (pid_producer == 0) {
        // Child process (producer)
        producer();
    } else if (pid_producer > 0) {
        // Parent process
        pid_t pid_consumer = fork();
        if (pid_consumer == 0) {
            // Child process (consumer)
            consumer();
        } else if (pid_consumer > 0) {
            // Parent process
            // Wait for child processes to finish
            wait(NULL);
            wait(NULL);
        } else {
            // Error occurred while forking
            perror("Error forking consumer process");
            exit(EXIT_FAILURE);
        }
    } else {
        // Error occurred while forking
        perror("Error forking producer process");
        exit(EXIT_FAILURE);
    }

    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}
