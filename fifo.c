#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int numberOfJob;
  int *noJob;
  int *timeArrive;
  int *timeUse;
  int *turnaroundTime;
  int *responseTime;
  
  float sumTimeUsed = 0;
  float sumTurnaroundTime = 0;
  float sumResponseTime = 0;
  
  FILE* file = fopen (argv[1], "r");
  int i = 0;

  fscanf (file, "%d", &numberOfJob);  
  noJob = (int*)malloc(numberOfJob*sizeof(int));
  timeArrive = (int*)malloc(numberOfJob*sizeof(int));
  timeUse = (int*)malloc(numberOfJob*sizeof(int));
  responseTime = (int*)malloc(numberOfJob*sizeof(int));
  turnaroundTime = (int*)malloc(numberOfJob*sizeof(int));
  for(i=0;i<numberOfJob;i++){
	fscanf(file,"%d %d %d",&noJob[i],&timeArrive[i],&timeUse[i]);
  }
  
  printf("No of Job = %d\n",numberOfJob);
  for(i=0;i<numberOfJob;i++){
	printf("%d %d %d\n",noJob[i],timeArrive[i],timeUse[i]);
  }
	
  responseTime[0] = 0;
  turnaroundTime[0] = responseTime[0] + timeUse[0];

  int systemTimeUsed = turnaroundTime[0];

  for(i=1;i<numberOfJob;i++)
  {
	if(systemTimeUsed < timeArrive[i])
	{
		responseTime[i] = 0;
		systemTimeUsed += timeArrive[i] + timeUse[i];
	}
	else
	{
		responseTime[i] = systemTimeUsed - timeArrive[i];
		systemTimeUsed += timeUse[i];
	}
	turnaroundTime[i] = responseTime[i] + timeUse[i];
  }

  for(i=0;i<numberOfJob;i++)
  {
	sumResponseTime	+= responseTime[i];	
	sumTimeUsed += timeUse[i];
	sumTurnaroundTime += turnaroundTime[i];
	printf("responseTime = %d\n", responseTime[i]);
	printf("timeUsed = %d\n", timeUse[i]);
	printf("turnaroundTime = %d\n\n", turnaroundTime[i]);
  }
	printf("avgResponseTime = %.2f\n", sumResponseTime/5);
	printf("avgTimeUsed = %.2f\n", sumTimeUsed/5);
	printf("avgTurnaroundTime = %.2f\n", sumTurnaroundTime/5);

  fclose (file);     
}
