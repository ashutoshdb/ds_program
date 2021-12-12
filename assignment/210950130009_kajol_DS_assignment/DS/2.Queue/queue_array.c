                                        ///* Day1. Assignment *///
                    ///* P2. Write a C Program to implement queue using Arrays.  *///
#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int que[MAX], front = -1, rear = -1;
void insert();
void delete();
void display();

int
main ()
{

  int c;
  while (1)
    {
      printf ("Press 1 to insert the queue element\n");
      printf ("Press 2 to delete the queue element\n");
      printf ("Press 3 for display the queue element\n");
      printf ("Press 4 for exit\n");
      printf ("Enter the choice:");
      
      scanf ("%d", &c);

      switch (c)
	{
	case 1:
	    insert ();
	    break;
	  
	case 2:
	  
	    delete ();
	    break;
	  
	case 3:
	  
	    display ();
	    break;
	  
	case 4:
	  exit (1);
	default:
	  printf ("wrong number\n");
	}
    }
  return 0;
}

void insert ()
{
  int ele;
  if (rear == MAX - 1)
    {
      printf ("Queue is full\n");
    }
  else 
  {
      if (front == -1)
      front = 0;
      printf ("Enter the queue element:");
      scanf ("%d", &ele);
      rear = rear + 1;
      que[rear]=ele;
    }
}

void delete ()
{
  if (front == -1 || front > rear)
    {
      printf ("Queue is empty\n");
      return;
    }
  else
    {
      printf ("Element deleted from the queue=%d\n", que[front]);
      front = front + 1;
    }
}

void display ()
{
  int i;
  if (front == -1 || front > rear)
    {
      printf ("Queue is empty\n");
      return;
    }
  else
    {
      printf ("Queue element:\n");
      for (i = front; i <= rear; i++)
	{
	  printf ("que[%d]=%d\n", i, que[i]);
	}
    }
}

