// if a matrix have 0 element value then the corrosponding row
// and col will be se 0.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void markRow(int row, vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int j = 0; j < m; j++)
        {
            if (matrix[row][j] != 0)
            {
                matrix[row][j] = -1; // the matrix elements should be >= 0
            }
        }
    }
    void markCol(int col, vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            if (matrix[i][col] != 0)
            {
                matrix[i][col] = -1;
            }
        }
    }

public:
    void bruteForce(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    markRow(i, matrix);
                    markCol(j, matrix);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        //TC -> O(m * n * (m + n)));
    }

    void better(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        // First pass: mark rows and columns that need to be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If element is zero, mark its row and column
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Second pass: set cells to zero based on markers
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the row or column is marked, set cell to zero
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    vector<vector<int>> optimal(vector<vector<int>> &matrix)
    {
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};

    Solution sol;

    sol.better(matrix);

    for (auto x : matrix)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}