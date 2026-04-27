#include <stdio.h>

int main() {
    int bt[10], wt[10], tat[10], n;
    int i, j, temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    // Sorting burst time (SJF)
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);

    return 0;
}
