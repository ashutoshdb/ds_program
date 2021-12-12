#include<stdio.h>
void maxheap (int *, int, int);
void maxheapify (int *, int, int);
void heapsort (int *, int);

int
main ()
{
  int arr[10], i, num;

  printf ("Enter the size of array:");
  scanf ("%d", &num);

  printf ("Enter the array element:\n");
  for (i = 0; i < num; i++)
    {
      scanf ("%d", &arr[i]);
    }

  printf ("The array elements in unsorted form:\n");
  for (i = 0; i < num; i++)
    {
      printf ("%d\t", arr[i]);
    }
  printf ("\n");

  maxheap (arr, 0, num - 1);
  heapsort (arr, num - 1);

  printf ("\nThe array element in sorted form:\n");
  for (i = 0; i < num; i++)
    {
      printf ("%d\t", arr[i]);
    }
  printf ("\n");

}

void
maxheap (int arr[10], int start, int end)
{
  int i;
  for (i = end / 2; i >= start; i--)	// condition for maxheap.
    maxheapify (arr, i, end);
}

void
maxheapify (int arr[10], int i, int end)
{
  int max = i;			//  i = root index.
  int left = 2 * i;		// left child of root index.  
  int right = (2 * i) + 1;	// right child of index.
  int temp;

  if (left <= end && arr[left] > arr[max])
    max = left;

  if (right <= end && arr[right] > arr[max])
    max = right;

  if (i != max)
    {
      temp = arr[i];
      arr[i] = arr[max];
      arr[max] = temp;

      maxheapify (arr, max, end);
    }
}

void
heapsort (int arr[10], int end)
{
  int i, temp;
  for (i = end; i >= 1; i--)	// swap the root element with max element  
    {
      temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      maxheapify (arr, 0, i - 1);	// call maxheapify function for again making the maxheap tree
    }
}
