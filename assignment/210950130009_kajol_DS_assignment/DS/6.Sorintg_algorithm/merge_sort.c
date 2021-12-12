#include<stdio.h>

void mergesort (int *, int, int);
void merge (int *, int, int, int);

int
main ()
{
  int arr[20], i, num;

  printf ("Enter the array size:");
  scanf ("%d", &num);

  printf ("\nEnter the array elements:\n");
  for (i = 0; i < num; i++)
    {
      scanf ("%d", &arr[i]);
    }

  printf ("\n\nThe array elements are:\n");
  for (i = 0; i < num; i++)
    {
      printf ("%d\t", arr[i]);
    }

  mergesort (arr, 0, num - 1);
  printf ("\n\nThe array element after merge sort:\n");
  for (i = 0; i < num; i++)
    {
      printf ("%d\t", arr[i]);
    }
  printf ("\n\n");
}

void
mergesort (int arr[20], int first, int last)
{
  int mid;
  if (first < last)
    {
      mid = (first + last) / 2;

      mergesort (arr, first, mid);
      mergesort (arr, mid + 1, last);
      merge (arr, first, mid, last);
    }
}

void
merge (int arr[20], int first, int mid, int last)
{
  int i, j, k;
  int b[20];

  i = first;
  j = mid + 1;
  k = first;

  while (i <= mid && j <= last)
    {
      if (arr[i] < arr[j])
	b[k++] = arr[i++];

      else
	b[k++] = arr[j++];

    }

  if (i > mid)
    while (j <= last)
      b[k++] = arr[j++];

  else
    while (i <= mid)
      b[k++] = arr[i++];

  for (i = first; i <= last; i++)
    {
      arr[i] = b[i];
    }
}
