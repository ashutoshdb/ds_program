#include<stdio.h>
#include<stdlib.h>

void insert (int);
int display ();
int count ();
int reverse();

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
      printf ("1. To enter the element at rear end\n");
      printf ("2. To display linked list item\n");
      printf ("3. To reverse the given linked list.\n");
      printf ("4. To exit\n");
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
          reverse();
          break;
       
       	case 4:
	  exit (1);
	  break;
	}
    }
}


void
insert(int num)
{
  struct node *temp1, *temp2;
  temp1 = (struct node *) malloc (sizeof (struct node));
  temp1->data = num;
  temp2 = head;
  if (head == NULL)		// only one element in the list
    {
      head = temp1;
      head->next = NULL;
    }
  else
    {
      while (temp2->next != NULL)	// traverse down to end 
	temp2 = temp2->next;
      temp1->next = NULL;
      temp2->next = temp1;
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


int reverse()
  {
   struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; // Make first node as last node

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode;
        }
          printf ("\nAfter Reversing the linked list:\n");
           while(head != NULL)
        {
            printf("%d\t", head->data); // Print the data of head node
            head = head->next;                 // Move to next node
        }
        printf ("\n\n");
    }
    

 
