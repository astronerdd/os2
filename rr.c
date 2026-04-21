#include <stdio.h>

int main() {
    int n, i, tq;
    int bt[10], rem[10], wt = 0, tat = 0, time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int done;
    do {
        done = 1;
        for(i = 0; i < n; i++) {
            if(rem[i] > 0) {
                done = 0;

                if(rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    wt += time - bt[i];
                    tat += time;
                    rem[i] = 0;
                }
            }
        }
    } while(!done);

    printf("\nAverage Waiting Time = %.2f", (float)wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)tat/n);

    return 0;
}