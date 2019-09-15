/*
    @Author: Raghav Maheshwari
    @Time: 09:36 P.M.
    @Topic: N Queens Problem
*/

#include <stdio.h>
int count = 0;
int noAttack(char board[100][100], int row, int col, int n)
{

    //Sabse pehle check karo same row me toh nahi hai,column vary karega
    for (int Y = 0; Y < n; Y++)
    {
        if (board[row][Y] == 'Q')
        {
            return 0; //0 matlab attack hoga
        }
    }
    //row check karne ke baad column check karo, matlab row badlega
    for (int X = 0; X < n; X++)
    {
        if (board[X][col] == 'Q')
        {
            return 0; //attack hoga.
        }
    }
    //Row aur column me check karne ke baad dono right aur left diagonals check karo.
    //Neeche ka filled nahi hai toh bas top right andtop left basically.

    //Toh top left me, har baar x aur y kam hoga, as going to left
    int x = row;
    int y = col;
    //Jab tak aap chessboard ke aandar ho
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 'Q')
        {
            return 0; //boldo attack hoga.
        }
        //keep decrementing x and y
        x--;
        y--;
    }

    //Ab baat karte hai top right ki,
    // toh obvious sa baat hai, x coordinate will dec and y will inc.
    //so x>=0 and y should be less than n
    int x1 = row;
    int y1 = col;
    while (x1 >= 0 && y1 < n)
    {
        if (board[x1][y1] == 'Q')
        {
            return 0; //boldo attack hoga.
        }
        x1--; //keep decrementing x
        y1++; //Keep incrementing y(Kyuki aap right mein ja rhe ho)
    }

    //Ab agar itna sab check karne ke baad bhi, kuch nahi mila, matlab Sab clear hai, no issue
    //bindass one return kardo.
    return 1;
}

int solveNQueenProblem(char board[100][100], int n, int row)
{
    //If we get to the end of the board, basically last queen is placed, (THis is the base case.)
    //then row will become equal to n, in that case we will print the solution.
    if (row == n)
    {
        //Printing the XY board here, if row is same as n.
        printf("\n*********************Solution %d**************\n", ++count);
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                printf("%c ", board[x][y]);
            }
            printf("\n");
        }

        //return 1; //Prints only one solution.

        /********************************** VERY VERY IMPORTANT ***************************/
        //If all solutions are two be printed we have to return 0 from the base case also,
        //showing that we need more solutions, completing the backtrack.
        //ALl we have to do is return 0 instead of 1

        /***********************************FOR PRINTING ALL SOLUTIONS *******************/
        return 0; //Prints all solutions
    }
    //Now considering the recursive case.
    //Try to place the queen in the current row.(We consider column by column)
    for (int col = 0; col < n; col++)
    {
        //First we check that there is no attack at the current position by passing the row and the column
        if (noAttack(board, row, col, n))
        {
            board[row][col] = 'Q';

            //NOw, check if we can place the next queen
            int agliQueenRakhSakteHai = solveNQueenProblem(board, n, row + 1); //Considering for next row.
            if (agliQueenRakhSakteHai == 1)
            {
                return 1;
            }
            //If not so,
            board[row][col] = '-';
        }
    }
    return 0; //This shows we are doing backtracking.
}

void main()
{

    char board[100][100]; //This will define a board of size nXn
    int n;
    printf("\nEnter the number of Queens:\t");
    scanf("%d", &n);

    //Initialize each and every member of the same

    //We put a dash at all the places at the start of the XY board, we consider the chess board to be
    // an XY board.
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            board[x][y] = '-'; //Putting a random character can be replaced by 0.
        }
    }
    //This function basically takes the board(As we defined earlier), the number of rows or queens
    //and the starting row, here we start from the row 0.
    solveNQueenProblem(board, n, 0);
}