#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int numberOfJob;
  int *noJob;
  int *timeArrive;
  int *timeUse;
  int *rt;
  
  FILE* file = fopen (argv[1], "r");
  int i = 0;

  fscanf (file, "%d", &numberOfJob);  
  noJob = (int*)malloc(numberOfJob*sizeof(int));
  timeArrive = (int*)malloc(numberOfJob*sizeof(int));
  timeUse = (int*)malloc(numberOfJob*sizeof(int));
  rt = (int*)malloc(numberOfJob*sizeof(int));
  for(i=0;i<numberOfJob;i++){
	fscanf(file,"%d %d %d",&noJob[i],&timeArrive[i],&timeUse[i]);
  }
  
  printf("No of Job = %d\n",numberOfJob);

  for(i=0;i<numberOfJob;i++){
	printf("%d %d %d\n",noJob[i],timeArrive[i],timeUse[i]);
  }
  

  
  int j=0,n = numberOfJob,time,remain = numberOfJob,flag=0;
  int ts = 2; //time slice
  int sum_wait=0,sum_turnaround=0; //at = arrive time, bt = burst time, rt = current time in each node
  int ganttP[50],ganttStartTime[50];
  
  for(i=0;i<n;i++)
  {
    rt[i]=timeUse[i];
  }
  printf("\n\nProcess\t|Turnaround time|waiting time\n\n");
  for(time=0,i=0;remain!=0;)
  {
    if(rt[i]<=ts && rt[i]>0)
    {
      ganttP[j]=i+1;
      ganttStartTime[j++]=time;
      time+=rt[i];
      rt[i]=0;
      flag=1;
    }
    else if(rt[i]>0)
    {
      ganttP[j]=i+1;
      ganttStartTime[j++]=time;
      rt[i]-=ts;
      time+=ts;
    }
    if(rt[i]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-timeArrive[i],time-timeArrive[i]-timeUse[i]);
      sum_wait+=time-timeArrive[i]-timeUse[i];
      sum_turnaround+=time-timeArrive[i];
      flag=0;
    }
    if(i==n-1)
      i=0;
    else if(timeArrive[i+1]<=time)
      i++;
  }
  printf("\nAvg sum_wait = %f\n",sum_wait*1.0/n);
  printf("Avg sum_turnaround = %f",sum_turnaround*1.0/n);
  printf("\n\n");
  for(i=0;i<j;i++)
  {
      printf("(P[%d],%d) ",ganttP[i],ganttStartTime[i]);
  }
  printf("\n");
  fclose (file);   
}