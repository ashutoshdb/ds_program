#include<stdio.h>

int main()
{
  int i,j,n,array[100];
  
   printf("Enter number of elements\n");
   scanf("%d",&n);
   
   printf("Enter %d integers\n", n);
   for ( c = 0 ; c < n ; c++ )
      scanf("%d",&array[c]);

for(i=0 ; i<n-1 ; i++){
	for(j=0; j< n -i-1; j++)
	
	if(array[j] >array[j+1]){
		temp = array[j];
		array[j] = array[j+1];
		array[j+1] = temp;
	}

}

printf("sorted array \n");

for( i=0; i<n ;i++)
pritf("%d \t" array[i])

return 0;
}
