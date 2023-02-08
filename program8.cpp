#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;        // process ID
    int burst_time;  // burst time
    int waiting_time; // waiting time
} process;

int main() {
    int n, i, time_quantum;
    process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of each process:\n");
    for (i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        scanf("%d", &processes[i].burst_time);
        processes[i].waiting_time = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    int total_waiting_time = 0;
    int current_time = 0;
    int completed_processes = 0;
    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0) {
                int remaining_time = processes[i].burst_time - time_quantum;
                if (remaining_time <= 0) {
                    // process has completed
                    current_time += processes[i].burst_time;
                    processes[i].burst_time = 0;
                    processes[i].waiting_time = current_time - processes[i].burst_time;
                    completed_processes++;
                } else {
                    // process is still running
                    current_time += time_quantum;
                    processes[i].burst_time -= time_quantum;
                }
            }
        }
    }

    printf("Process ID\tBurst Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        printf("%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time);
    }

    printf("Average waiting time: %f\n", (float)total_waiting_time / n);

    return 0;
}

