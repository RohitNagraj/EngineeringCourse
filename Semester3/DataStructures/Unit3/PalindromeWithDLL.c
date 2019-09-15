/*
Question: check if a string is palindrome using DLL

Logic:  Take in a string, puch each character to a new node
        Use 2 pointers to traverse the DLL, one from head and other from tail
        If at any point the data in the 2 pointers is not equal, return false
        If the pointer reaches null, that means all the characters matched, return true
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *previous;
    char s;
    struct node *next;
} node;

node *head = NULL, *tail = NULL, *ptr1 = NULL, *ptr2 = NULL;

node *createNode(char s)
{
    ptr1 = (node *)malloc(sizeof(node));
    ptr1->s = s;
    ptr1->previous = NULL;
    ptr1->next = NULL;
    return ptr1;
}

void add(char s) //Adds char s to a new node
{
    ptr1 = createNode(s);
    if (head == NULL) //Initial condition
    {
        head = ptr1;
        tail = ptr1;
        return;
    }

    tail->next = ptr1; //Adding a new node at the end
    ptr1->previous = tail;
    tail = ptr1;
}

int checkPalindrome()
{
    ptr1 = head;
    ptr2 = tail;
    while (ptr1 != NULL)
    {
        if (ptr1->s != ptr2->s) //If any char doesn't match, return false
            return 0;
        ptr1 = ptr1->next;
        ptr2 = ptr2->previous;
    }
    return 1;
}

int main()
{
    char s[20];
    int i;

    printf("Enter a string: \n");
    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++)
        add(s[i]);

    if (checkPalindrome())
        printf("It is a palindrome\n");
    else
        printf("Not a palindrome\n");

    return (0);
}