#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], tt[n], at[n], wt[n];
    float sumw = 0, sumt = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter arrival and burst time for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
    }

    // completion time array
    int completed[n];
    for (int i = 0; i < n; i++) {
        completed[i] = 0;
    }

    int time = 0;
    while (1) {
        int smallest = -1;
        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= time) {
                if (smallest == -1 || bt[i] < bt[smallest]) {
                    smallest = i;
                }
            }
        }

        if (smallest == -1) {
            break; // No process available to execute
        }

        completed[smallest] = 1; // Mark the process as completed
        printf("P[%d]\t|\t%d\t|\t%d\n", smallest + 1, time + bt[smallest] - at[smallest], time - at[smallest]);
        tt[smallest] = time + bt[smallest] - at[smallest];
        wt[smallest] = time - at[smallest];

        sumt += tt[smallest];
        sumw += wt[smallest];

        time += bt[smallest];
    }

    printf("\n\nAverage Waiting Time = %.2f", sumw / n);
    printf("\nAverage Turnaround Time = %.2f", sumt / n);

    return 0;
}
