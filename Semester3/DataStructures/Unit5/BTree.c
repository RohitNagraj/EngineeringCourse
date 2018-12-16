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
#define SIZE 2

typedef struct node
{
    int data[2 * SIZE - 1];
    struct node *next[2 * SIZE];
} node;

node *root = NULL, *tree = NULL, *ptr = NULL, *newNode = NULL;

node *createNode()
{
    int i;
    newNode = (node *)malloc(sizeof(node));
    for (i = 0; i < 2 * SIZE - 1; i++)
    {
        newNode->data[i] = 0;
        newNode->next[i] = NULL;
    }
    newNode->next[2 * SIZE - 1] = NULL;
    return newNode;
}

void sort(node *root) // sorts only non zero elements
{
    int i, j, temp;
    for (i = 0; i < 2 * SIZE - 2; i++)
        for (j = 0; j < 2 * SIZE - 2; j++)
        {
            if (root->data[j] > root->data[j + 1] && root->data[j + 1] != 0)
            {
                temp = root->data[j];
                root->data[j] = root->data[j + 1];
                root->data[j + 1] = temp;
            }
        }
}

node *addInLeaf(node *root, int data)
{
    int i = 0, k, l;
    while (root->data[i] != 0) //Finds the last free space
        i++;
    root->data[i] = data;
    sort(root);

    if (i == 2 * SIZE - 2) // If its an overflow condition
    {
        if (root == tree)
        {
            tree = createNode();
            tree->data[0] = root->data[SIZE - 1];
            root->data[SIZE - 1] = 0;
            tree->next[0] = root;
            newNode = createNode();
            for (k = SIZE, l = 0; k < 2 * SIZE - 1; k++, l++)
            {
                newNode->data[l] = root->data[k];
                newNode->next[l] = root->next[k];
                root->data[k] = 0;
                root->next[k] = NULL;
            }
            newNode->next[l] = root->next[k];
            root->next[k] = NULL;
            tree->next[1] = newNode;

            sort(tree);
            sort(root);
            sort(newNode);
            return NULL;
        }
        else
            return root; // So the previous recurrsion frame can handle it
    }

    else
        return NULL; // Successful insertion when i < 2
}

node *childOverflow(node *root) // Handles child overflowing
{
    int i, k, l, data;
    data = ptr->data[SIZE - 1]; // Pulls the middle element
    ptr->data[SIZE - 1] = 0;    // Makes the middle element 0 after pulling

    k = 0;
    while (root->data[k] < data)
    {
        if (root->data[k] == 0)
            break;
        k++;
    }
    for (l = 2 * SIZE - 3; l >= k; l--)
    {
        root->data[l + 1] = root->data[l];
        root->next[l + 2] = root->next[l + 1];
    }

    root->data[k] = data;             // Insert data pulled in root
    root->next[k + 1] = createNode(); // Make the required shifts
    for (l = SIZE, i = 0; l < 2 * SIZE - 1; l++, i++)
    {
        root->next[k + 1]->data[i] = ptr->data[l];
        root->next[k + 1]->next[i] = ptr->next[l];
        ptr->data[l] = 0;
        ptr->next[l] = NULL;
    }

    root->next[k + 1]->next[i] = ptr->next[l];
    ptr->next[l] = NULL;

    sort(ptr);
    sort(root);

    if (root->data[2 * SIZE - 2] != 0)
        return root; // If tree node is returning ptr, it is handled in insertNode
    else
        return NULL;
}

node *insert(node *root, int data)
//Returns null when no element split is pending
{
    int k, flag = 0;
    if (root == NULL)
    {
        tree = createNode();
        tree->data[0] = data;
        sort(tree);
        return NULL;
    }

    ptr = NULL;

    for (k = 0; k < 2 * SIZE - 2 && flag == 0; k++) // Travels the tree to find the right branch
    {
        if (root->data[k] == data)
        {
            printf("Element already exists\n");
            return NULL;
        }
        if (data < root->data[k] && root->next[k] != NULL)
        {
            ptr = insert(root->next[k], data);
            flag = 1;
            break;
        }
        if (data > root->data[k] && root->next[k + 1] != NULL && root->data[k + 1] == 0)
        {
            ptr = insert(root->next[k + 1], data);
            flag = 1;
            break;
        } // Found the root node where its to be inserted
    }

    if (flag == 0) // for the leaf node
    {
        return addInLeaf(root, data);
    }

    else if (flag == 1 && ptr != NULL) // When child is overflowing
    {
        return childOverflow(root);
    }
    else if (flag == 1 && ptr == NULL) // Successful insertion by the recursive frame
    {
        return NULL;
    }
}

void insertNode(int data)
{
    int k, l;
    if (insert(tree, data) != NULL)
    {
        root = tree;
        tree = createNode();
        tree->data[0] = root->data[SIZE - 1];
        root->data[SIZE - 1] = 0;
        tree->next[0] = root;
        newNode = createNode();
        for (k = SIZE, l = 0; k < 2 * SIZE - 1; k++, l++)
        {
            newNode->data[l] = root->data[k];
            newNode->next[l] = root->next[k];
            root->data[k] = 0;
            root->next[k] = NULL;
        }
        newNode->next[l] = root->next[k];
        root->next[k] = NULL;
        tree->next[1] = newNode;

        sort(tree);
        sort(root);
        sort(newNode);
    }
}

void preOrderPrint(node *root)
{
    if (root != NULL)
    {
        int i;
        for (i = 0; i < 2 * SIZE - 2; i++)
            printf("%d ", root->data[i]);
        printf("| ");

        for (i = 0; i < 2 * SIZE - 1; i++)
            preOrderPrint(root->next[i]);
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
            preOrderPrint(tree);
            break;
        case 3:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
    return (0);
}