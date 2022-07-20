/*insertion sort in c*/
#include <stdio.h>        
#include <stdlib.h>

#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
      
void insert(int a[], int n)
{  
      int i, j, temp;  
      for (i = 1; i < n; i++) 
      {  
            temp = a[i];  
            j = i - 1;  
            while(j>=0 && temp <= a[j])   
            {    
                	a[j+1] = a[j];     
                	j = j-1;    
            }    
            a[j+1] = temp;    
        }  
}  
      
void printArr(int a[], int n) 
{  
        int i;  
        for (i = 0; i < n; i++)  
            printf("%d\t", a[i]);  
}  
      
int main()  
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

  printf("UNSORTED ARRAY: \n");
  printArr(a, n);
  printf("\n");
  gettimeofday(&t0, NULL);  
  insert(a, n);  
  gettimeofday(&t1, NULL);
  printf("\nSORTED ARRAY: \n");    
  printArr(a, n);
  printf("\n");   
  elapsed = timedifference_msec(t0, t1);
  printf("Code executed in %f milliseconds.\n", elapsed);
  return 0;  
}    

