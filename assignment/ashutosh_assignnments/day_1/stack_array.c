#include<stdio.h>
#include <stdlib.h>
#define MAX 5
int push();
int pop();
int display();

int stack[MAX],top=-1;
int main() 	
{
int choice,n;
while(1)
{

printf("Enter 1 for push an element \n"
	"Enter 2 for pop the element \n"
	"enter e for exit \n");
printf("Enter the value");
scanf("%d",&n);
switch(n)
{
	case 1:
		push();
		break;
	case 2:
		pop();
		break;
	case 3:
		display();
		break;
	case 4 :
		exit(0);
}
}

return 0;
}


int push()
{
	if(top == MAX)
		printf("overflow");
	else
	{
	int ele;
	printf("Enter the element");
	scanf("%d",&ele);
	top++;
	printf("element %d is pushed %d \n",ele,top);
	stack[top] = ele;
	
	}
}

int pop()
{
if(top==-1)
	printf("Underflow");
else
{
top--;
printf("popped");
}
}


int display()
{
if(top==-1)
	printf("empty stack");
else
{
int i;
for(i=0;i<=top;i++){
printf("%d\t",stack[i]);

}


}

}
