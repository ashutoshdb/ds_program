                                           ///* Day1. Assignment *///
                    ///* P3. Write a C Program to implement circular queue using Arrays.  *///
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
  if ((front == 0 && rear == MAX - 1) || front ==rear+1 )
    {
      printf ("Queue is full\n");
    }
  else 
  {
      if (front == -1 && rear == -1)
             {
                 front = rear =0;
             }
      else
      {
           if (rear == MAX-1)
             {
             rear =0;
             }
           else
             {
            rear++;
             }
      }
      printf ("Enter the queue element:");
      scanf ("%d", &ele);
      que[rear]=ele;
      printf("%d is inserted in the queue\n", ele);
    }
}

void delete ()
{
  int x;
  if (front == -1)
    {
      printf ("Queue is empty\n");
      return;
    }
    x=que[front];
       if (front == rear)
        {
          front = rear = -1;
        }
  
    else
    {
      if (front == MAX-1)
          {
          front ==0;
          }
       else
          {
          front ++;
          }
     }
      printf ("Element deleted from the queue=%d\n", x);
}


void display ()
{
  int i, j;
  if (front == -1)
    {
      printf ("Queue is empty\n");
      return;
    }
  else
    {
      printf ("Queue element:\n");
      for (i = front; i != rear; i =(i+1)%MAX)
	{
	  printf ("%d\n",que[i]);
	}
	printf("%d\n",que[rear]);
    }
}



