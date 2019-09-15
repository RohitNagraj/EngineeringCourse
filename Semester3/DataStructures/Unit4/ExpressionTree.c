/*
This program implements an expression tree using a stack
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    struct node *left, *right;
    char data;
} node;

node *tree = NULL, *stack[10], *root = NULL;
int top = -1;

node *createNode(char s)
{
    root = (node *)malloc(sizeof(node));
    root->data = s;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void push(node *root) //Pushes the node into the stack
{
    if (top == 9)
    {
        printf("Stack overflow");
        exit(1);
    }
    stack[++top] = root;
}

node *pop() //Removes a node from the stack
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return (stack[top--]);
}

int isOperator(char s)
{
    if (s == '+' || s == '-' || s == '*' || s == '/')
        return 1;
    return 0;
}

void createTree(char *postfix) // Creates an expression tree given a postfix expression
{
    int i;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperator(postfix[i]))
        {
            /*
            Either single node or small expression trees are stored in the stack, so when
            we have an operator, we pop the top nodes, link it with the new operator and 
            push it. Thus, for example, we have 2+3 as an expression tree in stack[0] and 
            4+5 as another expression in stack[1], (where stack[0] and [1] only store the
            addresses of the root nodes that are the operators), we link the 2 with the new
            operator that we just recieved, giving us (2+3) * (4+5) and we push this back 
            (again, technically it is just storing address of * which is in turn linked with 
            all the other elements).
            */
            root = createNode(postfix[i]);
            root->right = pop();
            root->left = pop();
            push(root);
        }
        else
        {
            root = createNode(postfix[i]); // Just creates a node and pushes it
            push(root);
        }
    }
    tree = pop(); // The last element remaining in the stack is our required root node of the tree
}

int evaluate(node *root)
{
    if (isOperator(root->data))
    {
        if (root->data == '+')
            return (evaluate(root->left) + evaluate(root->right));
        else if (root->data == '-')
            return (evaluate(root->left) - evaluate(root->right));
        else if (root->data == '*')
            return (evaluate(root->left) * evaluate(root->right));
        else
            return (evaluate(root->left) / evaluate(root->right));
    }
    else
        return (root->data - '0');
}

int isValidPostfix(char *postfix)
{
    //Checks for the validity of entered single digit postfix expression
    //Returns 1 if valid, 0 otherwise
    int noOfDigits = 0, noOfOperations = 0, isValidExpression = 1, i;

    if (isdigit(postfix[0]) && postfix[1] == '\0')
        return (isValidExpression);

    if (!(isdigit(postfix[0]) && isdigit(postfix[1])))
        return (--isValidExpression);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
            noOfDigits++;
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
            noOfOperations++;
        else
            return (--isValidExpression);
    }

    if (noOfDigits - noOfOperations != 1)
        return (--isValidExpression);

    return (isValidExpression);
}

int main()
{
    char postfix[20];
    while (1)
    {
        printf("Enter a valid postfix: ");
        scanf("%s", postfix);
        if (isValidPostfix(postfix))
            break;
        printf("Invalid expression\n");
    }

    createTree(postfix);
    printf("The expression is evaluated to: %d\n", evaluate(tree));
    return (0);
}