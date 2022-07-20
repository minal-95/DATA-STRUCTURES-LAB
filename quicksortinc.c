#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
void quicksort(int a[],int first,int last)
{
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(a[i]<=a[pivot]&&i<last)
         i++;
         while(a[j]>a[pivot])
         j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }
      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quicksort(a,first,j-1);
      quicksort(a,j+1,last);
   }
}
void main(){
	 
	 struct timeval t0;
	 struct timeval t1;
	 float elapsed;
	
	 srand( (unsigned) time(NULL) * getpid());   

   int i, n;
   printf("Enter no of elements: ");
   scanf("%d",&n);
   int a[n];
   for (i=0;i<n;i++)
 	 {
		a[i]=rand()%1000;
	 }	
	 printf("Original array:\n");
	 for(i=0;i<n;i++)
   printf("%d\t ",a[i]);
   gettimeofday(&t0, NULL);  
   quicksort(a,0,n-1);
   gettimeofday(&t1, NULL);  
   printf("\nSorted array:\n");
   for(i=0;i<n;i++)
   printf("%d\t",a[i]);
   elapsed = timedifference_msec(t0, t1);
   printf("\nCode executed in %f milliseconds.\n", elapsed);
   printf("\n");
}
