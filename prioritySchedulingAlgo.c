#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;      // Process ID
    int bt;       // CPU Burst time required
    int priority; // Priority of this process
};

// Function to compare priorities (for sorting)
int comparison(const void *a, const void *b)
{
    struct Process *p1 = (struct Process *)a;
    struct Process *p2 = (struct Process *)b;
    return (p2->priority - p1->priority); // Descending order
}

// Function to find the waiting time for all processes
void findWaitingTime(struct Process proc[], int n, int wt[])
{
    wt[0] = 0; // Waiting time for the first process is 0
    for (int i = 1; i < n; i++)
    {
        wt[i] = proc[i - 1].bt + wt[i - 1];
    }
}

// Function to calculate turn around time
void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }
}

// Function to calculate average time
void findavgTime(struct Process proc[], int n)
{
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);
    printf("\nProcesses Burst time Waiting time Turn around time\n");
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        printf(" %d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, wt[i], tat[i]);
    }
    printf("\nAverage waiting time = %.2f", (float)total_wt / n);
    printf("\nAverage turn around time = %.2f\n", (float)total_tat / n);
}

// Priority Scheduling function
void priorityScheduling(struct Process proc[], int n)
{
    qsort(proc, n, sizeof(struct Process), comparison);
    printf("Order in which processes get executed:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", proc[i].pid);
    }
    printf("\n");
    findavgTime(proc, n);
}

// Driver code
int main()
{
    struct Process proc[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}};
    int n = sizeof(proc) / sizeof(proc[0]);
    priorityScheduling(proc, n);
    return 0;
}