#include <stdio.h>

int main() {
    // Matrix for storing Process Id, Burst Time, Waiting Time & Turn Around Time.
    int A[100][4];
    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    printf("Enter Burst Time:\n");
    // User Input Burst Time and assigning Process Id.
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &A[i][1]);
        A[i][0] = i + 1; // Process Id
    }

    // Sorting processes according to their Burst Time.
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1; j < n; j++) {
            if (A[j][1] < A[index][1]) {
                index = j;
            }
        }
        // Swap Burst Time
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;

        // Swap Process Id
        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }

    // Initial Waiting Time for the first process
    A[0][2] = 0;

    // Calculation of Waiting Times
    for (i = 1; i < n; i++) {
        A[i][2] = 0;
        for (j = 0; j < i; j++) {
            A[i][2] += A[j][1]; // Add burst times of previous processes
        }
        total += A[i][2]; // Accumulate total waiting time
    }
    
    avg_wt = (float)total / n; // Average Waiting Time
    total = 0;

    printf("\nProcess  BT  WT  TAT\n");
    // Calculation of Turn Around Time and printing the data.
    for (i = 0; i < n; i++) {
        A[i][3] = A[i][1] + A[i][2]; // Turn Around Time = Burst Time + Waiting Time
        total += A[i][3]; // Accumulate total Turn Around Time
        printf("P%d      %d   %d   %d\n", A[i][0], A[i][1], A[i][2], A[i][3]);
    }

    avg_tat = (float)total / n; // Average Turn Around Time

    // Print averages
    printf("Average Waiting Time = %f\n", avg_wt);
    printf("Average Turnaround Time = %f\n", avg_tat);

    return 0;
}
