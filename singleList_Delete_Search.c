#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

int  main()
{
    int i,num,loc, flag;
    struct node *n;
    head=NULL;

    while(1)
    {
    printf("\n List Operations\n");
    printf("===============\n");
    printf("1.Insert at beginning\n");
    printf("2.Insert at end\n");
    printf("3.Insert at specified location \n");
    printf("4.Display\n");
    printf("5.Size\n");
    printf("6.Delete at front\n");
    printf("7.Delete at end\n");
    printf("8.Delete the specified number\n");
    printf("9.Search the list\n");
    printf("10.Exit\n");
    printf("Enter your choice : ");
    if(scanf("%d",&i)<=0){
        printf("Enter only an Integer\n");
        exit(0);
    } else {
        switch(i)
        {
        case 1:  printf("Enter the number to insert : ");
                 scanf("%d",&num);
                 insert(num);
                 break;
        case 2:  printf("Enter the number to insert : ");
                 scanf("%d",&num);
                 insert_end(num);
                 break;
        case 3:  printf("Enter the number and location to insert : ");
                 scanf("%d %d",&num, &loc);
                 insert_loc(num, loc);
                 break;
        case 4:  printf("Element(s) in the list are : ");
                 display(n);
                 break;
        case 5:  printf("Size of the list is %d\n",count());
                 break;
        case 6:  delete_front();
                 break;
        case 7:  delete_end();
                 break;
        case 8:  if(head==NULL)
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
         case 9: printf("Enter the number to search: ");
                 scanf("%d",&num);
                 flag=search_num(num);
                 if(flag>=1)
                    printf("\nNumber is found in the List");
                    else
                    printf("\nNumber not found in List");
                 break;
        case 10: exit(0);
        default: printf("Invalid option\n");
        }
    }
}
    return 0;
}

int insert(int num)
{
    struct node *temp;
    temp= (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    if (head == NULL)
    {
       //List is Empty
       head=temp;
       head->next=NULL;
    }
    else
    {
       temp->next=head;
       head=temp;
    }
}

int insert_end(int num)
     {
        struct node *temp1, *temp2;

        temp1=(struct node *)malloc(sizeof(struct node));
        temp1->data=num;

        // Copying the Head location into another node.
        temp2=head;

        if(head == NULL)
        {
           // If List is empty we create First Node.
           head=temp1;
           head->next=NULL;
        }
        else
        {
           // Traverse down to end of the list.
           while(temp2->next != NULL)
           temp2=temp2->next;

           // Append at the end of the list.
           temp1->next=NULL;
           temp2->next=temp1;
        }
     }

int insert_loc(int num, int loc)
 {
    int i;
    struct node *temp, *prev, *curr;

    curr = head;
    if(loc > (count()+1) || loc <= 0)
    {
       printf("\nInsertion at given location is not possible\n ");
    }
    else
    {
        if (loc == 1)
        {
            insert(num);
        }
        else
        {
            for(i=1;i<loc;i++)
            {
                prev = curr;
                curr = curr->next;
            }
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = num;

            prev->next=temp;
            temp->next=curr;
        }
    }
 }

int delete_front()
{
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);
    return;
}

int delete_end()
{
    struct node *temp, *last;
    last=head;

    while(last->next!=NULL)
    {
        temp=last;
        last=last->next;
    }
    if(last==head)
    {
        free(last);
        head=NULL;
    }
    else
    {
        free(last);
        temp->next = NULL;
    }
    return;
}

int delete(int num)
{
    struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
    if(temp->data==num)
    {
        if(temp==head)
        {
        free(temp);
        head = NULL;
        return 1;
        }
        else
        {
        prev->next=temp->next;
        free(temp);
        return 1;
        }
    }
    else
   {
        prev=temp;
        temp= temp->next;
   }
    }
    return 0;
}

int search_num(int num)
 {
     int flag=0;
     struct node *temp;
     temp=head;
    while(temp!=NULL)
   {
        if(temp->data==num)
        {
            flag++;
            break;
        }
        else
        temp=temp->next;
   }
 return flag;
 }

int display(struct node *r)
{
    r=head;
    if(r==NULL)
    {
    printf("List is empty\n");
    return;
    }
    while(r!=NULL)
    {
    printf("%d\t",r->data);
    r=r->next;
    }
    printf("\n");
}

int count()
{
    struct node *n;
    int c=0;
    n=head;
    while(n!=NULL)
    {
    n=n->next;
    c++;
    }
    return c;
}
