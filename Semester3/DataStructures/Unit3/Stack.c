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
} *top = NULL, *ptr = NULL;

void push(int element) //Pushes the element into the stack
{
    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->link = top; //Points the new ptr node's link to top which will lie below this new node
    ptr->data = element;
    top = ptr;
    printf("Pushed Successfully\n");
}

int pop()
{
    if (top == NULL)
    {
        printf("The stack is empty\n");
        return 0;
    }
    int tempData = top->data; //Needed to return the value of the deleted item.
    ptr = top;
    top = top->link;
    free(ptr);
    return tempData;
}

void display()
{
    if (top == NULL)
    {
        printf("\nThe stack is empty\n");
        return;
    }

    printf("The stack is:\n");
    ptr = top;
    while (ptr != NULL)
    {
        printf("%d    \n", ptr->data);
        ptr = ptr->link;
    }
}

void displayMenu()
{
    printf("\n\n-------  MENU  -------\n");
    printf("1. Push\n");
    printf("2. Pop\n");
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
            push(element);
            break;

        case '2':
            element = pop();
            printf("The element popped is: %d\n", element);
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