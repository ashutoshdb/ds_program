#include<stdio.h>
int
main ()
{
  int arr[10], i, j, n, temp, min;

  printf ("enter the size of array:");
  scanf ("%d", &n);

  printf ("Enter the array element:");
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &arr[i]);
    }

  printf ("The array elements are(unsorted form):\n");

  for (i = 0; i < n; i++)
    {
      printf ("%d\t", arr[i]);
    }


  // selection sort algorithm

  for (i = 0; i < n; i++)
    {
      min = i;
      for (j = i + 1; j < n; j++)
	{
	  if (arr[j] < arr[min])
	    {
	      min = j;
	    }
	}
      if (min != i)
	{
	  temp = arr[min];
	  arr[min] = arr[i];
	  arr[i] = temp;
	}
    }

  printf ("\n\nThe array element in sorted form:\n");
  for (i = 0; i < n; i++)
    {
      printf ("%d\t", arr[i]);
    }
  printf ("\n");
  return 0;
}
