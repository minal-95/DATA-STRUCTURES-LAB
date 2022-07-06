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
	
	 int j=0,temp;    
    for(i=0; i<n ;i++)
				a[i]=rand()%100;
    for(i=0; i<n ;i++){     
        for(j=0; j<n ;j++){          
            if(a[j] > a[j+1]){               
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
		for(i=0; i<n ;i++)
        printf("%d\n",a[i]);
    printf("enter number to be searched:");
	  scanf("%d",&key);
		int l=0,h,mid;
		h=n-1;
		mid=(l+h)/2;
		gettimeofday(&t0, NULL);
		while(l<=h)
		{
			if(a[mid]<key){
				l=mid+1;}
			else if(a[mid]==key){
				printf("\nelement present at position: %d",mid+1);
				gettimeofday(&t1, NULL);
  			elapsed = timedifference_msec(t0, t1);
  			printf("Code executed in %f milliseconds.\n", elapsed);
			  exit(0);
			}
			else{
				h=mid-1;
			}
			mid=(l+h)/2;
		}
	printf("element not found!");
	
}
