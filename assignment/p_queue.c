    #include <stdio.h>
    #include<stdlib.h>
    #define MAX 5

    int queue_array[MAX];
    int rear = - 1, front = - 1;
void enqueue()
{
int num;
if(rear == (MAX-1))
	printf("Queue is Full");
else
{
if(front == -1)
	front = 0;
printf("Enter the number : ");
scanf("%d",&num);

rear++;
queue_array[rear] = num;
}
}

void dequeue()
{
if(front == -1 || front > rear)
	printf("Queue underflow \n");
else
{
printf("number popped is: %d",queue_array[front]);
front++;
}
}
void display()
{
if(front == -1 || front>rear)
	printf("queue is empty ");
else
{
int i;
for(i=front; i <=rear;i++)
{
printf("%d \t",queue_array[i]);
}
printf("\n");
}
}

    int main()
    {
        int choice;
        while (1)
        {
            printf("1.Insert element to queue \n");
            printf("2.Delete element from queue \n");
            printf("3.Display all elements of queue \n");
            printf("4.Quit \n");
            printf("Enter your choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
                case 1: enqueue();
                break;

                case 2: dequeue();
                break;

                case 3: display();
                break;

                case 4: exit(1);
                default:printf("Wrong choice \n");
            }
        } 
    }

