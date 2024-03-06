#include <stdio.h>

struct NonSJF {
    char name;
    int at, bt;
};
//GIRIBALA
void sortProcess (struct NonSJF list[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list[j].at > list[j+1].at) {
                struct NonSJF temp = list[j];
                list[j] = list[j + 1]; //Giribala
                list[j + 1] = temp; }
        }
    }
}

void findTimes(struct NonSJF list[], int n, int wt[], int tt[]) {
    wt[0] = 0;
    tt[0] = list[0].bt;

    for (int i = 1; i < n; i++) {
        wt[i] = tt[i - 1] - list[i].at;
        if (wt[i] < 0) //giribala
            wt[i] = 0;
        tt[i] = wt[i] + list[i].bt;
    }
}


void findAvg (struct NonSJF list[], int n) {
    int wt[n], tt[n];
    float total_wt = 0, total_tt = 0;

    findTimes (list, n, wt, tt);

    printf ("Process  AT   BT   WT  TT");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i]; //giribala
        total_tt += tt[i];
        printf("\n  %c      %d    %d    %d   %d\n", list[i].name, list[i].at, list[i].bt, wt[i], tt[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tt / n);
}

int main () {
    printf ("Giribala Arun CSB\n\n");
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct NonSJF list[n];

    for (int i = 0; i < n; i++) {
        printf("Enter process name, arrival and burst time for P%d: ", i + 1);
        scanf(" %c %d %d", &list[i].name, &list[i].at, &list[i].bt);
    }
    sortProcess (list, n);
    findAvg (list, n);
    
    return 0; 
} // GIRIBALA
