// this algo is for given color and same initial color would me change and give the hange matrix
// application of DFS

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image,
         int newColor, int deltaRow[], int deltaCol[], int intialColor)
{
    ans[row][col] = newColor;

    int n = image.size();
    int m = image[0].size();

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + deltaRow[i];
        int ncol = col + deltaCol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            image[nrow][ncol] == intialColor && ans[nrow][ncol] != newColor)
        {
            dfs(nrow, ncol, ans, image, newColor, deltaRow, deltaCol, intialColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int n = image.size();
    int m = image[0].size();

    int initalColor = image[sr][sc];

    vector<vector<int>> ans = image;
    int deltaRow[] = {-1, 0, 1, 0};
    int deltaCol[] = {0, 1, 0, -1};

    dfs(sr, sc, ans, image, newColor, deltaRow, deltaCol, initalColor);
    return ans;

    // TC-> O(N * M * 4)
    // SC-> O(N * M) + O(N * M) -> recursive;
}

int main()
{

    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> ans = floodFill(image, sr, sc, newColor);

    cout << "The final matrix: " << endl;

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}