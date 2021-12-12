#include<stdio.h>
#include<stdlib.h>

void insert(int);
void delete();
void display();

struct node
{
 int data;
 struct node *prev, *next;
 };
 
 struct node *front, *last;
 
 int main()
 {
  int i, ele;
  front= NULL;
  last = NULL;
  
  while(1)
  {
    printf ("\nList of choice:\n");
    printf ("1.To insert the items in the list.\n");
    printf ("2.To remove the items from the list.\n");
    printf ("3.To display the list element.\n");
    printf ("4.To exit.\n");
    printf ("\nEnter the choice:");
    scanf ("%d", &i);
    
    switch (i)
    {
     case 1:
           printf ("Enter the element to insert at front end:");
           scanf ("%d", &ele);
           insert(ele);
           display();
           break;
           
     case 2:
           delete();
           display();
           break;
           
     case 3:
           display();
           break;
           
     case 4:
           exit (1);
           break;
           
     default:
            printf ("Invalid choice.\n\n");
            break;
            }
            }
}
    
void insert(int ele)
{
 struct node *temp;
 temp =(struct node *)malloc(sizeof(struct node));
 temp->data = ele;
 if(front == NULL)
 {
   front = last = temp;
 }
 else
 {
  last->next = temp;
  last = temp;
  temp->next = front;
  front->prev = last;
  }
  printf ("\n%d inserted in the list.\n", temp->data);
}
  
   
void delete()
{
 struct node *temp;
 temp = front;
 if (temp == NULL)
 {
  printf ("list is empty\n");
  }
   else
   {
    if (front == last)
    {
     printf ("\n%d is deleted fromt the list.\n", temp->data);
     free(temp);
     front = last =NULL;
     }
     else
     {
      printf ("\n%d is deleted fromt the list.\n", temp->data);
      front = front->next;
      last->next = front;
      front->prev = last;
      free(temp);
       }
}
}
        
void display()
{
 struct node *temp;
 if (front==NULL)
 {
  printf ("list is empty.\n");
  }
  
  else
  {
   printf ("\nList elements are:\n");
   for (temp = front; temp != last; temp= temp->next)
   {
    printf ("%d\t", temp->data);
    }
    printf ("%d\t", temp->data);
    printf ("\n\n");
    }
}
 
 
 
 
 
 
 
 
 
         
           
    
