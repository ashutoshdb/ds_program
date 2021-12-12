#include<stdio.h>
#include<stdlib.h>

void insert (int);
void delete ();
int display();


struct node
{
  int data;
  struct node *next;
};

struct node *head, *last, *temp;

int
main ()
{
  int num, choice, loc, ele;
  head = NULL;

  while (1)
    {
      printf ("List of choices:\n");
      printf ("================\n");
      printf ("1. To enter the element in the linked list\n");
      printf ("2. To delete the element of linked list\n");
      printf ("3. To display the list items.\n");
      printf ("4. To exit\n");
      printf ("Enter the choice:");
      scanf ("%d", &choice);

      switch (choice)
	{
	case 1:
	  printf ("\nEnter the number:");
	  scanf ("%d", &num);
	  insert (num);
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
	}
    }
}

void
insert (int num)
{
  struct node *new;
  new = (struct node *) malloc (sizeof (struct node));
  new->data = num;
  if (last == NULL)		// only one element in the list
    {
      head = new;
      last = new;
    }
  else
    {
      last->next = new;
      last = new;
      }
  printf ("\n%d added successfully in the list.\n\n", num);
}

void delete()
{
 temp = head;
 if (head == NULL)
 {
  printf ("List is empty.\n");
  }
  else 
  {
    if (head == last)
     {
       printf ("\n%d successfully deleted from the list.\n", head->data);
       free(temp);
       head = last =NULL;
       }
       else 
         {
          printf ("\n%d successfully deleted from the list.\n", head->data);
           head = head->next;
           last->next = head;
           free(temp);
           }
           
           }
           
           }
           
int
display ()
{
  struct node *d;
  d = head;
  if (d == NULL)
    {
      printf ("\nList is empty\n\n");
      return 0;
    }
 printf ("\nThe linked list element(s)=\n\n");
  for ( d = head; d != last; d = d->next)
    {
      printf ("%d \t", d->data);
      
    }
  printf ("%d \t", d->data);
  printf ("\n\n");
  
}

  
  
  
  
  
  
  
  
 






 
