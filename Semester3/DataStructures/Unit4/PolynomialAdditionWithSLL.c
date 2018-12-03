/*
Question: Add two polynomials using a single linked list

Logic: Every node has three integers for the coefficients, and when the user chooses to add
a new expression, a new node is created, all the 3 coefficients are stored and it is linked
in the SLL.
When the user what to see the sum, the SLL is traversed and all the coefficient values are
added up and displayed
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int a, b, c;
    struct node *next;
} node;

node *head, *newNode, *ptr;

node *createNode()
{
    newNode = (node *)malloc(sizeof(node));
    newNode->next = NULL;
    return newNode;
}

void insert()
{
    newNode = createNode();
    printf("Enter polynomial of the form ax^2 + bx + c = 0\n");
    printf("Enter coefficient of x^2: ");
    scanf("%d", &newNode->a);
    printf("Enter coefficient of x: ");
    scanf("%d", &newNode->b);
    printf("Enter coefficient of 1: ");
    scanf("%d", &newNode->c);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newNode;
}

void sum()
{
    int a = 0, b = 0, c = 0;
    if (head == NULL)
    {
        printf("No polynomial expression added\n");
        return;
    }

    ptr = head;
    while (ptr != NULL)
    {
        a += ptr->a;
        b += ptr->b;
        c += ptr->c;
        ptr = ptr->next;
    }
    printf("The expression is: %dx^2 + %dx + %d = 0\n", a, b, c);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n\n1. Add new expression\n");
        printf("2. Display the sum\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            sum();
            break;
        case 3:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
    return (0);
}