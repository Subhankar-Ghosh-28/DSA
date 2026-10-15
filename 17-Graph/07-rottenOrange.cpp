// 1 rotten orange rotted all his neightbour orange. We find minimum time to rotten all
// if one ggod orange exixts then it return -1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        // row, col, time
        int visited[n][m];
        int cntFresh = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }

                else
                    visited[i][j] = 0;

                if (grid[i][j] == 1)
                    cntFresh++;
            }
        }
        int tm = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int cnt = 0;
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && visited[nr][nc] != 2 && grid[nr][nc] == 1)
                {
                    q.push({{nr, nc}, t + 1});
                    visited[nr][nc] = 2;
                    cnt++;
                }
            }
        }
        if (cnt != cntFresh)
            return -1;

        return tm;

        // TC-> O(N * M * 4)
        // SC-> O(N * M);
    }
};

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    Solution sol;

    cout << "The time required: " << sol.orangesRotting(grid) << "\n";

    return 0;
}