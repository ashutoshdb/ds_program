#include<stdio.h>
#include<stdlib.h>

struct node
{
     int data;
     struct node *previous;
     struct node *next;
};

struct node *head, *last;

int main()
{
    int value, i, loc;
    head=NULL;
    printf("Select the choice of operation on link list: ");
    printf("\n1. Insert at beginning\n2. Insert at End\n3. Insert at specified location");
    printf("\n4. Delete at the beginning\n5. Delete at the end\n6. Display list\n7. Exit");
    while(1)
    {
          printf("\n\n Enter the choice of operation: ");
          scanf("%d",&i);
          switch(i)
          {
                case 1:
                    printf("Enter the value you want to insert in begining\t");
                    scanf("%d",&value);
                    insert_begining(value);
                    display();
                    break;
                 case 2:
                    printf("Enter the value you want to insert at last\t");
                    scanf("%d",&value);
                    insert_end(value);
                    display();
                    break;
                 case 3:
                    printf("Enter the location you want to insert\t");
                    scanf("%d",&loc);
                    printf("Enter the data you want to insert in list\t");
                    scanf("%d",&value);
                    insert_location(value,loc);
                    display();
                    break;
                 case 4:
                    delete_begin();
                    display();
                    break;
                 case 5:
                    delete_from_end();
                    display();
                    break;
                 case 6 :
                    display();
                    break;
                 case 7 :
                      exit(0);
                      break;
          }
    }
    printf("\n\n%d",last->data);
    display();
}

int insert_begining(int value)
{
    struct node *temp;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->data=value;
     if(head==NULL)
     {
         head=temp;
         head->previous=NULL;
         head->next=NULL;
         last=head;
     }
     else
     {
         temp->previous=NULL;
         temp->next=head;
         head->previous=temp;
         head=temp;
     }
}

int insert_end(int value)
{
     struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=value;
     if(head==NULL)
     {
          head=temp;
          head->previous=NULL;
          head->next=NULL;
          last=head;
     }
     else
     {
     	last->next=temp;
     	temp->previous=last;
     	temp->next=NULL;
     	last=temp;
     }
}

int insert_location(int value, int loc)
{
     int i;
     struct node *temp,*var,*temp1;
     var=(struct node *)malloc(sizeof(struct node));
     var->data=value;

     if(head==NULL)
     {
           head=var;
           head->previous=NULL;
           head->next=NULL;
     }
     else
     {
           temp=head;
           for(i=1; i<loc-1; i++)
           {
                 temp=temp->next;
           }
           temp1=temp->next;
           temp->next=var;
           var->previous=temp;
           var->next=temp1;
           temp1->previous=var;
     }
}

int delete_begin()
{
    struct node *temp;
    temp=head;
    if(temp->next==NULL)
    {
      free(temp);
      head=NULL;
      last=NULL;
    }
    else
    {
      head=temp->next;
      head->previous=NULL;
      free(temp);
    }
}

int delete_from_end()
{
    struct node *temp;
    temp=last;
    if(temp->previous==NULL)
    {
      free(temp);
      head=NULL;
      last=NULL;
    }
    else
    {
      last=temp->previous;
      last->next=NULL;
      free(temp);
    }
}

int display()
{
     struct node *temp;
     temp=head;
     if(temp==NULL)
      {
         printf("List is Empty");
      }
     while(temp!=NULL)
     {
          printf("-> %d ",temp->data);
          temp=temp->next;
     }
}

