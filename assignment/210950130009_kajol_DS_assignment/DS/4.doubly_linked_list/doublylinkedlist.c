#include<stdio.h>
#include<stdlib.h>

void insert_B(int);
void insert_E(int);
void insert_L(int, int);
void delete_B();
void delete_E();
int count();
void display();

struct node
{
 int data;
 struct node *prev, *next;
 };
 
 struct node *front, *last;
 
 int main()
 {
  int i, ele, loc;
  front= NULL;
  last = NULL;
  
  while(1)
  {
    printf ("\nList of choice:\n");
    printf ("1.To insert at the begining.\n");
    printf ("2.To insert at the end.\n");
    printf ("3.To insert at any location.\n");
    printf ("4.To delete from the front end.\n");
    printf ("5.To delete fromt the rear end.\n");
    printf ("6.To count the size of list.\n");
    printf ("7.To display the list element.\n");
    printf ("8.To exit.\n");
    printf ("\nEnter the choice:");
    scanf ("%d", &i);
    
    switch (i)
    {
     case 1:
           printf ("Enter the element to insert at front end:");
           scanf ("%d", &ele);
           insert_B(ele);
           display();
           break;
           
     case 2:
           printf ("Enter the element to insert at rear end:");
           scanf ("%d", &ele);
           insert_E(ele);
           display();
           break;
           
     case 3:
          printf ("Enter the location and the number:");
          scanf ("%d %d", &loc, &ele);
          insert_L(loc, ele);
          display();
          break;
          
     case 4:
           delete_B();
           display();
           break;
        
     case 5:
           delete_E();
           display();
           break;
           
              
     case 6:
           printf ("The size of list is %d\n", count());
           break;
     
     case 7:
           display();
           break;
           
     case 8:
           exit (1);
           break;
           
     default:
            printf ("Invalid choice.\n\n");
            break;
            }
            }
}
    
void insert_B(int ele)
{
 struct node *temp;
 temp =(struct node *)malloc(sizeof(struct node));
 temp->data = ele;
 if(front == NULL)
 {
   front = temp;
   front->next =NULL;
   front->prev =NULL;
   last = front;
 }
 else
 {
  temp->prev = NULL;
  temp->next =front;
  front->prev = temp;
  front = temp;
  }
}
  
void insert_E(int ele)
{
 struct node *temp;
 temp =(struct node *)malloc(sizeof(struct node));
 temp->data = ele;
 if(front == NULL)
 {
   front = temp;
   front->next =NULL;
   front->prev =NULL;
   last = front;
  }
  else
  {
   last->next =temp;
   temp->prev =last;
   temp->next =NULL;
   last = temp;
   }
}

int count()
{
 int c=0;
 struct node *temp;
 temp = front;
 while (temp != NULL)
 {
  c++;
  temp= temp->next;
  }
  return c;
 }

void insert_L(int loc, int ele)
{
 struct node *temp1, *temp2, *temp;
 temp =(struct node *)malloc(sizeof(struct node));
 temp->data =ele;
 if (loc == 1)
 {
  insert_B(ele);
  }
  else if (loc == (count()+1))
  {
   insert_E(ele);
   }
   
   else
   {
    temp1 = front; 
    for (int i=0; i < loc-1; i++)
    {
     temp1 = temp1->next;
     }
     temp2 =temp1->next; 
     temp1->next = temp;
     temp->next =temp2;
     temp->prev = temp1;
     temp2->prev = temp;
     }
}
     
     
void delete_B()
{
 struct node *temp;
 temp = front;
 if (temp == NULL)
 {
  printf ("list is empty\n");
  }
  
  else if (temp->next == NULL)
  {
   free(temp);
   front = NULL;
   last = NULL;
   }
  
  else
  {
   front = front->next;
   front->prev = NULL;
   free(temp);
   printf ("Element deleted from the front end.\n");
   }
}

void delete_E()
{
 struct node *temp;
 temp = last;
 if (temp == NULL)
 {
  printf ("list is empty\n");
  }
  
  else if (temp->prev == NULL)
  {
   free(temp);
   front = NULL;
   last = NULL;
   }
   
   else 
   {
    last = temp->prev;
    last->next = NULL;
    free(temp);
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
   temp = front;
   printf ("List elements are:\n");
   while (temp != NULL)
   {
    printf ("%d\t", temp->data);
    temp =temp->next;
    }
    printf ("\n");
    }
}
 
 
 
 
 
 
 
 
 
         
           
    
