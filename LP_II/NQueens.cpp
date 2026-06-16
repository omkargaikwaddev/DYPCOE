#include <iostream>      // For input and output
#include <vector>        // For using vector

using namespace std;

// Function to print the chessboard
void printBoard(vector<vector<int>>& board, int n) {

    cout << "\nSolution:\n" << endl;

    // Traverse rows
    for (int i = 0; i < n; i++) {

        // Traverse columns
        for (int j = 0; j < n; j++) {

            // Print board element
            cout << board[i][j] << " ";
        }

        // Move to next line
        cout << endl;
    }
}

// Function to check whether queen can be placed
bool isSafe(vector<vector<int>>& board,
            int row,
            int col,
            int n) {

    int i, j;

    // Check left side of current row
    for (i = 0; i < col; i++) {

        // If queen already exists
        if (board[row][i] == 1) {

            return false;
        }
    }

    // Check upper-left diagonal
    for (i = row, j = col;
         i >= 0 && j >= 0;
         i--, j--) {

        // If queen already exists
        if (board[i][j] == 1) {

            return false;
        }
    }

    // Check lower-left diagonal
    for (i = row, j = col;
         i < n && j >= 0;
         i++, j--) {

        // If queen already exists
        if (board[i][j] == 1) {

            return false;
        }
    }

    // Position is safe
    return true;
}

// Recursive function to solve N-Queens
bool solveNQueens(vector<vector<int>>& board,
                  int col,
                  int n) {

    // Base condition:
    // If all queens are placed
    if (col >= n) {

        return true;
    }

    // Try placing queen in every row
    for (int i = 0; i < n; i++) {

        // Check if current position is safe
        if (isSafe(board, i, col, n)) {

            // Place queen
            board[i][col] = 1;

            // Recursive call for next column
            if (solveNQueens(board,
                             col + 1,
                             n)) {

                return true;
            }

            // BACKTRACKING:
            // Remove queen if solution not found
            board[i][col] = 0;
        }
    }

    // No solution found
    return false;
}

int main() {

    int n;

    // Input number of queens
    cout << "Enter number of queens: ";

    cin >> n;

    // Create chessboard initialized with 0
    vector<vector<int>> board(n,
                              vector<int>(n, 0));

    // Solve N-Queens problem
    if (solveNQueens(board, 0, n)) {

        // Print solution
        printBoard(board, n);
    }
    else {

        // If no solution exists
        cout << "\nNo Solution Exists!" << endl;
    }

    return 0;   // End program
}

/*
Example Input
Enter number of queens: 4
*/

/*
Example Output
Solution:

0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0
*/

/*
Simple Explanation
What is N-Queens Problem?

Place N queens on an N × N chessboard such that:

No two queens attack each other

Queens attack:

Horizontally
Vertically
Diagonally
What is Backtracking?

Backtracking means:

Try a solution
If it fails, undo it
Try another solution
Why is it Constraint Satisfaction Problem (CSP)?

Because:

Each queen placement must satisfy constraints
No conflict allowed
Backtracking Step

If placement fails:

Place Queen → Check → Fail → Remove Queen → Try Again
Time Complexity

Worst case:

O(N!)
*/