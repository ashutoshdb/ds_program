#include <stdio.h>
int main()
{
   int c, f l, m, n, key, array[100];
  
   printf("Enter number of elements\n");
   scanf("%d",&n);
   
   printf("Enter %d integers\n", n);
   for ( c = 0 ; c < n ; c++ )
      scanf("%d",&array[c]);
   
   printf("Enter value to find\n");
   scanf("%d",&key);
	 f = 0;
	 l = n-1;
	 m = (f+l)/2;
	 
	 while(f<l){
	 if(arr[m] < key){
	 f = m +1;
	 }
	 else if (arr[m] == key){
	 
	 
         printf("%d found at location %d\n", key, m+1);
         break;
      }
	 }
	 else
	 {
	 last = m -1;
	 }
	 m = (f +l)/2;
	
	 
	 }
	  if ( f > l )
      printf("Not found! %d is not present in the list\n", key);
   return 0;

}
