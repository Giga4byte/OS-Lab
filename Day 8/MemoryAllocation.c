#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *tail1 = NULL;
struct node *tail2 = NULL;
struct node *pointer = NULL;

void insertEndMem() {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (!p) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    scanf("%d", &p->data);
    p->next = NULL;
    if (head1 == NULL) {
        head1 = p;
        tail1 = p;
    } else {
        tail1->next = p;
        tail1 = p;
    }
}

void insertEndProc() {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (!p) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    scanf("%d", &p->data);
    p->next = NULL;
    if (head2 == NULL) {
        head2 = p;
        tail2 = p;
    } else {
        tail2->next = p;
        tail2 = p;
    }
}

void displayMem() {
    if (head1 == NULL) {
        printf("LIST IS EMPTY\n");
    } else {
        pointer = head1;
        while (pointer != NULL) {
            printf("%d ", pointer->data);
            pointer = pointer->next;
        }
    }
    printf("\n");
}

void displayProc() {
    if (head2 == NULL) {
        printf("LIST IS EMPTY\n");
    } else {
        pointer = head2;
        while (pointer != NULL) {
            printf("%d ", pointer->data);
            pointer = pointer->next;
        }
    }
    printf("\n");
}

void linkedToArrayMem(int array[], int size) {
    if (head1 == NULL) {
        printf("LIST IS EMPTY\n");
        return;
    }
    pointer = head1;
    int i = 0;
    while (pointer != NULL && i < size) {
        array[i] = pointer->data;
        pointer = pointer->next;
        i++;
    }
}

void linkedToArrayProc(int array[], int size) {
    if (head2 == NULL) {
        printf("LIST IS EMPTY\n");
        return;
    }
    pointer = head2;
    int i = 0;
    while (pointer != NULL && i < size) {
        array[i] = pointer->data;
        pointer = pointer->next;
        i++;
    }
}

void bubbleSortAsc(int n, int a[]) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void bubbleSortDesc(int n, int a[]) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] < a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void fitting(int memory[], int process[], int n, int m) {
    int alloc[m];
    for (int i = 0; i < m; i++) {
        alloc[i] = 0; // initializing it to 0
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (memory[j] >= process[i] && alloc[i] == 0) {
                alloc[i] = j;
                memory[j] -= process[i]; // find the rem mem
                break;
            }
        }
    }
    printf("PROCESS ALLOCATION:\n");
    for (int i = 0; i < m; i++) {
        if (alloc[i] != 0) {
            printf("Process %d allocated to Block %d\n", i, alloc[i]);
        } else {
            printf("Process %d cannot be allocated\n", i);
        }
    }
}

int main() {
    int n, m;
    printf("Enter the number of memory partitions: ");
    scanf("%d", &n);
    printf("Enter the number of processes: ");
    scanf("%d", &m);

    int memory[n];
    printf("\nEnter the sizes of memory partition\n");
    for (int i = 0; i < n; i++) {
        insertEndMem();
    }
    printf("Memory partitions: ");
    displayMem();
    linkedToArrayMem(memory, n);

    int process[m];
    printf("Enter the sizes of processes\n");
    for (int i = 0; i < m; i++) {
        insertEndProc();
    }
    printf("Processes: ");
    displayProc();
    linkedToArrayProc(process, m);

    printf("\nMENU:\n1. First Fit\n2. Best Fit\n3. Worst Fit\n4. Exit\n");
    int choice;
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                fitting(memory, process, n, m);
                printf("FIRST FIT ALLOCATION - COMPLETE!\n");
                break;
            case 2:
                printf("Mem in Ascending order: ");
                bubbleSortAsc(n, memory);
                printf("Process in Ascending order: ");
                bubbleSortAsc(m, process);
                fitting(memory, process, n, m);
                printf("BEST FIT ALLOCATION - COMPLETE!\n");
                break;
            case 3:
                printf("Mem in Descending order: ");
                bubbleSortDesc(n, memory);
                printf("Process in Ascending order: ");
                bubbleSortAsc(m, process);
                fitting(memory, process, n, m);
                printf("WORST FIT ALLOCATION - COMPLETE!\n");
                break;
            case 4:
                printf("Exiting the execution\n");
                return 0;
            default:
                printf("Wrong choice, choose again\n");
                break;
        }
    }
    return 0;
}
