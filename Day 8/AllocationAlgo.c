#include <stdio.h>

// ascending order
void bubbleSortAsc (int n, int a[]) {
    int i,j, temp;
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1-i; j++) {
            if (a[j]>a[j+1]) {
                temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;
            } 
        }
    }
    
    for (i=0; i<n; i++) {
        printf ("%d  ", a[i]);
    }
} 

// descending order
void bubbleSortDesc (int n, int a[]) {
    int i,j, temp;
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1-i; j++) {
            if (a[j]<a[j+1]) {
                temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;
            } 
        }
    }
    
    for (i=0; i<n; i++) {
        printf ("%d  ", a[i]);
    }
} 

void fitting (int memory[], int process[], int n, int m) {
    int alloc[m];
    for (int i = 0; i < m; i++) {
        alloc[i] = 0; // initialising it to 0
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

int main () {
    int n, m;
    printf ("Enter the number of memory partitions: ");
    scanf ("%d", &n);
    printf ("Enter the number of processes: ");
    scanf ("%d", &m);
    
    int memory[n], process[m];
    printf ("\nEnter the sizes of memory partition\n");
    for (int i=0; i<n; i++) {
        scanf ("%d", &memory[i]);
    }
    printf ("Enter the sizes of processes\n");
    for (int i=0; i<m; i++) {
        scanf ("%d", &process[i]);
    }
    
    printf ("\nMENU:\n1. First Fit\n2. Best Fit\n3. Worst Fit\n");
    
    int choice;
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: fitting(memory, process, n, m);
                    printf ("FIRST FIT ALLOCATION - COMPLETE!\n");
                    break;
                    
            case 2: printf ("Memory in Ascending order: ");
                    bubbleSortAsc (n, memory);
                    printf ("\nProcess in Ascending order: ");
                    bubbleSortAsc (m, process);
                    printf ("\n");
                    fitting(memory, process, n, m);
                    printf ("BEST FIT ALLOCATION - COMPLETE!\n");
                    break;
                    
            case 3: printf ("Memory in Descending order: ");
                    bubbleSortDesc (n, memory);
                    printf ("\nProcess in Ascending order: ");
                    bubbleSortAsc (m, process);
                    printf ("\n");
                    fitting(memory, process, n, m);
                    printf ("WORST FIT ALLOCATION - COMPLETE!\n");
                    break;
                    
            case 4: printf ("Exiting the execution\n");
                    return 0;
                    
            default: printf ("Wrong choice, choose again\n");
        }
    }
    
    return 0;
}
