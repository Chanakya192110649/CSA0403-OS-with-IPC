#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

// Data structure to store information about a process
typedef struct {
  int processId;
  int arrivalTime;
  int burstTime;
  int priority;
  int waitingTime;
  int turnaroundTime;
} Process;

// Function to compare two processes based on priority
int compareProcesses(const void *a, const void *b) {
  Process *p1 = (Process *)a;
  Process *p2 = (Process *)b;
  return p1->priority - p2->priority;
}

int main() {
  // Number of processes
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  // Array to store information about all processes
  Process processes[MAX_PROCESSES];

  // Input information about all processes
  for (int i = 0; i < n; i++) {
    printf("Enter information about process %d\n", i + 1);
    printf("Enter arrival time: ");
    scanf("%d", &processes[i].arrivalTime);
    printf("Enter burst time: ");
    scanf("%d", &processes[i].burstTime);
    printf("Enter priority: ");
    scanf("%d", &processes[i].priority);
    processes[i].processId = i + 1;
  }

  // Sort processes based on priority
  qsort(processes, n, sizeof(Process), compareProcesses);

  // Compute waiting time and turnaround time for each process
  int currentTime = 0;
  for (int i = 0; i < n; i++) {
    Process currentProcess = processes[i];
    if (currentTime < currentProcess.arrivalTime) {
      currentTime = currentProcess.arrivalTime;
    }
    currentProcess.waitingTime = currentTime - currentProcess.arrivalTime;
    currentTime += currentProcess.burstTime;
    currentProcess.turnaroundTime = currentTime - currentProcess.arrivalTime;
  }

  // Print information about all processes
  printf("Process ID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; i++) {
    Process currentProcess = processes[i];
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", currentProcess.processId, currentProcess.arrivalTime, currentProcess.burstTime, currentProcess.priority, currentProcess.waitingTime, currentProcess.turnaroundTime);
  }

  return 0;
}

