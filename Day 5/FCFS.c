#include <stdio.h>

struct FCFS {
    char name;
    int arrival, burst;
};

// finding the waiting time and turnaround time
void findTimes (struct FCFS list[], int wt[], int tt[], int n) {
    wt[0] = 0;
    
    for (int i=1; i<n; i++) {
        int wait = wt[i - 1] + list[i - 1].burst - list[i].arrival; 
        wt[i] = (wait > 0) ? wait : 0;
    }
    
    for (int i=0; i<n; i++) {
         tt[i] = list[i].burst + wt[i];
    }
}

// finding avg wt and tt
void findAvg (struct FCFS list[], int n) {
    int wt[n], tt[n];
    float total_wt = 0, total_tt = 0;

    findTimes (list, wt, tt, n);

    printf ("Process  AT   BT   WT  TT");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tt += tt[i];
        printf("\n  %c      %d    %d    %d   %d\n", list[i].name, list[i].arrival, list[i].burst, wt[i], tt[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tt / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct FCFS list[n];

    for (int i = 0; i < n; i++) {
        printf("Enter process name, arrival and burst time for P%d: ", i + 1);
        scanf(" %c %d %d", &list[i].name, &list[i].arrival, &list[i].burst);
    }

    findAvg (list, n);

    return 0;
}
