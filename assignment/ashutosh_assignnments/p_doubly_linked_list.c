 #include<stdio.h>

typedef struct node{
int data;
struct node *next;
struct node *prev;
} node;

node *head, *last;

void insert_start(){
node *temp;

temp = (node *)malloc(sizeof(node);
temp->data = num;

if(head == NULL)
{
head = temp;
temp->next = NULL;
temp->prev = NULL;
last = head;
}
else
{
temp->next = head;
temp->prev = NULL;
head-prev = temp;
head = temp;

}
}


void insert_end(){
node *temp1,temp2;


temp = (node *)malloc(sizeof(node);
temp->data = num;


if(head == NULL){
	head = temp;
	temp->next = NULL;
	temp->prev = NULL;
	last = head;

}
else{

last->next = temp;
temp->prev = last;
temp->next = NULL;
last = temp;
}
}

void insert_loc( int value, int num){

struct node *temp,*var,*temp1;
     var=(struct node *)malloc(sizeof(struct node));
     var->data=value;
int i;
node *temp, *temp1;

if(head==NULL){
	head = var;
	var->next = NULL;
	var->prev = NULL;
	last = head;
}
else{
temp = head;
for(i=1; i<=num -1;i++){
temp = temp->next;
}
temp1 = temp->next; //  for collectting the address of the next node
temp->next = var;
var->prev = temp;
var->next = temp1
temp1->prev = var
}
}


void delete_start(){

node *temp;
head = temp;

if(head->next == NULL){
	free(temp);
	head = NULL;
	last = NULL;

}
else{

head = temp->next;
head->prev = NULL;
free(temp);
}
}

void delete_end(){

node * temp;
temp = last;
if(temp->prev == NULL){
head = NULL; 
lst = NULL;
free(temp);
}
else
{

last = temp->prev;
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
                    insert_start(value);
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
                    insert_loc(value,loc);
                    display();
                    break;
                 case 4:
                    delete_start();
                    display();
                    break;
                 case 5:
                    delete_end();
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












































