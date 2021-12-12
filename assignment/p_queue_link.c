#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
} node;

node *front, *rear;


void enqueue(int num){
node *temp;

temp = (node *)malloc(sizeof(node));
temp->data = num;
temp->next = NULL;

if(rear == NULL){
rear=temp;
temp->next = NULL;
front = rear;
}
else{

rear->next = temp;
rear = temp; 
}
}


void dequeue(){
node *temp;
if(front == NULL){

	printf("queue is enpty");
}
else
{
temp = front;
front = temp->next;
free(temp);
}
}

void display()
{
node *r;
    r=front;
    if(r==NULL)
    {
    front = NULL;
    rear = NULL; 
    }
    while(r!=NULL)
    {
    printf("%d ",r->data);
    r=r->next;
    }
    printf("\n");
}




 int main()
 {
  int i, ele;
  node *front=NULL;
  node *rear=NULL;
  
  while(1)
  {
   printf ("\nList of choices:\n");
   printf ("1.To enter the element in the queue.\n");
   printf ("2.To remove the element from the queue.\n");
   printf ("3.To display the list element.\n");
   printf ("4.To exit\n");
   printf ("\nEnter the choice:");
   scanf ("%d", &i);
   
   switch (i)
   {
    case 1:
          printf ("Enter the element:");
          scanf ("%d", &ele);
          enqueue(ele);
          printf ("\n%d inserted into the list\n\n", ele);
          display();
          break;
          
    case 2:
          dequeue();
          display();
          break;
          
    case 3:
          display();
          break;
          
    case 4:
          exit (1);
          break;
          
    default:
          printf ("wrong choice");
          break;
          
    }
   }
 }

