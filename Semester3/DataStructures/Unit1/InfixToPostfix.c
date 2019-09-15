//Program to convert an infix expression to postfix
#include<stdio.h>
#include<ctype.h>
#define SIZE 40

int stack[SIZE],top=-1;
char infix[SIZE],postfix[SIZE];

void push(char element)
{
	//Input: char
	//Pushes the input character into the stack
	if(top==SIZE-1)
		printf("Error: Stack overflow");
	else
	{
		stack[++top] = element;
	}
}

char pop()
{
	//Removes the top element of the stack and returns the same
	if(top==-1)
	{
		printf("Error: Stack underflow");
		return('0');
	}
	else
	{
		return(stack[top--]);
	}
}

char peak()
{
	//Returns the top element of the stack
	if(top==-1)
		return('0');
	else
		return stack[top];

}

int priority(char x)
{
	//Sets the mathematical priority of math operations
	switch(x)
	{
		case '(':
			return 1;
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 3;
		default:
			return -1;
	}
}

void intopostfix()
{
	//Converts a valid single character element infix expression to a postfix expression
	int i,j=-1;
	for(i=0;infix[i]!='\0';i++)
	{
		if(infix[i]=='(')
			push(infix[i]);

		else if(isalnum(infix[i]))
			postfix[++j] = infix[i];

		else if(infix[i]==')')
		{
			while(peak()!='(')
			{
				postfix[++j]=pop();
			}
			pop();
		}
		else
		{
			while(priority(peak())>=priority(infix[i]))
			{
				postfix[++j] = pop();
			}
			push(infix[i]);
		}
	}
	while(top!=-1)
	{
		postfix[++j] = pop();
	}
}

int isValidInfix()
{
	//Checks if the entered infix expression is valid
	//Returns 1 if valid, 0 otherwise
	int i,noOfOpenBrackets=0,noOfClosingBrackets=0,noOfDigits=0,noOfOperations=0,isValidInfix=1;
	for(i=0;infix[i]!='\0';i++)
	{
		if(isalnum(infix[i]))
		{
			noOfDigits++;
		}
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/')
			noOfOperations++;
		else if(infix[i]=='(')
		{
			noOfOpenBrackets++;
		}
		else if(infix[i]==')')
		{
				noOfClosingBrackets++;
		}
		else
			return(--isValidInfix);
	}
	if((noOfOpenBrackets!=noOfClosingBrackets)||(noOfDigits-noOfOperations!=1))
		return(--isValidInfix);
	return(isValidInfix);
}

int main()
{
	while(1)
	{
		printf("Enter the infix expression : ");
		scanf("%s",infix);
		if(isValidInfix())
			break;
		else
			printf("Invalid expression\n\n");
	}

	intopostfix();
	printf("Initial infix expression : %s\n",infix);
	printf("Final postfix expression : %s",postfix);
	return 0;
}
