/*
This algorithm stores the linked list in a sorted manner and doesn't sort it when it needs
to be displayed. When the insertion happens, it checks and inserts it in the right place.
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *previous;
    int data;
    struct node *next;
} *head = NULL, *tail = NULL, *newNode = NULL, *searchPtr = NULL, *ptr = NULL;

void displayMenu()
{
    printf("\n\n ----------------  MENU  ----------------\n");
    printf("1. Insert\n");
    printf("2. DELETE\n");
    printf("3. Display\n");
    printf("0. Exit\n");
}

void createNode() //Creates a new node, fills the data in it, assigns NULL to both previous and next pointers and assigns that node to newNode.
{
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->previous = NULL;
    newNode->next = NULL;
}

void insert(int element) // Takes the element to be inserted as argument
{
    struct node *ptrBefore;

    ptr = head;
    if (head == NULL) // Case when list is empty
    {
        createNode();
        newNode->data = element;
        head = newNode;
        tail = newNode;
        return;
    }

    while (ptr != NULL) // Loop to find the node before which the new element must be inserted
    {
        if (ptr->data > element)
            break;
        ptr = ptr->next;
    }

    if (ptr == head) // Similar to insertBegin()
    {
        createNode();
        newNode->data = element;
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
        return;
    }

    else if (ptr == NULL) // Similar to insertEnd()
    {
        createNode();
        newNode->data = element;
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        return;
    }

    else // Similar to insertBefore()
    {
        ptrBefore = ptr->previous;
        createNode();
        newNode->data = element;

        newNode->previous = ptrBefore;
        newNode->next = ptr;
        ptr->previous = newNode;
        ptrBefore->next = newNode;
    }
}

struct node *searchNode(int element) //Searches for an element and returns its pointer if found
{
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == element)
            return ptr;
        ptr = ptr->next;
    }
    return ptr;
}

void display()
{
    if (head == NULL)
        printf("The list is empty\n");
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            printf("Previous: %x    Data: %d    Next: %x\n", ptr->previous, ptr->data, ptr->next);
            ptr = ptr->next;
        }
    }
}

void deleteNode()
{
    if (searchPtr == head)
    {
        head = head->next;
        head->previous = NULL;
    }
    else if (searchPtr == tail)
    {
        tail = tail->previous;
        tail->next = NULL;
    }
    else
    {
        searchPtr->previous->next = searchPtr->next;     //The previous's next is linked with current next
        searchPtr->next->previous = searchPtr->previous; //The next's previous is linked with current previous
    }

    free(searchPtr);
}

int main()
{
    char menu;
    int element;
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
            insert(element);
            break;

        case '2':
            printf("Enter the element you want to delete: ");
            scanf("%d", &element);
            searchPtr = searchNode(element);

            if (searchPtr == NULL)
                printf("The element doesn't exist in the list\n");

            else
                deleteNode();
            break;

        case '3':
            display();
            break;
        case '0':
            exit(0);
            break;
        default:
            printf("Wrong choice\n\n\n");
            break;
        }
    }
    return 0;
}