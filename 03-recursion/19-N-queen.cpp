#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define GREEN "\033[1;32m"
#define RESET "\033[0m"

// give a n number mean nXn chessboard and put queen in every colunm and row
class Solution
{
public:
    vector<vector<string>> bruteForce(int n)
    {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;

        bruteSolver(0, board, ans, n);

        return ans;
        // Time Complexity: O(N!*N),
        // Space Complexity: O(N^2 + N), additional space used for storing distinct boards and stack space.
    }

    vector<vector<string>> optimal(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        optimalSolve(0, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);
        return ans;
        // Time Complexity: O(N!), we try all possible permutations of placing the queens.
        // Space Complexity: O(N), three boolean arrays are stored to check for safety.
    }

private:
    void optimalSolve(int col, vector<string> &board, int n, vector<int> &leftRow,
                      vector<int> &upperDiagonal, vector<int> &lowerDiagonal, vector<vector<string>> &ans)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            // Check if it's safe to place the queen
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0)
            {
                // Place the queen
                board[row][col] = 'Q';

                // Mark the row and diagonals
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recurse to next column
                optimalSolve(col + 1, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);

                // Backtrack and remove the queen
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    bool isSafe(int row, int col, vector<vector<char>> &board, int n)
    {
        // same row
        for (int j = 0; j < col; j++)
        {
            if (board[row][j] == 'Q')
                return false;
        }
        // upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        // lower left diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void bruteSolver(int col, vector<vector<char>> &board, vector<vector<string>> &ans, int n)
    {
        vector<string> temp;
        if (col == n)
        {
            for (int i = 0; i < n; i++)
            {
                string row(board[i].begin(), board[i].end());
                temp.push_back(row);
            }
            ans.push_back(temp);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                // Place queen
                board[row][col] = 'Q';

                bruteSolver(col + 1, board, ans, n);
                // Back Tracking
                board[row][col] = '.';
            }
        }
    }
};

void printSideBySide(const vector<vector<string>> &res, int n, int perRow = 3)
{
    int total = res.size();

    for (int i = 0; i < total; i += perRow)
    {

        // Print solution titles
        for (int k = i; k < min(i + perRow, total); k++)
        {
            cout << "Solution " << k + 1;
            cout << string(10, ' ');
        }
        cout << "\n\n";

        // Print board rows
        for (int row = 0; row < n; row++)
        {
            for (int k = i; k < min(i + perRow, total); k++)
            {
                for (char c : res[k][row])
                {
                    if (c == 'Q')
                        cout << GREEN << "Q " << RESET;
                    else
                        cout << ". ";
                }
                cout << string(6, ' ');
            }
            cout << "\n";
        }

        cout << "\n"
             << string(80, '-') << "\n\n";
    }
}

int main()
{
    Solution sol;
    int n;

    cout << "Enter the board size: " << endl;
    cin >> n;

    auto result = sol.optimal(n);

    printSideBySide(result, n, 4);

    /*
    int solNo = 1;
    for (auto &board : result)
    {
        cout << "Solution " << solNo++ << ":\n";

        for (auto &row : board)
        {
            for (char c : row)
            {
                if (c == 'Q')
                    cout << GREEN << "Q " << RESET;
                else
                    cout << ". ";
            }
            cout << "\n";
        }
        cout << "--------------------\n";
    }
    */
    return 0;
}