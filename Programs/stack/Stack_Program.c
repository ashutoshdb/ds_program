#include<stdio.h>
#include<stdlib.h>
#define max 5

int stack[max], top=-1;

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
}

int push()
{
    if(top==max)
        printf("\nOverflow");
    else
    {
        int element;
        printf("\nEnter Element:");
        scanf("%d",&element);
 	top++;
        printf("\nElement(%d) has been pushed at %d \n", element, top);
        stack[top]=element;
    }
}

int pop()
{
    if(top==-1)
        printf("\nUnderflow");
    else
    {   
        top--;
        printf("\nElement has been popped out!\n");
    }
}

int display()
{
    if(top==-1)
        printf("\nStack is Empty!!");
    else
    {
        int i;
        for(i=0;i<=top;i++)
            printf("%d \t",stack[i]);
    }
}
