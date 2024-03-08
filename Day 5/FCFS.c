// day5FCFS.c

#include <stdio.h>

struct FCFS {
    char name;
    int arrival, burst;
};

// finding the waiting time and turnaround time
void findTimes (struct FCFS list[], int wt[], int tt[], int ct[], int n) {
    wt[0] = 0;
    
    for (int i=1; i<n; i++) {
    	ct[0] = list[0].burst;
    	ct[i] = ct[i-1] + list[i].burst;
        wt[i] = ct[i-1] - list[i].arrival; 
    }
    
    for (int i=0; i<n; i++) {
    	 tt[0] = list[0].burst;
         tt[i] = tt[i-1] + list[i-1].arrival + list[i].burst - list[i].arrival;
    }
}

// finding avg wt and tt
void findAvg (struct FCFS list[], int n) {
    int wt[n], tt[n], ct[n];
    float total_wt = 0, total_tt = 0;

    findTimes (list, wt, tt, ct, n);

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
    printf ("Giribala Arun CSB\n");
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
