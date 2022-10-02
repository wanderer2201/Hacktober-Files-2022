#include <bits/stdc++.h>
#define N 4
using namespace std;

// N Queens Problem Description:

/*
The N Queen is the problem of placing N chess queens on 
an N×N chessboard so that no two queens attack each other.
*/
/*Function to print solution */
void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << " " << board[i][j] << " ";
        printf("\n");
    }
}


/*
A function to check whether it is safe to place the
queen on position (row,col) given the current configuration
of the board.
*/
bool safePos(int board[N][N], int row, int col)
{
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

/* A recursive utility function to solve N
   Queen problem */

// A recursive function to solve the n queens
// problem by placing a queen in each column
// one at a time
bool nQueensSolver(int board[N][N], int col)
{
    // queen placed in all columns
    if (col >= N)
    {
        return true;
    }
    // Checking all rows for column col
    for (int i = 0; i < N; i++)
    {

        if (safePos(board, i, col))
        {

            // Recursive step
            board[i][col] = 1;
            if (nQueensSolver(board, col + 1))
                return true;

            // Backtracking by undoing previous change
            board[i][col] = 0;
        }
    }

    return false;
}

// Main Driver Program
int main()
{
    int board[N][N] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};

    if (nQueensSolver(board, 0) == false)
    {
        cout << "nQueens Problem cannot be solved";
    }
    else
    {
        printBoard(board);
    }

    return 0;
}

// Time complexity: O(N!)
// Space Complexity: O(N^2)
