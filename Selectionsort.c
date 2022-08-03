/*Selection Sort */
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
      
void selection(int a[], int n)  
{  
        int i, j, s,temp;  
          
        for (i = 0; i < n-1; i++)    // One by one move boundary of unsorted subarray  
        {  
            s = i; //minimum element in unsorted array  
            for (j = i+1; j < n; j++)  
            if (a[j] < a[s])  
           {
                s = j;  
               
           }
    	    // Swap the minimum element with the first element  
           int temp = a[s];  
           a[s] = a[i];  
           a[i] = temp;  
        }  
}  
      
void printArr(int a[], int n) /* function to print the array */  
{  
       int i;  
       for (i = 0; i < n; i++)  
       {
            printf("%d ", a[i]);  
    	}  
}
    
int main()  
{  
    	struct timeval t0;
	struct timeval t1;
	float elapsed;
	
	srand( (unsigned) time(NULL) * getpid()); 
	
        int n,i ;
	int a[100];
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		a[i]=rand()%100;
	}	
	gettimeofday(&t0, NULL);
        printf("Before sorting array elements are: \n");  
        printArr(a, n);
        printf("\n");  
        selection(a, n);  
        gettimeofday(&t1, NULL);
        printf("\nAfter sorting array elements are: \n");    
        printArr(a, n);
        printf("\n");  
        printf("\n");  
        elapsed = timedifference_msec(t0, t1);
   	printf("Code executed in %f milliseconds.\n", elapsed);
   	printf("\n");
        return 0;  
}    
