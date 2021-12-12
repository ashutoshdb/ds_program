#include<stdio.h>

int main()

{
 int arr[30];
 int i, num, key, f=0;
 
 
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
 
 printf ("enter the element you want to search:");
 scanf ("%d", &key);
 
 int first=0, last=num-1, mid= (first+last)/2;
 
 while (first <= last)
 {
  if (key == arr[mid])
  {
   printf ("\n%d available at %d location.\n", key, mid+1);
   f=1;
   break;
   }
   else if (key < arr[mid])
   {
    last=mid-1;
    mid= (first+last)/2;
    }
    else
    {
     first= mid+1;
     mid= (first+last)/2;
     }
     
     }
     
   if (f ==0)
      {
       printf ("%d is not available in the array.\n", key);
       }
 return 0;
 }
