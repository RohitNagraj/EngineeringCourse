/*
This algorithm stores the linked list in a sorted manner and doesn't sort it when it needs
to be displayed. When the insertion happens, it checks and inserts it in the right place.
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head = NULL, *searchPtr = NULL, *ptr = NULL, *newNode = NULL, *ptrBefore = NULL;

void displayMenu()
{
    printf("\n\n ----------------  MENU  ----------------\n");
    printf("1. Insert\n");
    printf("2. DELETE\n");
    printf("3. Display\n");
    printf("0. Exit\n");
}

struct node *createNode() //Creates a node with NULL as the link
{
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->link = NULL;
    //Creates a new node and assigns it to the variable newNode which is a global variable
    //and the other functions directly access the global variable, hence the function
    //doesn't return the new node created.
}

struct node *searchNode(int element) // Returns the pointer to the node which contains the
                                     // data that was searched for. Else returns NULL
{
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == element)
            return ptr;

        ptr = ptr->link;
    }
    return ptr;
}

void insert(int element) // Takes the element to be inserted as argument
{
    ptr = head;
    ptrBefore = head;

    if (head == NULL)
    {
        newNode = createNode();
        newNode->data = element;
        head = newNode;
        return;
    }

    while (ptr != NULL) // Loop finds the node before which a new node has to be created
    {
        if (ptr->data > element)
            break;
        ptr = ptr->link;
    }

    if (ptr == head) // Case when the element is smaller than the first element
    // This is similar to insertBegin()
    {
        newNode = createNode();
        newNode->data = element;
        newNode->link = head;
        head = newNode;
        return;
    }

    while (ptrBefore->link != ptr) // Loop to find the node before ptr so a newNode can be inserted between both of them
        ptrBefore = ptrBefore->link;

    newNode = createNode(); // Regular linking
    newNode->data = element;
    ptrBefore->link = newNode;
    newNode->link = ptr;
}

void deleteNode() //To delete a node at any location
{
    if (searchPtr == head) // Case when the head is to be deleted
    {
        ptr = head;
        head = head->link;
        free(ptr);

        printf("Deleted successfully\n");
        return;
    }

    ptr = head;
    while (ptr->link != searchPtr) //To search for the previous node, that lies before the node to be deleted.
        ptr = ptr->link;
    ptr->link = searchPtr->link;
    free(searchPtr);
    printf("Deleted successfully\n");
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d    ", ptr->data);
            ptr = ptr->link;
        }
    }
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