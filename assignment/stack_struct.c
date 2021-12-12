#include<stdio.h>

#define MAX 10
struct stack
{
	int arr[MAX] ;
	int top ;
} ;

int main( )
{
	struct stack s ;
	int i ;
	initstack ( &s ) ;

	push ( &s, 11 ) ;
	push ( &s, 23 ) ;
	push ( &s, -8 ) ;
	push ( &s, 16 ) ;
	push ( &s, 27 ) ;
	push ( &s, 14 ) ;
	push ( &s, 20 ) ;
	push ( &s, 39 ) ;
	push ( &s, 2 ) ;
	push ( &s, 15 ) ;	
	
	        i = pop ( &s ) ;
	printf ( "\n\nItem popped: %d", i );
	i = pop ( &s ) ;
	printf ( "\nItem popped: %d", i ) ;

	i = pop ( &s ) ;
	printf ( "\nItem popped: %d", i ) ;

	i = pop ( &s ) ;
	printf ( "\nItem popped: %d", i ) ;

	i = pop ( &s ) ;
	printf ( "\nItem popped: %d", i ) ;
}

/* intializes the stack */
void initstack ( struct stack *s )
{
	s -> top = -1 ;
}

/* adds an element to the stack */
int push (struct stack *s, int data)
{
	//int data;
	if ( s -> top == MAX - 1 )
	{
		printf ( "\n Stack is full\n" ) ;
		return ;
	}
	s -> top++ ;
	s -> arr[s ->top] = data;
}
/* removes an element from the stack */
int pop ( struct stack *s )
{
	int data ;
	if ( s -> top == -1 )
	{
		printf ( "\nStack is empty." ) ;
		return NULL ;
	}
	data = s -> arr[s -> top] ;
	s -> top-- ;
	return data ;
}
