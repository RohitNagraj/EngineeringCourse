//Program to carry out stack operations using an integer array as a stack
#include<stdio.h>
#define SIZE 20
int stack[SIZE],top=-1;

int isEmpty()
{
  return (top==-1);
}

int isFull()
{
  return (top==SIZE-1);
}

void push(int n)
{
  if(isFull())
    printf("Stack overflow\n");

  else
  {
    stack[++top]=n;
    printf("Element pushed successfully");
  }
}

void pop()
{
  if(isEmpty())
    printf("Stack is empty\n" );
  else
  {
    printf("The element popped is: %d", stack[top--] );
  }

}

void peak()
{
  if(isEmpty())
    printf("Stack is empty\n");
  else
  {
    printf("The top element is: %d",stack[top]);
  }
}

void display()
{
  int i;
  if(isEmpty())
    printf("The stack is empty");

  else
  {
    printf("The complete stack is:");
    for(i=top;i>-1;i--)
      printf("%d ",stack[i]);
  }
}
int main()
{
  char menu;
  int x;

  while(1)
  {
    fflush(stdin);
    printf("\n\n----------------------------------------------------------------------------------------------\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peak\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    menu=getchar();

    switch (menu) {
      case '1':
        printf("Enter the element to be pushed: ");
        scanf(" %d",&x);
        push(x);
        break;
      case '2':
        pop();
        break;
      case '3':
        peak();
        break;
      case '4':
        display();
        break;
      case '5':
        exit(0);
      default:
        printf("Invalid choice");
    }
  }
}
