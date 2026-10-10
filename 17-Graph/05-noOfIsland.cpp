// we are guven a N x M matrix and there is 1(land) and 0(water), we find how many island
// this is also a application of BFS

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        vis[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int deltaRow = -1; deltaRow <= 1; deltaRow++)
            {
                for (int deltaCol = -1; deltaCol <= 1; deltaCol++)
                {
                    int neighRow = row + deltaRow;
                    int neighCol = col + deltaCol;

                    if (neighRow >= 0 && neighRow < n && neighCol >= 0 && neighCol < m && grid[neighRow][neighCol] == '1' && !vis[neighRow][neighCol])
                    {
                        vis[neighRow][neighCol] = 1;
                        q.push({neighRow, neighCol});
                    }
                }
            }
        }
    }

public:
    int island(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!vis[row][col] && grid[row][col] == '1')
                {
                    bfs(row, col, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;

        // TC-> O(N * N)
        // SC-> O(N * N) + O(N * N)
    }
};

int main()
{
    int n = 5, m = 4;

    vector<vector<char>> grid = {
        {'0', '1', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '0', '0'},
        {'1', '1', '0', '1'}};

    Solution sol;
    cout << "The number of the island: " << sol.island(grid);

    return 0;
}