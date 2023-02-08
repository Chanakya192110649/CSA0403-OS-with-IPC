#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

struct process {
    int id;
    int burst_time;
};

int compare_processes(const void *a, const void *b) {
    struct process *p1 = (struct process *)a;
    struct process *p2 = (struct process *)b;
    return p1->burst_time - p2->burst_time;
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes;
    int i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the burst time of each process:\n");
    for (i = 0; i < num_processes; i++) {
        processes[i].id = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    qsort(processes, num_processes, sizeof(struct process), compare_processes);

    printf("The order of execution is:\n");
    for (i = 0; i < num_processes; i++) {
        printf("Process %d (burst time = %d)\n", processes[i].id, processes[i].burst_time);
    }

    return 0;
}

