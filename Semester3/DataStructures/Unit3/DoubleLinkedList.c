/*
This program implements double linked list using a structure as its node which contains the 
data, and pointers to both previous and next nodes. The pointers in this program have been 
declared globally for simplicity.
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
    printf("1. Insert at the BEGINNING of the list\n");
    printf("2. Insert at the END of the list\n");
    printf("3. Insert BEFORE an element in the list\n");
    printf("4. Insert AFTER an element in the list\n");
    printf("5. DELETE an element from the list\n");
    printf("6. Display the linked list\n");
    printf("0. Exit\n");
}

void createNode() //Creates a new node, fills the data in it, assigns NULL to both previous and next pointers and assigns that node to newNode.
{
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->previous = NULL;
    newNode->next = NULL;
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
}

void insertBegin() //To insert at the beginning of the list
{
    if (head == NULL)
    {
        createNode();
        head = newNode;
        tail = newNode;
        return;
    }

    createNode();
    newNode->next = head;     //Forward link from newNode to head
    head->previous = newNode; //Backward link from head to newNode
    head = newNode;
}

void insertEnd()
{
    if (head == NULL)
    {
        insertBegin();
        return;
    }

    createNode();
    tail->next = newNode;     //Forward link from tail to newNode
    newNode->previous = tail; //Backward link from newNode to tail
    tail = newNode;
}

void insertBefore()
{
    if (searchPtr == head)
    {
        insertBegin();
        return;
    }

    createNode();
    newNode->previous = searchPtr->previous;
    newNode->next = searchPtr;
    searchPtr->previous->next = newNode; //The order of this and the next line are super
    //important, if they are done in the reverse order, the logic is messed up since searchPtr->previous will be changed.
    searchPtr->previous = newNode;
}

void insertAfter()
{
    if (searchPtr == tail)
    {
        insertEnd();
        return;
    }

    createNode();
    newNode->previous = searchPtr;
    newNode->next = searchPtr->next;
    searchPtr->next->previous = newNode; //The order of this and the next line are super
    //important, if they are done in the reverse order, the logic is messed up.
    searchPtr->next = newNode;
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
        printf("\nHead: %x    Tail: %x\n", head, tail);
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