#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(vector<vector<int>> &mat)
    {
        int n = mat.size();

        vector<int> knowMe(n, 0);

        vector<int> Iknow(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    knowMe[j]++;
                    Iknow[i]++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (knowMe[i] == n - 1 && Iknow[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }

    int optimal(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int top = 0;
        int down = n - 1;

        while (top < down)
        {
            if (mat[top][down] == 1)
            {
                top++;
            }

            else if (mat[down][top] == 1)
                down--;
            else
            {
                top++;
                down--;
            }
        }
        
        if (top > down)
            return -1;
        top = down;
        for (int i = 0; i < n; i++)
        {
            if ( i== top) continue;
            if (mat[top][i] == 1 || mat[i][top] == 0)
                return -1;
        }
        return top;
    }
};

int main()
{
    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}};
    Solution sol;
    cout << sol.optimal(mat);
    return 0;
}