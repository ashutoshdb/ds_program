#include<stdio.h>
int
main ()
{
  int arr[10], i, j, n, temp;

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


  // insertion sort algorithm

  for (i = 1; i < n; i++)
    {
      temp = arr[i];
      j = i - 1;
      while (j >= 0 && arr[j] > temp)
	{
	  arr[j + 1] = arr[j];
	  j--;
        }
      arr[j + 1] = temp;
    }

  printf ("\n\nThe array element in sorted form:\n");
  for (i = 0; i < n; i++)
    {
      printf ("%d\t", arr[i]);
    }
  printf ("\n");
  return 0;
}
