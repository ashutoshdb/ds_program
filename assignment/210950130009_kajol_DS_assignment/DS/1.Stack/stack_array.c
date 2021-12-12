                       ///* Day1. Assignment *///
    ///* P1. Write a C Program to implement stack using Arrays *///

#include<stdio.h>
#include<stdlib.h>
#define MAX 6
int push();
int pop();
int display();
int arr[MAX], top=-1;
int main()
{
 
 int num;
 while(1)
 {
  printf("1.To insert the element in the stack\n");
  printf("2.To insert the element in the stack\n");
  printf("3.To insert the element in the stack\n");
  printf("4.exit\n");
  printf("Enter a choice:");
  scanf("%d", &num);
  
  switch(num)
  {
  case 1: 
  push(); 
  break;
  case 2: 
  pop(); 
  break;
  case 3: 
  display(); 
  break;
  case 4: 
  exit (1); 
  break;
  default: 
  printf("\nwrong choice\n");
  }
  }
  }
  
int push()
{
 int n;
  if (top == MAX-1)
  {
  printf("Stack Array is full\n");
  return 0;
  }
  else 
  {
  printf("Enter a number:");
  scanf("%d", &n);
  top++;
  printf("%d has been pushed to the location %d\n", n, top);
  arr[top]=n;
  
  }
}
  
int pop()
{
 if(top==-1)
 {
  printf("Stack array is already empty\n");
 }
 else
 {
 top--;
 printf("Top element has been pop out");
 }
 }
 
 int display()
 {
 if(top==-1)
 {
  printf("Stack array is already empty\n");
 }
 else
 {
 int i;
 for(i=0; i<=top; i++)
 printf("arr[%d]=%d\n", i, arr[i]);
 }
 }
 
  
  

