#include<stdlib.h>
#include<stdio.h>

#define size 10
int Q[size], rear=-1;

void enqueue( int x)
{
	int i;
	if(rear == -1)
	{
		Q[++rear]=x;
	}
	
	else if(rear==size-1)
	{
		printf("Queue is full\n");
	}
	
	else
	{
		for(i=rear;i>=0;i--)
		{
			if(Q[i]<x)
			{
				Q[i+1] = Q[i];
			}
			else
				break;
		}
		Q[i+1]=x;
		rear++;
	}
	printf("%d",rear);
	
}

int dequeue()
{
	if(rear==-1)
	{
		printf("Queue is empty\n");
		return 0;
	}
	else
		return (Q[rear--]);
		
}

void display()
{
	int i;
	if(rear==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		for(i=rear;i>=0;i--)
		{
			printf("%d  ",Q[i]);
		}
		printf("\n");
		
	}
}

int main()
{
	char choice;
	int x;
	
	while(1)
	{
	
		fflush(stdin);
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf(" %c",&choice);
	
		
	
		switch(choice)
		{
			case '1':
				printf("Enter the element to enqueue: ");
				fflush(stdin);
				scanf("%d",&x);
			 
				enqueue(x);
				break;
			case '2':
				dequeue();
				break;
			case '3':
				display();
				break;
			case '4':
				exit(0);
			default:
				printf("Wrong choice\n");
		}
	}
}
