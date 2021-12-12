#include <stdio.h>

int main()
{
   int arr[100], n, i, j, temp, minimum;

   printf("Enter number of elements\n");
   scanf("%d", &n);

   printf("Enter %d integers\n", n);

   for ( i = 0 ; i < n ; i++ )
      scanf("%d", &arr[i]);

       for ( i = 0 ; i < n-1 ; i++ )
        {
	       minimum=i;
                for ( j = i + 1 ; j < n ; j++ )
                {
                        if ( arr[j] < arr[minimum] )
                        {
			   minimum=j;
			}
		}
			if(minimum!=i)
			{
                                temp = arr[minimum] ;
                                arr[minimum] = arr[i] ;
                                arr[i] = temp ;
                        }
                
        }

   printf("Sorted list in ascending order:\n");

   for ( i = 0 ; i < n ; i++ )
      printf("%d\t", arr[i]);

      printf("\n");
      return 0;
}
