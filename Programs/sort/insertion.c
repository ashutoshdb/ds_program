#include<stdio.h>

int main()
{
  int i,j,n,temp,array[100];
  
   printf("Enter number of elements\n");
   scanf("%d",&n);
   
   printf("Enter %d integers\n", n);
   for (int  c = 0 ; c < n ; c++ )
      scanf("%d",&array[c]);
      
     for(i=1; i<n-1; i++)
     {
 	    j = i;
            while ( j > 0 && array[j-1] > array[j])
            {	        
                temp     = array[j];
                array[j]   = array[j-1];
                array[j-1] = temp;
                j--;
            }
      
     }
       	
