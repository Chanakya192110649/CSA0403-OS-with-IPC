#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;      // process ID
    int burst_time;  // burst time
} process;

int compare_processes(const void *a, const void *b) {
    process *p1 = (process *)a;
    process *p2 = (process *)b;
    return p1->burst_time - p2->burst_time;
}

int main() {
    int n, i;
    process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of each process:\n");
    for (i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        scanf("%d", &processes[i].burst_time);
    }

    // sort processes by burst time
    qsort(processes, n, sizeof(process), compare_processes);

    printf("Process ID\tBurst Time\n");
    int total_waiting_time = 0;
    int current_time = 0;
    for (i = 0; i < n; i++) {
        int waiting_time = current_time - processes[i].burst_time;
        total_waiting_time += waiting_time;
        current_time += processes[i].burst_time;
        printf("%d\t\t%d\n", processes[i].pid, processes[i].burst_time);
    }

    printf("Average waiting time: %f\n", (float)total_waiting_time / n);

    return 0;
}

