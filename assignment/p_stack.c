#include<stdio.h>
#include<stdlib.h>
#define max 5

int stack[max], top=-1;
void push()
{
if(top == max)
	printf("Stack overflow");
else
{
	int num;
	printf("Enter the element : ");
	scanf("%d",&num);
	top++;
	stack[top] = num;
}
}

void pop()
{
if( top == -1)
	printf("Stack underflow");
else
{
	top--;
	printf("element has been popped \n");
}
}

void display()
{
if( top == -1)
	printf("Stack underflow");
else
{
int i;
for(i=0;i<=top;i++)
printf("%d \t",stack[i]);
}

}
int main()
{
    int choice;
    while(1)
    {
    printf("\nStack Operations");
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
    printf("\nEnter your Choice:");
    scanf("%d",&choice);

      switch(choice)
        {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: display();
                break;
            case 4: exit(1);
            default: printf("\nEnter a valid choice!!");
        }
    }
return 0;
}





