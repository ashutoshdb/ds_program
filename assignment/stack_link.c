#include<stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
struct node *next;
} node;
node *top;


void push(int num)
{
node *temp;
temp = (node *)malloc(sizeof(node));
temp->data = num;
if(top == NULL)
{
top = temp;
temp->next = NULL;
}
else
{
temp->next = top;
top = temp;
}
}


void pull()
{
node *temp;
temp = head;
if(top == NULL)
	printf("Stack is already empty!!");
else
{

head = temp->next;
free(temp);
}
}
