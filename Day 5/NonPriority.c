#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define totalprocess 5

// Making a struct to hold the given input
struct process
{
    int at, bt, pr, pno;
};

struct process proc[50];

// Writing comparator function to sort according to priority if arrival time is same
bool comp(struct process a, struct process b)
{
    if (a.at == b.at)
    {
        return a.pr < b.pr;
    }
    else
    {
        return a.at < b.at;
    }
}

// Using FCFS Algorithm to find Waiting time
void get_wt_time(int wt[])
{
    // declaring service array that stores cumulative burst time
    int service[50];

    // Initialising initial elements of the arrays
    service[0] = proc[0].at;
    wt[0] = 0;

    for (int i = 1; i < totalprocess; i++)
    {
        service[i] = proc[i - 1].bt + service[i - 1];

        wt[i] = service[i] - proc[i].at;

        // If waiting time is negative, change it into zero
        if (wt[i] < 0)
        {
            wt[i] = 0;
        }
    }
}

void get_tat_time(int tat[], int wt[])
{
    // Filling turnaroundtime array
    for (int i = 0; i < totalprocess; i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }
}

void findgc()
{
    // Declare waiting time and turnaround time array
    int wt[50], tat[50];

    double wavg = 0, tavg = 0;

    // Function call to find waiting time array
    get_wt_time(wt);
    // Function call to find turnaround time
    get_tat_time(tat, wt);

    int stime[50], ctime[50];

    stime[0] = proc[0].at;
    ctime[0] = stime[0] + tat[0];

    // calculating starting and ending time
    for (int i = 1; i < totalprocess; i++)
    {
        stime[i] = ctime[i - 1];
        ctime[i] = stime[i] + tat[i] - wt[i];
    }

    printf("Process_no\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time\n");

    // display the process details
    for (int i = 0; i < totalprocess; i++)
    {
        wavg += wt[i];
        tavg += tat[i];

        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", proc[i].pno,
               stime[i], ctime[i], tat[i], wt[i]);
    }

    // display the average waiting time and average turn around time
    printf("Average waiting time is : ");
    printf("%f\n", wavg / (float)totalprocess);
    printf("average turnaround time : ");
    printf("%f\n", tavg / (float)totalprocess);
}

int main()
{
    printf("Enter arrival time, burst time, and priority for each process:\n");
    for (int i = 0; i < totalprocess; i++)
    {
        printf("For Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &proc[i].at);
        printf("Burst Time: ");
        scanf("%d", &proc[i].bt);
        printf("Priority: ");
        scanf("%d", &proc[i].pr);
        proc[i].pno = i + 1;
    }

    // Using inbuilt sort function
    qsort(proc, totalprocess, sizeof(struct process), comp);

    // Calling function findgc for finding Gantt Chart
    findgc();

    return 0;
}
