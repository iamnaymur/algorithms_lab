#include <bits/stdc++.h>
using namespace std;

int n;

// Function to check if placing a queen at (row, col) is safe
bool checkCondition(vector<vector<int>> &board, int row, int col)
{
    // Check this row on left side
    for (int c = 0; c < col; c++)
    {
        if (board[row][c] == 1)
            return false;
    }

    // Check upper diagonal on left side
    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--)
    {
        if (board[r][c] == 1)
            return false;
    }

    // Check lower diagonal on left side
    for (int r = row, c = col; r < n && c >= 0; r++, c--)
    {
        if (board[r][c] == 1)
            return false;
    }

    return true; // safe to place
}

// Recursive function to place queens
bool placeQueens(vector<vector<int>> &board, int n, int col)
{
    if (col >= n)
    { // all queens placed
        // Print solution
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << (board[i][j] == 1 ? "Q " : ". ");
            }
            cout << "\n";
        }
        cout << "\n";
        return true;
    }

    for (int row = 0; row < n; row++)
    {
        bool flag = checkCondition(board, row, col);
        if (flag == true)
        {
            board[row][col] = 1; // place queen
            bool success = placeQueens(board, n, col + 1);
            if (success == true)
                return true;     // found a solution
            board[row][col] = 0; // backtrack
        }
    }

    return false; // no valid placement in this column
}

int main()
{
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!placeQueens(board, n, 0))
    {
        cout << "No solution exists\n";
    }

    return 0;
}
