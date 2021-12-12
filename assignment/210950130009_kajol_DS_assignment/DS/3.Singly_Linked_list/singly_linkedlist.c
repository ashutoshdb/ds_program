#include<stdio.h>
#include<stdlib.h>

void insert (int);
void insert_end (int);
int count ();
void insert_spe (int, int);
int delete_f ();
void delete_e ();
int delete_r (int);
void delete_spe(int);
int display ();
void search (int);


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
      printf ("1. To enter the element at front end\n");
      printf ("2. To enter the element at rear end\n");
      printf ("3. To enter the element at any sepcified location\n");
      printf ("4. To delete the item from the front end\n");
      printf ("5. To delete the item from the rear end\n");
      printf ("6. To delete the random number\n");
      printf ("7. to delete from a specific location\n");
      printf ("8. To display linked list item\n");
      printf ("9. To search the element in the list\n");
      printf ("10. size of linked list\n");
      printf ("11. To exit\n");
      printf ("Enter the choice:");
      scanf ("%d", &choice);

      switch (choice)
	{
	case 1:
	  printf ("\nEnter the number:");
	  scanf ("%d", &num);
	  insert (num);
	  break;

	case 2:
	  printf ("\nEnter the number:");
	  scanf ("%d", &num);
	  insert_end (num);
	  break;

	case 3:
	  printf ("\nenter the number and location:");
	  scanf ("%d %d", &num, &loc);
	  insert_spe (num, loc);
	  break;

	case 4:
	  delete_f ();
	  break;

	case 5:
	  delete_e ();
	  break;

	case 6:
	  if (head == NULL)
	    printf ("List is empty\n");
	  else
	    {
	      printf ("\nEnter a number to delete from the list:");
	      scanf ("%d", &num);
	      if (delete_r (num))
		{
		  printf ("\n%d deleted sucessfully from the list\n\n", num);
		}
	      else
		{
		  printf ("\n%d in not available in the list\n\n", num);
		}
	    }
	  break;
	  
	  case 7:
	 printf("\nEnter a location:");
	 scanf("%d", &loc);
	 delete_spe(loc);
	 break;

	case 8:
	  printf ("\nElement(s) of the list : \n");
	  display ();
	  break;

        case 9:
          printf ("\nEnter the element to search:");
          scanf ("%d", &ele);
          search(ele);
          break;
          
	case 10:
	  printf ("\nSize of the list:%d\n\n", count ());
	  break;

	
	case 11:
	  exit (1);
	  break;
	}
    }
}

void
insert (int num)
{
  struct node *temp;
  temp = (struct node *) malloc (sizeof (struct node));
  temp->data = num;
  if (head == NULL)		// only one element in the list
    {
      head = temp;
      head->next = NULL;
    }
  else
    {
      temp->next = head;
      head = temp;
    }
  printf ("\n%d added successfully at the front of the list.\n\n", num);
}

void
insert_end (int num)
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
  printf ("\n%d added successfully at the end of the list.\n\n", num);
}

int
count ()
{

  struct node *n;
  int i = 0;
  n = head;
  while (n != NULL)
    {
      n = n->next;
      i++;
    }
  return i;
}


void
insert_spe (int num, int loc)
{
  struct node *temp, *curr, *prev;
  curr = head;
  if (loc > (count () + 1) || loc <= 0)
    {
      printf ("\n Element can not be insert in the list\n\n");
    }
  else
    {
      if (loc == 1)
	{
	  insert (num);		// function calling for inserting the element at the front.
	}
      else if (loc == (count () + 1))
	{
	  insert_end (num);	// function calling for inserting the element at the end.
	}
      else
	{
	  for (int i = 1; i < loc; i++)
	    {
	      prev = curr;
	      curr = curr->next;
	    }
	  temp = (struct node *) malloc (sizeof (struct node));
	  temp->data = num;
	  prev->next = temp;
	  temp->next = curr;
	}
    }
  printf ("\n%d added successfully in the list at location %d\n\n ", num, loc);
}

int
delete_f ()
{
  struct node *temp;
  if (head == NULL)
    {
      printf ("\nList is alreay empty\n\n");
      return 0;
    }
  else
    {
      temp = head;
      head = head->next;
      free (temp);
      printf ("\nData deleted successfully from the frond end\n\n");
    }
}

void
delete_e ()
{
  struct node *temp1, *temp2;
  if (head == NULL)
    {
      printf ("\nList is alreay empty\n\n");
    }
  else if (head->next == NULL)	// only one element in the list
    {
      free (head);
      head = NULL;
    }
  else
    {
      temp1 = head;
      temp2 = head;
      while (temp1->next != NULL)
	{
	  temp2 = temp1;
	  temp1 = temp1->next;
	}
      temp2->next = NULL;
      free (temp1);
      printf ("\nData deleted succesfully from the rear end\n\n");
    }
}

int
delete_r(int num)
{
  struct node *curr, *prev;
  curr = head;
  while (curr != NULL)
    {
      if (curr->data == num)
	{
	  if (curr == head)
	    {
	      head = curr->next;
	      free (curr);
	      return 1;
	    }
	  else
	    {
	      prev->next = curr->next;
	      free (curr);
	      return 1;
	    }
	}
      else
	{
	  prev = curr;
	  curr = curr->next;
	}

    }
  return 0;
}

void delete_spe(int loc)
{
 int num;
 struct node *curr, *prev;
 curr=head;
 if(loc==1)
 {
  delete_f(num);
  }
  else if (loc == count())
  {
   delete_e(num);
   }
   else
   {
    for(int i=1; i<loc; i++)
    {
     prev = curr;
     curr= curr->next;
     }
     prev->next = curr->next;
     free(curr);
     }
     printf("\nElement delete from the location %d\n\n", loc);
     }


void search(int ele)
{
 int f=0;
 struct node *temp;
 temp =head;
 while (temp != NULL)
  {
   if (temp->data==ele)
     {
      f++;
      break;
      }
      else
      {
       temp =temp->next;
       }
       }
       if (f>=1)
         {
           printf("\nElement available on the list\n\n");
           }
           else
           {
            printf("\nElement is not available\n\n");
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

  while (d != NULL)
    {
      printf ("%d \t", d->data);
      d = d->next;
    }
  printf ("\n\n");
}


  
  
  
  
  
  
  
  
 






 
