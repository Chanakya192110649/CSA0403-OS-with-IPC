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

//The burst time of a process is the amount of time the process needs to complete its execution. In other words, it's the amount of CPU time required by a process.

//In real-life scenarios, the burst time is usually estimated based on the process's requirements, such as its computational needs, input/output operations, memory accesses, and so on. The actual burst time can be measured while the process is running, and can be used to fine-tune the scheduling algorithms.

//In this program, the burst time of each process is entered by the user. The program then uses the burst time to determine the order of execution of the processes using the shortest job first (SJF) algorithm.
