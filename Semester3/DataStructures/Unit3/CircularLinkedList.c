/*
This program is an implementation of circular linked list. The insertBefore and insertAfter
functions remain same and there are mild changes in the rest of the functions. All variables
are made global for simplicity of the code.
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head = NULL, *searchPtr = NULL, *ptr = NULL, *newNode = NULL;

void displayMenu()
{
    printf("\n\n ----------------  MENU  ----------------\n");
    printf("1. Insert at the BEGINNING of the list\n");
    printf("2. Insert at the END of the list\n");
    printf("3. Insert BEFORE an element in the list\n");
    printf("4. Insert AFTER an element in the list\n");
    printf("5. DELETE an element from the list\n");
    printf("6. Display the linked list\n");
    printf("0. Exit\n");
}

struct node *createNode() //Creates a node with NULL as the link
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->link = NULL;
    //Creates a new node and assigns it to the variable newNode which is a global variable
    //and the other functions directly access the global variable, hence the function
    //doesn't return the new node created.
}

void insertBegin() //To insert an element at the beginning of the linked list
{
    createNode();

    if (head == NULL)
    {
        head = newNode;
        head->link = head; //Linked to itself if its the only node
        printf("Inserted successfully\n");
        return;
    }

    ptr = head;
    while (ptr->link != head) // Loop to find the last node
        ptr = ptr->link;

    newNode->link = head;
    head = newNode;
    ptr->link = head; // The last node's link is updated to the new head
    printf("Inserted successfully\n");
}

void insertEnd() // To insert at the end of linked list
{
    if (head == NULL) // Case when the list is empty
    {
        insertBegin();
        return;
    }

    createNode();

    ptr = head;
    while (ptr->link != head) // Loop to find the last node
        ptr = ptr->link;

    ptr->link = newNode;
    newNode->link = head; //Circular linking
    printf("Inserted successfully\n");
}

struct node *searchNode(int element) // Returns the pointer to the node which contains the
                                     // data that was searched for. Else returns NULL
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->data == element)
        return head;

    ptr = head->link;
    while (ptr != head)
    {
        if (ptr->data == element)
            return ptr;

        ptr = ptr->link;
    }
    return NULL;
}

void insertBefore() // To insert a node before an existing node
{
    ptr = head;

    if (searchPtr == head) //Case when the user wants to insert before the first node itself
    {
        insertBegin();
        return;
    }

    while (ptr->link != searchPtr) //Loop to search for the node which stands before the node before which the data has to be entered
        ptr = ptr->link;

    createNode();
    ptr->link = newNode;
    newNode->link = searchPtr;
    printf("Inserted successfully\n");
}

void insertAfter() //To insert a node after an existing node
{
    ptr = head;

    createNode();
    newNode->link = searchPtr->link;
    searchPtr->link = newNode;

    printf("Inserted successfully\n");
}

void deleteNode() //To delete a node at any location
{
    struct node *temp;
    if (searchPtr == head) // Case when the head is to be deleted
    {
        ptr = head;
        temp = head;

        while (ptr->link != head) // Loop to find the last node
            ptr = ptr->link;

        //Now ptr holds the last node
        head = head->link;
        ptr->link = head;

        free(temp);

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
        ptr = head->link;
        printf("Head's link: %x\n", head);
        printf("Data: %d    Link: %x\n", head->data, head->link);
        while (ptr != head)
        {
            printf("Data: %d    Link: %x\n", ptr->data, ptr->link);
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
            insertBegin();
            break;

        case '2':
            insertEnd();
            break;

        case '3':
            printf("Enter the element you want to insert before: ");
            scanf("%d", &element);
            searchPtr = searchNode(element);

            if (searchPtr == NULL)
                printf("The element doesn't exist in the list\n");

            else
                insertBefore();

            break;

        case '4':
            printf("Enter the element you want to insert after: ");
            scanf("%d", &element);
            searchPtr = searchNode(element);

            if (searchPtr == NULL)
                printf("The element doesn't exist in the list\n");

            else
                insertAfter();

            break;

        case '5':
            printf("Enter the element you want to delete: ");
            scanf("%d", &element);
            searchPtr = searchNode(element);

            if (searchPtr == NULL)
                printf("The element doesn't exist in the list\n");

            else
                deleteNode();
            break;

        case '6':
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