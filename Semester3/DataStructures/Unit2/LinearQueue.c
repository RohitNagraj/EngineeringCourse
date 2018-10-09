/*
This linear queue program uses array as a queue. The basic idea of a queue is whichever element
goes in the queue first comes out of the queue first, and this logic is also referred to as FIFO which
stands for First In First Out.
*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10 //Change the queue size here

void enqueue(int Q[], int* front, int* rear, int x)
{
  //Takes 4 arguments, an integer array, front, rear and the element to enqueue.
  //Array is passed by reference by default and hence any changes made in the array in this function will also
  //be reflected everywhere else.
  // front and rear are also passed by reference so that any changes made here are reflected in the main and other functions as well.



  if(*rear == SIZE-1)
  {
    printf("Queue is full\n\n\n");
  }

  else if(*front == -1) //Case of first element
  {
    *front=0;
    *rear=0;
    Q[*rear] = x;
    printf("Enqueued successfully\n\n\n");
  }

  else
  {
    Q[++(*rear)] = x;
    printf("Enqueued successfully\n\n\n");
  }
}

int dequeue(int Q[], int* front, int* rear)
{
  int temp;
  /*
  Takes 3 arguments, the queue itself and its front and rear values all passed as reference so that any
  changes made here are reflected everywhere else as well.
  */
  if(*front==-1)
  {
    printf("Queue is empty\n");
    return 0;
  }

  else if(*front==*rear)
  {
    temp=*front;
    *front=-1;
    *rear=-1;
    return(Q[temp]);
  }

  else
  {
    return(Q[(*front)++]);
  }
}

void display(int Q[], int* front, int* rear)
{
  int i;
  if(*front==-1)
    printf("Queue is empty\n\n\n");

  else
  {
    printf("Queue: ");
    for(i=*front; i<=*rear; i++)
    {
        printf("%d  ", Q[i] );
    }
    printf("\n\n\n");
  }
}

int main()
{
  char choice;
  int x,Q[SIZE],front=-1,rear=-1;
  while (1)
  {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter Your choice: ");
    choice = getchar();

    fflush(stdin); //To clear the enter key registered by the OS which is then given to scanf as the input
    //Remove it and see what happens, you might understand the above statement.

    switch (choice)
    {
      case '1':
        printf("Enter the element to enqueue: ");
        scanf("%d", &x);
        fflush(stdin);
        enqueue(Q,&front,&rear,x); //Passing addresses of front and rear
        break;

      case '2':
        printf("The element dequeued is: %d\n\n\n", dequeue(Q, &front, &rear));
        break;

      case '3':
        display(Q, &front, &rear);
        break;

      case '4':
        exit(0);

      default:
        printf("Wrong choice\n\n\n");
      }
  }
  return 0;
}
