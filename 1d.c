//1d prio
#include<stdio.h>
void findavgTime(int p[],int n,int bt[],int pr[])
{
    int wt[20],tat[20],i,j,total=0,pos,temp;
    float avg_wt,avg_tat;
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0; 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        total+=wt[i];
    }
    avg_wt=total/n;     
    total=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     
        total+=tat[i];
        printf("\n %d ",p[i]);
        printf(" \t\t %d ",bt[i]);
        printf("\t\t    %d",wt[i]);
        printf("\t\t\t%d",tat[i]);
    }
 
    avg_tat=total/n;     
    printf("\n\nAverage Waiting Time= %f",avg_wt);
    printf("\nAverage Turnaround Time= %f",avg_tat);
}
void main() 
{ 
	int processes[100],burst_time[100],priority[100],n;
	printf("Enter number of processes : ");
	scanf("%d",&n);
	printf("Enter the burst time of each Process \n");
	for(int i=0;i<n;i++)
	{
	    processes[i]=i+1;
	    printf("Process %d : ",i+1);
	    scanf("%d",&burst_time[i]);
	}
	printf("Enter the priority of each Process \n");
	for(int i=0;i<n;i++)
	{
	    printf("Process %d : ",i+1);
	    scanf("%d",&priority[i]);
	}
	findavgTime(processes,n,burst_time,priority); 
} 
