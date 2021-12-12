#include<stdio.h>
#include<stdlib.h>

void push (int);
void pop ();
void display ();

struct node
{
  int data;
  struct node *next;
};

struct node *top;

int
main ()
{
  int i, ele;

  while (1)
    {
      printf ("\nList of choices:\n");
      printf ("=================\n");
      printf ("\n1.push the element in the stack\n");
      printf ("2.pop the element from the stack\n");
      printf ("3.display the stack element\n");
      printf ("4.exit\n\n");
      printf ("Enter the choice:");
      scanf ("%d", &i);

      switch (i)
	{
	case 1:
	  printf ("Enter the element to push into the stack: ");
	  scanf ("%d", &ele);
	  push (ele);
	  printf ("%d pushed into the stack\n\n", ele);
	  break;

	case 2:
	  pop ();

	  break;

	case 3:

	  display ();
	  break;

	case 4:
	  exit (1);
	  break;

	default:
	  printf ("Wrong choice.\n\n");
	  break;

	}
    }
}


void
push (int ele)
{
  struct node *temp;
  temp = (struct node *) malloc (sizeof (struct node));
  temp->data = ele;
  if (top == NULL)
    {
         top=temp;
         top->next=NULL;
    }
    else
    {
        temp->next=top;
        top=temp;
    }

}

void
pop ()
{
  struct node *temp;
  if (top == NULL)
    {
      printf ("\nStack is empty\n\n");
      return;
    }

  else
    {
      temp = top;
      top = top->next;
      free (temp);
    }
  printf ("Element pop out from the stack.\n\n");
}

void
display ()
{
  struct node *temp;
  if (top == NULL)
    {
      printf ("\nStack is empty\n\n");
      return;
    }

  else
    {
      temp = top;
      printf ("\nStack elements are:\n");
      while (temp != NULL)
	{

	  printf ("%d\t", temp->data);
	  temp = temp->next;
	}

    }
  printf ("\n");
}
