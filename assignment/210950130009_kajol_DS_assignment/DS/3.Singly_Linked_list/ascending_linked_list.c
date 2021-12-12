#include<stdio.h>
#include<stdlib.h>

void insert (int);
int ascending();
int display ();

struct node
{
  int data;
  struct node *next;
};

struct node *head;

int
main ()
{
  int num, choice, loc, ele;
  head = NULL;

  while (1)
    {
      printf ("List of choices:\n");
      printf ("================\n");
      printf ("1. To enter the element\n");
      printf ("2. To display linked list item\n");
      printf ("3. To exit\n");
      printf ("Enter the choice:");
      scanf ("%d", &choice);

      switch (choice)
	{
	case 1:
	  printf ("\nEnter the number:");
	  scanf ("%d", &num);
	  insert(num);
	  display();
	  break;

	
	case 2:
	  display ();
	  break;

            
       	case 3:
	  exit (1);
	  break;
	}
    }
}



void
insert(int num)
{
  struct node *temp, *ptr;
  temp = (struct node *) malloc (sizeof (struct node));
  temp->data = num;
  if (head == NULL)		// only one element in the list
    {
      head = temp;
      head->next = NULL;
    }
  else if (temp->data <= head->data)
  {
    temp->next = head;
    head = temp;
    }
         else
         {
               ptr = head;
		while(ptr->next != NULL && ptr->data < temp->data) //traversing to the end
		{
			ptr = ptr->next;
		}
		
		temp->next = ptr->next;
		ptr->next = temp;
		}
}


int display ()
{
  struct node *d;
  d = head;
  if (d == NULL)
    {
      printf ("\nList is empty\n\n");
      return 0;
    }
 printf ("\nThe element(s) of the list:\n");
  while (d != NULL)
    {
      printf ("%d \t", d->data);
      d = d->next;
    }
  printf ("\n\n");
}




 
