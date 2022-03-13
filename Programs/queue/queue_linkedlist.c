#include<stdio.h>
#include<stdlib.h>

void enqueue(int);
void dequeue();
void display();
struct node
{
 int data;
 struct node *next;
 };
 
 struct node *front, *last;
 
 int main()
 {
  int i, ele;
  front=NULL;
  last=NULL;
  
  while(1)
  {
   printf ("\nList of choices:\n");
   printf ("1.To enter the element in the queue.\n");
   printf ("2.To remove the element from the queue.\n");
   printf ("3.To display the list element.\n");
   printf ("4.To exit\n");
   printf ("\nEnter the choice:");
   scanf ("%d", &i);
   
   switch (i)
   {
    case 1:
          printf ("Enter the element:");
          scanf ("%d", &ele);
          enqueue(ele);
          printf ("\n%d inserted into the list\n\n", ele);
          display();
          break;
          
    case 2:
          dequeue();
          display();
          break;
          
    case 3:
          display();
          break;
          
    case 4:
          exit (1);
          break;
          
    default:
          printf ("wrong choice");
          break;
          
    }
   }
 }

void enqueue(int ele)
{
 struct node *temp;
 temp =(struct node *)malloc(sizeof(struct node));
 temp->data=ele;
 if(last == NULL)
 {
  last = temp;
  last->next = NULL;
  front = last;
 }
 else
 {
   last->next = temp;
   last = temp;
   last->next = NULL;
 }
 }
 
void dequeue()
{
 struct node *temp;
 temp = front;
 if(front == NULL)
 {
 printf ("\n bb List is empty\n\n");
  
  }
   else
   {
    front = front->next;
  free(temp);
  printf ("\nElemenet removed from the list\n\n");
    }
}

void display()
{
 struct node *temp;
 temp = front;
 if (temp == NULL)
    {
    printf ("\n aaa List is empty\n");
    } 
  while (temp != NULL)
     {
       printf ("%d \t", temp->data);
        temp = temp->next;
        }
       printf ("\n"); 
       }
  
         








  
 
 
 
 
 
 
 
 
 
 
 
           
