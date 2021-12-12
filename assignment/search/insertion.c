#include<stdio.h>




int main()
{
  int i,j,n,temp,array[100];
  
   printf("Enter number of elements\n");
   scanf("%d",&n);
   
   printf("Enter %d integers\n", n);
   for ( c = 0 ; c < n ; c++ )
      scanf("%d",&array[c]);
      
     
     
     for(i=1;i<n; i++){
     j = i-1;
     temp  = array[i];
   
   	while(j>0 && array[j]>temp){
   	array[j+1] = array[j];
   	j--;
   	}
   	array[j+1] = temp;
   
     }
       	
