//Program to evaluate a postfix expression

//NOTE: THIS CODE INCLUDES AN OPTIONAL PART. GO THROUGH IT BEFORE PROCEEDING TO USE THE CODE.
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define SIZE 40

int stack[10], top=-1;
char postfix[SIZE];

int isEmpty()
{
  //Returns 1 if stack is empty, 0 otherwise
  return (top==-1);
}

int isFull()
{
  //Returns 1 is stack is full, 0 otherwise
  return (top==9);
}

void push(int element)
{
  //Input: one integer
  //Pushes the input integer into the stack
  if(isFull())
  {
    printf("Error: Stack overflow\n");
  }
  else
  {
    stack[++top]=element;
  }
}

int pop()
{
  //Removes an element from the Stack
  //Return: Integer element removed
  if(isEmpty())
    {
        printf("Stack Underflow\n");
        return -1;
    }
  else
    return(stack[top--]);
}

int isValidSingleDigitPostfix()
{
  //Checks for the validity of entered single digit postfix expression
  //Returns 1 if valid, 0 otherwise
  int noOfDigits=0,noOfOperations=0,isValidExpression=1,i;

  if(isdigit(postfix[0]) && postfix[1]=='\0')
    return(isValidExpression);

  if(!(isdigit(postfix[0]) && isdigit(postfix[1])))
    return(--isValidExpression);

  for(i=0;postfix[i]!='\0';i++)
  {
    if(isdigit(postfix[i]))
      noOfDigits++;
    else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/')
      noOfOperations++;
    else
      return (--isValidExpression);
  }

  if(noOfDigits-noOfOperations!=1)
    return (--isValidExpression);

  return (isValidExpression);
}

//WARNING : DO NOT TRY TO IMPLEMENT THIS CODE UNLESS YOU UNDERSTAND IT AND ARE ABLE TO EXPLAIN IT.
//IT IS OPTIONAL AND I RECOMMEND YOU DELETE THIS PART FROM YOUR SUBMISSION UNLESS YOU KNOW WHAT YOU ARE DOING.
int isValidMultiDigitPostfix()
{
  //Checks for the validity of entered multi-digit postfix expression
  //Returns 1 if valid, 0 otherwise
  int noOfDigits=0,noOfOperations=0,isValidExpression=1,noOfSpaces=0,length,i,j;

  //To add a space at the end of the string
  length = strlen(postfix);
  postfix[length]=' ';
  postfix[length+1] = '\0';

  for(i=0;postfix[i]!='\0';i++)
  {
    if(postfix[i]==' ')
    {
      if(noOfSpaces<2)
      {
        if(!isdigit(postfix[i-1]))
        {
          return (--isValidExpression);
        }

        else
        {
          j=i-1;
          while (postfix[j]!=' ' && j>=0)
          {
            if(!isdigit(postfix[j]))
              return(--isValidExpression);
            j--;
          }
          noOfDigits++;
          noOfSpaces++;
        }
      }

      else if(isdigit(postfix[i-1]))
      {
        j=i-1;
        while (postfix[j]!=' ' && j>=0)
        {
          if(!isdigit(postfix[j]))
            return(--isValidExpression);
          j--;
        }
        noOfDigits++;
      }


      else if((postfix[i-1]=='+' &&postfix[i-2]==' ') || (postfix[i-1]=='-' &&postfix[i-2]==' ') || (postfix[i-1]=='*' &&postfix[i-2]==' ') || (postfix[i-1]=='/' &&postfix[i-2]==' '))
        noOfOperations++;
      else
      {
        return (--isValidExpression);
      }
    }
  }

  if(noOfDigits-noOfOperations!=1)
  {
    return (--isValidExpression);
  }


  return (isValidExpression);
}

//WARNING : DO NOT TRY IMPLEMENT THIS CODE UNLESS YOU UNDERSTAND IT AND ARE ABLE TO EXPLAIN IT.
//IT IS OPTIONAL AND I RECOMMEND YOU DELETE THIS PART FROM YOUR SUBMISSION UNLESS YOU KNOW WHAT YOU ARE DOING.
void multiDigitEvaluate()
{
  //Evaluates a multi-digit postfix expression, wherein each emtry is seperated by a whitespace, entered by the user and displays the result.
  int i,j,powerTen,element,x1,x2,zeroDivision=0;

  while(1)
  {
    printf("Enter a valid postfix expression with each entry seperated by a whitespace: ");
    fflush(stdin);
    gets(postfix);
    if(isValidMultiDigitPostfix())
    {
      break;
    }
    else
      printf("The postfix expression entered is invalid\n\n");
  }

  for(i=0;postfix[i]!='\0';i++)
  {
    if(postfix[i]==' ')
    {
      j=i-1;

      if(isdigit(postfix[j]))
      {
        powerTen=0;
        element=0;
        while(isdigit(postfix[j]) && j!=-1)
        {
          element += (postfix[j]-'0')*pow(10,powerTen);
          j--;
          powerTen++;
        }

        push(element);
      }

      else if(postfix[j] == '+')
      {
        x2=pop();
        x1=pop();
        push(x1+x2);
      }
      else if(postfix[j] == '-')
      {
        x2=pop();
        x1=pop();
        push(x1-x2);
      }
      else if(postfix[j] == '*')
      {
        x2=pop();
        x1=pop();
        push(x1*x2);
      }
      else if(postfix[j] == '/')
      {
        x2=pop();
        x1=pop();
        if(x1==0 && x2==0)
        {
          zeroDivision = 1;
          break;
        }

        else if(x2==0)
        {
          zeroDivision = 2;
          break;
        }
        else
          push(x1/x2);
      }
    }
  }
    if(zeroDivision==1)
      printf("The result is: NaN\n");
    else if(zeroDivision==2)
      printf("The result is: %c\n",236);
    else
      printf("The result is: %d\n",pop());

}

void singleDigitEvaluate()
{
  //Evaluates the postfix expression with only single digit numbers entered by the user and displays the result
  int i,x1,x2,zeroDivision=0;
  while(1)
  {
    printf("Enter a valid postfix expression: \n");
    scanf("%s",postfix);
    if(isValidSingleDigitPostfix())
    {
      break;
    }
    else
      printf("The postfix expression entered is invalid\n\n");
  }

  for(i=0;postfix[i]!='\0';i++)
  {
    if(isdigit(postfix[i]))
    {
      push(postfix[i]-'0');
    }
    else if(postfix[i] == '+')
    {
      x2=pop();
      x1=pop();
      push(x1+x2);
    }
    else if(postfix[i] == '-')
    {
      x2=pop();
      x1=pop();
      push(x1-x2);
    }
    else if(postfix[i] == '*')
    {
      x2=pop();
      x1=pop();
      push(x1*x2);
    }
    else if(postfix[i] == '/')
    {
      x2=pop();
      x1=pop();
      if(x1==0 && x2==0)
      {
        zeroDivision = 1;
        break;
      }

      else if(x2==0)
      {
        zeroDivision = 2;
        break;
      }
      else
        push(x1/x2);
    }
  }

  if(zeroDivision==1)
    printf("The result is: NaN\n");
  else if(zeroDivision==2)
    printf("The result is: %c\n",236); //236 is the ascii of infinity symbol
  else
    printf("The result is: %d\n",pop());
}

void menu()
{
  //Loops the menu until a valid option is selected
  char menu;
  while(1)
  {
      printf("1. Single digit numbers in the expression\n");
      printf("2. Multi-digit numbers in the expression\n");
      printf("Enter your choice: \n");
      scanf(" %c",&menu);


        if(menu=='1')
        {
          singleDigitEvaluate();
          break;
        }
        else if(menu=='2')
        {
          multiDigitEvaluate();
          break;
        }
        else
          printf("Invalid choice\n\n");
      }
}

int main()
{
  menu();
  return 0;
}
