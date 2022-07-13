#include <stdio.h>
#include <stdlib.h>

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
	int n,temp;
	printf("Enter no of elements:");
	scanf("%d",&n);
	int a[n];
	int i,j=0;
	printf("Enter elements:\n");    
  for(i=0; i<n ;i++)
				a[i]=rand()%100;
	printf("elements are:\n");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	gettimeofday(&t0, NULL);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	gettimeofday(&t1, NULL);
  
 	printf("\nSorted elements are:\n");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	elapsed = timedifference_msec(t0, t1);
	printf("\nCode executed in %f milliseconds.\n", elapsed);
	
}
		
