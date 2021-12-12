#include<stdio.h>
void quicksort (int *, int, int);

int
main ()
{
  int arr[20];
  int i, num;

  printf ("\nEnter the size of array:");
  scanf ("%d", &num);

  printf ("\nEnter the elements of array:\n");
  for (i = 0; i < num; i++)
    {
      scanf ("%d", &arr[i]);
    }


  printf ("\nThe array elements are:\n");
  for (i = 0; i < num; i++)
    {
      printf ("%d\t", arr[i]);
    }

  quicksort (arr, 0, num - 1);

  printf ("\n\nThe array elements in sorted form:\n\n");
  for (i = 0; i < num; i++)
    {
      printf ("%d\t", arr[i]);
    }
  printf ("\n\n");
}

void
quicksort (int arr[20], int first, int last)
{
  int i, j, temp, pivot;

  if (first < last)
    {
      pivot = first;
      i = first;
      j = last;

      while (i < j)
	{
	  while (arr[i] <= arr[pivot] && i < j)
	    {
	      i++;
	    }
	  while (arr[pivot] < arr[j])
	    {
	      j--;
	    }
	  if (i < j)
	    {
	      temp = arr[i];
	      arr[i] = arr[j];
	      arr[j] = temp;
	    }
	}
      temp = arr[pivot];
      arr[pivot] = arr[j];
      arr[j] = temp;

      quicksort (arr, first, j - 1);
      quicksort (arr, j + 1, last);
    }

}
