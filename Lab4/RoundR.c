#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

struct process
{
	int process_id;
	int arrival_time;
	int burst_time;
	int completion_time;
	int waiting_time;
	int turn_around_time;
	int remaining_time;
};

int queue[N];
int front = 0, rear = 0;
struct process proc[N];

void enqueue(int process_id)
{
	queue[rear] = process_id;
	rear = (rear+1)%N;
}

int dequeue()
{
	if(front == rear)
		return -1;

	int return_position = queue[front];
	front = (front +1)%N;
	return return_position;
}

int main()
{
	float wait_time_total = 0.0, tat = 0.0, avg_ct = 0.0;
	int n,time_quantum;
	printf("Enter the number of processes: ");
	scanf("%d", &n);

	//input
	for(int i=0; i<n; i++)
	{
		printf("Arrival time ( process %d ): ",i+1);
		scanf("%d", &proc[i].arrival_time);
		printf("Burst time ( process %d ): ",i+1);
		scanf("%d", &proc[i].burst_time);
		proc[i].process_id = i+1;
		proc[i].remaining_time = proc[i].burst_time;
	}
	printf("Enter time quantum: ");
	scanf("%d",&time_quantum);

	int time=0; 
	int processes_left=n;   
	int position=-1; 		
	int local_time=0; 

	//enqueuing all arrived elements
	for(int j=0; j<n; j++)
		if(proc[j].arrival_time == time)
			enqueue(j);

	while(processes_left)
	{
		if(local_time == 0) 
		{
			if(position != -1)
				enqueue(position);

			position = dequeue();
		}

		for(int i=0; i<n; i++)
		{
			if(proc[i].arrival_time > time)
				continue;
			if(i==position)
				continue;
			if(proc[i].remaining_time == 0)
				continue;

			proc[i].waiting_time++;
			proc[i].turn_around_time++;
		}

		if(position != -1)
		{
			proc[position].remaining_time--;
			proc[position].turn_around_time++;
			
			if(proc[position].remaining_time == 0)
			{
				processes_left--;
				local_time = -1;
				position = -1;
			}
		}
		else
			local_time = -1; 

		time++;
		local_time = (local_time +1)%time_quantum;
		for(int j=0; j<n; j++)
			if(proc[j].arrival_time == time)	
				enqueue(j);
	}

	printf("\n");

	//to calculate ct
	for (int i = 0; i < n; ++i)
	{
		proc[i].completion_time = proc[i].turn_around_time + proc[i].arrival_time;
	}

	printf("Process\t\tAT\t\tBT\t\tCT\t\tWT\t\tTAT\n");
	for(int i=0; i<n; i++)
	{
		printf("%d\t\t%d\t\t", proc[i].process_id, proc[i].arrival_time);
		printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].burst_time,proc[i].completion_time, proc[i].waiting_time, proc[i].turn_around_time);

		tat += proc[i].turn_around_time;
		wait_time_total += proc[i].waiting_time;
		avg_ct += proc[i].completion_time;
	}

	tat = tat/(1.0*n);
	wait_time_total = wait_time_total/(1.0*n);
	avg_ct /= n;
	printf("\nAvg ct     : %f",avg_ct);
	printf("\nAvg wt    : %f",wait_time_total);
	printf("\nAvg TAT   : %f\n", tat);
	
}

