#include <stdio.h>

void queueUpdation(int queue[],int timer,int arrival[],int n, int maxProccessIndex){
    int zeroIndex;
    for(int i = 0; i < n; i++){
        if(queue[i] == 0){
            zeroIndex = i;
            break;
        }
    }
    queue[zeroIndex] = maxProccessIndex + 1;
}
void queueMaintainence(int queue[], int n){
    for(int i = 0; (i < n-1) && (queue[i+1] != 0) ; i++){
        int temp = queue[i];
        queue[i] = queue[i+1];
        queue[i+1] = temp;
    }
}
void checkNewArrival(int timer, int arrival[], int n, int maxProccessIndex,int queue[]){
    if(timer <= arrival[n-1]){
    int newArrival = 0;
    for(int j = (maxProccessIndex+1); j < n; j++){
            if(arrival[j] <= timer){
            if(maxProccessIndex < j){
                maxProccessIndex = j;
                newArrival = 1;
            }
        }
    }
    if(newArrival)
        queueUpdation(queue,timer,arrival,n, maxProccessIndex);
    }
}
int main(){
    int n,tq, timer = 0, maxProccessIndex = 0;
    float avgWait = 0, avgTT = 0;
    printf("\nEnter the time quanta : ");
    scanf("%d",&tq);
    printf("\nEnter the number of processes : ");
    scanf("%d",&n);
    int arrival[n], burst[n], wait[n], turn[n], queue[n], temp_burst[n];
    int complete[n];
    printf("\nEnter the arrival time of the processes : ");
    for(int i = 0; i < n; i++)
        scanf("%d",&arrival[i]);
    printf("\nEnter the burst time of the processes : ");
    for(int i = 0; i < n; i++){
        scanf("%d",&burst[i]);
        temp_burst[i] = burst[i];
    }
    for(int i = 0; i < n; i++){
        complete[i] = 0;
        queue[i] = 0;
    }
    while(timer < arrival[0])
        timer++;
    queue[0] = 1;
    while(1){
        int flag = 1;
        for(int i = 0; i < n; i++){
            if(temp_burst[i] != 0){
                flag = 0;
                break;
            }
        }
        if(flag)
            break;
        for(int i = 0; (i < n) && (queue[i] != 0); i++){
            int ctr = 0;
            while((ctr < tq) && (temp_burst[queue[0]-1] > 0)){
                temp_burst[queue[0]-1] -= 1;
                timer += 1;
                ctr++;
                checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
            }
            if((temp_burst[queue[0]-1] == 0) && (complete[queue[0]-1] == 0)){
                //turn array currently stores the completion time
                turn[queue[0]-1] = timer;   
                complete[queue[0]-1] = 1;
            }

            int idle = 1;
            if(queue[n-1] == 0){
                for(int i = 0; i < n && queue[i] != 0; i++){
                    if(complete[queue[i]-1] == 0){
                        idle = 0;
                    }
                }
            }
            else
                idle = 0;

            if(idle){
                timer++;
                checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
            }
            queueMaintainence(queue,n);
        }
    }

    for(int i = 0; i < n; i++){
        turn[i] = turn[i] - arrival[i];
        wait[i] = turn[i] - burst[i];
    }

    printf("\nProgram No.\tArrival Time\tBurst Time\tWait Time\tTurnAround Time\n");
    for(int i = 0; i < n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,arrival[i],burst[i],wait[i],turn[i]);
    }
    for(int i =0; i< n; i++){
        avgWait += wait[i];
        avgTT += turn[i];
    }
    printf("\nAverage wait time : %d\nAverage Turn Around Time : %d",(avgWait/n),(avgTT/n));
    return 0;
    
}
