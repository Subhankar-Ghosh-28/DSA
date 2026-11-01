// distance of nearest all have 1
// we have a matrix where 1, 0 are palace what is the nearest 1 of a 0,, apply Multi-Source BFS

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> nearest(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, (vector<int>(m, 0)));
        vector<vector<int>> distance(n, (vector<int>(m, 0)));

        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            distance[row][col] = steps;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }
        return distance;
        // TC-> O(n * m * 4)
        // SC-> O(n * m)
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0, 1},
        {0, 0, 1, 1},
        {0, 1, 1, 0},
        {1, 1, 0, 0}};

    Solution sol;
    vector<vector<int>> distance = sol.nearest(grid);

    cout << "Distance of each cell from the nearest 1:" << '\n';
    for (const vector<int> &row : distance)
    {
        for (int value : row)
        {
            cout << value << ' ';
        }
        cout << '\n';
    }

    return 0;
}