/*
This is a menu driven program to maintain a simple linked list which allows all operations
including adding at any position in the list and deleting from any position in the list. 
The program uses 3 seperate functions to create new nodes at different positions, and uses
only one function to delete nodes at any position.
*/
#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* link;
} node;

node *head = NULL, *temp = NULL;

char menu() //To display the main menu
{
	char choice;
	printf("----------------------------   MENU   ----------------------------\n");
	printf("1. Add Data\n");
	printf("2. Delete Data\n");
	printf("3. Display Data\n");
	printf("4. Exit\n");
	printf("Choice: ");
	fflush(stdin);
	choice = getchar();
	return choice;
}

void newHead() //Creates a new node at the beginning
{
	node* temp = (node*) malloc(sizeof(node));
	printf("Enter the data: ");
	scanf("%d",&temp->data);
	temp->link = head;
	head = temp;
}

void newMid(int pos) //Creates a new node in-between the list
{
	node* temp = (node*) malloc(sizeof(node));
	node* next = head; //Denotes the node next to the new node created
	node* previous = head; //Denotes the node previous to the new node created
	int i=1;

	if(head == NULL && pos>1) //If list is empty and user wants to enter somewhere other than beginning
	{
		printf("Index out of range\n");
		return;
	}
	else if(head==NULL) //If list is empty and pos = 1
	{
		printf("Enter the data: ");
		scanf("%d",&temp->data);
		temp->link = NULL;
		head =temp;
		return;
	}
	else
	{
		while(i<pos-1) //Finding the node after which the user want to data
		{
			if (previous == NULL)
			{
				printf("Index out of range\n");
				return;
			}
			else
				previous = previous->link;
			i++;
		}
	}
	

	printf("Enter the data: ");
	scanf("%d",&temp->data);

	next = previous->link;
	previous->link = temp; //Breaking the list and adding the new node
	temp->link = next;
}

void newTail() //Creates a new node at the end
{
	node* temp = (node*) malloc(sizeof(node));
	node* last = head;
	printf("Enter the data: ");
	scanf("%d",&temp->data);
	temp->link = NULL;

	if(head == NULL)
		head = temp;

	else
	{
		while(last->link!=NULL) //To find the last node
			last=last->link;
		last->link = temp;
	}
}

void removeNode(int pos) //To remove a node from any given position
{
	node* previous = head;
	node* temp;
	int i=1;

	if (head == NULL)
	{
		printf("List is empty\n\n\n");
		return;
	}

	else if (head->link == NULL) //Only 1 node
	{
		if(pos>1)
		{
			printf("Index out of range\n");
			return;
		}
		free(previous);
		head = NULL;
	}
	else if(pos == 1) //Removing the first node
	{
		temp = head;
		head = head->link;
		free(temp);
	}
	else
	{
		while(i<pos-1) //Finding node to remove
		{
			if (previous == NULL)
			{
				printf("Index out of range\n");
				return;
			}
			previous=previous->link;
			i++;
		}
		temp = previous->link;
		previous->link = temp->link;
		free(temp);
	}
}

void addData() //To add a node
{
	char choice;
	int pos;
	do
	{
		printf("\n\nChoose the position of data\n");
		printf("1. Beginning\n");
		printf("2. Somewhere in-between\n");
		printf("3. End\n");
		printf("Choice: ");
		fflush(stdin);
		choice = getchar();

		if(choice<'1' || choice>'3')
		{
			printf("Wrong Choice\n");
		}
	}
	while(choice<'1' || choice>'3');
	
	switch (choice)
	{
		case '1':
			newHead();
			break;

		case '2':
			printf("Enter the specific position: ");
			fflush(stdin);
			scanf("%d",&pos);
			if(pos<1)
			{
				printf("Incorrect index\n");
				return;
			}
			newMid(pos);
			break;

		case '3':
			newTail();
			break;
	}
}

void deleteData() //To delete a node
{
	int pos;
	
	printf("Enter the position: ");
	fflush(stdin);
	scanf("%d",&pos);
	if(pos<1)
	{
		printf("Incorrect index\n");
		return;
	}
	removeNode(pos);
}

void displayData() //To display all data
{
	node* temp = head;
	int i=1;
	printf("\n\n");
	if (temp == NULL)
		printf("List is empty\n");
	else
	{
		while(temp != NULL)
		{
			printf("%d. Data: %d Link: %p\n", i++, temp->data, (void*) temp->link);
			temp = temp->link;
		}
	}
	
	printf("\n\n\n");
}

int main()
{
	char choice;
	
	while (1)
	{
		choice = menu();

		switch (choice)
		{
			case '1':
				addData();
				displayData();
				break;
			case '2':
				deleteData();
				displayData();
				break;
			case '3':
				displayData();
				break;
			case '4':
				exit(0);
			default:
				printf("Wrong choice\n\n\n");
		}
	}
	return 0;
}