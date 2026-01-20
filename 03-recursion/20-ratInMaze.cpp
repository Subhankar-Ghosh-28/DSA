#include <bits/stdc++.h>
using namespace std;

// rat in maze means a rat place at (0,0) and want to reach (n-1, n-1) of maze nXn
// some cell fill with  1(open) an 0(close) ,, give all possible path

bool isSafe(int x, int y, int n, vector<vector<int>> &maze,
            vector<vector<int>> &visited)
{
    return (x >= 0 && x < n && y >= 0 && y < n &&
            maze[x][y] == 1 && visited[x][y] == 0);
}

void pathFinder(int i, int j, int n, string path, vector<vector<int>> visited,
                vector<vector<int>> &maze, vector<string> &result)
{
    if (i == n - 1 && j == n - 1)
    {
        result.push_back(path);
    }

    /* instited of write 4 if write this and change somthing and di = {1,0,0,-1}  dj = {0,-1,1,0} in findPAth

    this chage in pathfinder

    string dir = "DLRU";
    for(int ind = 0 ; ind < 4; ind++){
        int nexti = i + di[ind];
        int nextj = j + dj[ind];

        if(nexti >=0 && nextj >= 0 && nexti < n && nextj < n && 
            !visited[nexti][nextj] && maze[nexti][nextj] == 1){
            
            visited[i][j] = 1;

            pathFinder(nexti,...)
        }
    }
    */

    // Mark the cell visited
    visited[i][j] = 1;

    // Try moving Down
    if (isSafe(i + 1, j, n, maze, visited))
    {
        pathFinder(i + 1, j, n, path + "D", visited, maze, result);
    }
    // Try moving Left
    if (isSafe(i, j - 1, n, maze, visited))
    {
        pathFinder(i, j - 1, n, path + "L", visited, maze, result);
    }
    // Try moving Right
    if (isSafe(i, j + 1, n, maze, visited))
    {
        pathFinder(i, j + 1, n, path + "R", visited, maze, result);
    }
    // Try moving Up
    if (isSafe(i - 1, j, n, maze, visited))
    {
        pathFinder(i - 1, j, n, path + "U", visited, maze, result);
    }

    // Backtrack: unmark cell as visited
    visited[i][j] = 0;
}

vector<string> findPath(vector<vector<int>> &maze)
{
    int n = maze.size();
    vector<string> result;
    vector<vector<int>> visited(n, vector<int>(n, 0));

    if (maze[0][0] == 1)
    {
        pathFinder(0, 0, n, "", visited, maze, result);
    }
    return result;
}

// Time Complexity: O(4^(N*N)),, because on every cell we need to try 4 different directions.
// Space Complexity: O(N*N), additional space for visited array and maximum Depth of the recursion tree(auxiliary space).

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    vector<string> paths = findPath(maze);

    for (auto &p : paths)
        cout << p << " ";
    return 0;
}