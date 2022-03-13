#include<stdio.h>
#include<stdlib.h>
#define max 5
int front=-1,rear=-1,q[max];

int main()
{
    int c; 
    while(1)
     {
       printf("1:Insert\n2:Deletion\n3:Display\n4:Exit\n Enter choice:");
       scanf("%d",&c);
       switch(c)
          {
               case 1:enqueue();break;
               case 2:dequeue();break;
               case 3:qdisplay();break;
               case 4:printf("Program Ends\n");
               exit(0);
               default:printf("wrong choice\n");break;
          }
     }
}
int enqueue()
{
     int x;
     if((front==0&&rear==max-1)||(front==rear+1)) 
     {
          printf("Queue is full\n");
	  return;
     }
     if(front==-1 && rear==-1)
     {
          front=rear=0;
     }
     else
     {
          if(rear==max-1)
          {
               rear=0;
          }
          else
               rear++;
     }
     printf("Enter the number:\n");
     scanf("%d",&x);
     q[rear]=x;
     printf("%d successfully inserted\n",x);
     return;
}

int dequeue()
{
     int y;
     if(front==-1)
     {
          printf("Queue is empty\n");
	  return;
     }
     y=q[front];
     if(front==rear)
     {
          front=rear=-1;
     }
     else
     {
          if(front==max-1)
          {
               front=0;
          }
          else
          {
               front++;
          }
     }
     printf("%d successfully deleted\n",y);
     return;
}
int qdisplay()
{
     int i,j;
     if(front==-1)
     {
          printf("Queue is empty\n"); return;
     }
     else
        {
     printf("Elements of circular queue are :\n");

     for(i=front;i!=rear;i=(i+1)% max)
     {
          printf("%d\n",q[i]);
     }
     printf("%d\n",q[rear]);
     }
}
