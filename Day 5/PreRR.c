#include<stdio.h>
 
int main()
{
      /*int i, limit, total = 0, x, counter = 0, time_quantum;
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
      float average_wait_time, average_turnaround_time;*/
    int n, x;
    printf("Enter number of process: ");
    scanf("%d", &n);
    x = n;
    printf ("\n");
      
    int arrival_time[n], burst_time[n], temp[n];
    for(int i = 0; i < n; i++) {
        printf("DETAILS OF PROCESS %d\n", i + 1);
        printf("Arrival and Burst Time: ");
        scanf("%d%d", &arrival_time[i], &burst_time[i]);
        temp[i] = burst_time[i];
    }
 
    int time_quantum;
    printf("\nEnter Time Quantum: ");
    scanf("%d", &time_quantum);
    
    int counter = 0, wait_time = 0, turnaround_time = 0;
    float average_wait_time = 0, average_turnaround_time = 0;
    int i, total;
    
    printf("\nPID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
    for (total = 0, i = 0; x != 0;) {
// checking if the burst time of the process is <=QT or >QT
        if (temp[i] <= time_quantum && temp[i] > 0) {
            total = total + temp[i];
            temp[i] = 0;
            counter = 1;
        } else if (temp[i] > 0) {
            temp[i] = temp[i] - time_quantum;
            total = total + time_quantum;
        }

// condition in case the process is "complete"
        if(temp[i] == 0 && counter == 1) {
            x--;
            
            // process is printed in the ascending order of completion
            printf("\nP%d\t\t   %d\t\t      %d\t\t\t    %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
            
            // calculate the total wait and turnaround time
            wait_time = wait_time + total - arrival_time[i] - burst_time[i];
            turnaround_time = turnaround_time + total - arrival_time[i];
            
            // reset counter
            counter = 0;
        }
        
        if (i == n - 1) {
            i = 0;
        } else if (arrival_time[i + 1] <= total) {
            i++;
        } else {
            i = 0;
        }
    }
 
    average_wait_time = wait_time / n;
    average_turnaround_time = turnaround_time / n;
    printf("\nAverage Waiting Time: %f", average_wait_time);
    printf("\nAverage Turnaround Time: %f\n", average_turnaround_time);
    
    return 0;
}

/*
FORMULA FOR WAITING TIME USED HERE:
    current_wt = process_total - arrival - burst;
*/
