/*This program implements a binary search tree with the inputs from the user, prints it out in 
all 3 tree traversing ways, ie preOrder, inOrder and postOrder traversals.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left, *right;
    int data;
} node;

node *tree = NULL; //Global pointer to hold the pointer of root node

node *createNode(int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void createLeaf(node *root) //Creates a binary tree with the root given as parameter
{
    int data;

    if (root == NULL) //Case for first node
    {
        printf("Enter the root element: ");
        scanf("%d", &data);
        root = createNode(data);
        tree = root; //Global tree pointer holds this root value as it is the first node
        return;
    }

    printf("Enter the element: ");
    scanf("%d", &data);

    while (1)
    {
        if (data >= root->data && root->right != NULL) //If there is an element is the right
        {
            root = root->right;
        }
        else if (data < root->data && root->left != NULL) //if there is an element in the left
        {
            root = root->left;
        }
        else //if there is no element after the root element in the desired direction
            break;
    }

    if (data >= root->data)
        root->right = createNode(data);
    else
        root->left = createNode(data);
}

void preOrderPrint(node *root)
{
    if (root != NULL)
    {
        printf("%d  ", root->data); //Root first, left element second and then right element
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }
}

void inOrderPrint(node *root)
{
    if (root != NULL)
    {
        inOrderPrint(root->left); //Left first, root second, right third.
        printf("%d  ", root->data);
        inOrderPrint(root->right);
    }
}
void postOrderPrint(node *root)
{
    if (root != NULL)
    {
        postOrderPrint(root->left); //Left first, right second, root third.
        postOrderPrint(root->right);
        printf("%d  ", root->data);
    }
}

node *deleteBranch(node *root, int data)
{
    if (root != NULL)
    {
        if (root->data == data)
        {
            free(root);
            return NULL;
        }
        root->left = deleteBranch(root->left, data);
        root->right = deleteBranch(root->right, data);
    }
}

int searchNode(node *root, int data)
{
    if (root == NULL)
        return 0;
    else
    {
        if (root->data == data)
            return 1;
        return (searchNode(root->left, data) || searchNode(root->right, data));
    }
}

int main()
{
    int menu, x;
    while (1)
    {
        printf("\n\n1. Insert\n");
        printf("2. Print\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &menu);

        switch (menu)
        {
        case 1:
            createLeaf(tree);
            break;
        case 2:
            printf("\nPre order: ");
            preOrderPrint(tree);
            printf("\nIn order: ");
            inOrderPrint(tree);
            printf("\nPost order: ");
            postOrderPrint(tree);
            printf("\n");
            break;

        case 3:
            printf("Enter the element to search: ");
            scanf("%d", &x);
            if (searchNode(tree, x))
                printf("Element is present\n");
            else
                printf("Element is not present\n");
            break;

        case 4:
            printf("Enter the root to delete: ");
            scanf("%d", &x);
            deleteBranch(tree, x);
            break;

        case 5:
            exit(0);

        default:
            printf("Wrong choice\n\n");
            break;
        }
    }

    return (0);
}
