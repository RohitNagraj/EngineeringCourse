/*
 * @Author: Rohit Nagraj 
 * @Date: 2018-12-12 20:06:16 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2018-12-12 20:14:25
 */
/*
B-Tree
Key = 2
Max no. of elements = 2n-1 = 3
Min no. of elements = ceil(n/2) = 1
currently only insertion
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data[3];
    struct node *next[4];
} node;

node *root = NULL, *tree = NULL, *ptr = NULL, *newNode = NULL, *root2 = NULL;

node *createNode()
{
    int i;
    newNode = (node *)malloc(sizeof(node));
    for (i = 0; i < 3; i++)
    {
        newNode->data[i] = 0;
        newNode->next[i] = NULL;
    }
    newNode->next[3] = NULL;
    return newNode;
}

void sort(node *root) // sorts only non zero elements
{
    int i, j, temp;
    for (j = 0; j < 2; j++)
        for (i = 0; i < 2; i++)
        {
            if (root->data[i] > root->data[i + 1] && root->data[i + 1] != 0)
            {
                temp = root->data[i];
                root->data[i] = root->data[i + 1];
                root->data[i + 1] = temp;
            }
        }
}

node *insert(node *root, int data)
//Returns null when no element split is pending
{
    int i, j, flag = 0;
    if (root == NULL)
    {
        tree = createNode();
        tree->data[0] = data;
        sort(tree);
        return NULL;
    }

    ptr = NULL;
    if (data < root->data[0] && root->next[0] != NULL)
    {
        ptr = insert(root->next[0], data);
        flag = 1;
    }

    else if (data > root->data[0] && root->next[0] != NULL && root->data[1] == 0)
    {
        ptr = insert(root->next[1], data);
        flag = 1;
    }

    else if (data < root->data[1] && root->next[1] != NULL)
    {
        ptr = insert(root->next[1], data);
        flag = 1;
    }
    else if (data > root->data[1] && root->next[2] != NULL)
    {
        ptr = insert(root->next[2], data);
        flag = 1;
    } // Found the root node where its to be inserted

    if (flag == 0) // for the leaf node
    {
        i = 0;
        while (root->data[i] != 0) //Finds the last free space
            i++;
        root->data[i] = data;
        sort(root);

        if (i == 2) // If its an overflow condition
        {
            if (root == tree)
            {
                tree = createNode();
                tree->data[0] = root->data[1];
                root->data[1] = 0;
                tree->next[0] = root;
                newNode = createNode();
                newNode->data[0] = root->data[2];
                newNode->next[0] = root->next[2];
                newNode->next[1] = root->next[3];
                root->data[2] = 0;
                root->next[2] = NULL;
                root->next[3] = NULL;
                tree->next[1] = newNode;
                sort(tree);
                sort(root);
                sort(newNode);
                return NULL;
            }
            else
            {
                return root; // So the previous recurrsion frame can handle it
            }
        }

        else
        {
            return NULL; // Successful insertion when i < 2
        }
    }

    else if (flag == 1 && ptr == NULL) // Successful insertion by the recursive frame
    {
        return NULL;
    }

    else if (flag == 1 && ptr != NULL) // When child is overflowing
    {
        i = 0;
        while (root->next[i] != NULL) // Find the last element
            i++;
        j = i;
        data = ptr->data[1];      // Pulls the middle element
        ptr->data[1] = 0;         // Makes the middle element 0 after pulling
        if (root->data[0] > data) // To shift to maintain sorting
        {
            root->data[2] = root->data[1];
            root->next[3] = root->next[2];
            root->data[1] = root->data[0];
            root->next[2] = root->next[1];
            i = 1;
        }
        else if (root->data[1] > data)
        {
            root->data[2] = root->data[1];
            root->next[3] = root->next[2];
            i = 2;
        }
        root->data[i - 1] = data;     // Insert data pulled in root
        root->next[i] = createNode(); // Make the required shifts
        root->next[i]->data[0] = ptr->data[2];
        ptr->data[2] = 0;
        sort(ptr);
        sort(root);

        if (j == 3)
            return ptr; // If tree node is returning ptr, it is handled in insertNode
        else
            return NULL;
    }
}

void inOrderPrint(node *root)
{
    if (root != NULL)
    {
        printf("%d %d ,", root->data[0], root->data[1]);
        inOrderPrint(root->next[0]);
        inOrderPrint(root->next[1]);
        inOrderPrint(root->next[2]);
    }
}

void insertNode(int data)
{
    if (insert(tree, data) != NULL)
    {
        root = tree;
        tree = createNode();
        tree->data[0] = root->data[1];
        root->data[1] = 0;
        tree->next[0] = root;
        newNode = createNode();
        newNode->data[0] = root->data[2];
        newNode->next[0] = root->next[2];
        newNode->next[1] = root->next[3];
        root->data[2] = 0;
        root->next[2] = NULL;
        root->next[3] = NULL;
        tree->next[1] = newNode;
        sort(tree);
        sort(root);
        sort(newNode);
    }
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n\n\n1. Enter new number\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number: ");
            scanf("%d", &data);
            insertNode(data);
            break;
        case 2:
            inOrderPrint(tree);
            break;
        case 3:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
    return (0);
}