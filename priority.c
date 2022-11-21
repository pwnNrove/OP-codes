#include <stdio.h>
int totalprocess = 0;

struct process
{
int at,bt,pr,pno;
}proc[50];

void sort(struct process* a, struct process* b){
    struct process temp;
    if (a->at > b->at){
        temp = *a;
        *a = *b;
        *b = temp;
    }
    else if (a->at == b->at){
        if (a->pr > b->pr){
            temp = *a;
            *a = *b;
            *b = temp;
        }
    }
}

void get_wt_time(int wt[])
{
    int service[50];
    service[0] = proc[0].at;
    wt[0]=0;
    for(int i=1;i<totalprocess;i++)
    {
        service[i]=proc[i-1].bt+service[i-1];
        wt[i]=service[i]-proc[i].at;
        if(wt[i]<0)
        {
            wt[i]=0;
        }
    }
}

void get_tat_time(int tat[],int wt[])
{
    for(int i=0;i<totalprocess;i++)
    {
        tat[i]=proc[i].bt+wt[i];
    }
}

void findgc()
{
    int wt[50],tat[50];
    double wavg=0,tavg=0;
    get_wt_time(wt);
    get_tat_time(tat,wt);       
    int stime[50],ctime[50];
    stime[0] = proc[0].at;
    ctime[0]=stime[0]+tat[0];
    for(int i=1;i<totalprocess;i++)
        {
            stime[i]=ctime[i-1];
            ctime[i]=stime[i]+tat[i]-wt[i];
        }        
    printf("Process_no\tArrival time\tPriority\tBurst time\tStart_time\tComplete_time\tTurn_Around_Time\tWaiting_Time\n");        
    for(int i=0;i<totalprocess;i++)
        {
            wavg += wt[i];
            tavg += tat[i];

            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",proc[i].pno,proc[i].at,proc[i].pr,proc[i].bt,stime[i],ctime[i],tat[i],wt[i]);
        }   
    printf("\nAverage waiting time is : %f\n",wavg/(float)totalprocess);
    printf("average turnaround time : %f\n",tavg/(float)totalprocess);

}

int main()
{

    printf("\nEnter no. of processes: ");
    scanf("%d",&totalprocess);
    int arrivaltime[totalprocess];
    int bursttime[totalprocess];
    int priority[totalprocess];
    for(int i=0; i<totalprocess; i++)
    {
        printf("\n\t\tP%d",i+1);
        printf("\nEnter Arrival time : ");
        scanf("%d",&proc[i].at);
        printf("Enter burst time : ");
        scanf("%d",&proc[i].bt);
        printf("Enter priority : ");
        scanf("%d",&proc[i].pr);
        proc[i].pno = i+1;
    }
    for (int i=0;i<totalprocess-1;i++){
        sort(proc+i,proc+(i+1));
    }
    findgc();
    return 0;
}

