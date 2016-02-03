#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int numberOfJob;
  int *jobID;
  int *timeArrive;
  int *timeUse;

  int *responseTime;
  int *turnAroundTime;
  
  FILE* file = fopen (argv[1], "r");
  int i = 0;

  fscanf (file, "%d", &numberOfJob);  
  jobID = (int*)malloc(numberOfJob*sizeof(int));
  timeArrive = (int*)malloc(numberOfJob*sizeof(int));
  timeUse = (int*)malloc(numberOfJob*sizeof(int));
  responseTime = (int*)malloc(numberOfJob*sizeof(int));
  turnAroundTime = (int*)malloc(numberOfJob*sizeof(int));
  for(i=0;i<numberOfJob;i++){
	fscanf(file,"%d %d %d",&jobID[i],&timeArrive[i],&timeUse[i]);
  }
  
  printf("No of Job = %d\n",numberOfJob);
  for(i=0;i<numberOfJob;i++){
	printf("%d %d %d\n",jobID[i],timeArrive[i],timeUse[i]);
  }
  
  fclose (file);        
}