#include<stdio.h>

int main(){
    int no_pr;
    printf("\nAkshit Gupta - 21BCS3509");
    printf("\nEnter no. of processes: ");
    scanf("%d",&no_pr);

    int burst_time[no_pr];
    printf("\nEnter burst time according to their arrival: ");

    for (int i=0; i<no_pr;i++){
        printf("\nProcess %d ::",i+1);
        scanf("%d",&burst_time[i]);
    }

    int wait_time[no_pr];
    wait_time[0] = 0;

    for(int i=1;i<no_pr;i++){
        wait_time[i] = wait_time[i-1] + burst_time[i-1];
    }

    int ta_time[no_pr];
    for (int i=0; i<no_pr; i++){
        ta_time[i] = wait_time[i]+burst_time[i];
    }
    printf("\nProcess no.  Burst Time  Waiting Time  TurnAround Time");
    for (int i=0; i<no_pr; i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d",i+1,burst_time[i],wait_time[i],ta_time[i]);
    }
}
