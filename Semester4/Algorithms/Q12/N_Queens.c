/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-05-27 11:18:29 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-05-27 11:24:02
 */

/*
 * Question: Implement N-Queens problem using backtracking.
 * 
 * Explaination: https://www.youtube.com/watch?v=0DeznFqrgAI
 * Logic: Place 1 queen in the first row at each cell and check if the 
 * rest of the board can be filled with this config. This repeats
 * recurrsively for all rows.
 * Time Complexity = O(N!)
 * Space complexity = O(N^2)
*/

#include<stdio.h>
#define N 4


//Takes the current board, the row and column where to check if its possible
// to place and returns 1 if under attack.
int underAttack(int board[N][N], int row, int col)
{
    int i, j;
    for(i=0; i<row;i++)
    {
        for(j=0;j<N;j++)
        {
            if(j==col && board[i][j]) // check for the cells above the current cell
                return 1;
            else if(row+col == i+j && board[i][j]) // Secondary Diagonal
                return 1;
            else if(row-col == i-j && board[i][j]) // Primary diagonal
                return 1;
        }
    }
    return 0;
}

// Takes in the row at which u want to place the queen, and places it if 
// possible and returns 1, else returns 0.
int placeQueen(int board[N][N], int row)
{
    if(row>=N)
        return 1; // Means all the N queens are placed. Only then row>=N

    int i,j,k,l, possible = 0;
    for(i=0;i<N;i++)
    {
        if(!underAttack(board, row, i)) // Takes a particular row, checks
        // each cell of that row to determine of its possible to place it there.
        {
            board[row][i] = 1;
            possible = placeQueen(board, row+1);
            if(possible)
            {
                // Uncomment this code if u want all possible solutions
                // also remove the prints in main function
                // if(row == 0)
                // {
                //     for(k=0;k<N;k++)
                //     {
                //         for(l=0;l<N;l++)
                //             {
                //                 printf("%d ", board[k][l]);
                //                 board[k][l] = 0;
                //             }
                //         printf("\n");
                //     }
                //     printf("\n");
                // }
                // else
                // {
                //     return 1;
                // }
                return 1;
            }
            else
            {
                board[row][i] = 0; // if placing in the next row isn't possible,
                // make the current cell 0 as well, and try the next cell in that row.
            }  
        }
    }
    return 0;
}

int main()
{
    int board[N][N] = {0}, i,j;

    if(placeQueen(board, 0)) // We place the first queen and the above function
    // automatically places the queens in successive rows.
    {
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
                {
                    printf("%d ", board[i][j]);
                    board[i][j] = 0;
                }
            printf("\n");
        }
    }
    return(0);
}