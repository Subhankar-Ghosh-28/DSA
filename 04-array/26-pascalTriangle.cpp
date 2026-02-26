#include <bits/stdc++.h>
using namespace std;

class Solution1
{

public:
    // Generate full triangle
    vector<vector<int>> generator(int rowNum)
    {
        vector<vector<int>> triangle;

        for (int i = 0; i < rowNum; i++)
        {

            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++)
            {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};

int main()
{
    int n = 7;

    Solution1 sol;
    cout << "The pascal triangle of " << n << " is :" << endl;
    vector<vector<int>> ans = sol.generator(n);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
    return 0;
}