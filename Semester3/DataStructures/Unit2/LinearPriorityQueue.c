/*
This priority queue program uses array as the queue and uses the variable front as a tracker of the
front end of the queue. The elements will be removed from the front end and will be inserted based
on the value of the element. The order of the priority can be easily changed by changing just one
parameter in line no. 33. > symbol will make it a descending order priority queue and < symbol will
make it an ascending order priority queue.
*/

#include<stdlib.h>
#include<stdio.h>
#define SIZE 10

int Q[SIZE], rear=-1;

void enqueue( int x)
{
	int i;
	if(rear == -1) //Case when queue is empty
	{
		Q[++rear]=x;
		printf("Enqueued successfully\n\n\n");
	}

	else if(rear==SIZE-1) //Case when queue is full
	{
		printf("Queue is full\n\n\n");
	}

	else
	{
		for(i=rear;i>=0;i--)
		{
			if(Q[i]<x)  //Change the operator here to make it ascending or descending.
			{
				Q[i+1] = Q[i]; //Moves all the elements which have a lower value one step back
			}
			else
				break; //breaks when an element with higher value is encountered
		}

		Q[i+1]=x; //inserts the element for which an empty space was created by the above loop
		rear++; //Since all the elements with lower value moved one step back

		printf("Enqueued successfully\n\n\n");
	}
}

void dequeue()
{
	if(rear==-1)
		printf("Queue is empty\n\n\n");
	else
		printf("The element dequeued is: %d\n\n\n",Q[rear--]);
		/*
		Decrement is used as the deletion here happens from the rear end and the rear end has the element
		with the lowest value due to the operator chosen in line no. 33.
		*/
}

void display()
{
	int i;
	if(rear==-1)
		printf("Queue is empty\n\n\n");
	else
	{
		printf("The queue is: ");
		for(i=rear;i>=0;i--) //Because the first element to exit will be the element at the rear and hence,
		//we display it from rear to front.
		{
			printf("%d  ",Q[i]);
		}
		printf("\n\n\n");
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
				printf("Wrong choice\n\n\n");
		}
	}
}
