#include<stdio.h>

int main()

{
 int arr[30];
 int i, num, key=0, f=0, loc;
 
 printf("Enter the size of array:");
 scanf ("%d", &num);
 
 printf ("Enter the array element:");
 for (i=0; i<num; i++)
 {
 scanf ("%d", &arr[i]);
 }
 
 printf ("The array elements are:\n");
 for (i=0; i<num; i++)
 {
 printf ("arr[%d]=%d\n",i, arr[i]);
 }
 
 printf ("\nEnter the key you want to search:");
 scanf ("%d", &key);
 
 for (i=0; i<num; i++)
 {
  if (key == arr[i])
  {
   f =1;
   loc = i+1;
   break;
   }
 }
 
 if (f == 1)
 {
  printf ("%d is available in the array at %d location.\n", key, loc);
  }
  else
  {
   printf ("%d is not available in the array.\n", key);
   }
 return 0;
 }
