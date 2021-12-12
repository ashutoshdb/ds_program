#include<stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
struct node *next;
} node;
node *head;

int count();
int
main ()
{
    int i,num,loc;
    struct node *n;
    head=NULL;
    while(1)
    {
    printf("\n List Operations\n");
    printf("===============\n");
    printf("1.Insert at begining\n");
    printf("2.Insert at end\n");
    printf("3.Insert at specified location \n");
    printf("4.Display\n");
    printf("5.Size\n");
    printf("6.Delete\n");
    printf("7.Exit\n");
    printf("Enter your choice : ");
    if(scanf("%d",&i)<=0){
        printf("Enter only an Integer\n");
        exit(0);
    } else {
        switch(i)
        {
        case 1:  printf("Enter the number to insert : ");
                 scanf("%d",&num);
                 insert_start(num);
                 break;
        case 2:  printf("Enter the number to insert : ");
                 scanf("%d",&num);
                 insert_end(num);
                 break;
        case 3:  printf("Enter the number and location to insert : ");
                 scanf("%d %d",&num, &loc);
                 insert_loc(num, loc);
                 break;
        case 4: if(head==NULL)
                {
                printf("List is Empty\n");
                }
                else
                {
                printf("Element(s) in the list are : ");
                }
                display(n);
                break;
        case 5:    printf("Size of the list is %d\n",count());
                   break;
        case 6:     if(head==NULL)
                printf("List is Empty\n");
                else{
                printf("Enter the number to delete : ");
                scanf("%d",&num);
                if(delete(num))
                    printf("%d deleted successfully\n",num);
                else
                    printf("%d not found in the list\n",num);
                }
                break;

        case 7:     return 0;
        default:    printf("Invalid option\n");
        }
    }
    }
	
  return 0;
}

void
insert_start (int num)
{
  node *temp;
  temp = (node *) malloc (sizeof (node));
  temp->data = num;
  if (head == NULL)
    {
      head = temp;
      temp->next = NULL;
    }
  else
    {
      temp->next = head;
      head = temp;
    }
}


void
insert_end (int num)
{
  node *temp1, *temp2;
  temp1 = (node *) malloc (sizeof (node));
  temp1->data = num;
   temp1->next = NULL;
  temp2 = head;
  if (head == NULL)
    {
      head = temp1;
      temp1->next = NULL;
    }
  else
    {
      while (temp2->next != NULL)
	{
	  temp2 = temp2->next;
	}
   
    temp2->next = temp1;}
}


void
insert_loc (int num, int n)
{
int i;
  node *temp1, *prev, *curr; 
  temp1 = (node *) malloc (sizeof (node));
  temp1->data = num;
  curr = head;
  if (n > (count () + 1) || n <= 0)
    {
      printf ("Insertion not  possible");
    }

  if (n == 1)
    {
    insert_start (num);}
  for (i = 0; i <= n; i++)
    {
      prev = curr;
      curr = prev->next;
    }

  prev->next = temp1;
  temp1->next = curr;
}
int delete_front()
{
node *temp;
temp = head;
head = head->next;
free(temp);
return ;
}

int delete_end()
{
node *temp,*last;
last = head;

while(last->next!=NULL)
{-
temp = last;
last = last->next;

}
if(last == head)
{
free(last);
head = NULL;
}
else{
free(last);
temp->next = NULL;
}
}
void
delete (int num)
{
  node *temp, *prev;
  temp = head;
  while (temp != NULL)
    {
      if (temp->data == num)
	{
	  if (temp == head)
	    {
	      head = temp->next;
	      free (temp);
	      return 1;
	    }
	  else
	    {
	      prev->next = temp->next;
	      free (temp);
	      return 1;
	    }
	}
      else
	{
	  prev = temp;
	  p;temp = temp->next;
	}
    }
  return 0;
}

void delete_loc (int n)
{
int i;
node *prev,*curr;
curr =head;

 for (i = 0; i <= n; i++)
    {
      prev = curr;
      curr = prev->next;
    }
    	prev->next = curr->next;
	      free (curr);
	      return 1;


}

void
display ()
{
  node *n;
  n = head;
  while (n != NULL)
    {
        printf ("the value is %d", n->data);
      n = n->next;
  

    }
  printf ("\n");
}

int count()
{
  node *n;
  n = head;
  int count = 0;
  while (n != NULL)
    {
      n = n->next;
      count++;
    }

return count;
}

void search()

{
 int flag =0;
 node *temp; 
 temp =  head;
 while(temp!=NULL)
 {
 if(temp->data == num)
{
flag++;
break;
}
else
temp = temp->next; 
 }
retun flag; 
}



























