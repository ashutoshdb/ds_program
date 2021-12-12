#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *next;
};

struct Node *top;

int main(int argc, char *argv[])
{
     int i=0,value;
     top=NULL;
     printf(" \n1. Push to stack");
     printf(" \n2. Pop from Stack");
     printf(" \n3. Display data of Stack");
     printf(" \n4. Exit\n");
     while(1)
     {
          printf(" \nChoose Option: ");
          scanf("%d",&i);
          switch(i)
          {
               case 1:        printf("\nEnter a value to push into Stack: ");
                              scanf("%d",&value);
                              push(value);
                              display();
                              break;

               case 2:        popStack();
                              display();
                              break;

               case 3:        display();
                              break;

               case 4:        exit(0);
               default:  printf("\nwrong choice for operation");
          }
       }
    }

int push(int value)
{
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->Data=value;
    if (top == NULL)
    {
         top=temp;
         top->next=NULL;
    }
    else
    {
        temp->next=top;
        top=temp;
    }
}

int popStack()
{
    struct Node *var; 
    var=top;
    if(var==top)
    {
        top = top->next;
        free(var);
    }
    else
    printf("\nStack Empty");
}

int display()
{
     struct Node *var=top;
     if(var!=NULL)
     {
          printf("\nElements are as:\n");
          while(var!=NULL)
          {
               printf("\t%d\n",var->Data);
               var=var->next;
          }
     printf("\n");
     }
     else
     printf("\nStack is Empty");
}
