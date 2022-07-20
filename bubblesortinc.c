#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void bubblesort(int a[],int n)
{
		
	int i, j,temp;
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if (a[j]<a[i])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	
}

void  main()
{
	struct timeval t0;
	struct timeval t1;
	float elapsed;
	srand( (unsigned) time(NULL) * getpid()); 
	int n,i ;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int a[n];
	for (i=0;i<n;i++)
	{
		a[i]=rand()%1000;
	}	
	gettimeofday(&t0, NULL);
	printf("The array elements are:\n");
	for (i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	bubblesort(a,n);
	gettimeofday(&t1, NULL);
	elapsed = timedifference_msec(t0, t1);
	printf("SORTED ARRAY:\n");
	for (i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
  printf("Code executed in %f milliseconds.\n", elapsed);
}

