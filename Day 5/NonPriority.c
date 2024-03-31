#include <stdio.h>

struct process {
    int no, at, bt, priority;
};

int main () {
    int n;
    printf ("Enter the number of processes: ");
    scanf ("%d", &n);
    
    struct process list[n];
    printf ("\nEnter the Number, Arrival Time, Burst Time and Priority\n");
    for (int i=0; i<n; i++) {
        printf ("Process %d: ", i+1);
        scanf ("%d%d%d%d", &list[i].no, &list[i].at, &list[i].bt, &list[i].priority);
    }
    
    int wt[n], tt[n];
    float avg_wt=0, avg_tt=0;
    int comp=0;
    
    for (int i = 0; i < n; i++) {
        if (list[i].at == 0) {
            wt[i] = 0;
            tt[i] = list[i].bt;
            comp = tt[i];
        } else if (list[i].at < comp && list[i-1].priority < list[i].priority) {
            wt[i] = comp - list[i].at;
            tt[i] = comp + list[i].bt - list[i].at;
            comp += list[i].bt;
        } else {
            wt[i] = comp - list[i].at;
            tt[i] = comp + list[i].bt - list[i].at;
            comp += list[i].bt;
        }
    }
    
    printf ("\nProcess No\tArrival Time\tBurst Time\tPriority\tWait Time\tTurnaround Time\n");
    for (int i=0; i<n; i++) {
        printf ("%d\t\t\t   %d\t\t\t %d\t\t\t %d\t\t\t %d\t\t\t %d\n", list[i].no, list[i].at, list[i].bt, list[i].priority, wt[i], tt[i]);
    }
    
    for (int i=0; i<n; i++) {
        avg_wt = avg_wt + wt[i];
        avg_tt = avg_tt + tt[i];
    }
    printf("Average waiting time is %f\n", avg_wt/n);
    printf("Average turnaround time is %f\n", avg_tt/n);
    
    return 0;
}
