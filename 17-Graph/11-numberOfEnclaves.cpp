// The problem state that land which does not have any escape point from the water then
// we just cnt the no of 1's(land),, the boundary 1 has escape points so they dont cnt;;; use BFS

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int enclaves(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {

                    if (grid[i][j] == 1)
                        q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    cnt++;
                }
            }
        }
        return cnt;

        // TC -> O(N*M*4);
        //  SC -> O(N*M);
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};

    Solution solution;
    cout << "Number of enclaves: " << solution.enclaves(grid) << '\n';

    return 0;
}