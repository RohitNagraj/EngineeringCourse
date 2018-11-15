/*
This is an implementation of the stack operations using linked lists. The nodes are of a
structure type which consist a data element and a pointer to the node next to it (or below 
it in terms of stack). 2 pointers are globally declared for simplicity.
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *front = NULL, *rear = NULL, *ptr = NULL;

void enqueue(int element) //Enqueues the element into the queue
{
    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->link = NULL; //The link contains data of who is behind this node, and since this node is the last one, its link is NULL
    ptr->data = element;

    if (front == NULL) // Empty queue
    {
        front = ptr;
        rear = ptr;
        return;
    }

    rear->link = ptr;
    rear = ptr;
}

int dequeue()
{
    int temp; //Required to return the dequeued value
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return 0;
    }

    ptr = front;
    front = front->link;
    temp = ptr->data;
    free(ptr);
    return temp;
}

void display()
{
    if (front == NULL)
    {
        printf("\nThe queue is empty\n");
        return;
    }

    printf("The queue is:\n");
    ptr = front;
    while (ptr != NULL)
    {
        printf("%d    \n", ptr->data);
        ptr = ptr->link;
    }
}

void displayMenu()
{
    printf("\n\n-------  MENU  -------\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
}
int main()
{
    int element;
    char menu;
    while (1)
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &menu);

        switch (menu)
        {
        case '1':
            printf("Enter the data: ");
            scanf("%d", &element);
            enqueue(element);
            break;

        case '2':
            element = dequeue();
            printf("The element dequeued is: %d\n", element);
            break;

        case '3':
            display();
            break;

        case '4':
            exit(0);
            break;

        default:
            printf("Wrong choice\n");
            break;
        }
    }
    return (0);
}