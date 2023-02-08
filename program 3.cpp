#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

struct Process {
    int pid;
    int burstTime;
};

int main() {
    struct Process processes[MAX_PROCESSES];
    int numProcesses, i;
    float avgWaitTime = 0.0;


    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    
    for (i = 0; i < numProcesses; i++) {
        processes[i].pid = i + 1;
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    
    for (i = 0; i < numProcesses; i++) {
        avgWaitTime += (float) processes[i].burstTime;
        for (int j = 0; j < i; j++) {
            avgWaitTime -= (float) processes[j].burstTime;
        }
    }

    
    avgWaitTime /= (float) numProcesses;

    
    printf("\nProcess\tBurst Time\tWait Time\n");
    for (i = 0; i < numProcesses; i++) {
        printf("%d\t\t%d\t\t%.2f\n", processes[i].pid, processes[i].burstTime, avgWaitTime);
    }
    printf("\nAverage wait time: %.2f\n", avgWaitTime);

    return 0;
}

