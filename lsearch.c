#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
void main()
{
	struct timeval t0;
  struct timeval t1;
  float elapsed;
  srand( (unsigned) time(NULL) * getpid());
	int n,key,i=0;
	printf("enter size of array:");
	scanf("%d",&n);
	int a[n];
	for (i=0;i<n;i++){
		a[i]=rand()%1000;
	}
	
	for (i=0;i<n;i++){
		printf("%d\n",a[i]);}
	printf("enter number to be searched:");
	scanf("%d",&key);
	gettimeofday(&t0, NULL);
	for(i=0;i<n;i++)
	{
		if(key==a[i]){
			printf("\nelement present at position: %d\n",i+1);
			gettimeofday(&t1, NULL);

  		elapsed = timedifference_msec(t0, t1);

  		printf("Code executed in %f milliseconds.\n", elapsed);
			exit(0);
		}
	}
	printf("element not found!");
	
}
