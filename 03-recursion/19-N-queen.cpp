#include <bits/stdc++.h>
using namespace std;
// give a n number mean nXn chessboard and put queen in every colunm and row
class Solution
{
public:
    vector<vector<string>> queenSolver(int n)
    {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;

        solver(0, board, ans, n);

        return ans;
    }

private:
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

    void solver(int col, vector<vector<char>> &board, vector<vector<string>> &ans, int n)
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

                solver(col + 1, board, ans, n);
                // Back Tracking
                board[row][col] = '.';
            }
        }
    }
};
// Time Complexity: O(N!*N),
// Space Complexity: O(N^2 + N), additional space used for storing distinct boards and stack space.

int main()
{
    Solution sol;
    int n = 4;

    vector<vector<string>> result = sol.queenSolver(n);

    int solNo = 1;
    for (auto &board : result)
    {
        cout << "Solution " << solNo++ << ":\n";

        for (auto &row : board)
        {
            for (char c : row)
            {
                cout << c << " ";
            }
            cout << "\n";
        }
        cout << "--------------------\n";
    }
    return 0;
}