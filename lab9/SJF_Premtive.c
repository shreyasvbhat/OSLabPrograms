#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct{
        int pid;
        int arrivalTime;
        int burstTime;
        int startTime;
        int finishTime;
        int waitTime;
        int TATime;
        int remainingTime;
        int completed;
}Process;

void calculate_time(Process *processes,int n){
 int currTime=0,completed_processes=0, prev=-1;

 while(completed_processes<n){
  int sji=-1,srt=INT_MAX;

  for(int i=0; i<n; i++){
   if(processes[i].arrivalTime<=currTime && !processes[i].completed && processes[i].remainingTime<srt){
     srt=processes[i].remainingTime;
     sji=i;
   }
  }

  if(sji==-1)
        currTime++;
  else{
        if(prev != sji){
                processes[sji].startTime = (processes[sji].startTime == -1)? currTime : processes[sji].startTime;
                prev = sji;
        }
        processes[sji].remainingTime--;
        currTime++;
        if(processes[sji].remainingTime == 0){
                processes[sji].finishTime = currTime;
                processes[sji].waitTime = processes[sji].finishTime - processes[sji].burstTime - processes[sji].arrivalTime;
                processes[sji].TATime = processes[sji].finishTime - processes[sji].arrivalTime;
                processes[sji].completed = 1;
                completed_processes++;
        }
        printf("| (%d)  P%d  (%d)  ", currTime-1 , processes[sji].pid, currTime);
 }
 }
 printf("| ");
}

void printInfo(Process *processes, int n){
        float avgWT =0;
        float avgTAT = 0;
        int totWT = 0;
        int totTAT =0;
        printf("\n\nObservation Table:\nPID\tAT\tBT\tST\tFT\tWT\tTAT\n");
        for(int i=0; i<n; i++){
                printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",processes[i].pid,processes[i].arrivalTime,processes[i].burstTime,processes[i].startTime,processes[i].finishTime,processes[i].waitTime,processes[i].TATime);
                totTAT += processes[i].TATime;
        totWT += processes[i].waitTime;
        }
        avgTAT = (float)totTAT/n;
        avgWT = (float)totWT/n;
        printf("\nAverage Waiting Time: %.2f\n",avgWT);
        printf("\nAverage Turn Around Time: %.2f\n",avgTAT);
}

void main(){
        int n;
        printf("Enter no. of processes:");
        scanf("%d",&n);
        Process *processes=(Process*)malloc(n*sizeof(Process));
        for(int i=0; i<n; i++){
         printf("Enter arrival time and burst time for processe %d : ",i+1);
         processes[i].pid=i+1;
         processes[i].completed=0;
         processes[i].startTime = -1;
         scanf("%d%d",&processes[i].arrivalTime,&processes[i].burstTime);
         processes[i].remainingTime = processes[i].burstTime;
        }
        calculate_time(processes,n);
        printInfo(processes,n);
        free(processes);
}