#include <stdio.h>
#include <conio.h>

void main()
{
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0;
    int at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    printf("Enter the number of processes (NOP): ");
    scanf("%d", &NOP);

    for (i = 0; i < NOP; i++)
    {
        printf("\nEnter the arrival and burst time of process[%d]\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i]; 
    }

    printf("Enter the time quantum for the process: ");
    scanf("%d", &quant);

    printf("\nProcess No \t Burst Time \t TAT \t Waiting Time");

    // Round Robin scheduling
    y = NOP;    
    int time = 0; 
    while (y > 0)
    {
        for (i = 0; i < NOP; i++)
        {
            if (temp[i] > 0 && at[i] <= time)
            { 
                if (temp[i] <= quant)
                {
                    time += temp[i]; 
                    temp[i] = 0;     
                    count = 1;       
                }
                else
                {
                    temp[i] -= quant; 
                    time += quant;    
                }
                if (temp[i] == 0 && count == 1)
                {
                    y--;               
                    tat = time - at[i]; 
                    wt = tat - bt[i];   
                    printf("\nProcess No[%d] \t %d \t\t %d \t\t %d", i + 1, bt[i], tat, wt);
                    count = 0; 
                }
            }
        }
    }

    avg_wt = (float)wt / NOP;
    avg_tat = (float)tat / NOP;
    printf("\n\nAverage TAT: \t%.2f", avg_tat);
    printf("\nAverage WT: \t%.2f", avg_wt);
    getch();
}